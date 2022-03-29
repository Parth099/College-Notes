# Problem Set 9
## P1
> Let $a$ be an integer. Prove that $2a + 1$ and $4a^2 + 1$ are relatively prime.

Suppose $2a+1, 4a^2 + 1 \in\mathbb{Z}$

Let $d = \text{gcd}(2a+1, 4a^2+1)$

Then $d|(2a+1)$ and $d|(4a^2+1)$
Thus $d|n(4a^2+1)-m(2a+1)$ for any $n,m\in\mathbb{Z}$

Since $2a+1\in\mathbb{Z}$, $2a-1\in\mathbb{Z}$
Let $m = 2a-1$ and $n=1$

Then, $d|(4a^2+1)-(2a-1)(2a+1)$  and $d|2$

Since $d\gt0$, this means $d|1$ **or** $d|2$

Observe that $2\nmid2a+1$ and since $d|2a+1$, $d \neq 2$

Thus $d = 1$. Since $\text{gcd}(2a+1, 4a^2+1)=1$, the two integers are **relatively prime**.
