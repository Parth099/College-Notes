def isNilpotent(n: int, Z: int):
    
    k = 1
    remainder = n % Z

    prev_remainders = set([remainder])
    
    print(f"[{n}]^{k}&=", end="")

    while remainder > 0:

        last_remainder = remainder

        print(f"[{last_remainder}], ", end="")

        remainder *= n
        k+=1

        print(f"[{n}]^{k}=[{remainder}]=", end="")

        remainder %= Z

        if remainder in prev_remainders: 
            return False, k

        prev_remainders.add(remainder) 

    return True, k

Z = 8

for n in range(0, Z):
    (status, k) = isNilpotent(n, Z)

    if status: 
        print(f"[0]\\\\")
    else: 
        print(f"\\neq[0]\\\\")

