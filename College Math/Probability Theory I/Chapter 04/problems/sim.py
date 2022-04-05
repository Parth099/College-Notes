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
#print(PPV(0.36, 0.99, 0.06))
# need 0.69677419354

_r = [[(x,y) for x in range(1, 7)]for y in range(1, 7)]
r = [item for sublist in _r for item in sublist]
cnt = 0
for element in r:
    x, y = element
    if x > 3 and x + y > 7:
        cnt += 1
        print(x, y)
         

print(cnt)

