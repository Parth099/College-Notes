'''
@project       : Temple University CIS 4360 Computational Methods in Finance
@Instructor    : Dr. Alex Pang

@Student Name  : Parth Patel

@Date          : Fall 2023, Sept 25

A Simple Mortgage Calculator
'''

import math, locale
from bisection_method import bisection

class MortgageCalculator(object):

    MORTGAGECALCULATOR_ERROR_THRESHOLD = 1e-6
    MORTGAGECALCULATOR_NUM_PERIODS = 12.0

    def __init__(self, loan_amount, int_rate, term):
        self.loan_amount = loan_amount
        self.int_rate = int_rate
        self.term = term

    # Get the next month's bal based on a suggested level_payment
    def _calc_next_month_balance(self, prev_balance, level_payment):
        period_int_rate = self.int_rate / MortgageCalculator.MORTGAGECALCULATOR_NUM_PERIODS
        return prev_balance * (1 + period_int_rate) - level_payment
    
    # Get the final month's bal based on a suggested level_payment and term length
    def _last_month_balance(self, level_payment):
        prev_bal = self.loan_amount
        no_periods = int(self.term * MortgageCalculator.MORTGAGECALCULATOR_NUM_PERIODS)
        for _ in range(no_periods):
            prev_bal = self._calc_next_month_balance(prev_bal, level_payment)
            
        return prev_bal
    
    # Get the level payment numerically based via the bisection method
    def calc_level_payment(self):
        a = self.loan_amount * (1 + self.int_rate * self.term) / (MortgageCalculator.MORTGAGECALCULATOR_NUM_PERIODS * self.term)
        b = a/2

        x_left, x_right = min(a, b), max(a, b)    

        bisection_f = lambda level_payment_guess: self._last_month_balance(level_payment_guess)
        level_payment_approx, num_iter = bisection(bisection_f, \
                                                    x_left, \
                                                    x_right, \
                                                    MortgageCalculator.MORTGAGECALCULATOR_ERROR_THRESHOLD, \
                                                    return_x_list=False \
                                                )

        return level_payment_approx

    def compute_level_payment_analytically(self):
        period_int_rate = self.int_rate / MortgageCalculator.MORTGAGECALCULATOR_NUM_PERIODS
        rate_pow = math.pow(1 + period_int_rate, self.term * MortgageCalculator.MORTGAGECALCULATOR_NUM_PERIODS)
        
        return (self.loan_amount * rate_pow * period_int_rate) / (rate_pow - 1) 

    
def _test():
    #
    loan_amount = 240000
    int_rate = 0.05
    mortgage_term = 30

    mtgCalc = MortgageCalculator(loan_amount, int_rate, mortgage_term)
    print(mtgCalc.calc_level_payment())
    print(mtgCalc.compute_level_payment_analytically())

def _test2():

    test_cases = [
        MortgageCalculator(240_000, 0.05, 30),
        MortgageCalculator(1_000_000, 0.125, 15),
        MortgageCalculator(5_400, .20, 6)
    ]

    for (i, mortgageCalculator) in enumerate(test_cases, start=1):
        level_payment = mortgageCalculator.calc_level_payment()
        analytical_level_payment = mortgageCalculator.compute_level_payment_analytically()
        print(f"Case {i}: (periods per year={MortgageCalculator.MORTGAGECALCULATOR_NUM_PERIODS})")
        print(f"\tloan_amount={locale.currency(mortgageCalculator.loan_amount, grouping=True)}")
        print(f"\tint_rate={mortgageCalculator.int_rate}")
        print(f"\tterm={mortgageCalculator.term}")
        print(f"\tNumerical  Level Payment={locale.currency(level_payment, grouping=True)}")
        print(f"\tAnalytical Level Payment={locale.currency(analytical_level_payment, grouping=True)}\n")

if __name__ == "__main__":
    locale.setlocale( locale.LC_ALL, '' )
    _test()
    _test2()
