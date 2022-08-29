# Bounding Functions
## Big O: $O(g(n))$
$f(n) \in O(g(n))$ if $\exists c, k\in\mathbb{R}$ s.t $\forall n \gt k, f(n) \leq c\cdot g(n)$

If that statement above holds up $f(n)$ is said to be $O(g(n))$.

### Little O: $o(n)$
> Little o notation is used to describe an upper bound that cannot be tight. In other words, loose upper bound of f(n). - [tutorialspoint](https://www.tutorialspoint.com/little-oh-notation-o)

We say that a function $f$ is little oh of $g$ (notation: $o(g(n))$) if:
$$
\lim_{n\to\infty} \frac{f(n)}{g(n)} = 0
$$

Example: $n^2 \in o(n^3)$

## Big Omega: $\Omega(g(n))$
$f(n) \in O(g(n))$ if $\exists c, k\in\mathbb{R}$ s.t $\forall n \gt k, f(n) \geq c\cdot g(n)$

If $O(g(n))$ is the upperbound for $f$ then $\Omega(g(n))$ is the lower bound. 

## Big Theta: $\Theta(g(n))$
$f(n) \in \Theta(g(n))$ if $f(n) \in O(g(n))$  **and** $f(n) \in \Omega(g(n))$ 

$f$ is said to be "big theta" of $g$ if $\exists c_0, c_1 \in\mathbb{R}$ s.t 
$$
0 \leq c_0g(n) \leq f(n) \leq c_1g(n)
$$

# Lecture
`todo`
