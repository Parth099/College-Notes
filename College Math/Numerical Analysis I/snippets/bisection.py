TOL = 1e-5
MAX_ITER_DEPTH = 500

#performs the bisection algo
def _bisection(F, left, right, depth):

    p_0 = (left + right) / 2 
    FP = F(p_0)

    print(f'ITERATION: {depth}  a={left} | b={right} | p_{depth} = {p_0} | F(p_{depth}) = {FP}')

    
    if depth >= MAX_ITER_DEPTH or abs(FP - p_0) <= TOL or (right - left) / 2 <= TOL:
        return p_0


    F_left = F(left)

    if F_left * FP > 0: #both same sign
        return _bisection(F, p_0, right, depth + 1)

    #if both are not the same sign the root has to between them
    return _bisection(F, left, p_0, depth + 1)
    

def bisection(F, left, right):
    return _bisection(F, left, right, 0)

#3\left(x+1\right)\left(x-1\right)\left(x-\frac{1}{2}\right)\left\{-1.25\le x\le2.5\right\}
def poly2b(x):
    a = x + 1
    b = x - (1.0/2.0)
    c = x - 1

    return 3 * a * b * c

bounds = [-1.25, 2.5]

