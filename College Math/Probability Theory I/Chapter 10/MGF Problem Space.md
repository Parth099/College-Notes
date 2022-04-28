# Discrete
## 1
![[c10_1p1.png]]
#### a)
Suppose $X$ represents a single flip of a coin. Then this coin is a Bernoulli Trial. Let $X$ be an indicator variable. 

$$
p_X = \begin{pmatrix}  
	0 & 1 \\ 
	\frac{1}{2} & \frac{1}{2}\\ 
	\end{pmatrix}$$

$$
\begin{align}
	g(t) &= \sum_{k = 0}^1 e^{tk} p_X(k)\\
		 &= \frac{1}{2} + \frac{1}{2}e^t
		 
		 \\\\
		 
	h(z) &= \frac{1}{2} + \frac{1}{2}z
\end{align}
$$

#### b)
Suppose $X$ represents the the dice output then $x\in\{1, 2, 3, 4, 5, 6\}$ where each outcome has a uniform outcome. 

$$
\begin{align}
	g(t) &= \sum_{k = 1}^6 e^{tk}p_X(k) \\
		 &= \frac{1}{6}\sum_{k = 1}^6 e^{tk} \\
		 &= \frac{1}{6}(e^{t} + \dotso + e^{6t}) \\
		 &= \frac{1}{6}\frac{e^t(e^{6t} - 1)}{e^t - 1} \\\\
		 
	h(z) &= \frac{1}{6}z + \frac{1}{6}z^2 + \frac{1}{6}z^3 +\frac{1}{6}z^4 +\frac{1}{6}z^5 + \frac{1}{6}z^6	 
\end{align}
$$

Notice how $h^\prime(1)$ gives the $\mathbb{E}(X)$

#### c)
Suppose $X$ is always $3$
Then $p_X(3) = 1$
$$
\begin{align}
	g(t) &= \sum_{k = 3}^3 e^{tk} p_X(k) \\
		 &=	e^{3t}
		 \\\\
		 
	h(t) &= z^3
\end{align}
$$

#### d)
$X$ is uniform on $\{n, n+1, \dotso, n+k\}$. The set contains $k+1$ elements. 

$$p_X(x) = \frac{1}{n+k-n + 1} = \frac{1}{k+1}$$


$$
\begin{align}
	g(t) &= \frac{1}{k+1}\sum_{j = n}^{n+k} e^{tj}\\ \\
	
	&= \frac{1}{k+1}\biggr[e^{tn} + e^{t(n+1)} + \cdots + e^{t(n+k)}\biggr] \\ \\
	
	&= \frac{1}{k+1} \biggr[e^{tn} + e^{tn + t} + \cdots + e^{tn+tk}\biggr] \\ \\
	
	&= \frac{1}{k+1}e^{tn} \biggr[1 + e^{t} + \cdots + e^{tk}\biggr] \\ \\
	
	&= \frac{1}{k+1}e^{tn} \sum_{j = 0}^{k} e^{tk} \\ \\
	
	h(z) &= \frac{1}{k+1}z^n \sum_{j = 0}^{k}z^j
		
\end{align}
$$

#### e)
$X$ is binomial on $\{n, n+1, \dotso, n+k\}$. The set contains $k+1$ elements. 

$$
\begin{align}
	g(t) = E(e^{tX}) &= \sum_{j = 0}^{k}e^{t(j+n)}\binom{k}{j}p^j q^{k-j}
	\\
	&= e^{tn}\sum_{j = 0}^{k}\binom{k}{j}p^je^{tj} \cdot q^{k-j}
	\\
	^{*} &= e^{tn}\biggr[pe^t+q\biggr]^k
	\\ \\
	h(z) &= z^n(pz+q)^k
\end{align}
$$

\* - Binomial Theorem 
#### f)
$X$ is geometric on the non-negative integers with $$p_X(j) = \frac{2}{3^{j+1}}$$

$$
\begin{align}
	g(t) &= \sum_{k = 0}^\infty e^{tk} p_X(k) \\
	&= \sum_{k = 0}^{\infty} e^{tk} \frac{2}{3^{k+1}} \\
		
	&= \frac{2}{3}\sum_{k = 0}^{\infty} e^{tk} \frac{1}{3^{k}} \\
	
	&= \frac{2}{3}\sum_{k = 0}^{\infty} \frac{e^{tk}}{3^{k}} \\
	
	&= \frac{2}{3}\sum_{k = 0}^{\infty} \biggr(\frac{e^t}{3}\biggr)^k \\
	\\
	&= \frac{2}{3}\frac{1}{3-\frac{e^t}{3}}\\
	
	&= \frac{2}{3}\frac{1}{\frac{1}{3}(3-e^t)} \\ \\
	
	&= \frac{2}{3-e^t} \\\\
	
	h(z) &= \frac{2}{3 - z}
