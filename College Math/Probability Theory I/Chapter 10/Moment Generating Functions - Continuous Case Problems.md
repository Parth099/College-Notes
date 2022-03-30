# Moment Generating Functions - Continuous Case Problems
## Example 1
> Suppose $X$ is distributed uniformly on $[0, 1]$ 

Then, $f_X(x) = 1$ for any $x\in[0, 1]$

Then $$\mu_n = \int_{-\infty}^{+\infty} x^n f_X(x) \mathop{dx} = \int_{0}^{1} x^n \mathop{dx} = \frac{1}{1+n}$$

Then, 
$$
\begin{align}
	g(t) = \sum_{k = 0}^{\infty} \mu_k \frac{t^k}{k!} &= \sum_{k = 0}^{\infty} \frac{1}{1+k} \frac{t^k}{k!} \\ \\
	&= \sum_{k = 0}^{\infty} \frac{t^k}{(k+1)!} \\
	&= \frac{1}{t}\sum_{k = 0}^{\infty} \frac{t^{k+1}}{(k+1)!}\\
	
	&= \frac{1}{t}\sum_{k = 1}^{\infty} \frac{t^{k}}{k!} \\
	
	&= \frac{1}{t}(e^t - \frac{t^0}{0!})\\
	
	&= \frac{e^t - 1}{t}
\end{align}
$$

We can also use the *new* definition

$$
\begin{align}
	g(t) &= \int_{-\infty}^{+\infty} e^{tx} f_X(x) \mathop{dx} = \int_{0}^{1} e^{tx} \mathop{dx} = \frac{1}{t}(e^t - 1)
\end{align}
$$

After using Limit laws ($\overset{\mathrm{H}}{=}$)


$$
\begin{align}
	\mu_0 &= g(0) = \lim_{t\to0} = \frac{1}{t}(e^t - 1) = 1   \\
	\mu_1 &= g^\prime(0) = \frac{1}{2}   \\
	\mu_2 &= g^{\prime\prime}(0) = \frac{1}{3}    \\
\end{align}
$$

## Example 2
> Suppose $X$ is distributed exponentially

Then, $f_X(x) = \lambda e^{-\lambda x}$