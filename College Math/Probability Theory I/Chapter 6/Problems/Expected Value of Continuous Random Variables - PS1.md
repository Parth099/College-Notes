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
	&= \frac{2}{4}
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

At the low end $x = -1$ and  to force $0 \leq f_X(x) \leq 1$, $x \geq -\frac{1}{2}$
At the high end $x = 1$ and  to force $0 \leq f_X(x) \leq 1$ and $f_X(x) \leq 1$, $x \leq \frac{1}{2}$

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
## 10
![[cp6_4p10.png]]


### a)
Lets first find the distribution functions
It will be easier to find the CDF $F(r)$

$$
\begin{align}
	F(r) &= P(|X-Y| < r) \\
		 &= P(-r < X - Y <r) \\
		 &= P(-r+Y < X <r + Y) \\
\end{align}
$$
We Extract these two equations:
$$
\begin{align}
	y &\gt x - r \\
	y &\lt x + r
\end{align}
$$
We plot and see this
![[cp6_4p10_aid1.png]]
See that 
$$F(r) = 1 - (1 - r)^2 = 2r - r^2 \text{ on } r\in[0, 1]$$
$$\implies f(r) = 2 - 2r = 2(1-r)$$

Now that we have $f_r(r)$ we can get the expected value.

Since $r \in [0, 1]$
$$E(|X-Y|) = \int_0^1 rf_r(r) \ dr = \frac{1}{3}$$

### b)
$$E(W = \text{max(X, Y)})$$
Lets attain the CDF. 
I found this ingenious [online](https://math.stackexchange.com/questions/1114516/probability-density-function-of-maxx-y)

$$
\begin{align}
	F(w) &=^{*}\ P(\text{max(X, Y)} \lt w) \\
		 &=^{**} P(X \lt w \text{ and } Y \lt w) \\
		 &= P(X \lt w) P(Y \lt w) \\
		 &= w^2 \text { for } w\in[0, 1]
\end{align}
$$

$$
\implies f(w) =
\begin{cases} 
	2w & \text{ if } 0 \leq w \leq 1 \\
	0  & \text{otherwise}
\end{cases}
$$

\* - notice that for $\text{max(X, Y)} \lt w$ both $X$ and $Y$ must be less than $w$. Thus, 

\*\* - both are independent

$$
\begin{align}
E(\text{max(X, Y)}) &= \int_0^1 w f_W(w)\mathop{dw} \\
				    &= \int_0^1 2w^2 \mathop{dw} \\
					&= \frac{2}{3}\biggr[w^3\biggr]_{w=0}^{w=1} \\
					&= \frac{2}{3}
					
\end{align}
$$

### c)
We can attain $E(W = \text{min}(X, Y))$ the same way.

$$
\begin{align}
	F(w) &=\ P(\text{min}(X, Y) \lt w) \\
		 &= 1 - P(\text{min}(X, Y) \gt w) \\
     ^{*}&= 1 - P(X \gt w) P(Y \gt w) \\
	^{**}&= 1 - (1-w)^2 \\
		 &= 2w - w^2 \text { for } w\in[0, 1]
\end{align}
$$

\* - Check all possible ways the *min* can we less than $w$, its $3$
They are:
1. Both $x, y \tt w$
2. One of $x, y$ is less than $w$ (2 ways)

We can apply demorgans and flip in equality. 
$$
\implies f(w) =
\begin{cases} 
	2 - 2w & \text{ if } 0 \leq w \leq 1 \\
	0        & \text{otherwise}
\end{cases}
$$

We have already calculated this function: $wf_W(w)$ before:
$$\int_0^1 w(2-2w) \mathop{dw} = 1/3$$

---
<!--
[TEMP]
$$
\begin{align}
	\int_{-1}^{+1} x f_X(x) \mathop{dx}
\end{align}
$$
-->