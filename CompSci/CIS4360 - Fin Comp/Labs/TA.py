'''
@project       : Temple University CIS 4360 Computational Methods in Finance
@Instructor    : Dr. Alex Pang

@Student Name  : Parth Patel

@Date          : 10/6/2023

Technical Indicators

'''

import os
import enum
import calendar
import math
import pandas as pd
import numpy as np
import sqlite3
import datetime

from datetime import date
from scipy.stats import norm

from math import log, exp, sqrt
import option

from stock import Stock

from typing import List

class SimpleMovingAverages(object):
    '''
    On given a data frame, calculate corresponding simple moving averages
    '''
    def __init__(self, ohlcv_df: pd.DataFrame, periods: List[int]):
        #
        self.ohlcv_df = ohlcv_df
        self.periods = periods
        self._sma = {}

    def _calc(self, period: int, price_source: str) -> pd.Series:
        '''
        for a given period, calc the SMA as a pandas series from the price_source
        which can be  open, high, low or Close
        '''
        result = self.ohlcv_df[price_source] \
                    .rolling(period, min_periods=1) \
                    .mean(numeric_only=True)

        return(result)
        
    def run(self, price_source = 'Close'):
        '''
        Calculate all the simple moving averages as a dict
        '''
        for period in self.periods:
            self._sma[period] = self._calc(period, price_source)
    
    def get_series(self, period):
        return(self._sma[period])

    
class ExponentialMovingAverages(object):
    '''
    On given a OHLCV data frame, calculate corresponding EMA
    '''
    def __init__(self, ohlcv_df: pd.DataFrame, periods: List[int]):
        #
        self.ohlcv_df = ohlcv_df
        self.periods = periods
        self._ema = {}

    def _calc(self, period: int, price_source: str) -> pd.Series:
        
        result = self.ohlcv_df[price_source] \
                                .ewm(span=period, 
                                    min_periods=1, 
                                    ignore_na=True)
                                
        
        return result.mean()
        
    def run(self):
        '''
        Calculate all the expo moving averages as a dict
        '''
        for period in self.periods:
            self._ema[period] = self._calc(period, price_source = 'Close')

    def get_series(self, period):
        return(self._ema[period])


class RSI(object):

    PRICE_SOURCE = 'Close'
    UNDERBOUGHT_THRESHOLD = 30
    OVERBOUGHT_THRESHOLD = 70

    def __init__(self, ohlcv_df: pd.DataFrame, period = 14):
        self.ohlcv_df = ohlcv_df
        self.period = period
        self.rsi = None

    def get_series(self):
        return(self.rsi)

    def run(self):
        '''
        '''

        diff = self.ohlcv_df[RSI.PRICE_SOURCE].diff(periods=1)
        
        gain, loss = diff.copy(), diff.copy()
        
        # remove datapoints we dont need
        gain[gain < 0] = 0 
        loss[loss > 0] = 0

        avg_gain = gain.ewm(self.period, min_periods = self.period).mean()
        avg_loss = loss.ewm(self.period, min_periods = self.period).mean()

        rs = np.abs(avg_gain / avg_loss)
        self.rsi = 100 - (100/ (1 + rs))
        self.rsi = self.rsi[~np.isnan(self.rsi)]

class VWAP(object):

    CUMSUM_COLUMN = 'Cum_Vol'
    CUMSUM_PRICE_COLUMN = 'Cum_Vol_Price'
    VWAP_COLUMN = 'VWAP'

    def __init__(self, ohlcv_df: pd.DataFrame):
        self.ohlcv_df = ohlcv_df.copy()
        self.vwap = None

    def get_series(self):
        return(self.vwap)

    def run(self):
        '''
        '''
        # use HLC as shown by Trading view
        volume = self.ohlcv_df['Volume']
        price = (self.ohlcv_df['High'] + self.ohlcv_df['Close'] + self.ohlcv_df['Low']) / 3.0
        self.vwap = (volume * price).cumsum() / volume.cumsum()

def _test1():
    opt = option.Option()
    # set default settings

    # we use relative path here, you can set it with a full path
    opt.data_dir = "./data"
    opt.output_dir = os.path.join(opt.data_dir, "daily")
    opt.sqlite_db = os.path.join(opt.data_dir, "sqlitedb/Equity.db")

    ticker = 'AAPL'
    db_connection = sqlite3.connect(opt.sqlite_db)
    stock = Stock(opt, db_connection, ticker)

    start_date = datetime.date(2020, 1, 1)
    end_date = datetime.date(2023, 10, 12)

    #start_date = datetime.date(2015, 1, 1)
    #end_date = datetime.date(2019, 10, 1)
    
    df = stock.get_daily_hist_price(start_date, end_date)
    print(df.head())
    print(df.tail())
    
    periods = [9, 20, 50, 100, 200]
    smas = SimpleMovingAverages(df, periods)
    smas.run()
    s1 = smas.get_series(9)
    print("9 SMA", s1.index)
    print("9 SMA [HEAD]", s1.head(10))
    print("9 SMA [TAIL]", s1.tail(10))
    s2 = smas.get_series(50)
    print("50 SMA [HEAD]",s2.head(10))
    print("50 SMA [TAIL]",s2.tail(10))

    emas = ExponentialMovingAverages(df, periods)
    emas.run()
    e1 = emas.get_series(9)
    print("9 EMA", e1.index)
    print("9 EMA [HEAD]", e1.head(10))
    print("9 EMA [TAIL]", e1.tail(10))
    
    rsi_indicator = RSI(df)
    rsi_indicator.run()

    print(f"RSI for {ticker} is {rsi_indicator.rsi}")

    vwap_indicator = VWAP(df)
    vwap_indicator.run()
    vwap_1 = vwap_indicator.get_series()
    print("Volume Weighed Average Price (VWAP)")
    print(f"VWAP for {ticker} is {list(vwap_1.items())[-1][1]}")
    print(vwap_indicator.vwap)
    print(df)
    
if __name__ == "__main__":
    _test1()

    
