# Set 7
## 2.1.6

> If $a= b \bmod n$ and $k|n$, is it true that $a= b \bmod k$? Justify your answer.

Since $a= b \mod n$ , $n|a-b$ and since $k|n$ it implies that $k|a-b$.

Therefore $a= b \mod k$ .


## 2.1.7

> If $a$ is an integer show that $a^2$ is not congruent to $2\bmod4$ or $3\bmod4$ 



### 2.1.7 - Mod Solution

Integers under $\mod 4$ will have one of four remainders: $0, 1, 2$ , or $3$ .

When squared these remainders will move to $0$ or $1$ . Therefore $a^2 \not\equiv 2 \bmod 4$ and $a^2 \not\equiv 3 \bmod 4$ .


## 2.1.8

Let $a$ be an odd integer. Under the division algorithm upon division by $4$ :

$$
\begin{align}
a = 4q+r &\text{ for } 0 \leq r \leq 4\\
&\text{ and } q, r \in\mathbb{Z}
\end{align}
$$

Now $r=1, 3$ since $r=0, 2$ means $a$ will be even. 

This implies that either $a=1\bmod4$ or $a=3\bmod4$ .