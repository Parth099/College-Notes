# Chebyshev Inequality
Let $X$ be a discrete random variable with expected value $\mu =E(X)$. Then let $\epsilon \in \mathbb{R}^+$.

Then, 
$$P(|X - \mu| \geq \epsilon) \leq \frac{V(X)}{\epsilon^2}$$

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

## Downfall of the Chebyshev Inequality
> Suppose $X$ is uniform on $[0, 1]$
> Compare 
> $$g(\epsilon) = P\biggr(\biggr|X - \frac{1}{2}\biggr| \geq \epsilon\biggr)$$
> with
> $$h(\epsilon) = \frac{V(X)}{\epsilon^2}$$

See that $h$ is the Chebyshev upper-bound

Consider $g(\epsilon)$
$$
\begin{align}
	P\biggr(\biggr|X - \frac{1}{2}\biggr| \geq \epsilon \biggr) &= P\biggr(-\epsilon \geq X - \frac{1}{2} \geq \epsilon \biggr)
	\\\\
	&= P\biggr(-\epsilon + \frac{1}{2} \geq X \geq \epsilon + \frac{1}{2} \biggr)
	\\\\
	&= 1 - P\biggr(-\epsilon + \frac{1}{2} \leq X \leq \epsilon + \frac{1}{2} \biggr)
	\\\\
	g(\epsilon)&= 1 - 2\epsilon
\end{align}
$$

$$
\begin{align}
	E(X) &= \frac{1}{2} \\
	V(X) &= E((X-\mu)^2) = \int_0^1 (x-\frac{1}{2})^2 1 \mathop{dx} = \boxed{\frac{1}{12}}
\end{align}
$$

$$
\begin{align}
	g(\epsilon)&= 1 - 2\epsilon \\
	h(\epsilon)&= \frac{1}{12\epsilon^2}
\end{align}
$$

Notice the $\epsilon \in [0, \frac{1}{2}]$

Graph of the upperbound and actual $P(\text{Event})$
![[chebys_comparison.png]]

We conclude that the Chebyshev Inequality is not the best way to estimate probabilities.  