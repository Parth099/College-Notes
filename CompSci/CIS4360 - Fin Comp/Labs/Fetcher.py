'''
@project       : Temple University CIS 4360 Computational Methods in Finance
@Instructor    : Dr. Alex Pang

@Student Name  : Parth Patel

@Date          : 10/3/2023

Download daily stock price from Yahoo

'''


import os
import pandas as pd
import numpy as np
import sqlite3

# pip install pandas-datareader
import pandas_datareader as pdr

import yfinance as yf

import option

from typing import List, Dict

# https://www.geeksforgeeks.org/python-stock-data-visualisation/

class Fetcher(object):

    DELETE_ROWS_BY_TICKER_QUERY = "DELETE FROM {db_table} WHERE Ticker = ?;"
    INSERT_ROW_QUERY = "INSERT INTO {db_table} (Ticker, AsOfDate, Open, High, Low, Close, Volume, TurnOver, Dividend) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)"

    def __init__(self, opt: option.Option, db_connection: sqlite3.Connection):
        # opt is an option instance
        self.opt = opt
        self.db_connection = db_connection

    def get_daily_from_yahoo(self, ticker: str, start_date: str, end_date: str) -> pd.DataFrame:
        """Obtains daily data for the said `ticker` between specfied dates via the yahoo API. **Note**: Start day and End Day are NOT included.
        Args:
            ticker (str): stock symbol
            start_date (str): stock data start data
            end_date (str): stock data start data

        Returns:
            pd.DataFrame: data frame of stock data between dates.
        """

        stock = yf.Ticker(ticker)
        df = stock.history(start=start_date, end=end_date)
        print("obtained API data: ", ticker)

        if df.shape[0] == 0: print(f"No data found for ticker=${ticker}")

        return df

    def download_data_to_csv(self, list_of_tickers: List[str]):
        """take DF and save them to CSVs per stock symbol

        Args:
            list_of_tickers (List[str]): list of tickers to process and download
        """

        start_date, end_date = self.opt.start_date, self.opt.end_date
        output_dir = self.opt.output_dir

        for ticker in list_of_tickers:
            stock_data = self.get_daily_from_yahoo(ticker, start_date, end_date)
            stock_data['Ticker'] = ticker
            stock_data.to_csv(f"{output_dir}\\{ticker}_daily.csv")
            print("saved to csv: ", ticker)

        
    def csv_to_table(self, csv_file_name: str, fields_map: Dict[str, str], db_table: str):
        """Takes CSV File Data from the file system and INSERTs into Sql File

        Args:
            csv_file_name (str): name of csv file
            fields_map (dict): Set of Table headers
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

            insert_statement = Fetcher.INSERT_ROW_QUERY.format(db_table=db_table)
            
            cursor.execute(insert_statement, (Ticker, AsOfDate, Open, High, Low, Close, Volume, 0, Dividend))

        
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
        cursor = self.db_connection.cursor()

        delete_statement = Fetcher.DELETE_ROWS_BY_TICKER_QUERY.format(db_table=db_table)
        cursor.execute(delete_statement, (ticker, ))

        # instead of looping over rows we can just use df.apply and apply an insert function along the rows
        df.apply(insert_function, axis=1)

        self.db_connection.commit()
        cursor.close()
        
    def save_daily_data_to_sqlite(self, daily_file_dir, list_of_tickers):
        # read all daily.csv files from a dir and load them into sqlite table
        db_table = 'EquityDailyPrice'

        fields_map = {'Date': 'AsOfDate', 'Dividends': 'Dividend', 'Stock Splits': 'StockSplits'}
        for f in ['Ticker', 'Open', 'High', 'Low', 'Close', 'Volume']:
            fields_map[f] = f

        for ticker in list_of_tickers:
            file_name = os.path.join(daily_file_dir, f"{ticker}_daily.csv")
            self.csv_to_table(file_name, fields_map, db_table)
            print("saved to DB: ", ticker)

    
def run():
    #
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
        
    list_of_tickers = ['AAPL']
    print(list_of_tickers)
    print(opt.start_date, opt.end_date)

    db_file = opt.sqlite_db
    db_connection = sqlite3.connect(db_file)
    
    fetcher = Fetcher(opt, db_connection)
    print(f"Download data to {opt.data_dir} directory")

    fetcher.download_data_to_csv(list_of_tickers)
    fetcher.save_daily_data_to_sqlite(opt.output_dir, list_of_tickers)

    db_connection.close()


    
if __name__ == "__main__":
    #_test()
    run()
