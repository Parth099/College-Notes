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

%%
	To be finished
	pg 258 -> 268 
%%
