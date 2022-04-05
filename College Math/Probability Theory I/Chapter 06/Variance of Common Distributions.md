# Variance of Common Distributions
## Bernoulli Trials
Recall from [[Expected Value of Discrete Random Variables - PS1]] that if $X \sim \text{Binom}(n, p)$
$$E(X) = np$$

$$
\begin{align}
	V(X) &= E(X^2) - E(X)^2 \\
		 &= E(X^2) - (np)^2 \\\\
		 
	E(X^2) &= \sum_{k=0}^n k^2 \binom{n}{k}p^kq^{n-k}
\end{align}
$$
That last step will be too much of a problem to calculate directly. We can attempt to use the properties of Variance to find $E(X^2)$.
$$\text{The property: }V(X+Y) = V(X)+V(Y)$$

Suppose $X = \sum_{i = 0}^n X_i$
Then $X$ is the sum of its indicator random variables.
$$
X_i = 
\begin{cases}
	1 & \text{ if Success} \\
	0 & \text{ if Failure} \\
\end{cases}
$$

Then we can say that
$$
\begin{align}
	V(X) &= \sum_{i=0}^{n} V(X_i) \\
	\\
	V(X_i) &= E(X^2) - [E(X)]^2 \\
		   &= p - p^2 \\
		   &= p(1-p) \\
		   &= pq \\
	\\	   
	\sum_{i=0}^{n} V(X_i) &= \sum_{i=0}^{n} pq \\
						  &= \boxed{npq}
\end{align}
$$


## Poisson Distributions
Lets start with the basics
$$\text{Suppose }\ X \sim\text{Poisson}(\lambda)$$
Then
$$
\begin{align}
	V(X) &= E(X^2) - \mu^2 \\
	  ^* &= E(x^2) - \lambda^2 
\end{align}
$$

\* - We already know from the PS1 above that $E(X) = \lambda$

### Calculating $E(X^2)$

Given $X \sim\text{Poisson}(\lambda)$,
$$
\begin{align}
	E(X^2) &= \sum_{k = 0}^{\infty} 
			k^2 \cdot e^{-\lambda}\frac{\lambda^k}{k!} \\
			
		  ^* &= e^{-\lambda}\sum_{k = 1}^{\infty} 
			k \cdot \frac{\lambda^k}{(k-1)!} \\
\end{align}
$$

Due to the extra $k$ we aren't going to be going anywhere with this. 

###  "Algebraic" Trick
We will use the Linearity of Expectations from [[Expected Value of Discrete Random Variables]].

Notice
$$
\begin{align}
	E(X^2) &= E(X(X-1)+X) \\
		   &= E(X(X-1)) + E(X) \\
\end{align}
$$
Then, 
$$
\begin{align}
	E(X(X-1)) &= \sum_{n = 0}^{\infty} k(k-1) \cdot e^{-\lambda}\frac{\lambda^k}{k!} \\
	
	^* &= \sum_{n = 2}^{\infty} e^{-\lambda}\frac{\lambda^k}{(k-2)!} \\
	
	&= e^{-\lambda} \lambda^2\sum_{n = 2}^{\infty} \frac{\lambda^{k-2}}{(k-2)!} \\
	
	&= e^{-\lambda} \lambda^2 e^{\lambda} \\
	
	&= \lambda^2
\end{align}
$$

Now back to our Linearity of Expectation trick:
$$E(X(X-1)) + E(X) = \lambda^2 + \lambda$$

---
Now we can finally attain $V(X)$

$$
\begin{align}
	V(X) &= E(X^2) - \mu^2 \\
	     &= \lambda^2 + \lambda - (\lambda)^2 \\
		 &= \lambda
\end{align}
$$

The fact that $\bf{V(X) = \boldsymbol\lambda}$ makes sense looking at the above Binomial example. This is because $q \approx 1$ and $np = \lambda$

## When $V(X) = 0$ 
Since Variance represents the *spread* of data we can not that 
> If $V(X) = 0$ all values of $X$ have the same probability.

$$
V(X) = E((X - \mu)^2)
$$

Know that if there is only value for $X$ then that is the expected value.

Looking at this formula we notice that 
1. Any offset of $X$ from the expected value $\mu$ will result in a non-zero $V(X)$
2. The reason why $\#1$ is true is because the difference (distance to $\mu$) is squared. Thus $\forall x\in\mathbb{R}, (x-\mu)^2 \geq 0$ and we cannot accidentally 'cancel out' any offsets.