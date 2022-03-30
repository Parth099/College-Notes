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

## 2
> Show that $\exists X, Y\in\mathbb{Z}$ s.t $X(2^a)+Y(2^b - 1) = 1$ for $b\geq a$

Let $d = \text{gcd}(2^a, 2^b - 1)$
This implies that $d|2^a$ and $d|2^b-1$
Then by extension $d|n(2^a)+m(2^b-1)$ for integers $n,m$

Suppose $n = 2^{b-a}$
Since $b\geq a$, $b - a\geq 0$ and thus $n\in\mathbb{Z}$

Then suppose $m = -1$
This means that $d|2^{b - a}(2^a)+(2^b-1) = 1$
This means that the greatest common divisor of the two integers is $1$.

Given that it is $1$, they are **relatively** prime.
Then, $\exists X, Y\in\mathbb{Z}$ s.t $X(2^a)+Y(2^b - 1) = 1$ for $b\geq a$ because $2^a, 2^b - 1$ are **relatively** prime.