\end{align}
$$

## 3
![[c10_1p3.png]]
#### a)
> Recall $$g(t) = \sum_{k = 0}^{\infty} \mu_k\frac{k^t}{k!}$$

Then, 
$$
\begin{align}
	h(z) &=  az^0 + bz^1 + cz^2 \\
	h^{\prime}(z) &= b + 2cz \\
	h^{\prime}(1) &= b + 2c \\ \\
	h^{\prime\prime}(z) &= 2c \\
	
	h^{\prime\prime}(z) &= \mu_2 - \mu_1 \\
	\\
	\implies \mu_2 - \mu_1 &= 2c \\ 
	c &= \frac{1}{4}
	
	

\end{align}
$$

Thus, $c = \frac{1}{4}$ and $b = \frac{1}{2}$
Since $a+b+c = 1$, $a = \frac{1}{4}$

$$
h(z) = \frac{1}{4} + \frac{1}{2}z + \frac{1}{4}z^2
$$

#### b)
$$h(e^t) = g(t) = \frac{1}{4} + \frac{1}{2}e^t + \frac{1}{4}e^{2t}$$

#### c)
| $k$th Derivative                                      | Moment                              | Value         |
| ----------------------------------------------------- | ----------------------------------- | ------------- |
| $g^{\prime}(t)= \frac{1}{2}e^t + \frac{1}{2}e^{2t}$   | $\mu_1 = g^{\prime}(0)$             | 1             |
| $g^{\prime\prime}(t)= \frac{1}{2}e^t + e^{2t}$        | $\mu_2 = g^{\prime\prime}(0)$       | $\frac{3}{2}$ |
| $g^{\prime\prime\prime}(t)= \frac{1}{2}e^t + 2e^{2t}$ | $\mu_2 = g^{\prime\prime\prime}(0)$ | $\frac{5}{2}$ |

**Notice** $$\mu_k = \frac{1}{2} + 2^{k-2}$$
This formula is valid for $k\geq1$

Another way to do this was to decompose the powers of $e^t$ in $g(t)$ into Taylor Expansion. This will expose $\mu_k$. 
#### d)
$$p = \begin{pmatrix} 0 & 1 & 2 \\ \frac{1}{4} & \frac{1}{2} & \frac{1}{4}\end{pmatrix}$$


## Continuous 
Recall that 
$$
\begin{align}
	\mu_k &= \int_{-\infty}^{+\infty} x^k f_X(x) \mathop{dx} \\ g(t) = \mathbb{E}(e^{tX}) &= \int_{-\infty}^{+\infty} e^{tx} f_X(x) \mathop{dx} 
\end{align}
$$
## 1
![[c10_3p1.png]]
#### a)
$$
\begin{align}
	g(t) &= \int_0^2 e^{tx} \cdot \frac{1}{2}\: dx  \\
	&= \frac{e^{tx}}{2t}\biggr|_{x=0}^{x=2} \\
	&= \frac{e^{2t}-1}{2t}
\end{align}
$$

#### b)
$$
\begin{align}
	g(t) &= \int_0^2 e^{tx} \cdot \frac{1}{2}x\: dx  \\
	&= \frac{1}{2}\int_0^2 xe^{tx}\: dx\\
	&= \frac{1}{2}\biggr[\frac{x}{t}e^{tx}-\frac{1}{t^2}e^{tx}\biggr]_{x=0}^{x=2} \\
	&= \frac{1}{2}\biggr(\frac{2}{t}e^{2t} - \frac{1}{t^2}e^{2t} +\frac{1}{t^2}\biggr) \\

	&= \frac{1}{2}\biggr(\frac{2t}{t^2}e^{2t} - \frac{1}{t^2}e^{2t} +\frac{1}{t^2}\biggr) \\
	
	&= \frac{1}{2}\biggr(\frac{2te^{2t}-e^{2t} + 1}{t^2}\biggr) \\
	
	&= \frac{1}{2}\biggr(\frac{e^{2t}(2t-1) + 1}{t^2}\biggr) \\ \\
	
	&= \frac{e^{2t}(2t-1) - 1}{2t^2}
\end{align}
$$

#### c)
no

#### d)
let $f_X = |1-x|$ be the density function for the interval $[0, 2]$. 

