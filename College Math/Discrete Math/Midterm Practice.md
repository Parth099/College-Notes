# Midterm Practice
## Inequalities
### Problem 1
Let $a, b, c, \dotso$ be an elements of an ordered field. Show the following
#### P1 - Part A
**Statement**

If $a < b$ and $c > d$, then $a − c < b − d$.

**Proof**:
Suppose $a < b$ and $c > d$.
Then $b-a\gt0$ and $c-d\gt0$
Due to additive closure, $b-a+c-d\gt0$
Observe that
$$
b-a+c-d = b-d-a+c = (b-d) - (a-c)
$$

Since $(b-d) - (a-c)\gt 0$, $a-c\lt b-d$.

#### P1 Part B
**Statement**

Prove If $0 < a < 1$, then $a^2 < a$

**Proof**

Suppose $0 < a < 1$
Due to multiplicative closure and the fact that $a \gt 0$, if  $0\lt a$ then $0 \lt a^2$.

By the same idea, if $a\lt 1$ then $a^2 \lt a$
Thus, $a^2 \lt a$ if $0 < a < 1$

#### P1 Part C
**Statement**

If $b, d\gt 0$ and $\frac{a}{b}\lt\frac{c}{d}$ then show that
$$
\frac{a}{b} \lt \frac{a+c}{b+d} \lt \frac{c}{d}
$$

**Proof**

Suppose $b, d\gt 0$
Consider $\frac{a}{b}\lt\frac{c}{d}$
Then, 
$$
\frac{c}{d} - \frac{a}{b} = \frac{bc-ad}{bd} \gt 0
$$

Since $b, d\gt 0$, $bc-ad\gt 0$

Consider $\frac{c}{d} -  \frac{a+c}{b+d}$.

Then, 
$$
\begin{align}
	\frac{c}{d} -  \frac{a+c}{b+d} &=
	
	\frac{c(b+d)-(a+c)d}{d(b+d)}
	\\
	&= \frac{bc+dc-ad-cd}{d(b+d)}
	\\
	&= \frac{bc-ad}{d(b+d)}
\end{align}
$$

Since $b, d\gt 0$, $d(b+d)\gt 0$
Since $d(b+d)\gt 0$ and $bc-ad\gt0$, 
$$
\frac{c}{d} -  \frac{a+c}{b+d} \gt 0
$$

Thus, $\frac{c}{d} \gt  \frac{a+c}{b+d}$


Consider $\frac{a+c}{b+d}-\frac{a}{b}$.
Then, 
$$
\begin{align}
	\frac{a+c}{b+d}-\frac{a}{b}
	&= \frac{b(a+c) - a(b+d)}{b(b+d)}
	
	\\
	
	&= \frac{ba+bc - ab-ad}{b(b+d)} \\
	
	&= \frac{bc-ad}{b(b+d)}
\end{align}
$$

Since $b, d \gt 0$, $b(b+d)\gt 0$
Since $b(b+d) \gt 0$ and $bc-ad\gt0$, 
$$
\frac{a+c}{b+d}-\frac{a}{b} \gt 0
$$
Thus $\frac{a+c}{b+d} \gt \frac{a}{b}$

Therefore, 
$$
\frac{a}{b} \lt \frac{a+c}{b+d} \lt \frac{c}{d}
$$

### Problem 2
Let $F$ be an ordered field and let $$F_{\geq0} = \{x \in F : x > 0 \lor x = 0\}$$

#### P2 Part 1
**Statement**

Show $F_{\geq0}$ is closed under addition and multiplication.  

**Proof**

Let $x, y \in F_{\geq0}$

Suppose both $x, y \in F^+$
Then $x+y \in F^+$ and $xy\in F^+$
Thus $x+y, xy\in F_{\geq0}$

Say one of $x, y$ say $y$ is $0$
Then $x+y = x \in F^+$ and $xy = 0$
Then $x+y, xy\in F_{\geq0}$

If both $x, y$ are $0$ then $x+y = 0$ and $xy = 0$. Then $x+y, xy\in F_{\geq0}$

Therefore $\forall x, y\in F_{\geq0}$, $x+y, xy \in F_{\geq0}$

#### P2 Part 2
![[midterm_prac_q2.png]]

**a)**

Suppose $x\leq y$ and $y\leq z$
Then $y-x\geq 0$ and $z-y\geq 0$
Due to closure, $(z-y)+(y-x) = z-x \geq 0$

Thus, $x\leq z$

**b)**

Suppose $x\leq y$ and $z\in F$
Them $y-x\leq 0$
See that $y+z-z-x = (y+z)-(x+z)\geq 0$
Thus, $x+z\leq y+z$

