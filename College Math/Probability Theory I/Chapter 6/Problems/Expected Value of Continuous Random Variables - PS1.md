# Expected Value of Continuous Random Variables - PS1
## 1
![[cp6_3p1.png]]
### a)
$$
\begin{align}
	\int_{-1}^{+1} x f_X(x) \mathop{dx} &= \int_{-1}^{+1} x \frac{1}{2} \mathop{dx} \\
	&= \frac{1}{4} x^2\biggr|_{-1}^1
	&= 0
\end{align}
$$
This result is expected
$$
\begin{align}
	E(X^2) = \int_{-1}^{+1} x^2 f_X(x) \mathop{dx} &= \int_{-1}^{+1} x^2 \frac{1}{2} \mathop{dx} \\
	&= \frac{1}{6} x^3\biggr|_{-1}^1 \\
	&= 1/3
\end{align}
$$
Then
$$V(X) = 1/3 - 0^2 = 1/3$$



### b)
$$
\begin{align}
	\int_{-1}^{+1} x f_X(x) \mathop{dx} &= \int_{-1}^{+1} x |x| \mathop{dx} \\
\end{align}
$$
Recall the definition of an odd function 
$$f(-x) = -f(x)$$
The function $g(x) = x|x|$ is by definition odd.
Thus
$$\int_{-1}^{+1} x |x| \mathop{dx} = 0$$


$$
\begin{align}
	E(X^2) = \int_{-1}^{+1} x^2 |x| \mathop{dx} &= 2\int_{0}^{+1} x^2 |x| \mathop{dx} \\
	&= \frac{1}{2}
\end{align}
$$

Then $V(X) = \frac{1}{2}$

### c)
$$
\begin{align}
	\int_{-1}^{+1} x (1-|x|) \mathop{dx} = 0
\end{align}
$$
Verified that this function is odd and thus $\mu = 0$

Since $\mu = 0$
$$\sigma^2 = \int_{-1}^{+1} x^2 (1-|x|) \mathop{dx}$$

Since $f(x) = f(-x)$, this function is even, 
$$
\begin{align}
	\int_{-1}^{+1} x^2 (1-|x|) \mathop{dx} &= 2\int_{0}^{+1} x^2 (1-|x|) \mathop{dx} \\
	&= 2\int_{0}^{+1} x^2 - x^3 \mathop{dx} \\
	&= 2 \biggr[\frac{x^3}{3} - \frac{x^4}{4}\biggr]_{x=0}^{x=1}
	&= \frac{1}{6}
\end{align}
$$

### d)
Trivial since we can see that 
$$xf_X(x) = x^3\frac{2}{3} \ \text{ is odd}$$


## 4
![[cp6_4p4.png]]

### a)
$$
\begin{align}
	\int_{-1}^{+1} ax+b \mathop{dx} &= \int_{-1}^{+1} ax \mathop{dx} + \int_{-1}^{+1} b \mathop{dx} \\
	&= 0^* + 2b
	
\end{align}
$$

\* - function was odd
Since $2b = 1$, $b = 1/2$

### b)
See that $\int_{-1}^{+1} ax+b \mathop{dx} = 0$ has no regard for the constant $a$, yet $b$ is fixed at $1/2$ . 

$$f_X(x) = ax + \frac{1}{2} \geq 0$$
Since it is a linear function we can simply watch its endpoints. 

At the low end $x = -1$ and  to force $f_X(x)\geq 0$, $x \geq -\frac{1}{2}$
At the high end $x = 1$ and  to force $f_X(x)\geq 0$ and $f_X(x) \leq 1$, $x \leq \frac{1}{2}$

With these facts, we can show that
$$-\frac{1}{2}\leq a \leq \frac{1}{2}$$
%%TBF%%

### c)
$$
\begin{align}
	\int_{-1}^{+1} x(ax+b) \mathop{dx} &= \int_{-1}^{+1} ax^2 + bx \mathop{dx} \\
	&= \biggr[a\frac{x^3}{3}+b\frac{x^2}{2}\biggr]_{x = -1}^{x = 1}
	\\\\
	\mu &= a\frac{2}{3}
\end{align}
$$
And we can use $b)$ to show that
$$-1/3 \leq\mu\leq 1/3$$

### d)
$$
\begin{align}
	\int_{-1}^{+1} x^2 (ax+b) \mathop{dx} &= \int_{-1}^{+1} ax^3 + bx^2 \mathop{dx} = ^*\int_{-1}^{+1} bx^2 \mathop{dx} \\
	&= b\biggr[\frac{x^3}{3}\biggr]_{x = -1}^{x = 1} \\
	&= b\frac{2}{3} \\
	^{**} &= \frac{1}{3}
\end{align}
$$
\* - $ax^3$ is odd 
\*\* - $b = 1/2$

Now that we have 
$$
\begin{align}
	   \mu &= \frac{2}{3}a \\
	E(X^2) &= \frac{1}{3} \\\\
	
	\sigma^2(X) = \frac{1}{3} - \frac{4}{9}a^2 
\end{align}
$$

## 9
![[cp6_4p9.png.png]]
%%TBF%%

---
<!--
[TEMP]
$$
\begin{align}
	\int_{-1}^{+1} x f_X(x) \mathop{dx}
\end{align}
$$
-->
