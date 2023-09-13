'''
@project       : Temple University
@Instructor    : Dr. Alex Pang
@Date          : Sept 2023

@Student Name  : first last

https://github.com/JECSand/yahoofinancials

'''

from yahoofinancials import YahooFinancials 

class MyYahooFinancials(YahooFinancials):
    '''
    Extended class based on YahooFinancial libary

    '''
    def __init__(self, symbol, freq = 'annual'):
        YahooFinancials.__init__(self, symbol)
        self.freq = freq

    def get_operating_cashflow(self):
        return self._financial_statement_data('cash', 'cashflowStatementHistory', 'totalCashFromOperatingActivities', self.freq)

    def get_capital_expenditures(self):
        return self._financial_statement_data('cash', 'cashflowStatementHistory', 'capitalExpenditures', self.freq)

    def get_long_term_debt(self):
        return self._financial_statement_data('balance', 'balanceSheetHistory', 'longTermDebt', self.freq)

    def get_account_payable(self):
        return self._financial_statement_data('balance', 'balanceSheetHistory', 'accountsPayable', self.freq)

    def get_total_current_liabilities(self):
        return self._financial_statement_data('balance', 'balanceSheetHistory', 'totalCurrentLiabilities', self.freq)

    def get_other_current_liabilities(self):
        return self._financial_statement_data('balance', 'balanceSheetHistory', 'otherCurrentLiab', self.freq)

    def get_cash(self):
        return self._financial_statement_data('balance', 'balanceSheetHistory', 'cash', self.freq)

    def get_short_term_investments(self):
        return self._financial_statement_data('balance', 'balanceSheetHistory', 'shortTermInvestments', self.freq)

def _test():
    symbol = 'AAPL'
    
    yfinance = MyYahooFinancials(symbol)

    
    print("Getting Financial Data for {}".format(symbol))
    print("Long Term Debt: ", yfinance.get_long_term_debt())


if __name__ == "__main__":
    _test()