**c)**

Suppose $x\leq y$ and $z\geq 0$
Then $y-x\geq 0$
Due to closure $z(y-x) = yz-xz\geq0$
Thus, $xz\leq yz$

### Problem 3
Show that $$\forall x\in\mathbb{R}, x+\frac{1}{4x}\geq1$$

Consider the figure $x+\frac{1}{4x} - 1$
Then, 
$$
\begin{align}
	x+\frac{1}{4x} - 1 &= \frac{4x^2-4x+1}{4x} \\\\
	&= \frac{(2x-1)^2}{4x}
\end{align}
$$

See that $(2x-1)^2 \geq 0$ for any $x$
Since $x\geq0$, $\frac{1}{4x}\gt 0$

Since both $(2x-1)^2 \geq 0$ and $\frac{1}{4x}\gt 0$, $x+\frac{1}{4x} - 1 \geq 0$

Thus, $\forall x\in\mathbb{R}, x+\frac{1}{4x}\geq 1$

### Problem 4
**Statement**

Find all $x\in\mathbb{R}$ such that $$\frac{2}{x+1} \lt x$$

**Work**

$\frac{2}{x+1} \lt x$ if and only if $x-\frac{2}{x+1}\gt0$
Then, 
$$
\begin{align}
	x-\frac{2}{x+1} &= \frac{x(x+1) - 2}{x+1} \\
	&= \frac{x^2+x-2}{x+1} \\
	&= \frac{(x+2)(x-1)}{x+1} 
\end{align}
$$

The sign of $\frac{1}{x+1}$ depends on $x+1$

Flag Diagram:
![[midterm_prac_q4_flag.png]]

This $\frac{2}{x+1} \lt x$ on the interval $(-2, 1)\cup(1, \infty)$

## Divisibility 
### Problem 1
Find $N$ that make the following true. 

![[midterm_div_q1.png]]

**a)**

$$100\text{ div } N = 5$$
In the context of the division algorithm we are looking for all $N\in\mathbb{Z}$ such that 
$$
100 = 5N + r \text{ for } 0\leq r \lt N
$$

Then $100 = 5N + r \geq 5N + 0 = 5N$
Thus $N \leq 20$

Also, $100 = 5N+r \lt 5N+N = 6N$
Thus, $N \gt 16\frac{2}{3}$

Thus $17\leq N \leq 20$

**b)**

$$N \text{ div } 10 = 5$$

We must find all integers $N$ such that $$N = 50+r\text{ for } 0\leq r \lt 10$$

Since $0\leq r \lt 10$, $50\leq r+50 \lt 60$

Thus, $50\leq N \lt 60$

**c)**

$$100\text{ mod } N = 5$$

We must find all integers $N$ such that 
$$100 = Nq + 5$$

This is the same as $Nq = 95$
The divisors of $95$ are: 
$$
\{
	1, 5, 19, 95
\}
$$

We know the remainder is $5$ so $1, 5$ are not valid values for $N$.

This $N\in\{19, 95\}$

**d)**

$$N\text{ mod } 10 = 5$$

In the context of the Division Algorithm we need to find all values of $N$ such that $N=10q+5$

Thus, $N\in\{10q+5: q\in\mathbb{Z}\}$

### Problem 2
**Statement**
Show that consecutive integers are coprime. 

**Proof**
Let $n\in\mathbb{Z}$. Then $n+1$ is the next number. 

Let $d = \gcd{(n, n+1)}$
Them $d|n$ and $d|(n+1)$
Thus, $d|(n+1)-(n) = 1$

Since $d\gt 1$ and $d|1$ then $d = 1$
Since $\gcd{(n, n+1)} = 1$, $n, n+1$ are relatively prime. 

### Problem 3
**Statement**

Show that for any integer $a$, $2a+1$ and $4a^2+1$ are relatively prime. 

**Proof**

Let $d = \gcd(2a+1, 4a^2+1)$
Then $d|(2a+1)$ and $d|(4a^2 + 1)$

Since $a\in\mathbb{Z}$, $2a-1\in\mathbb{Z}$

Then $d|(4a^2+1)- (2a+1)(2a-1) = 2$
Thus, $d|2$

Since $d\gt0$, $d = 1$ or $d = 2$

Since $2\nmid2a+1$ for any integer $a$, $d\neq 2$. 

Therefore $\gcd(2a+1, 4a^2+1) = 1$ and by extension $2a+1, 4a^2+1$ are relatively prime.

## Modular Arithmetic 
### Problem 1
**Statement**

In the context of $\mathbb{Z}_{11}$ find $x$ such that 
$$[\:3\:][\:x\:] = [\:4\:]$$

