'''
@project       : Temple University CIS 4360 Computational Methods in Finance
@Instructor    : Dr. Alex Pang

@Student Name  : Parth, Patel

@Date          : 9/12/2023

Download daily stock price from Yahoo

'''

import os
import multiprocessing as mp # :)

import pandas as pd
import sqlite3

import yfinance as yf
import option

from typing import List, Tuple, Set

# https://www.geeksforgeeks.org/python-stock-data-visualisation/

# Type defs
download_singlar_data_to_csv_func_arg = Tuple[option.Option, str]
download_singlar_data_to_csv_func_args = List[download_singlar_data_to_csv_func_arg]


def get_daily_from_yahoo(ticker: str, start_date, end_date):
    """Gets daily stock data from yahoo via yfinance 

    Args:
        ticker (str): ticker of stock required 
        start_date (any): interval start date to obtain data for (start day not included)
        end_date (any): interval end date to obtain data for (end day not included)
    """
    stock = yf.Ticker(ticker)
    df = stock.history(period="1d", start=start_date, end=end_date)
    return df

def download_singlar_data_to_csv(args: download_singlar_data_to_csv_func_arg):
    """downloads a single ticker to csv file

    Args:
        args (download_singlar_data_to_csv_func_arg): arguments to function, see type hint
    """

    opt, ticker = args

    start_date, end_date = opt.start_date, opt.end_date
    output_dir = opt.output_dir

    daily_df = get_daily_from_yahoo(ticker, start_date, end_date)
    daily_df['Ticker'] = ticker

    print("saving to:", f"{output_dir}\\{ticker}_daily.csv")
    daily_df.to_csv(f"{output_dir}\\{ticker}_daily.csv")

def download_data_to_csv(opt: option.Option, list_of_tickers: List[str]):
    """Runs the function `download_singlar_data_to_csv` in parallel

    Args:
        opt (option.Option): Python object with fallback defaults or custom injected options
        list_of_tickers (List[str]): List of Stock Ticker to call data for
    """

    no_tickers = len(list_of_tickers)
    no_cpus = mp.cpu_count()

    function_args = list(zip([opt]*no_tickers, list_of_tickers)) # args for each parellel call (no need to create new opt objects we can use same pointer)

    # run parallel jobs to download CSVs faster!
    with mp.Pool(processes = no_cpus) as parallel_pool:
        parallel_pool.map(download_singlar_data_to_csv, function_args)
        
def csv_to_table(csv_file_name: str, fields_map: Set, db_connection: sqlite3.Connection, db_table: str):
    """Takes CSV File Data from the file system and INSERTs into Sql File

    Args:
        csv_file_name (str): name of csv file
        fields_map (Set): Set of Table headers
        db_connection (sqlite3.Connection): connection to sqlite db
        db_table (str): name of table
    """

    def insert_function(row: pd.Series):
        AsOfDate = row['AsOfDate']
        Open = row['Open']
        High = row['High']
        Low = row['Low']
        Close = row['Close']
        Volume = row['Volume']
        Dividend = row['Dividend']
        StockSplits = row['StockSplits']
        Ticker = row['Ticker']

        cursor.execute(INSERT_ROW_QUERY, (Ticker, AsOfDate, Open, High, Low, Close, Volume, 0, Dividend))


    # Query constants  
    DELETE_ROWS_BY_TICKER_QUERY = f"DELETE FROM {db_table} WHERE Ticker = ?;"
    INSERT_ROW_QUERY = f"INSERT INTO {db_table} (Ticker, AsOfDate, Open, High, Low, Close, Volume, TurnOver, Dividend) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)"

    # insert data from a csv file to a table
    df = pd.read_csv(csv_file_name)
    if df.shape[0] <= 0:
        return
    # change the column header
    df.columns = [fields_map[x] for x in df.columns]

    # move ticker columns
    new_df = df[['Ticker']].copy()
    for c in df.columns[:-1]:
        new_df.loc[:, c] = df.loc[:, c]

    ticker = os.path.basename(csv_file_name).replace('.csv','').replace("_daily", "")
    print(ticker)
    cursor = db_connection.cursor()

    cursor.execute(DELETE_ROWS_BY_TICKER_QUERY, (ticker, ))

    # instead of looping over rows we can just use df.apply and apply an insert function along the rows
    df.apply(insert_function, axis=1)

    db_connection.commit()
    cursor.close()
    #db close happens in caller function


def save_daily_data_to_sqlite(opt, daily_file_dir, list_of_tickers):
    # read all daily.csv files from a dir and load them into sqlite table
    db_file = os.path.join(opt.sqlite_db)
    print(db_file)
    db_conn = sqlite3.connect(db_file)
    db_table = 'EquityDailyPrice'
    
    fields_map = {'Date': 'AsOfDate', 'Dividends': 'Dividend', 'Stock Splits': 'StockSplits'}
    for f in ['Ticker', 'Open', 'High', 'Low', 'Close', 'Volume']:
        fields_map[f] = f

    for ticker in list_of_tickers:
        file_name = os.path.join(daily_file_dir, f"{ticker}_daily.csv")
        print(file_name)
        csv_to_table(file_name, fields_map, db_conn, db_table)

    #db_conn.close()
    
def _test():
    ticker = 'MSFT'
    start_date = '2020-01-01'
    end_date = '2023-08-01'

    print (f"Testing getting data for {ticker}:")
    df = get_daily_from_yahoo(ticker, start_date, end_date)
    print(df)

def run():
    parser = option.get_default_parser()
    parser.add_argument('--data_dir', dest = 'data_dir', default='./data', help='data dir')    
    
    args = parser.parse_args()
    opt = option.Option(args = args)

    opt.output_dir = os.path.join(opt.data_dir, "daily")
    opt.sqlite_db = os.path.join(opt.data_dir, "sqlitedb/Equity.db")

    if opt.tickers is not None:
        list_of_tickers = opt.tickers.split(',')
    else:
        fname = os.path.join(opt.data_dir, "S&P500.txt")
        list_of_tickers = list(pd.read_csv(fname, header=None).iloc[:, 0])
        print(f"Read tickers from {fname}")
        
    print(list_of_tickers)
    print(opt.start_date, opt.end_date)

    # download all daily price data into a output dir
    if 1:
        print(f"Download data to {opt.data_dir} directory")
        download_data_to_csv(opt, list_of_tickers)

    if 1:
        # read the csv file back and save the data into sqlite database
        save_daily_data_to_sqlite(opt, opt.output_dir, list_of_tickers)
    
if __name__ == "__main__":
    #_test()
    run()
