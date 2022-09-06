from math import sqrt


def actualError(p, _p):
    return p - _p

def absoluteError(p, _p):
    return abs(actualError(p, _p))

def relativeError(p, _p):
    return absoluteError(p, _p) / abs(p)


p = .00542
_p = .0054

print(f'p :{p}\np*:{_p}\nAerror: {absoluteError(p, _p)}\nRerror: {relativeError(p, _p)}')