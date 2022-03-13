# Markov Inequality

## Intro
We use the Markov Inequality to learn more information about the probabilities of "extreme events".

For example this statement is intuitive: 
> If $X \geq 0$ and $E(X)$ is small, then $X$ is unlikely to be very large.

We can guess that because $E(X)$ there may be a higher probabilistic density of smaller numbers making $E(X)$ smaller.

## Markov Inequality
> IF $X \geq 0$ and $a\in\mathbb{R}^+$, then 
> $$P(X\geq a) \leq \frac{E(X)}{a}$$

See how the above example fits into this *inequality* .

## Derivation: CTS
See that 
$$
P(X \geq a) = \int_a^\infty x\:f_X(x)\:dx
$$
$$
\begin{align}
	E(X) = \int_0^\infty x\:f_X(x)\:dx
\end{align}
$$

Observe that:
$$
\begin{align}

\biggr[\int_0^\infty x\:f_X(x)\:dx\biggr] &{\geq} \biggr[\int_a^\infty x\:f_X(x)\:dx\biggr] \\ \\

\end{align}
$$

See that on the RHS the integration region is $[a, \infty)$. Thus the internal variable $x$ is at-least $a$. Thus $x \geq a$. We can state the following:

$$
\biggr[\int_a^\infty x\:f_X(x)\:dx\biggr] \geq \biggr[\int_a^\infty a\:f_X(x)\:dx\biggr] = \biggr[a\int_a^\infty f_X(x)\:dx\biggr] 
$$

Recognize that 
$$
F(a) = \int_a^\infty f_X(x)\:dx = P(X\geq a)
$$
And thus we arrive at the following:

$$
E(X) = \biggr[\int_0^\infty x\:f_X(x)\:dx\biggr] \geq \dotso \geq  \biggr[a\int_a^\infty f_X(x)\:dx\biggr] = aP(X \geq a)
$$

The $\dotso$ represent the steps we took to arrive here.

Thus
$$
\begin{align}
	E(X) &\geq aP(X \geq a)
	\\\\
	P(X \geq a) &\leq \frac{E(X)}{a}
\end{align}
$$

## ALT Derivation
Suppose $Y$ is a random variable with the following concept

$$
Y = 
\begin{cases}
	0 & \text{if} & x \lt a \\
	a & \text{if} & x \geq a
\end{cases}
$$

Then  if $X \gt 0$ and $a \gt 0$ we have
$$
\begin{align}
	Y &\leq X \\
	E(Y) &\leq E(X) \\
	aP(X \geq a)\:\:^{*}&\leq E(X)\\ \\
	P(X \geq a) &\leq \frac{E(X)}{a}
\end{align}
$$

\* - $E(Y) = 0\cdot P(X \lt a) + a\cdot P(X \geq a)$