| Date     |
| -------- |
| 09-09-22 |

# Matrix-based GCD

I am going to to immediately move to an example because its an easy algorithm

The goal here is to find $s, t$ s.t $as+bt = \gcd(a, b)$

Recall the division algorithm:
$$
a=bq+r \text{ for } 0\leq r \lt b
$$

Notice that $q = \lfloor\frac{a}{b}\rfloor$

## Example
Initial Variables: $a = 81, b = 11$

Initially $Q = \begin{pmatrix} 0 & 1 \\ 1 & -q \end{pmatrix}$ 

| $a$ | $b$ | $q$ | $r$         | $Q$                                                                                                                                                |
| --- | --- | --- | ----------- | -------------------------------------------------------------------------------------------------------------------------------------------------- |
| 81  | 11  | 7   | 4           | $\begin{pmatrix} 0 & 1 \\ 1 & -7 \end{pmatrix}$                                                                                                    |
| 11  | 4   | 2   | 3           | $\begin{pmatrix} 0 & 1 \\ 1 & -2 \end{pmatrix}\begin{pmatrix} 0 & 1 \\ 1 & -7 \end{pmatrix} = \begin{pmatrix} 1 & -7 \\ -2 & 15\end{pmatrix}$      |
| 4   | 3   | 1   | $\boxed{1}$ | $\begin{pmatrix} 0 & 1 \\ 1 & -1 \end{pmatrix}\begin{pmatrix} 1 & -7 \\ -2 & 15\end{pmatrix} = \begin{pmatrix} -2 & 15 \\ 3 & -22 \end{pmatrix}$   |
| 1   | 1   | 1   | 0           | $\begin{pmatrix} 0 & 1 \\ 1 & -1 \end{pmatrix}\begin{pmatrix} -2 & 15 \\ 3 & -22 \end{pmatrix} = \begin{pmatrix} 3 & -22\\ -5 & 37 \end{pmatrix}$ | 

## How this works

$Q$ is used as a transition matrix.

See that:
$$
\begin{pmatrix} 0 & 1 \\ 1 & -q \end{pmatrix}\begin{pmatrix} a \\ b \end{pmatrix} = \begin{pmatrix} b \\ a-bq \end{pmatrix} = \begin{pmatrix} b \\ r \end{pmatrix}
$$

This relation can be used to check the work at each step. 