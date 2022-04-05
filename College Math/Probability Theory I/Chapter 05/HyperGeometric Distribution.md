# HyperGeometric Distribution
## Motivation
Suppose we have a set of $N$ balls. $k$ are red and the rest blue. We then choose $n$ of these red/blue balls without replacement and define $X$ to be the red balls in our set of $n$ balls we chose ourselves.

$$
\text{Then } X \sim \text{ Hypergeometric}
$$

We can infer that $X$ will depend on the values of $N, k , n$. Thus we will define the Hypergeometric Distribution using the following params:
$$h(N, k, n, x)$$
where $x$ serves for $P(X = x)$. 

Lets define $h(N, k, n, x)$

Note that there is $\binom{N}{n}$ ways to choose $n$ balls from a set of $N$ **total** balls.

Then there are $\binom{k}{x}$ ways to pick $x$ red balls from a total of $k$ balls and $\binom{N-k}{k-x}$ ways of picking the rest of the blue colored balls.


Hence, 
$$
h(N, k, n, x) = \frac{\binom{k}{x}\binom{N-k}{k-x}}{\binom{N}{n}}
$$

Lets analyze the top of the fraction: $\binom{k}{x}\binom{N-k}{k-x}$

Recall that $P(X=x)$ is the probability of picking $x$ red balls.

We can imagine the situation like so:
We need a line of $n$ balls total. This is a given. We want $x$ of them to be red so we find all the ways that we can pick red balls: $\binom{k}{x}$. We do the same for the blue. We multiply because each way of picking reds can be matched with all the ways we can pick blues. 

Notice how getting a red ball alters the probability of getting another one. If we **were replacing the balls** this would simple be a Binomial distribution.

## General Case
Generally if we want to plot this here is the meaning of each variable.
$$h(N, k, n)$$
1. $N$ - Total population Size
2. $k$ - Total population size that fits criterion
3. $n$ - sample size of $k$

PMF: 
$$
P(X = x) = h(N, k, n, x) = \frac{\binom{k}{x}\binom{N-k}{k-x}}{\binom{N}{n}}
$$

$$
\begin{align}
	E(X) = n\frac{k}{N}
\end{align}
$$