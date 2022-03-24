# General Case for CTL
 Let $S_n = \sum_{i = 0}^nX_i$ be the sum of $n$ independent discrete random variables with common distribution $m(x)$. If each $X_i$ has mean $\mu$ and variance $\sigma^2$ we have seen by simulations that $S_n$ has a *normal* curve. 
 
 The same theorems from [[Central Limit Theorem for Bernoulli Trials]] apply. 
 
 ## Examples
 > A die is rolled $420$ times. What is the probability the sum of the rolls lies between $1400$ and $1550$?

Notice that $$S_{420} = \sum_{i = 1}^{420} X_i$$

For each $X_i$ notice that $\mu = \frac{7}{2}$ and $\sigma^2 = \frac{35}{12}$

$$
\implies 
\begin{cases}
	E(S_{420}) = 1470\\
	V(S_{420}) = 1225\\
	D(S_{420}) = 35  \\
\end{cases}
$$

$$
\begin{align}
	P(1400 \leq S_{420} \leq 1550) &\approx
	P(-2.01 \leq S^*_{420} \leq 2.30)
	\\
	&\approx .967
\end{align}
$$