# SelectK

> **Goal**: Find the $k\text{-th}$ smallest element in an array. 

The algorithm and relevant tests are defined in 
```shell
../snippets/selectk.py
../snippets/selectk_test.py
```

## Runtime 
Amortized $O(n)$ average runtime via Master Theorem (see [[01 - Master Theorem]]). 

Worst case $O(n^2)$ occurs $1/n!$ of the time[^1].

# Prefect Square

> **Goal**: Find if a number $N$ is a prefect square or not. 

Since $N\geq4\implies 1\lt\sqrt{N}\lt N$

We can employ a binary search to find a $\sqrt{N}\in\mathbb{Z}$ such that $(\sqrt{N})^2 = N$ .

The algorithm and relevant tests are defined in 
```shell
../snippets/prefectSquare.py
../snippets/prefectSquare_test.py
```

> This same idea can be employed to find a fixed point in an array. This is when $\text{A}[i]=i$

[^1]: Each time selectk would have to pick the largest element: $\frac{1}{n}\times\frac{1}{(n-1)}\cdots\times\frac{1}{2}=1/n!$