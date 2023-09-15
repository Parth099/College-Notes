# Set 5
## 1.3.6

> If $p > 5$ is prime and $p$ is divided by $10$, show that the remainder is $1, 3, 7,$ or $9$ .

By the division algorithm the only remainders when dividing by 10 are $0, 1, \dotso, 9$ .

However remainders of $2, 4, 6, 8, 0$ would make $p$ even and thus cannot exist. Next, a remainder of $5$ would mean that

$$
\begin{align}
p = 10q + 5 = 5(2q+1)\text{ for } q \in \mathbb{Z}
\end{align}
$$

Since $5 | p$ , $5$ cannot be a valid remainder. 

Thus only $1, 3, 7, 9$ are valid remainders. 

## 1.3.7

> If $a, b, c$ are integers and $p$ is a prime that divides both $a$ and $a + bc$, prove
> that $p| b$ or $p| c$.

Since $p|a$ and $p|a+bc$, $p|a+bc-(a)=bc$

Since $p$ is prime and divides $bc$ it must follow that $p|b$ or $p|c$ .