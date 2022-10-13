## Bisection
***REQ***
+ $f\in C^0[a, b]$
+ signs of $f(a)$ and $f(b)$ are different


***ERROR***
+ $|p-p_n| \lt \frac{b-a}{2^n}$

## Fixed Point
1. $g\in C[a, b]$ and $g:[a, b]\to[a, b]$ implies $\exists p\in[a, b]$ s.t $g(p) = p$
2. $g'$ exists in $(a, b)$ and $\exists k \in (0, 1)$ s.t $\forall x\in(a, b),\ |g'(x)|\leq k$ implies $\exists! p\in[a, b]$ s.t $g(p) = p$ 

> $(1)$ is exists, $(1)+(2)$ is uniqueness

Formula: $g(p_n) = g(p_{n-1})$

## Convergence for Fixed Point
1. Linear: $(1)+(2)$ and $g(p)\neq0$ then any starting point converges linearly.
2. Quadratic: $g'(p)=0$, $g''(x)$ is cts and bounded above by some $M$. Then starting values from some interval trigger quadratic or better convergence. 

## Errors
If $g$ satisfies $(1)+(2)$ the error bound is:
$$
|p_n - p| \leq k^n \max\{p_0-a, b-p_0\}
$$
and 
$$
|p_n - p| \leq \frac{k^n}{1-k}|p_1 - p_0|
$$

## Newtons (root finding)

$$
p_n = p_{n-1}  - \frac{f(p_{n-1})}{f'(p_{n-1})}
$$

Quad convergence: $p$ is a simple zero (hint: $f'(p)\neq0$) and initial guess is close to $p$.

### Secant Method

$$
p_n = p_{n-1} - \frac{f(p_{n-1})[{p_{n-1} - p_{n-2}}]}{f(p_{n-1}) - f(p_{n-2})}
$$

## Hermite Interpolation

$$
\begin{align}
H_{2n+1}(x) &= \sum_{j=0}^{n} f(x_j) H_{n, j}(x) + f'(x_j)\hat{H}_{n, j}(x) 
\\
H_{n, j}(x) &= \biggr[ 1 - 2(x-x_j)L'_{n,j}(x) \biggr]L^2_{n, j}(x)
\\
\hat{H}_{n, j}(x) &= (x - x_j)L^2_{n, j}(x)
\\
\text{where } L_{n, j}(x_k) &= \prod_{i=0, i\neq j}^{n} \frac{(x-x_i)}{(x_j - x_i)} = 
\begin{cases}
1 &\text{if}& j = k \\
0 &\text{if}& j \neq k \\
\end{cases}
\end{align}
$$

Divided Differences:
$$
H_{2n+1}(x) = f[z_0] + \sum_{k=1}^{2n+1}f[z_0, \dotso, z_{k}]\prod_{i = 0}^{k-1}(x-z_i)
$$

Error:
$$
f(x) = H_{2n+1}(x) + \frac{(x-x_0)^2\times\dotso\times(x-x_n)^2}{(2n+2)!}f^{(2n+2)}(\xi(x))
$$

## Lagrange Error

$$
f(x) = P(x) + \underbrace{\frac{f^{n+1}(\xi(x))}{(n+1)!}(x-x_0)\dotso(x-x_n)}_{h(x)}
$$

## Taylor Series

$$
\begin{align}
\sin{x} &= x-\frac{x^3}{3!}+\frac{x^5}{5!}-\dotso = \sum_{k=0}^\infty \frac{(-1)^nx^{2n+1}}{(2n+1)!} \\
\\
\cos{x} &= 1-\frac{x^2}{2!}+\frac{x^4}{4!}-\dotso = \sum_{k=0}^\infty \frac{(-1)^nx^{2n}}{(2n)!} \\
\end{align}
$$