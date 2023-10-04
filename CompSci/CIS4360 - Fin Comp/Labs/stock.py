'''
@project       : Temple University CIS 4360 Computational Methods in Finance
@Instructor    : Dr. Alex Pang

@Student Name  : first last

@Date          : 9/1/2023

Download daily stock price from Yahoo

'''

import os
import pandas as pd
import numpy as np
import datetime 
import sqlite3

from utils import MyYahooFinancials 
import option

class Stock(object):
    '''
    Stock class for getting financial statements as well as pricing data
    '''
    def __init__(self, opt, db_connection, ticker):
        self.opt = opt
        self.db_connection = db_connection
        self.ticker = ticker
        self.ohlcv_df = None
        

    def get_daily_hist_price(self, start_date, end_date):
        # Get daily historical OHLCV from database
        try:
            sql = f"select * from EquityDailyPrice where ticker = '{self.ticker}' order by AsOfDate asc"
            df = pd.read_sql(sql, self.db_connection)
            df['AsOfDate'] = df['AsOfDate'].apply(lambda x: datetime.datetime.strptime(x[:10], "%Y-%m-%d").date())

            # filter data between start and end date
            df = df[ df.AsOfDate >= start_date ]
            df = df[ df.AsOfDate <= end_date ]

            # create an index based on the AsOfDate column
            df['Date'] = df.AsOfDate
            df = df.set_index('Date')
            
            self.ohlcv_df = df
            return(df)
            
        except Exception as e:
            print(f"Failed to get data for {self.ticker}: {e}")
            raise Exception(e)

def _test():
    # a few basic unit tests

    dt = datetime.datetime.strptime("2013-01-02", "%Y-%m-%d")
    
    parser = option.get_default_parser()
    parser.add_argument('--data_dir', dest = 'data_dir', default='./data', help='data dir')    
    
    args = parser.parse_args()
    opt = option.Option(args = args)

    opt.output_dir = os.path.join(opt.data_dir, "daily")
    opt.sqlite_db = os.path.join(opt.data_dir, "sqlitedb/Equity.db")

    db_file = opt.sqlite_db
    db_connection = sqlite3.connect(db_file)

    print(vars(opt))
    
    symbol = 'AAPL'
    stock = Stock(opt, db_connection, symbol)
    #
    
    start_date = datetime.date(2020, 1, 1)
    end_date = datetime.date(2023, 10, 1)
    df = stock.get_daily_hist_price(start_date, end_date)

    print(df.head())



if __name__ == "__main__":
    _test()
