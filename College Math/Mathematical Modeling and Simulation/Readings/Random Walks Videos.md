# Random Walks Videos [Week 3]

> A random walk in $1D$ is simply moving either left or right. For the code, the steps are either $-1$ or $1$ .

## Random Walk 2D

Two cases for random walks:
1. Integer steps: $(-1, 0, 1)^2$
2. Real steps: $[-1, 1]^2$

Both sample spaces are **Uniform**


## Random Walk Levy Fight

+ 2D random walk
+ Step size is taken from a heavy-tailed distribution and random direction $\phi$ is chosen to take that step in.
	+ Step size here is log normally distributed
	+ heavy-tailed: contains more larger numbers


A variable $X$ is ***log normally distributed*** if $Y = \ln(X)$ is normally distributed. So, $\exp(Y) = X$ . The reason for having a heavy-tailed distribution is to have a model where both large steps and small steps are possible. 

If $\vec{x}$ is the position currently the next position is defined by selecting a random number $d$ (log normally distributed) and adding it to $\vec{x}$ via:

$$
\vec{x}_{n+1} = \vec{x}_{n} + \begin{bmatrix}
d \cos \phi \\
d \sin \phi 
\end{bmatrix}
$$

> $\vec{x}_0 = [0\ 0]^T$