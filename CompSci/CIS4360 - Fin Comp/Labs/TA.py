'''
@project       : Temple University CIS 4360 Computational Methods in Finance
@Instructor    : Dr. Alex Pang

@Student Name  : first last

@Date          : 9/1/2023

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


class SimpleMovingAverages(object):
    '''
    On given a OHLCV data frame, calculate corresponding simple moving averages
    '''
    def __init__(self, ohlcv_df, periods):
        #
        self.ohlcv_df = ohlcv_df
        self.periods = periods
        self._sma = {}

    def _calc(self, period, price_source):
        '''
        for a given period, calc the SMA as a pandas series from the price_source
        which can be  open, high, low or Close
        '''
        result = None
        #TODO: implement details here
        # hint: use rolling method
        #
        #end TODO
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
    On given a OHLCV data frame, calculate corresponding simple moving averages
    '''
    def __init__(self, ohlcv_df, periods):
        #
        self.ohlcv_df = ohlcv_df
        self.periods = periods
        self._ema = {}

    def _calc(self, period):
        '''
        for a given period, calc the SMA as a pandas series
        '''
        result = None
        #TODO: implement details here
        # 
        #end TODO
        return(result)
        
    def run(self):
        '''
        Calculate all the simple moving averages as a dict
        '''
        for period in self.periods:
            self._ema[period] = self._calc(period)

    def get_series(self, period):
        return(self._ema[period])


class RSI(object):

    def __init__(self, ohlcv_df, period = 14):
        self.ohlcv_df = ohlcv_df
        self.period = period
        self.rsi = None

    def get_series(self):
        return(self.rsi)

    def run(self):
        '''
        '''
        #TODO: implement details here
        # you can use pandas series.diff(1) 
        # then call the ewm of the average gain and loss
        #
        #rs = abs(gain/ loss)
        #self.rsi = 100 - (100/(1+rs))
        #end TODO


class VWAP(object):

    def __init__(self, ohlcv_df):
        self.ohlcv_df = ohlcv_df
        self.vwap = None

    def get_series(self):
        return(self.vwap)

    def run(self):
        '''
        '''
        #TODO: implement details here
        #

        #end TODO

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
    end_date = datetime.date(2023, 10, 1)

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
    print("9 SMA", s1.head(10))
    print("9 SMA", s1.tail(10))

    s2 = smas.get_series(50)
    print("50 SMA",s2.tail(10))
    
    rsi_indicator = RSI(df)
    rsi_indicator.run()

    print(f"RSI for {ticker} is {rsi_indicator.rsi}")

    vwap_indicator = VWAP(df)
    vwap_indicator.run()
    vwap_1 = vwap_indicator.get_series()
    print("Volume Weighed Average Price (VWAP)")
    print(f"VWAP for {ticker} is {list(vwap_1.items())[-1][1]}")
    print(vwap_indicator.vwap)
    
if __name__ == "__main__":
    _test1()

    
