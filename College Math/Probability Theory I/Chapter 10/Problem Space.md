## Discrete
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
$X$ is uniform on $\{n, n+1, \dotso, n+k\}$

$$p_X(x) = \frac{1}{n+k-n + 1} = \frac{1}{k+1}$$


%%MISCOUNT - NEEDS FIX %%
$$
\begin{align}
	g(t) &= \frac{1}{k}\sum_{j = n}^{n+k} e^{tj}\\
		 &= \frac{1}{k}\underbrace{(e^{tn}+ e^{t(n+1)} + \dotso + e^{t(n+k)})}_{k \text{ items}} \\
		 
		 &= \frac{e^{tn}}{k}\underbrace{(1 + e^{t} + \dotso + e^{tk})}_{k \text{ items}} \\
		 
		 &= \frac{e^{tn}}{k}\frac{e^{tk} - 1}{e^{t} - 1}
\end{align}
$$

<!--
TEMPLATE


$$
\begin{align}
	g(t) &= \sum_{k = 0}^n e^{tk}
\end{align}
$$

-->