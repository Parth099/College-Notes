# Law of Large Numbers for Discrete Random Variables
This is know as the fundamental law of probability.

One way to view probability is the frequency of an outcome with which it occurs in the long run, when an experiment is repeated a **large** number of times. 

More mathematically, the probability of an outcome is the output of the distribution function of a random variable representing the experiment. 

This note will align these two models.

## Theorem
> Let $X_1, \dotso, X_n$ be an independent trials process with finite $\mu = E(X_j)$ and $\sigma^2 = V(X_j)$. 
> Then let $S_n = \sum_j^n X_i$. Then for any $\epsilon\in\mathbb{R^+}$,
> $$P(\biggr|\frac{S_n}{n} - \mu\biggr| \geq \epsilon) \to 0$$
> for $n \to \infty$ 

The proof employs [[Chebyshev Inequality]]

Note: Give the $\frac{S_n}{n}$, this law is often called the "**Law of Averages**" .

### 'English Explantion'
Firstly, $|\frac{S_n}{n} - \mu|$ gives the distance of the average $A_n = \frac{S_n}{n}$ from the expected value $\mu$. Now it says that for any $\epsilon > 0$ the probability approaches zero. Thus means that as we increase $n$, $A_n \to \mu$ . 
## Examples

### Quiz Question
> Suppose $X_i$ represents the outcome of independent Bernoulli Trials with 
> $$X_i = \begin{pmatrix} 0 & 1\\  \frac{2}{3} & \frac{1}{3} \end{pmatrix}$$
> $$\text{Let }S_n = \sum_{i = 1}^n X_i$$
> Find a value $n$ such that $$P(|A_n - \frac{1}{3}| \geq 0.1) \leq 0.1$$


We know that $E(X_i) = \frac{1}{3}$ and $V(A_n) = V(S_n)/n^2$

$$V(X_i) = E(X_i^2) - E(X_i)^2$$

$$
\begin{align}
	E(X_i^2) &= 0^2 (\frac{2}{3}) + 1^2 (\frac{1}{3}) = \frac{1}{3} \\
	E(X_i)^2 &= (\frac{1}{3})^2 = \frac{1}{9}
	\\
	
	V(X_i) &= \frac{1}{3} - \frac{1}{9} = \boxed{\frac{2}{9}}
\end{align}
$$

We could have also used the fact that $E(X^2) = pq$ given that $X$ is an indicator rand-var. 

Thus $$V(S_n) = \sum_{i = 1}^n V(X_i) = \sum_{i = 1}^n \frac{2}{9} = \frac{2}{9}n$$

$$V(S_n/n) = \frac{1}{n^2}V(S_n) = \frac{2}{9n}$$

Recall [[Chebyshev Inequality]]
$$P(|X - \mu| \geq \epsilon) \leq \frac{V(X)}{\epsilon^2}$$

We can fill in the following
$$P(|A_n - \mu| \geq 0.1) \leq \frac{\frac{2}{9n}}{0.1}$$

We need to solve for $$\frac{\frac{2}{9n}}{0.1} = 0.1$$

Then,
$$
\begin{align}
	\frac{2}{9n} &= 0.01 \\
	2 &= 0.09n \\
	\frac{2}{0.09} &= n \\
	\\
	n &= 222.2\overline{2} \\
	\lceil n \rceil &= \boxed{223}
\end{align}
$$
