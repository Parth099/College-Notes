# Chebyshev Inequality
Let $X$ be a discrete random variable with expected value $\mu =E(X)$. Then let $\epsilon \in \mathbb{R}^+$.

Then, 
$$P(|X - \mu| \geq \epsilon) \leq \frac{V(X)}{\epsilon}$$

What is this says is that $\frac{V(X)}{\epsilon}$ is the upper bound for the probability of the Random Variable being of $\epsilon$ distance from the mean. 


### Proof
We first make a note about the distance
$$
P(|X - \mu| \geq \epsilon) = \sum_{|x-\mu| \geq \epsilon} m(x)
$$

This takes the sum of all $P(X = x)$ for$|x-\mu| \geq \epsilon$

Recall that 
$$V(X) = \sum_{x} (x - \mu)^2m(x)$$

See that 
$$
\sum_{x} (x - \mu)^2m(x) \geq \sum_{|x - \mu| \geq \epsilon} (x - \mu)^2m(x) \geq \sum_{|x - \mu| \geq \epsilon} \epsilon^2m(x)
$$

This is the same as 
$$
= \frac{1}{\epsilon^2}\sum_{|x - \mu| \geq \epsilon} m(x) = \frac{1}{\epsilon^2}P(|X - \mu| \geq \epsilon)
$$

Since 
$$

\begin{align}
	V(X) &\geq \frac{1}{\epsilon^2}P(|X - \mu| \geq \epsilon)
	\\ \\
	\frac{V(X)}{\epsilon^2} &\geq P(|X - \mu| \geq \epsilon)
\end{align}
$$

## Motivation
Sat Score Distribution
![[motivation CI.png]]

Often times we have a distribution and we want to find distance from the mean. Here we want to know the probability of scoring 315 points from the mean of $1059$ .

This is possible when we know how $X$ is distributed but not when we are unsure what distribution $X$ follows. 

This is why we need the ***Chebyshev Inequality*** .

We want to answer this same question:
What is the probability that we are $a$ distance from the mean. 
$$P(|X-\mu| \geq a)?$$

For this example above we plug the values into our inequality and see that 

$$
P(|X-\mu| \geq 315) \leq \frac{210^2}{315^2} \approx .444
$$

This means that for any distribution $P(|X-\mu| \geq 315)$ will **not** exceed $.444$ 