# Important Distributions and Densities
For: [[Probability Theory 1]]
## Discrete Uniform Distribution
Occurs when the **all** outcomes of an experiment are equally likely. This means $X$ is uniformly distributed. Let $S$ be the sample space for this distribution, then $S$ is:
$$0 \lt |S| \lt \infty$$
The distribution function $m(\omega)$ for this case is simply $\frac{1}{|S|}$ for all $\omega\in S$. 

**Note**: When a random variable is Discrete it has a Probability Mass function(*PMF*) $m(\omega_i)$ 
## Binomial Uniform Distribution
More information on this can be located in [[Combinations & Binomials]]. 
$$b(n, p, j) = \binom{n}{j}p^j (1-p)^{n-j}$$
## Poisson Distribution
Aside from [[#Discrete Uniform Distribution]] and [[#Binomial Uniform Distribution]], The Poisson Distribution is one of the more important distributions. 

Suppose we have a situation where a certain kind of occurrence happens **randomly** over a time interval. This can be something like police calls in a large city. We want a model so we can think about events like over 10 calls in 5 minutes.  Note that there would be more calls at 6pm - 7pm than 4am-5am. Firstly, we need a minutely average $\lambda$.  Thus in 5 minutes it is $5\lambda$ calls **on** average. Note that our rate **$\lambda$** would be different for the two time intervals. 

Next, we assume the calls in the time intervals are independent. This means calls in the range 5 - 5:15 do not effect the calls later. 

You can model this via a Binomial Distribution. Imagine that a time interval is broken up into $n$ equal intervals. The intervals must be very small as we must make the probability of 2 calls in one interval *negligible*. Now, each subinterval represents a binary number of calls make to the station: $0$ or $1$.

To land on a value $p$ see that there are $\lambda t$ occurrences in a time interval length of $t$. If this time interval is divided into $n$ subintervals, then, we would expect $np$ occurrences.
$$\lambda t = np \to p = \frac{\lambda t}{n}$$

Consider a random variable $X$ that counts the number of occurrences in an interval. We will assume $t = 1$ to make life easier.

$$
\begin{align*}
	P(X=0) &= b(n, p, 0) = (1-p)^n = (1-\frac{\lambda}{n})^n\\
	%P(X=1) &= b(n, p, 1) &= \ & np(1-p)^{n-1} 
\end{align*}
$$
Recall that 
$$\lim_{n \to \infty}{(1+\frac{a}{n})^n = e^a}$$

Using this fact we can see that for $P(X = 0)$ and for large $n$
$$P(X = 0) \approx e^{-\lambda}$$

Lets Derive the Poisson Formula from the Binomial Distribution
$$b(n, p, j) = \binom{n}{j}p^j (1-p)^{n-j}$$
Let $P(X)$ be the function for the Poisson Formula counting changes in a interval of length $n$ over time. 
$$P(X = x) = \frac{n!}{j!(n-j)!}(\frac{\lambda}{n})^x(1-\frac{\lambda}{n})^{n-x}$$

Let $n\to\infty$. Our subintervals will be infinitely small.
$$
\begin{align*}
P(X = x) &= \frac{n!}{j!(n-j)!}(\frac{\lambda}{n})^x(1-\frac{\lambda}{n})^{n-x}
\\\\
&= \frac{n!}{j!(n-j)!} \frac{\lambda^x}{n^x}(1-\frac{\lambda}{n})^{n}(1-\frac{\lambda}{n})^{-x}
\\\\
&= \frac{n(n-1)\dotso(n-x+1)}{n^x}\frac{\lambda^x}{x!}\frac{\lambda^x}{n^x}(1-\frac{\lambda}{n})^{n}(1-\frac{\lambda}{n})^{-x} 
\\\\
&= (1)
\frac{\lambda^x}{x!}(1-\frac{\lambda}{n})^{n}(1-\frac{\lambda}{n})^{-x} 
\\\\
&= \frac{\lambda^x}{x!}e^{-\lambda}(1-\frac{\lambda}{n})^{-x} 
\\\\

&= \frac{\lambda^x}{x!}e^{-\lambda}

\end{align*}
$$
### Key Details
$$
\begin{align*}
\frac{n(n-1)\dotso(n-x+1)}{n^x} &= \frac{n}{n}\frac{n-1}{n}\dotso\frac{n-x-1}{n} \\

&= [1(1-\frac{1}{n})\dotso(1-\frac{x-1}{n})]\\
& \text{Recall } n\to\infty\\

&= 1
\end{align*}
$$