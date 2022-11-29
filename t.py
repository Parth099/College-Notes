from math import prod

s = list(map(lambda x: x * 7, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
s = list(map(lambda x: x % 11, s))
print(s, prod(s) % 11)