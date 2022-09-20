| Date     |
| -------- |
| 09-16-22 | 

# Units and Modular Arithmetic
We say $a$ is a unit in $\mathbb{Z}_n$ if $\exists b\in\mathbb{Z}_n$ s.t $$ab\equiv 1\mod{n}$$
$b$ here is the inverse of $a$. 

Otherwise $b$ is a zero divisor. This is when a $\exists b\in\mathbb{Z}_n$ where $b\neq0$ s.t $ab\equiv 0\mod{n}$

## Uniqueness Theorem
If $a$ is a unit in $\mathbb{Z}_n$ then $\exists!b\in\mathbb{Z}_n$ s.t $ab\equiv 1\mod{n}$ ($b = a^{-1}$)

This is simply not true for **zero divisors**.


## Example with $n=15$
| $n=15$  | 0   | 1           | 2           | 3   | 4           | 5   | 6   | 7           | 8           | 9   | 10  | 11          | 12  | 13          | 14          |
| ------- | --- | ----------- | ----------- | --- | ----------- | --- | --- | ----------- | ----------- | --- | --- | ----------- | --- | ----------- | ----------- |
| $\gcd$  | $-$ | $\boxed{1}$ | $\boxed{1}$ | 3   | $\boxed{1}$ | 5   | 3   | $\boxed{1}$ | $\boxed{1}$ | 3   | 5   | $\boxed{1}$ | 3   | $\boxed{1}$ | $\boxed{1}$ |
| inverse | $-$ | 1           | 8           | $-$ | 4           | $-$ | $-$ | 13          | 2           | $-$ | $-$ | 11          | $-$ | 7           | 14          | 

I have boxed the units per the definition.

See that I can find the inverse via the **extended euclidean algorithm**([[Matrix-based GCD]]). We have $a$ and $n$ and require that $ax+ny = 1$.

## Unit "Fun"
Lets multiply each unit by $7$ and then take their $\mod{15}$.

The set of units is:

| Unit $U$ | $(U * 7) \mod 15$ |
| -------- | ----------------- |
| 1        | 7                 |
| 2        | 14                |
| 4        | 13                |
| 8        | 11                |
| 11       | 2                 |
| 13       | 1                 |
| 14       | 8                 | 

Let $U_{15}$ represent the set of units in $\mathbb{Z}_{15}$. We notice that 
$$
7 \times U_{15} = U_{15} \text{ and } 7\in U_{15}
$$

### Why this works
$$
\begin{align}
(7 \times 1) (7 \times 2) (7 \times 4) (7 \times 7) (7 \times 8) (7 \times 11) (7 \times 13) (7 \times 14) &\equiv_{15} 
\end{align} 1 \times 2 \times 4 \times 7 \times 8 \times 11 \times 13 \times 14 
$$

We got to the equality by seeing that all the mults on the LHS get reduced to the ones on the right under $\equiv_{15}$. 

Also we can see that the RHS is $\equiv_{15}  1$ since we can pair up the numbers to get $1\times1\times1\times1$. **Therefore**, $7^8\equiv_{15}1$ . This is derived from the fact that the LHS can factor out eight $7$s. 

## Notation and Theorem
We will denote the number of units in $\mathbb{Z}_N$ as $\phi(N)$. We just say that $$\phi(15) = 8$$

For any prime $p$ notice that $\phi(p) = p-1$

**THEOREM**:
if $a\in U_N$ where $U_N$ is the set of all units for integers modulo $N$, then 
$$
a^{\phi(N)} \equiv_{n} 1
$$