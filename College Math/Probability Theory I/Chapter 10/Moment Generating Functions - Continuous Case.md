# Moment Generating Functions - Continuous Case
> Suppose that $X$ is a random variable defined on some space $\Omega$ with density $f_X$.
## Moments
The moments of $X$ are
$$\mu_k = \int_{-\infty}^{+\infty} x^n f_X(x) \mathop{dx}$$

Provided the same integral with $|x|^n$ converges.
## Moment Generating Functions

We learned to define Generating Functions from the previous section. We said that
$$
g(t) = \sum_{k = 0}^{\infty} \frac{\mathbb{E}(X^k) t^k}{k!}\\
$$

But notice the definition for $\mu_k =\mathbb{E}(X^k)$ is different.
Thus,
$$
g(t) = \int_{-\infty}^{+\infty} e^{tx} f_X(x) \mathop{dx}
$$

This is the same as $\mathbb{E}(e^{tX})$ for **continuous** variables. 

If the above integral converges, 
$$\mu_k = g^{(k)}(0)$$ 

## Theorem for Convergence
> Suppose $X$ is a random variable with range contained $[-M, M]$. Then the series, 
> $$g(t) = \sum_{k = 0}^{\infty} \mu_k \frac{t^k}{k!}$$
> converges for all $t$ and is infinitely differentiable.