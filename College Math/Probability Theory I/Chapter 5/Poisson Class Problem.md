

# Lecture 2/16/22 
## Why The Poisson Distribution is a Distribution
> **Definition**:
> If $$P(X = k) = \frac{e^{-\lambda}\lambda^k}{k!}$$
> for all $k$, then $$X \sim \text{Poisson}(\lambda)$$

$$\sum_{k = 0}^\infty e^{-\lambda} \frac{\lambda^k}{k!} = e^{-\lambda}\sum_{k = 0}^\infty\frac{\lambda^k}{k!} = e^{-\lambda}e^\lambda = 1$$
Hence, the Poisson Distribution is a valid Distribution.

# Problem
## Background
> Suppose there exists a machine in a factory that breaks down $3$ times per month on average.

Let $B$ be a random variable that counts the number of times the machine breaks down per month.

Then 
$$B \sim \text{Poisson}(\lambda = 3)$$

This setup is *perfect* for a Poisson Distribution because it has a 
1. High amount of trials $n$
2. a very low $p$ (*success*)
3. $\lambda$ is more accessible than $p$ directly 
## Question Set 1
1. Find the probability of it not breaking down at all in a month
2. Find the  probability of it breaking down 4 times in 2 months.
3. Find the  probability of it breaking down 0 times in $t$ months for $t\in\mathbb{R}^+$

### QS1 - 1
$$P(B = 0, \lambda = 3) = e^{-3}\frac{3^0}{0!} = \boxed{\frac{1}{e^3}}$$
### QS1 - 2
#### Method  A - More Efficient 
See that 
$$\lambda = \frac{3\text{ breakdowns}}{\text{month}}$$
We can extend this idea to 2 months:
$$\lambda = \frac{6\text{ breakdowns}}{2 \text{ months}}$$
Thus
$$P(B = 4, \lambda = 6) = \frac{e^{-6}6^4}{4!} \approx .134$$

### QS1 - 3
We need to convert our given $\lambda = 3$ into a lambda for $t$ months. 
$$\lambda = \frac{3\text{ breakdowns}}{\text{month}} \to \lambda = \frac{3t\text{ breakdowns}}{t \text{ months}}$$

$$P(B = 0, \lambda = 3t) = e^{-3t}\frac{3t^0}{0!} = e^{-3t}$$

Notice how it aligns with Q1 (where $t = 1$ for 1 month).

## Question Set 2
Let $T$, a random variable, be the time until the first breakdown.
> 1. Find a CDF for $T$
> 2. Find a PDF for $T$

### QS2 - 1
Find the CDF.

Let $F(t)$ represent this CDF. Then:
$$F(t) = P(T \leq t)$$
This asks for the probability that the breakdown occurs within $[0, t)$
See that 
$$P(T \leq t) = 1 - P(T \gt t)$$

$P(T \gt t)$ asks the question: "What is the probability that $0$ breakdowns occur within $[0, t)$". This is because $T \gt t$ represents the first breakdown occurring after $t$ time has passed.

We know how to calculate $P(T \gt t)$.
Assume there are $\lambda$ breakdowns per month instead of the $3$ to make the problem more general.

(Look back at ***QS1-3***)
$$P(B = 0) = e^{-\lambda t}\frac{(\lambda t)^0}{0!} = e^{-\lambda t}$$

Hence our CDF is as follows:
$$
F(t) = 
\begin{cases}
	0 & \text{ if } t \lt 0 \\
	1 - e^{-\lambda t} & \text{ if } t \geq 0
\end{cases}
$$
It is $1 - e^{-\lambda t}$ from the $1 - P(T \gt t)$

### QS2 - 2
Recall
$$\dfrac{d}{dt}F(t) = f(t)$$
where $F(t)$ is the CDF

Hence
$$
f(t) = 
\begin{cases}
	0 & \text{ if } t \lt 0 \\
	\lambda e^{-\lambda t} & \text{ if } t \geq 0
\end{cases}
$$
The PDF represents an *exponential density*. 