from random import randrange
from typing import Union

# Union for numerica datatypes
Vector = Union[int, float]

def selectK(S: list[Vector], k: int) -> Vector:
    
    #error guard
    if k > len(S):
        return float("-inf")

    while k >= 1:

        n = len(S)
        rand_idx = randrange(0, n) #set [0, n)
        pivot = S[rand_idx]


        # put items in a bucket
        S_left = list(filter(lambda x: x < pivot, S))
        S_eq = list(filter(lambda x: x == pivot, S))
        S_right = list(filter(lambda x: x > pivot, S))


        LEN_SL = len(S_left)
        LEN_SEQ = len(S_eq)

        #kth smallest is inside the smallest elemets selected
        if k <= LEN_SL:
            S = S_left
        
        #element found
        elif k <= LEN_SL + LEN_SEQ:
            return pivot
        
        # update k after we realize it cannot be in left or middle (equal) partition
        else:
            S = S_right
            k -= (LEN_SL + LEN_SEQ)
            
