# Law of Large Numbers for Continuous Random Variables
Recall the [[Chebyshev Inequality]]
$$P(|X - \mu| \geq \epsilon) \leq \frac{\sigma^2}{\epsilon^2}$$

Let $X$ be any CTS random variable such that $E(X) - \mu$ and $V(X) = \sigma^2$. If $\epsilon = k\sigma$, this is the same as $k$ std-deviations, then
$$P(|X - \mu| \geq \epsilon) \leq \frac{\sigma^2}{k^2\sigma^2} = \frac{1}{k^2}$$

This part is the same as that of [[Law of Large Numbers for Discrete Random Variables]]

Note the law is the same too,
## The Law
> Let $X_1, \dotso, X_n$ be an independent trials process with finite $\mu = E(X_j)$ and $\sigma^2 = V(X_j)$ and a **cts** PDF: $f(x)$
> Then let $S_n = \sum_j^n X_i$. Then for any $\epsilon\in\mathbb{R^+}$,
> $$P(\biggr|\frac{S_n}{n} - \mu\biggr| \geq \epsilon) \to 0$$
> $$P(\biggr|\frac{S_n}{n} - \mu\biggr| \leq \epsilon) \to 1$$
> for $n \to \infty$ 

As we commit more and more trials the average distance from the mean approaches **zero**. That is the theoretical value approaches the expected. 

## Examples
### Uniform Case
> Suppose we pick $n$ numbers from the cts interval $[0, 1]$, Let $X_i$ represent the $i$th choice. 

$$
\begin{align}
	\mu &= E(X_i) = \int_0^1 x\mathop{dx} = \frac{1}{2}\\
	\sigma^2 &= V(X_i) = \biggr[\int_0^1 x^2\mathop{dx}\biggr] - \mu^2 = \frac{1}{3} - \frac{1}{2^2} \\
	&= \boxed{\frac{1}{12}}
\end{align}
$$

Thus

$$
\begin{align}
	E\biggr(\frac{S_n}{n}\biggr) &= \frac{1}{2} \\
	V\biggr(\frac{S_n}{n}\biggr) &=^{*} \frac{1}{12n} \\
\end{align}
$$

\* - since $V(X_i) = \frac{1}{12}$

Lets look at the Chebyshev Inequality with this information
$$
P(|\frac{S_n}{n} - \frac{1}{2}|\geq \epsilon) \leq \frac{1}{12n\epsilon^2}
$$

#### Analysis
If we chose $n$ numbers at random in $[0, 1]$ The chance that 
the difference $|\frac{S_n}{n} - \mu|$ is less then $\epsilon$ is $$1 - \frac{1}{12n\epsilon^2}$$


We can use this as an error bound. 

### Quiz Question
> Suppose $X_1,\dotso, X_{1000}$ are chosen independently from $[0, 2]$ .
> $$S_n = \sum_{i = 1}^{1000}X_i$$
> What is 
> $$P\biggr(\biggr|\frac{S_{1000}}{1000} - 1\biggr|\geq 0.1\biggr)\: ?!$$

Notice that $E(\frac{S_n}{n}) = \frac{2-0}{2} = 1$
See that 
$$
f_{X}(x) = \frac{1}{2-0} = \frac{1}{2}
$$
$$
\begin{align}
	V(X_i) &= \biggr[\int_0^2x^2 f_{X}(x) \mathop{dx}\biggr] - 1^2 \\
	     &= \frac{4}{3} - 1 \\
		 &= \boxed{\frac{1}{3}}
\end{align}
$$
This is the variance per trial.
$$V(A_{1000}) = V(\frac{S_{1000}}{1000}) = \frac{1}{1000^2}V(S_n) = \frac{1}{1000^2}(1000 \times \frac{1}{3}) = \frac{1}{3\cdot 1000}$$


Since $\epsilon = 0.1$, the original probability  is bounded above by 
$$
\frac{V(A_{1000})}{0.1^2} = \frac{\frac{1}{3\cdot 1000}}{0.1^2} = \frac{1}{3\cdot1000\cdot0.1^2} = \frac{1}{30}
$$

Thus, 

$$
P\biggr(\biggr|\frac{S_{1000}}{1000} - 1\biggr|\geq 0.1\biggr) \leq \boxed{\frac{1}{30}}
$$