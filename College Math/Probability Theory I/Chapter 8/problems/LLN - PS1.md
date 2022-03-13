# Law of Large Numbers & The Chebyshev Inequality
## 1
![[c8_1p1.png]]

$$X \sim \text{Binom}(n = 100, p = 1/2)$$
$$X = \sum_{i = 1}^{100} X_i$$


We see that $3$ deviations means that we need
$$
P(\biggr|X - 50\biggr| \geq 15) 
$$

This value is always less than $\frac{V(X)}{15^2}$

Given that each coin flip is independent we see that 
$$V(X) = V\biggr(\sum_{i = 1}^{100} X_i\biggr) = \sum_{i = 1}^{100}V(X_i)$$

See that 
$$X_i = 
\begin{pmatrix} 
	0 & 1\\  
	q & p
\end{pmatrix}$$

Then 
$$
\begin{align}
	E(X_i)   &= \frac{1}{2} \\
	E(X_i^2) &= \frac{1}{2} \\
	V(X_i)   &= \frac{1}{4} \\
\end{align}
$$

Thus 
$$
V(X) = \sum_{i = 1}^{100}V(X_i) = 25
$$

Finally, 

$$
P(\biggr|X - 50\biggr| \geq 15) \leq \boxed{\frac{25}{15^2}} = \frac{1}{11}
$$
### 1 - More Efficient method 
Here is the Chebyshev Inequality
$$P(|X - \mu| \geq \epsilon) \leq \frac{V(X)}{\epsilon^2}$$

Since the problem gives is the deviation: $D(X) = 5$, then $V(X) = 25$ 

## 5
![[c8_1p5.png]]
The upper bound will be $\frac{1}{k^2} = 0.01$, thus $k = 10$

## 6
![[c8_1p6.png]]

$$\frac{S_n}{n} = A_n$$
$$
A_n = \frac{1}{n}\sum_{i = 0}^n X_i \text{ for } X_i = 
\begin{cases}
	1 & \text{ if Success} \\
	0 & \text{ if Failure} \\
\end{cases}
$$

$$V(A_n) = \frac{1}{n^2}V(S_n) = npq\frac{1}{n^2} = \frac{p(1-p)}{n}$$

Since 
$$P(|\frac{S_n}{n} - p| \geq \epsilon) \leq \frac{V(X)}{\epsilon^2}$$

$$
\implies P(|\frac{S_n}{n} - p| \geq \epsilon) \leq \frac{\frac{p(1-p)}{n}}{\epsilon^2}
$$

$$
\implies P(|\frac{S_n}{n} - p| \geq \epsilon) \leq \frac{p(1-p)}{n\epsilon^2}
$$

## 7
![[c8_1p7.png]]

Let $f(p) = p(1-p) = p - p^2$
Then
$$
\begin{align}
	\dfrac{df}{dp} &= 1 - 2p 
	\\ \\
	\dfrac{df}{dp} &= 0 \text{ when } p = \frac{1}{2}
\end{align}
$$

We can watch the sign of $\dfrac{df}{dp}$ on interval $[0, 1]$
If $p \in [0, \frac{1}{2})$, $\dfrac{df}{dp} \gt 0$
If $p \in (\frac{1}{2}, 1]$, $\dfrac{df}{dp} \lt 0$

This implies that $p = \frac{1}{4}$ is a local max on the interval $[0, 1]$

Furthermore, this means that
$$
\forall (p\in[0, 1]),\: p - p^2 \leq f(\frac{1}{2}) = \frac{1}{4}
$$
Actually, $1/4$ is the max for that Function. *


Thus, the E6 has the property that
$$
P\biggr(\biggr|\frac{S_n}{n} - p\biggr|\geq \epsilon\biggr) \leq \frac{1}{4n\epsilon^2}
$$

\* - After using Calculus I saw that we do not need it, we already know that the vertex of a quadratic occurs at $\frac{-b}{2a}$ and this would be a formal global max given $a \leq 0$ .