Then, $[\:x\:] = [\:3\:]^{-1}[\:4\:]$

We need to find a n such that $[\:3\:][\:b\:] = [\:3b\:]= [\:1\:]$

Thus $3b \equiv 1 \text{ mod }11$
Then $11|(1-3b)$ and $11n = 1-3b$ for some integer $n$

Thus, $1 = 11n+3b$
Via the Euclidean algorithm these numbers are $n=2$ and $b=-7$

Thus $1 = -7*3 \text{ mod }11$
Thus $[\:3\:]^{-1} = [\:-7\:] = [\:4\:]$

Finally, $[\:x\:] = [\:4\:][\:4\:] = [\:16\:] = [\:5\:]$
## Functions
### Problem 1
Determine if each set is a function and find their respective domain/range:


![[midterm_functions_q1.png]]

**b)**

Let $(x, y)\in f$ and $(x, z)\in f$
Then $y = 2x$ and $z = 2x$
Then $y = 2x = z$
Therefore $f$ is a function

$$
\begin{align}
	\text{dom }f &= \mathbb{Z} \\
	\text{im }f &= \{x\in\mathbb{Z}: 2|x\}
\end{align}
$$

**c)**

For all $x\in\mathbb{Z}$ there exists a single unique integer $y$ such that $x+y=0$. This integer $y$ is namely $-x$

Thus, $f$ is a function.

$$
\begin{align}
	\text{dom }f &= \mathbb{Z} \\
	\text{im }f &= \mathbb{Z}
\end{align}
$$

**d)**

Let $x = 0$
Then $(x, 1)\in f$ since $0\cdot1=0$ *and* $(x, 5)\in f$ since $0\cdot5=0$ 

Since there exists more than one value for $x$ in $f$, $f$ is not a function. 

**e)**

Suppose $(x, y)\in f$ and $(x, z)\in f$.
Then $y=x^2$ and $z = x^2$

Since $y=z=x^2$, $f$ is a function. 

$$
\begin{align}
	\text{dom }f &= \mathbb{Z} \\
	\text{im }f &= \{x^2: x\in\mathbb{Z}\}
\end{align}
$$

**g)**

Let $x=0$
Then $(x, 1)\in f$ since $0^2+1^2 = 1$ and $(x, -1)\in f$ since $0^2 + (-1)^2 = 1$.

Since $-1\neq 1$, $f$ is not a function. 

**h)**

Suppose $x = 2$
Then $(x, 4) \in f$ since $2|4$ and $(x, 6) \in f$ since $2|6$

Since $4\neq 6$, $f$ is not a function.

### Problem 2
Find the image of each:

![[midterm_functions_q2.png]]

**a)**

$$
\text{im }f = \{x\in{\mathbb{Z}}: 2|x\}
$$

**b)**

$$
\begin{align}
	\text{im }f &= \{|x|:x\in{\mathbb{Z}}\}
	\\
	&= \{x\in{\mathbb{Z}}: x\geq0\}
	\\
	&= \mathbb{Z}^{+} + \{0\}
\end{align}
$$

I would have just put $\mathbb{N}$ but ...

**c)**

$$
\text{im }f = \mathbb{Z}
$$

**d)**
$$f(x) = \frac{1}{x^2+1}$$
Then an element in the image would in the form $$\sqrt{\frac{1}{y} - 1}$$

<!-- ask about this -->

## Induction
### Problem 1
**Statement**

Show that for $n \geq 7, \:3^n \lt n!$

**Proof** 

For $n = 7$,  $3^7 = 2187$ while $7! = 5040$
thus the formula is valid for $n = 7$

Assume $3^n \lt n!$ for some $n\geq 7$
Then, $$3\cdot 3^n = 3^{n+1} \leq 3 \cdot n! \lt n \cdot n! = (n+1)!$$

Therefore, for all integers greater than $6$, $3^n \leq n!$ 

### Problem 2
Show that for all $n \geq 4$, $n^3 < 3^n$

For $n = 4$, $n^3 = 64$ while $3^4 = 81$
Since $64 \lt 81$ the formula is valid for $n = 4$.

Assume $n^3 < 3^n$ for some $n \geq 4$

Since $n\geq 4$, $\frac{1}{n}\leq \frac{1}{4}$

Thus, $$\biggr(1+\frac{1}{n}\biggr)^3 \leq \biggr(1+\frac{1}{4}\biggr)^3 = \frac{125}{64} \lt 3$$

Then, 
$$
(n+1)^3 = \biggr(1+\frac{1}{n}\biggr)^3n^3 \lt 3 \cdot 3^n = 3^{n+1}
$$

Therefore, $\forall n\geq 4, n^3 \lt 3^n$