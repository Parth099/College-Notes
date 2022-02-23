# Expected Value of *Functions* of Random Variables

> **Theorem**
> $$E(\phi(X)) = \sum_x \phi(X)P(X = x)$$

This theorem will be more clear when examples are presented. 

## Examples
### Basic Example
$$
\text{Let } X = 
	\begin{pmatrix}  
		-1 & 0 & 1 & 2\\  
		\frac{1}{3} & \frac{1}{6} & \frac{1}{6} & \frac{1}{3} \\ 
	\end{pmatrix}
$$
Note this is not a matrix. The top row represents the values $X$ can take on and the bottom row represents the *probabilities* of $X$ taking on the value above them. 

$$E(X) = -1\frac{1}{3} + 0\frac{1}{6} + 1\frac{1}{6} + 2\frac{1}{3} = 1/2$$

> What is $E(X^2)$ ? 


$$E(X^2) = (-1)^2\frac{1}{3} + (0)^2\frac{1}{6} + (1)^2\frac{1}{6} + (2)^2\frac{1}{3} = 11/6$$

Lets look at the actual distribution of $X^2$

$$
X^2 = 
	\begin{pmatrix}  
		0 & 1 & 4\\  
		\frac{1}{6} & \frac{1}{2} & \frac{1}{3} \\ 
	\end{pmatrix}
$$

$$E(X^2) = 0\frac{1}{6} + 1\frac{1}{2} + 4\frac{1}{3} = 11/6$$

We note that they are both the same yet the above calculation allowed us to know $E(X^2)$ with only the knowledge of $X$

Also, there isn't really any magic going on here. Notice that for $X^2$ we have both $-1$ and $1$ being transformed into $1$, and then their probabilities being added. Both ways of doing it account for *these* transformations. 

### Examples 
#### E1
> Let $X$ indicate $A$ where $P(A) = p$

Find
+ $E(X)$
+ $E(X^2)$
+ $E(e^{tX})$

##### E1.1
We note that $X$ is an indicator. This means simply: 
$$
X = 
\begin{cases}
	1 & \text{ if } & \text{success}  \\
	0 & \text{ if } & \text{failure}  \\
\end{cases}
$$

$$\text{Thus, }E(X) = 1p + 0q = p$$

##### E1.2
Time to apply the theorem
$$E(X^2) = (1)^2p + (0)^2q = p$$

##### E1.3
$$\phi(X) = e^{tX}$$

$$
\begin{align}
	E(e^{tX}) &= e^{t(1)}p + e^{t(0)}q \\
		      &= pe^t + 1 - p
\end{align}
$$
Notice how the expected value is a function defined by $t$
#### E2
> Find $E(X^2)$ if $X$ represents the number of dice being rolled.

See $\Omega = {1, 2, 3, 4, 5, 6}$ with each having a probability of $1/6$

$$E(X^2) = 1^2(\frac{1}{6})+2^2(\frac{1}{6})+3^2(\frac{1}{6})+4^2(\frac{1}{6})+5^2(\frac{1}{6})+6^2(\frac{1}{6})$$
$$\frac{1}{6}\sum_{n = 1}^6 n^2 = \frac{91}{6}$$

---

### An Advanced Example
> Suppose $$X \sim \text{Binom}(n, p)$$

Find $E(e^{tX})$

#### Solution
$$
\begin{align}
	E(e^{tX}) &= 
		\sum_{k = 0}^{n}e^{tk}
		\binom{n}{k}p^kq^{n-k} 
		\\
		
		&= \sum_{k = 0}^{n}(e^{t})^{k}
		\binom{n}{k}p^kq^{n-k} 
		\\
		
		&= \sum_{k = 0}^{n}(e^{t})^{k}p^k
		\binom{n}{k}q^{n-k} 
		\\
		
		&= \sum_{k = 0}^{n}(pe^{t})^k
		\binom{n}{k}q^{n-k} 
		\\
		
		&= \sum_{k = 0}^{n}\binom{n}{k}
		(pe^{t})^kq^{n-k} 
		\\
		
		^{*} &= (\ pe^{t} + q\ )^n
\end{align}
$$

\* - Result of the **Binomial Theorem**
$$(a+b)^n = \sum_{k = 0}^{n} \binom{n}{k} a^kb^{n-k}$$