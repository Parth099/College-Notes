from math import isclose # compare floats
from math import floor 

# determine if N is a prefect square by finding sqrt(N)
def perfectSquare(N: float):

    # sqrt(N) has to be in this interval
    L, U = 1, N

    # loop ends if U - L < 1 since there will no longer exist any ints between L and U
    while U - L > 1:
        M = floor((L + U) / 2)
        SQ_Approx = M**2

        if isclose(N, SQ_Approx):
            return True

        if SQ_Approx > N:
            U = M
        else:
            L = M
        
    return False