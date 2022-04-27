# Functions of Random Variables
This note details the relation between Random Variables related by a function. 
## Theorem 
> Let $X$ be a continuous random variable and suppose a function $g(x)$ is **strictly** increasing on the range of $X$. 
> Let $Y = g(X)$. Suppose then that $X$ and $Y$ have CDFs named $F_Y$ and $F_X$. Then they are related by 
> 1) $$F_Y(y) = F_X(g^{-1}(y))$$
> 2) $$F_Y(y) = 1- F_X(g^{-1}(y))$$
> 
> $\# 2$ applies if $g(x)$ is strictly decreasing

Note: The range of $X$ **does not** transfer over to $Y$.

## Proof
> **Preface**
> See that we assert that $Y = g(x)$ is **strictly** increasing.
> This means that events:
> $$(g(X) \leq y) = (X \leq g^{-1}(y))$$

### Proof: $g(x)$ is increasing

### Proof: $g(x)$ is decreasing

%%TBA%%
## Examples
### EX - 1 : Non Conforming
> $$Y = X^2 \implies g(x) = x^2$$

$$
\begin{align}
F_Y(y) &= P(Y \leq y) \\
&= P(X^2 \leq y) \\
^{*}&= P(-\sqrt{y}\leq X \leq \sqrt{y}) \\
&= P(X \leq \sqrt{y}) - P(X \leq -\sqrt{y}) \\
&= F_X(\sqrt{y}) - F_X(-\sqrt{y}) \\
&= 2\sqrt{y}
\end{align}
$$
#### EX1 - Details 
\* : This split is caused as $\sqrt{p} = \pm q$

### EX - 2 
> $U$ is uniform distributed on $[0, 1]$

Find CDF for the following:
$$
\begin{align}
	(a)\ Y &= U + 2\\
	(b)\ Y &= U^3
\end{align}
$$
---
***a)***
$$
\begin{align}
	F_Y(y) &= P(Y \leq y)\\
		   &= P(U + 2 \leq y) \\
		   &= P(U \leq y - 2) \\
		   &= \boxed{y - 2}
\end{align}
$$
Notice  $U \in [0, 1] \implies y - 2 \in [0, 1] \implies y \in [2, 3]$

%%CFD OUT%%

$$
F_Y(y) = 
\begin{cases}
	0 & \text{if} & y \lt 2 \\
	y - 2 & \text{if} & 2 \leq y \leq 3 \\
	1 & \text{if} & y \gt 3 \\ 
\end{cases}
$$
$$
\implies f(y) = 1
$$

Since $Y$ is just a shift of $U$, $f(y) = 1$ makes total sense.

---
***b)***
$$
\begin{align}
	F_Y(y) &= P(Y \leq y)\\
		   &= P(U^3 \leq y)\\
	   ^{*}&= P(U \leq \sqrt[3]{y})\\
	  ^{**}&= \sqrt[3]{y} 
\end{align}
$$

\* - $3$rd roots are unique.
\*\* - This seems intuitive for an increasing function $f(y)$. We know that $U\in[0, 1]$. The length of the interval is $1$. Now how many $U\in[0, 1]\leq f(y)$?. It is how long $[0,f(y)]$ is. 

$$
F_Y(y) = 
\begin{cases}
	0 & \text{if} & y \lt 0\\
	\sqrt[3]{y} & \text{if} & 0 \leq y \leq 1\\
	1 & \text{if} & y \gt 1\\
\end{cases}
$$

$$\dfrac{d}{dy}F_Y(y) = f_Y(y)$$
$$
\implies 
f_Y(y) = 
\begin{cases}
	\frac{1}{3}x^{\frac{2}{3}} & \text{if} & 0 \leq y \leq 1\\
	0 & \text{otherwise}\\
\end{cases}
$$
---
### EX - 3
> $U$ is uniform distributed on $[0, 1]$

Find CDF for the following:
$$
\begin{align}
	(a)\ Y &= \frac{1}{U+1}\\
	(b)\ Y &= \log{(U+1)}
\end{align}
$$