Then, 
$$
f_X(x) = \begin{cases}
	1 - x & \text{if} & 0 \leq x \leq 1 \\
	x - 1 & \text{if} & 1 \lt x \leq 2 \\
	0 & \text{otherwise}
\end{cases}
$$

**MGF**:
$$
\begin{align}
	g(t) &= \int_{0}^{2} e^{tx} f_X(x)\:dx \\
	&= \int_{0}^{1} (1-x)e^{tx}\:dx + \int_{1}^{2} (x-1)e^{tx}\:dx \\
	^*&= \frac{1}{t^2}(e^t - t - 1) \:+\: \frac{e^t}{t^2}(te^t - e^t + 1) \\
	&= \frac{1}{t^2}\biggr[e^{2t}(t-1)+2e^t - t - 1\biggr]
\end{align}
$$

\* - series of *Integration by Parts*

#### e)
Let the density be $f_X(x) = \frac{3}{8}x^2$ on the interval $[0, 2]$

Then, 

$$
\begin{align}
	g(t) &= \int_{0}^{2} e^{tx} f_X(x)\:dx \\
		 &= \frac{3}{8}\int_0^2 x^2e^{tx}\:dx \\
	&= \frac{3}{8}\biggr[
	\frac{x^2}{t}e^{tx} - \frac{2x}{t^2}e^{tx} + \frac{2}{t^3}e^{tx}	 
		 \biggr]_{x = 0}^{x = 2} \\ \\
	&= \frac{3}{8}\frac{e^{2t}(4t^2 - 4t + 2) - 2}{t^3}\\
\end{align}
$$
How nice.

### 3
Let X be a continuous random variable with values in $[0,1)$ and density $f_X$. Find the moment generating functions for X given $f_X$:

$$f_X = 2e^{-2x}$$

Then 
$$
\begin{align}
g(t) &= E(e^{tX}) \\
	 &= \int_{-\infty}^{+\infty}e^{tx}f_X\:dx\\
	 &= \int_{0}^{\infty}e^{tx}\cdot2e^{-2x}\:dx
	 \\
	 &= 2\int_{0}^{\infty}e^{tx-2x}\:dx\\
	 &= 2\int_{0}^{\infty}e^{x(t-2)}\:dx\\
	 &= 2\int_{0}^{\infty}e^{x(t-2)}\:dx\\
	 &= \lim_{b\to\infty}\frac{2}{t-2}\biggr[e^{x(t-2)}\biggr]_{x=0}^{x=b} \\
	^* &= 
	\lim_{b\to\infty}\frac{2}{t-2}\biggr[e^{b(t-2)} - 1\biggr] \\
	&= \frac{2}{2-t}
	 
\end{align}
$$

\* Conditional Convergence: $t \lt 2$

We can generalize this problem for any exponential parameter $\lambda$ 
$$
M(t) = \frac{\lambda}{\lambda - t}
$$

For any $t \lt \lambda$

### 7
Let $X$ be a continuous random variable with values in $[0, 1]$, uniform density function $f_X(x) = 1$ and moment generating function $g(t) = (e^t − 1)/t$. Find in terms of $g(t)$ the moment generating function for

+ $-X$
+ $1+X$
+ $3X$
+ $aX+b$

**Part 1**
Let $Y = -X$
Then,
$$
\begin{align}
	g_Y(t) &= E(e^{Yt})\\
		&= E(e^{-Xt}) \\ \\
		&= g_X(-t) \\
		&= \frac{e^{-t} - 1}{-t}
\end{align}
$$

**Part 2**
Let $Y = 1+X$
Then,
$$
\begin{align}
	g_Y(t) &= E(e^{Yt})\\
		&= E(e^{(1+X)t}) \\ 
		&= e^{t}E(e^{tX}) \\ \\
		&= e^{t}g_X(t)\\
		&= e^t\frac{e^t - 1}{t}
\end{align}
$$

**Part 3**
Let $Y = 3X$
Then,
$$
\begin{align}
	g_Y(t) &= E(e^{Yt})\\
		&= E(e^{3Xt}) \\ \\
		&= g_X(3t)\\
		&= \frac{e^{3t} - 1}{3t}
\end{align}
$$

**Part 4**
Let $Y = aX+b$
Then,
$$
\begin{align}
	g_Y(t) &= E(e^{Yt})\\
		&= E\biggr(e^{(aX+b)t}\biggr) \\ 
		&= E(e^{aXt + bt})\\
		&= e^{bt}E(e^{aXt}) \\ \\
		
		&= e^{bt}g_X(at)\\
		&= e^{bt}\frac{e^{at} - 1}{at}
\end{align}
$$