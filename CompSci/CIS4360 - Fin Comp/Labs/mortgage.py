'''
@project       : Temple University CIS 4360 Computational Methods in Finance
@Instructor    : Dr. Alex Pang

@Student Name  : Parth Patel

@Date          : Fall 2023, Sept 25

Basic Mortgage Calculation

'''

from typing import Union, Dict, List, Literal
from bisection_method import bisection

import locale

TestCaseDictEntries = Union[Literal["loan_amount"], Literal["int_rate"], Literal["term"]]
TestCase = Dict[TestCaseDictEntries, float | int]

def calc_next_month_balance(prev_balance: float, level_payment: float, int_rate: float) -> float:
    """Get Next Month's Balance

    Math: B_next = `prev_balance`(1+`int_rate`) - `level_payment`

    Args:
        prev_balance (float): balance from last month
        level_payment (float): (Approx, Pred) Payment to get to balance = 0 at the end of month
        int_rate (float): **YEARLY** int rate of the debt

    Returns: 
        float: balalce from last month
    """
    monthly_int_rate = int_rate / 12.0
    return prev_balance * (1 + monthly_int_rate) - level_payment

def last_month_balance(loan_amount: float, int_rate: float, mortgage_term: int, level_payment: float) -> float:
    """Use the `level_payment` to get the balance after `mortgage_term` terms.

    Args:
        loan_amount (float): debt taken
        int_rate (float): **YEARLY** int rate of the debt
        mortgage_term (int): In years, length of loan
        level_payment (float): (Approx, Pred) Payment to get to balance = 0 at the end of month

    Returns:
        float: final balance (+ or -) after `mortgage_term` terms 
    """

    # calculate the last month remaining balance
    # mortgage_term is the number of years for the mortgage
    # int_rate is the annual interest rate in fraction

    prev_bal = loan_amount

    for term_no in range(mortgage_term * 12):
        prev_bal = calc_next_month_balance(prev_bal, level_payment, int_rate)
        
    return(prev_bal)


def calc_level_payment(loan_amount, int_rate, mortgage_term) -> float:
    """Approx the `level_payment` via Bisection  method

    Args:
        loan_amount (float): debt taken
        int_rate (float): **YEARLY** int rate of the debt
        mortgage_term (int): In years, length of loan

    Returns:
        float: level_payment
    """
    a = loan_amount * (1+int_rate * mortgage_term)/(12*mortgage_term)
    b = a/2

    x_left, x_right = min(a, b), max(a, b)    

    bisection_f = lambda level_payment_guess: last_month_balance(loan_amount, int_rate, mortgage_term, level_payment_guess)
    level_payment_approx, num_iter = bisection(bisection_f, x_left, x_right, 1e-6, return_x_list=False)

    return level_payment_approx
    
def test1():
    loan_amount = 240000
    int_rate = 0.05
    term = 30
    level_payment = loan_amount * (1+int_rate * term)/(12*term) / 2
    print(level_payment)
    print(last_month_balance(loan_amount, int_rate, term, level_payment))

def test2():
    # level_payment = loan_amount * (1+int_rate * term)/(12*term) / 2
    # print(level_payment)
    # print(last_month_balance(loan_amount, int_rate, term, level_payment))

    test_cases: List[TestCase] = [
        {
            "loan_amount": 240_000,
            "int_rate": 0.05,
            "term":  30,
        },
        {
            "loan_amount": 1_000_000,
            "int_rate": 0.125,
            "term":  15,
        },
        {
            "loan_amount": 5_400,
            "int_rate": 0.20,
            "term":  6,
        },
    ]

    for (i, case) in enumerate(test_cases, start=1):
        loan_amount, int_rate, term = case["loan_amount"], case["int_rate"], case["term"]
        level_payment = calc_level_payment(loan_amount, int_rate, term)
        print(f"Case {i}:")
        print(f"\tloan_amount={locale.currency(loan_amount, grouping=True)}")
        print(f"\tint_rate={int_rate}")
        print(f"\tterm={term}")
        print(f"\tLevel Payment={locale.currency(level_payment, grouping=True)} (monthly)\n")
          
def run():
    #
    loan_amount = 240000
    int_rate = 0.05
    mortgage_term = 30

    print(calc_level_payment(loan_amount, int_rate, mortgage_term))

if __name__ == "__main__":
    locale.setlocale( locale.LC_ALL, '' )
    test1()
    test2()
    run()