---
***a)***
$$
\begin{align}
	F_Y(y) &= P(Y\leq y)\\
		   &= P(\frac{1}{U+1} \leq y)  \\
	  ^{*} &= P(\frac{1}{y} - 1\leq U) \\
	  	   &= 1 - P(U \leq \frac{1}{y} - 1) \\
		   &= 2 - \frac{1}{y}
\end{align}
$$

#### Details - Part(a)
\* - When dividing we must be careful to keep the flow of logic correct $A \iff B$. Now we know 

$$0\leq U \leq 1 \iff 1\leq U + 1 \leq 2 \iff \frac{1}{1} \geq \frac{1}{U + 1}\geq \frac{1}{2}$$
$$\implies y\in[\frac{1}{2}, 1]$$
Both vars remain positive and this we do not need to flip signs. 

$$
F_Y(y) = 
\begin{cases}
0 & \text{if} & y \lt \frac{1}{2}\\
2 - \frac{1}{y} & \text{if} & \frac{1}{2} \leq y \leq 1\\
1 & \text{if} & y \leq 1\\
\end{cases}
$$

$$\implies f_Y(y) = \frac{1}{y^2} \text{ for } y\in[\frac{1}{2}, 1] \text{ else } 0$$

---
***b)***
$$
\begin{align}
	F_Y(y) &= P(Y\leq y)\\
		   &= P(\log{(U+1)} \leq y)  \\
		   &= P(U \leq e^y - 1) \\
		   &= e^y - 1
\end{align}
$$
$$
0 \leq U \leq 1 \iff 1 \leq U+1 \leq 2 \iff 0 \leq \log{U+1} \leq \log{2}
$$

CDF:
$$
F_Y(y) = 
\begin{cases}
	0 & \text{if} & y \lt 0  \\
	e^y - 1 & \text{if} & 0 \leq y \leq \ln{2}  \\
	1 & \text{if} & y \gt \ln2 
\end{cases}
$$
---
### EX - 4 
> $U$ is uniform distributed on $[0, 1]$

Find CDF for the following:
$$
\begin{align}
	(a)\ Y &= |U - \frac{1}{2}|\\
	(b)\ Y &= {(U-\frac{1}{2})^2}
\end{align}
$$
---
***a)***
$$
\begin{align}
	F_Y(y) &= P(Y \leq y)\\
		   &= P(|U - \frac{1}{2}| \leq y)\\
		   &= P(-y + \frac{1}{2} \leq U \leq y + \frac{1}{2})\\
		   &= P(U \leq y + \frac{1}{2}) - P(U \leq -y + \frac{1}{2})\\
		   &=y + \frac{1}{2} - (-y + \frac{1}{2})\\
		   &= 2y\\
\end{align}
$$

$$
\implies F_Y(y)=
\begin{cases}
	0  & \text{if} & y \lt 0\\
	2y & \text{if} & 0 \leq y \leq \frac{1}{2}\\
	1  & \text{if} & y \gt \frac{1}{2}
\end{cases}
$$

$$
\implies f_Y(y) = 2 \text{ on } y\in[0, 1/2]
$$

This makes logical sense. 
See that $\frac{1}{2}$ is the highest output we can achieve on this function $g(U)$. Moreover there is 2 ways to make each data point based on the definition of $\text{abs()}$.

---
***b)***
$$
\begin{align}
	F_Y(y) &= P(Y \leq y)\\
		   &= P((U-\frac{1}{2})^2 \leq y)\\
		   &= P(-\sqrt{y} \leq U - \frac{1}{2} \leq +\sqrt{y})\\
		   &= P(-\sqrt{y}+ \frac{1}{2} \leq U  \leq +\sqrt{y} + \frac{1}{2})\\
		   &= P(U \leq +\sqrt{y} + \frac{1}{2}) - P(U \leq -\sqrt{y} + \frac{1}{2})\\
		   &= \sqrt{y} + \frac{1}{2} - (-\sqrt{y} + \frac{1}{2})\\
		   &= 2\sqrt{y}
\end{align}
$$

$$F_Y(y) = 2\sqrt{y} \text{ on } y\in[0, \frac{1}{4}]$$