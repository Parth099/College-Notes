# Variance of Discrete Variables
While we did study the expected value of random experiments we also need to study what the deviation from this expect value will be. This is where variance comes in. It is a measure of this deviation based on the elements $\in\Omega$ and their respective probabilities.

## Variance Definition
> Let $X$ be a numerical random variable with $E(x) = \mu$, Then the variance of $X$, denoted by $\text{var}(X)$ or $V(X)$ is:
> $$V(X) = E((X-\mu)^2)$$
> See that this a functional expression we can do something about. \*
> 
> With the information above:
> $$V(X) = \sum_x (x - \boldsymbol{\mu})^2m(x)$$
> for a valid distribution function $m(x)$

\* - See [[Expected Value of Functions of Random Variables]]

## Standard Deviation
The *standard deviation* of $X$ is denoted by $D(X)$ where
$$D(X) = \sqrt{V(X)}$$.

Often times we use $\sigma$ for $D(X)$ and $\sigma^2$ for $V(X)$

## Example for the Calculation of Variance
> Let $X$ represent a dice roll, that is $X$ is the number rolled.

Lets find $V(X)$ :

$$\mu = E(X) = \sum_{i = 1}^6 i\frac{1}{6} = \frac{7}{2}$$

Now that we have $\mu$ we can attain $E((X-\boldsymbol{\mu})^2)$

**Calculation Table**
![[variance_tab_ex1.png]]
$$
\begin{align}
V(X) &= \sum_x (x - \boldsymbol{\mu})^2m(x) \\
	&= 2(\frac{25}{4}\frac{1}{6}) + 2(\frac{9}{4}\frac{1}{6}) + 2(\frac{1}{4}\frac{1}{6}) \\
	&= 35/12
	\\\\
	D(X) &= \sqrt{V(X)} = \sqrt{35/12} \approx 1.7
\end{align}
$$

## Alternate way for Calculation of Variance
This method uses the "Linearity of Expectation" theorem from [[Expected Value of Discrete Random Variables]].

> **Theorem**
> Suppose a random variable $X$ has $E(X) = \mu$
> Then the variance is:
> $$V(X) = E(X^2) - \mu^2$$

Why?
$$
\begin{align}
	V(X) &= E((X - \mu)^2) = E(X^2 - 2\mu X + \mu^2) \\
	     &= E(X^2) - 2\mu E(X) - \mu^2 = E(X^2) - \mu^2
\end{align}
$$
See that this alternate agrees with the dice roll $V(X)$ calculated above. 

## Properties of Variance
Unlike $E(X)$, $V(X)$ is non-linear.
### Prop 1
> **Theorem**
> Let $X$ be a random variable and $c$ be some constant then
> $$V(cX) = c^2V(X)$$
> and 
> $$V(X + c) = V(X)$$

Both can be proven via the Expectation of Linearity.

### Prop 2
Let $X, Y$ be random variables. For expectation, $E(X)+E(Y)=E(X+Y)$, yet this is untrue for $V(X+Y)$.
Let $Y = -X$ and see what occurs for variance and for expected value. (Hint: $E(X+Y) = E(0) = 0$)

However if the two random variables **are independent** then, 
> $$V(X + Y) = V(X) + V(Y)$$
