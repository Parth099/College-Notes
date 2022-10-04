Vector = list[float]

def sanatize_input(x: Vector, f: Vector):
    N = len(x)

    z = [x[i // 2] for i in range(2*N)]
    fz = [f[i // 2] for i in range(2*N)]

    return z, fz

def hermite_dd(x, f, df):

    #internal function
    def divided_diff(a: float, b: float, x_a: float, x_b: float):
        return (b - a) / (x_b - x_a)

    DIM = len(x)

    Q = [[0 for _ in range(DIM)] for _ in range(DIM)]

    #fix col 1
    for x_i in range(DIM):
        Q[x_i][0] = f[x_i]

    #fix col 2
    for x_i in range(1, DIM):
        Q[x_i][1] = df[x_i // 2] if x_i % 2 else divided_diff(Q[x_i][0], Q[x_i-1][0], x[x_i], x[x_i-1])


    for col in range(2, DIM):
        for row in range(col, DIM):
            Q[row][col] = divided_diff(Q[row][col - 1], Q[row - 1][col - 1], x[row], x[row - col])

    return Q

    


x = [0.1, 0.2, 0.3]
f = [-0.29004996, -0.56079734, -0.81401972]
df = [-2.8019975, -2.6159201, -2.9734038]

# double the relavent information
x, f = sanatize_input(x, f)

Q = hermite_dd(x, f, df)

#print stuff 
for row in Q:
    for element in row:
            print("{:+10.6f}".format(element), end=' ')

    print("")
