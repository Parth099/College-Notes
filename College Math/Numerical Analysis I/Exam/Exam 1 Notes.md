# Bisection
***REQ***
+ $f\in C^0[a, b]$
+ signs of $f(a)$ and $f(b)$ are different


***ERROR***
+ $|p-p_n| \lt \frac{b-a}{2^n}$

# Fixed Point
1. $g\in C[a, b]$ and $g:[a, b]\to[a, b]$ implies $\exists p\in[a, b]$ s.t $g(p) = p$
2. $g'$ exists in $(a, b)$ and $\exists k \in (0, 1)$ s.t $\forall x\in(a, b),\ |g'(x)|\leq k$ implies $\exists! p\in[a, b]$ s.t $g(p) = p$ 

> $(1)$ is exists, $(1)+(2)$ is uniqueness

Formula: $g(p) = g(p_1)$

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

## Newtons
Quad convergence: $p$ is a simple zero (hint: $f'(p)\neq0$) and initial guess is close to $p$.