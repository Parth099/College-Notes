# The GCD
## Theorem
> Suppose the $\text{gcd}$ of two non-zero integers $a, b$ is $d$. Then:
> 1. $d|a$  and $d|b$
> 2. $\forall e\in\mathbb{Z}$ s.t $e|a$ and $e|b$, $e\leq d$


We can observe that for any valid $a, b$, 
$$d = \text{gcd}(a, b) \geq 1$$
This is because if $m$ is a divisor of $k$ then so is $-m$. Thus we only consider positive divisors. 

## GCD Examples
### EX - 1
> Find $\text{gcd}(1000, 1001)$

Suppose there exists $d$ such that $d = \text{gcd}(1000, 1001)$.

Then $d|1000$ and $d|1001$
By a previous theorem, $d|(1000p+1001q)$ for $p,q\in\mathbb{Z}$

Suppose $p = -1, q = 1$
Then $1000(-1)+1001(1) = 1$
This $d|1$

Thus, $d = \{-1, 1\}$
Since $d\gt 0$, $\boxed{d = 1}$

$$\text{gcd}(1000, 1001) = 1$$

### EX 2
> Show $$\forall a\in\mathbb{Z},\text{gcd}(a, a+2)=\begin{cases}1 &\text{if}& 2\nmid a \\2 &\text{if}&2\:|\:a\end{cases}$$

Let $d = \text{gcd}(a, a+2)$. Then $d|[(a+2) - a]$ and thus $d|2$.

Since $d\gt0$, $d\in\{1, 2\}$

Suppose $2\nmid a$. Then $d\neq 2$. Hence $d = 1$
Suppose $2|a$, then $2|a+2$ and $d =2$ since $2>1$

### EX 3
> Show $\forall n\in\mathbb{Z}, \text{gcd}(3n+2, 7n+5) = 1$

Let $d = \text{gcd}(3n+2, 7n+5)$. 
Then $d|(3n+2)$ and $d|(7n+5)$

> Recall an earlier theorem about division. 
> $$\text{if } d|a \text{ and } d|b \text{ then } d|(ax+by)$$ 

Since $d|(3n+2)$ and $d|(7n+5)$, then 
$$d|[3(7n+5) - 7(3n+2)] = 1$$

Thus $d|1$.
Since $d>1$, $d = 1$ for any integer $n$