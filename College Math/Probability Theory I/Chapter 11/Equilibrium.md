# Equilibrium
Recall from the first section what a statement like the one below means
$$\vec{w}\mathbf{P} = \vec{w}$$
$w_i$ represents the probability of starting in state $i$. 

Notice that 
$$\vec{w}\mathbf{P}^n = \vec{w}$$
The probability of being in various states remains the same after $n$ iterations. This process is known as **stationary**. 

> Note: $\vec{w}$ is unique to $\mathbf{P}$

## Theorems
### Theorem 1
Let $\mathbf{P}$ be the transition matrix for an ergodic chain. Then define $\mathbf{A}_n$ as
$$
\mathbf{A}_n = \frac{\mathbf{I}+\mathbf{P}+\mathbf{P}^2+\dotso+\mathbf{P}^n}{n+1}
$$

Then $\mathbf{A}_n \to \mathbf{W}$

**Interpretation**:
Suppose the ergodic chain starts in state $s_i$.
Then let $X^{(m)} = 1$ if the $m$th step is to state $s_j$ and 0 other wise. 