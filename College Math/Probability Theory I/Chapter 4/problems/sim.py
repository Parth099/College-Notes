from ctypes.wintypes import tagRECT


def p6():
    target = 12
    cards = [2, 4, 6, 8, 10] 
    lst = []
    for i in cards:
        for j in cards:
            for k in cards:
                tup = (i, j, k)
                if sum(tup) == target:
                    lst.append(tup)

    return lst

def matchTuple(t1, t2): #poor
    match = all([t in t2 for t in t1])
    return len(t1) == len(t2) and match


def PPV(sensitivity, specificity, prior):
    return sensitivity * prior / (sensitivity * prior + (1 - specificity) * (1 - prior))
# EB test PPV
print(PPV(0.36, 0.99, 0.06))
# need 0.69677419354

