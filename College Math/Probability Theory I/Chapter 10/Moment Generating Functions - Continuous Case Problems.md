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

Then, $$f_X(x) = \lambda e^{-\lambda x} \text{ for } x\in[0, \infty) \text{ klse } 0$$

Notice that $$\mu_k = \int_{0}^{\infty} x^k f_X(x)\:dx$$
is too hard to calculate. $\mu_{k}$ requires $k+1$ layers of integration by parts.

Lets work on $g(t)$

$$
\begin{align}
	g(t) &= \int_{0}^{\infty} e^{tx} \lambda e^{-\lambda x}\:dx \\
		&=  \lambda\int_{0}^{\infty} e^{x(t-\lambda)}\:dx\\
	^{*}&= \lambda \frac{e^{x(t-\lambda)}}{(t-\lambda)}\biggr|_{x=0}^{x\to\infty}
\end{align}
$$

Consider the three states of $t-\lambda$ (see [[Ordered Rings and Fields]])

1. $t-\lambda \gt 0$
2. $t-\lambda \lt 0$
3. $t-\lambda = 0$

Notice that in cases $1, 3$ the integral is **divergent** (consider the sign of the power of $e$)

Assume $t \lt \lambda$

The integral endpoints evaluate to 
$$0 - \frac{\lambda}{t - \lambda} = \frac{\lambda}{\lambda - t} = \mathbf{g(t)}$$

Hence, 

$$
g(t) = 
\begin{cases}
	\frac{\lambda}{\lambda - t} & \text{if} & t \lt \lambda \\
	\text{undefined} & \text{if} & t \geq \lambda
\end{cases}
$$

**Moment Information**

| k   | Derivative                         | $k$th Moment          |
| --- | ---------------------------------- | --------------------- |
| $$1$$   | $$\frac{\lambda}{(\lambda - t)^2}$$  | $$\frac{1}{\lambda}$$   |
| $$2$$   | $$\frac{2\lambda}{(\lambda - t)^3}$$ | $$\frac{2}{\lambda^2}$$ |
| $$3$$   | $$\frac{6\lambda}{(\lambda - t)^4}$$ | $$\frac{6}{\lambda^3}$$                      |

At this rate:
$$
\begin{align}
	g^{(k)}(t) &= \frac{k!\lambda}{(\lambda - t)^{k+1}} \\ \\
	g^{(k)}(0) = \mu_k &= \frac{k!}{\lambda^{k}} 
\end{align}
$$

## Example 3
> $X$ is distributed via this function:
> $$f_X(x)\begin{cases}xe^{-x} &\text{if}& x \geq 0\\0 & \text{otherwise} \end{cases}$$
> Find:
> 1. $g_X(t)$
> 2. $\mu_k$

$$
\begin{align}
	g(t) = \mathbb{E}(e^{tX}) &= \int_{0}^\infty e^{tx} xe^{-x}\:dx
	\\
	&= \int_{0}^\infty xe^{x(t-1)}\:dx
\end{align}
$$

Notice that this converges **only if** $t-1 \lt 0$, hence we assume $t \lt 1$ for the rest of the calculations. 

*Tabular* Integration by Parts table

| Sign | Derivative | Integrand                 |
| ---- | ---------- | ------------------------- |
| $$+$$  | $$x$$        | $$e^{x(t-1)}$$          |
| $$-$$  | $$1$$        | $$\frac{1}{t-1}e^{x(t-1)}$$ |
| $$+$$  | $$0$$        | $$\frac{1}{(t-1)^2}e^{x(t-1)}$$ | 

$$
\begin{align}
	\int_{0}^\infty xe^{x(t-1)}\:dx = \lim_{b\to\infty} \biggr(\frac{x}{t-1}e^{x(t-1)} - \frac{1}{(t-1)^2}e^{x(t-1)}\biggr)\biggr|_{x = 0}^{x = b}
\end{align}
$$

> $$\text{Recall }\:\forall n, \lim_{x\to\infty} \frac{x^n}{e^x} = \mathbf{0}$$

$$
\begin{align}
	&= \biggr(0 - 0\biggr) - \biggr(0 - \frac{1}{(t-1)^2}\biggr) \\
	&= \frac{1}{(t-1)^2}
\end{align}
$$

**Definition of** $g(t)$

$$
g(t) = 
\begin{cases}
	\frac{1}{(t-1)^2} & \text{if} & t\lt1
	\\
	\text{undefined} & \text{if} & t\geq1
\end{cases}
$$


**Moment Information**

| k   | Derivative      | $k$th Moment |
| --- | --------------- | ------------ |
| $$1$$   | $$-2(t-1)^{-3}$$  | $$2$$          |
| $$2$$   | $$6(t-1)^{-4}$$   | $$6$$          |
| $$3$$   | $$-24(t-1)^{-5}$$ | $$24$$         |

From this pattern we see that:
$$
\begin{align}
	g^{(k)}(t) &= \frac{(-1)^k(k+1)!}{(t-1)^{k+2}} \\
	\\
	g^{(k)}(0) = \mu_k &= (k+1)!
\end{align}
$$