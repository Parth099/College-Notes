# Finals Function Practice
Recall the following
1. $f$ is an left inverse iff $f$ is *one-to-one*
2. $f$ has a right inverse iff $f$ is *onto*

## Composition 
For each function find $f \circ g$ and $g \circ f$

$$
\begin{align}
	(1) \:\: f, g &: \mathbb{R} \to \mathbb{R} \\ \\
	f(x)&= x^2 - 3x\\
	g(x)&= 3x-2 
	\\ \\
	(2) \:\: f, g &: \mathbb{Z} \to \mathbb{Z} \\ \\
	f(n)&= 2n + 3\\
	g(n)&= \begin{cases}
		2n-1 &\text{if}& n \:|\: 2 \\
		n + 1 &\text{if}& n \nmid 2
	\end{cases}
	
\end{align}
$$

Work for: **(1)**

$$
\begin{align}
	f \circ g &= f\biggr((g(x))\biggr) \\
	&= f(3x-2) \\
	&= (3x-2)^2 - 3(3x-2) \\
	&= 9x^2 - 12x + 4 - 9x + 6 \\
	&= 9x^2 -21x + 10
\\ \\ 
	g \circ f &= g\biggr((f(x))\biggr) \\
	&= g(x^2 - 3x) \\
	&= 3(x^2 - 3x)-2 \\
	&= 3x^2 - 9x -2
\end{align}
$$

Work for **(2)**
$$
\begin{align}
	f \circ g &= f\biggr((g(n))\biggr) \\ \\
	
 f(g(n)) &= \begin{cases}
		2(2n-1) + 3 &\text{if}& n \:|\: 2 \\
		2(n+1) + 3 &\text{if}& n \nmid 2
	\end{cases} 
	\\
	&= \begin{cases}
		4n+1 &\text{if}& n \:|\: 2 \\
		2n+5 &\text{if}& n \nmid 2
	\end{cases} 

\\ \\ \\ 

	g\circ f &= g(f(n)) \\
			 &= g(2n+3) \\
		 ^{*}&= (2n+3) + 1 \\
		 	 &= 2n+4
\end{align}
$$

\*: $2n+3$ is always odd for any integer $n$
## Function Problem Set
### Q1
$$
\begin{align}
	f : \mathbb{Z} &\to \mathbb{Z} \\
	f(n) &= 3n+5
\end{align}
$$

**Q1:** Show $f$ is *one-to-one*

Suppose $f(a_1) = f(a_2)$
Then, $3a_1+5 = 3a_2+5$ and subsequently $3a_1 = 3a_2$.
Thus, $a_1 = a_2$.

Therefore $f$ **is** *one-to-one*

**Q2:** Show $\text{ran}(f) = \{a\in\mathbb{Z}: 2 \equiv a \text{ mod } 3\}$. Then draw a conclusion on whether $f$ is *onto* or not. 

Proof:

Suppose $k \in \text{ran}(f)$
Then $k = 3n+5$ for some $n \in \mathbb{Z}$

Then, $k-2 = 3n+3 = 3(n+1)$
Since $3|3(n+1)$, $3|(k-2)$
Thus, $2\equiv k \text{ mod } 3$ and $k \in \{a\in\mathbb{Z}: 2 \equiv a \text{ mod } 3\}$

Thus, $\text{ran}(f) \subseteq \{a\in\mathbb{Z}: 2 \equiv a \text{ mod } 3\}$

> Now we must prove the *proposed* image is the subset of the range

Conversely suppose $k \in \{a\in\mathbb{Z}: 2 \equiv a \text{ mod } 3\}$

Then $k \equiv 2 \text{ mod } 3$ and $3|k-2$

Then $k-2 = 3m$ for some integer $m$ and $3m+2 = k$

Let $n = m - 1$, then $n \in \mathbb{Z}$

Then,
$$
f(n) = 3n+5 = 3(m-1) + 5 = 3m+2 = k
$$

> This just showed $k$ can be produced by the function

Thus $k \in \text{ran}(f)$
Thus the two sets are equal. 

*Onto Status*:
This function is not onto since $\{a\in\mathbb{Z}: 2 \equiv a \text{ mod } 3\} \neq \mathbb{Z}$. For example $0 \in \mathbb{Z}$ yet $0 \not \in \text{ran}(f)$.

**Q3** Find a left inverse for $f$, call it $g$

There exists a left inverse since $f$ is *one-to-one*
Since $g$ is a left inverse $g(f(n)) = n$
for $g : \mathbb{Z}\to \mathbb{Z}$

Thus, 
$$
g(n) = \begin{cases}
	\frac{n - 5}{3} &\text{if}& 2 \equiv n \text{ mod } 3 
	\\
	1 &\text{if}& 2 \not\equiv n \text{ mod } 3 
\end{cases}
$$

**Q4** Find a right inverse for $f$, call it $g$

There exists no right inverse of $f$ because it is not onto. 

### Q2
$$
\begin{align}
	f : \mathbb{Z} &\to \mathbb{Z} \\
	f(n) &= \begin{cases}
		\frac{n}{2} & \text{n is even} \\
		\frac{1-n}{2} & \text{n is odd}
	\end{cases}
\end{align}
$$

**Claim** $f$ is not *one-to-one*
$f(0) = \frac{0}{2} = 0$ and $f(1) = \frac{1-1}{2} = 0$
Since $f(0) = f(1)$ but $0 \neq 1$, $f$ is not *one-to-one*

**Claim** $f$ is *onto*
Let $k$ be some integer. 
Then let $n = 2k$, then $n\in\mathbb{Z}$.


Since $2|n$, $f(n) = \frac{n}{2} = \frac{2k}{2} = k$

Thus, $\forall k \in\mathbb{Z}, \exists n\in\mathbb{Z}$ s.t $f(n) = k$
Therefore $f$ is *onto*. 

Using the results above we can conclude that:
1. $f$ has **no** left inverse
2. $f$ has a right inverse

**Work**: Finding a function $h:\mathbb{Z}\to\mathbb{Z}$ such that $f(h(n)) = n$

Let $h(n) = 2n$, $2n$ by definition *even*.
Then $f(2n) = \frac{2n}{n} = n$

Thus, $h(n) = 2n$
### Q3
Same as Q2 but $f$ is changed.
$$
\begin{align}
	f : \mathbb{N} &\to \mathbb{Z} \\
	f(n) &= \begin{cases}
		\frac{n}{2} & \text{n is even} \\ 
		\frac{1-n}{2} & \text{n is odd}
	\end{cases}
\end{align}
$$

*Observe* that if $n$ is even. Then $n$ is at least 2 and thus $f(n) = \frac{n}{2} \geq 1 \gt 0$.
If $n$ is odd. Then $n$ is at least 1 and $f(n) = \frac{n-1}{2} \leq \frac{1-1}{2} = 0$

Thus $f(n)$ has different signs when $n$ is odd or even.

**Claim**: $f$ is *one-to-one*
By the previous argument we notice that $f(a_1) = f(a_2)$ if $a_1, a_2$ are both either even or odd. 

***Case 1***: Both $a_1, a_2$ are even.

Then $f(a_1) = f(a_2)$ iff $\frac{a_1}{2} = \frac{a_2}{2}$.
Thus $a_1 = a_2$

***Case 2***: Both $a_1, a_2$ are odd.
Then $f(a_1) = f(a_2)$ iff $\frac{1-a_1}{2} = \frac{1-a_2}{2}$.
Then, $-a_1 = -a_2$.
Thus $a_1 = a_2$

Since $f(a_1) = f(a_2)$ if $a_1 = a_2$, $f$ is one-to-one. 

**Claim**: $f$ is onto
Let $m \in \mathbb{Z}$
If $m \geq 0$, let $n = 2m$.
Then $n \in \mathbb{N}$ and $n$ is even.

Then $f(n) = \frac{n}{2} = \frac{2m}{2} = m$

If $m \leq 0$. Let $n = 1-2m$
Then $n \geq 1$ and $n$ is odd. 
Then,  $f(n) = \frac{1-n}{2} = \frac{1-(1-2m)}{2} = m$

Thus, $\forall m \in \mathbb{Z}, \exists n \in \mathbb{N}$ s.t $f(n) = m$
Therefore, $f$ is *onto*.

**Bijection \& The Inverse**
Since $f$ is both *onto* and *one-to-one*, $f$ is *bijective*. 

Therefore, $f$ is a unique inverse.
This inverse is:
$$
f^{-1}(m) = \begin{cases}
	2m & \text{if} & m \gt 0 \\
	1-2m & \text{if} & m \leq 0 \\
\end{cases}
$$

## Function Book Problems
### p24.14
Try to find Left and Right inverses. 
#### Part 1
$$
\begin{align}
	f : \mathbb{Z} &\to \mathbb{Z} \\
	f(n) &= 2n
	
\end{align}
$$

**Claim**: $f$ is *one-to-one* 
Suppose $f(a_1) = f(a_2)$
Then $2a_1 = 2a_2$ and $a_1 = a_2$

Therefore $f$ is one-to-one

**Claim**: $f$ is not onto
Let $y = 1$
Then $y = 2n$ for $n=1/2$
Since $1/2 \not\in \mathbb{Z}$, $f$ is not onto. 

Thus we can conclude that only a left inverse exists: there exists a function $g:\mathbb{Z}\to\mathbb{Z}$ such that $g(f(n)) = n$

This function is:
$$
g(n) = \begin{cases}
	\frac{n}{2} &\text{if}& 2\:|\:n \\
	1 &\text{if}& 2\nmid n
\end{cases}
$$

#### Part 2
$$
\begin{align}
	f : \mathbb{Z} &\to \mathbb{Z} \\
	f(x) &= 10+x
	
\end{align}
$$

**Claim**: $f$ is *one-to-one*
Proof is trivial.

**Claim**: $f$ is *onto*

Suppose $y \in \mathbb{Z}$
Thus $y = x + 10$.
Then let $x = y - 10$. Since $y \in \mathbb{Z}$, $x  \in \mathbb{Z}$

Then, 
$$
f(x) = x+10 = y - 10 + 10 = y
$$

Therefore $\forall y\in\mathbb{Z}, \exists x\in\mathbb{Z}$ s.t $f(x) = y$

Since the function is bijective there exists one unique inverse. 
$$
g(x) = x - 10
$$

#### Part 3
$$
\begin{align}
	f : \mathbb{N} &\to \mathbb{N} \\
	f(x) &= 10+x
	
\end{align}
$$

**Claim**: $f$ is *one-to-one*
Proof is trivial.

**Claim**: $f$ is not onto. 
Suppose $y = 5$.
Then $f(x) = x+10 = y$ for $x=-5$.
Since $-5 \not\in \mathbb{N}$, $f$ is *not* onto. 

Since $f$ is only one-to-one it only has a left inverse. 

We can see that the image is: 
$$
\{x\in\mathbb{N}: x \gt 10\}
$$

Thus we can define a left inverse of $f$ as 
$$
g(x) = \begin{cases}
	x - 10 &\text{if}& x\gt 10 \\
	1 &\text{if}& x \leq 10 
\end{cases}
$$

#### Part 4
$$
\begin{align}
	f : \mathbb{Z} &\to \mathbb{Z} \\
	f(n) &= \begin{cases}
		\frac{n}{2} & \text{n is even} \\ 
		\frac{n-1}{2} & \text{n is odd}
	\end{cases}
\end{align}
$$

**Claim**: $f$ is not *one-to-one*

Consider $f(n) = 4$
Both $f(8) = \frac{8}{2}= 4$ and $f(9) = \frac{9-1}{2} = 4$
Since $8 \neq 9$, $f$ is not one-to-one

**Claim**: $f$ is *onto*
Let $m \in \mathbb{Z}$
Then let $n = 2m$, then $n$ is even and $n \in \mathbb{Z}$
Then, 
$$
f(n) = \frac{n}{2} = \frac{2m}{2} = m
$$

Thus, $\forall m \in \mathbb{Z}, \exists n\in\mathbb{Z}$ s.t $f(n) = m$
Therefore, $f$ is onto.

Since $f$ is only *onto* there exists only the right inverse: a function $g:\mathbb{Z}\to\mathbb{Z}$ where $f(g(n)) = n$

Let $g(n) = 2n$

Then $f(g(n)) = \frac{2n}{2} = n$



#### Part 5
> Recall that $\mathbb{Q} = \{\frac{a}{b}: a, b\in\mathbb{Z}, b\neq 0\}$

$$
\begin{align}
	f : \mathbb{Q} &\to \mathbb{Q} \\
	f(x) &= x^2
	
\end{align}
$$

**Claim** $f$ is not *one-to-one*

Consider $y = 9$
Then $f(3) = 9$ and $f(-3) = 9$.
since $3 \neq -3$, $f$ is not one-to-one

**Claim** $f$ is not *onto*

Consider $y = -1$
There exists no such rational $x$ such that $x^2 = -1$ since $x^2 \geq 0$ for any $x$. 

This function has no left or right inverse. 

### p26.9
Suppose $A$, $B$, and $C$ are sets and $f : A \to B$ and $g : B \to C$. Prove the following

***(a)***: If $f$ and $g$ are one-to-one, so is $g \circ f$
**Proof**:

Suppose $f, g$ are one-to-one. 
Then for any $a_1, a_2\in A$, $f(a_1) = f(a_2)$ iff $a_1 = a_2$.

Similarly, for any $b_1, b_2 \in B$, $g(b_1) = g(b_2)$ iff $b_1 = b_2$.

Thus $g(f(a_1)) = g(f(a_2))$

Therefore $g \circ f$ is one-to-one. 




***(b)***: If $f$ and $g$ are onto, so is $g \circ f$
**Proof**:

Suppose $f,g$ are onto.
Then for any $b\in B$ there exists an $a\in A$ such that $f(a) = b$

Similarly, for any $c \in C$ there exists a $b \in B$ such that $g(b) = c$  

Then $g(f(a)) = c$
Thus, $\forall c\in C, \exists a\in A$ s.t $g(f(a)) = c$. 
Therefore $g \circ f$ is also onto. 

### p26.11
The function $f$ is defined on set $A$,
$$
f: A\to A
$$

+ If $f$ is one-to-one, must $f$ be also onto?
+ If $f$ is onto, must $f$ be also one-to-one?

**Q1**
This is not true. Consider $f(n) = 3n+1$ over the integers. This function is one-to-one yet not onto, there exists no $n$ such that $f(n) = 0$

**Q2**
Consider the function $f(x) = x^3 + x^2$ over the real numbers. This function is onto, sadly this is quite hard to prove. However this function is *not* one-to-one since $f(0) = f(-1)$ and $0 \neq -1$


# Misc Items
## Equality of Sets
### HW2.3
Let $A = \{12n+11 : n\in \mathbb{Z}\}$ and $B = \{4m+3:m\in \mathbb{Z}\}$

Show that $A \subseteq B$

**Proof**:
Suppose $a \in A$
Then $a = 12n+11 = (12n+8)+3 = 4(3n+2)+3$
Let $m = 3n+2$, then $m\in\mathbb{Z}$

Now, $a = 4m+3$
Thus $a \in B$ and subsequently $A \subseteq B$

Consider the integer $3$, $3 \in B$ since $4(0)+3 = 3$.

Suppose $3 \in A$. Then $3 = 12n+11$ and $n = -\frac{2}{3}$. Since $-\frac{2}{3} \not\in\mathbb{Z}$, $3\not\in A$

Thus $A\subseteq B$ but $A\neq B$

### HW2.4
Let 
$$
\begin{align}
	A &= \{8n+36m:n, m\in\mathbb{Z}\}\\
	B &= \{a \in\mathbb{Z}: 4|a\}
\end{align}
$$
**Show** $A=B$

Suppose $a \in A$
Then $a = 8n+36m$ for integers $n, m$.
See that $a = 4(2n+9m)$
Since $4|a$, $a \in B$
Thus $A \subseteq B$

Suppose $b \in B$
Then $4| b$ and $b = 4k$ for some integer $k$

See that $4 = 8(5) + 36(-1)$
Thus $4k = [8(5) + 36(-1)]k = 8(5k)+36(-k)$

Let $n = 5k$ and $m = -k$.
Since $k \in \mathbb{Z}$, $n, m\in\mathbb{Z}$
Thus $b = 8n+36m$ and subsequently $b \in A$.
Thus $B \subseteq A$

Since $A \subseteq B$ and $B \subseteq A$, $A = B$
### HW2.5
Let 
$$
\begin{align}
	A &= \{(x, y)\in\mathbb{R}^2: y=3x - 4\}\\
	B &= \{(1 + t, -1 + 3t): t\in \mathbb{R}\}
\end{align}
$$

**Show** $A=B$

Suppose $(x, y) \in A$
Then $y = 3x - 4$ for real numbers $x, y$
Let $t = x - 1$.
Then $t \in \mathbb{R}$ and $x = t+1$
Then $y = 3x-4 = 3(t+1)-4 = 3t-1$
Thus $(x, y)\in B$

Hence $A \subseteq B$

Suppose $(x, y) \in B$
Then, 
$$
\begin{align}
	x &= 1+t \\
	y &= -1+3t
\end{align}
$$
for a real number $t$

Then $t = x - 1$
Then $y = -1+3t = -1+3(x-1) = 3x - 4$

Thus $(x, y) \in A$
Thus $B \subseteq A$

Since $A \subseteq B$ and $B \subseteq A$, $A = B$

### p10.10 with Generalization
Let 
$$
\begin{align}
	A &= \{x\in\mathbb{Z}: 4|x\}\\
	B &= \{x \in\mathbb{Z}: 2|x\}
\end{align}
$$
**Show** $A \subseteq B$

Suppose $a \in A$
Then $4|a$ and thus $a = 4n$ for an integer $n$. 

See that $a = 4n = 2(2n)$. 
Since $2n \in \mathbb{Z}$, $2|a$.

This means that $a\in B$
Therefore $A \subseteq B$

## Induction
### Recurrence Relation Proof
Recurrence Details:
$$
\begin{align}
	c_0 &= 3 \\
	c_n &= c_{n-1} + n \text{ for } n \gt 0\\
	\\
	\text{Prove that } c_n &= \frac{n^2+n+6}{2} 
\end{align}
$$

For $n = 0$, 
$$c_0 = \frac{0^2+0+6}{2} = 3$$
Thus the formula is valid for $c_0$.

Assume $c_n = \frac{n^2+n+6}{2}$ for some $n \geq 0$

Then, 
$$
\begin{align}
	c_{n+1} &= c_{n} + (n+1) \\
			&= \frac{n^2+n+6}{2} + n+1 \\
			&= \frac{n^2+n+6 + 2n + 2}{2} \\
			&= \frac{(n^2 + 2n + 1) + (n + 1) + 6}{2} \\
			&= \frac{(n + 1)^2 + (n + 1) + 6}{2} \\
\end{align}
$$

Therefore, for all $n \gt 0$, $c_n = \frac{n^2+n+6}{2}$ if $c_{n} = c_{n-1}+n$ and $c_0 = 3$

## Quantifiers
### 11.4
For each of the statements prove or disprove them. Context: $x, y \in \mathbb{Z}$

![[c11p4.png]]

***a)***
Let $x, y = 5$
Then $x + y = 10 \neq 0$
Thus the statement is not true for all integers $x, y$

***b)***
Let $x \in \mathbb{Z}$ and let $y = -x$. Then $y \in \mathbb{Z}$
Then $x + y = x + (-x) = 0$ 
Therefore $\forall x \: \exists y$ s.t $x+y = 0$

***c)***
Let $x$ an arbitrary integer. Then let $y = -x + 1$. Then $y$ is also an integer. 

Their sum, $x+y = x+(-x+1) = 1 \neq 0$

Since there exists a counter example, the statement is untrue. 

***d)***
Trivial. Take $y = -x$ for any $x$

***e)***
Let $x = y = 1$
Then $xy = 1$ and the statement is false. 

***f)***
Let $x$ be a arbitrary integer. Let $y = 0$.

Then $xy = 0$ 
Therefore $\forall x \: \exists y$ s.t $xy = 0$

***g)***
Let $x = 0$ and $y$ an arbitrary integer. Then $xy = 0$.

Therefore $\exists x \: \forall y$ s.t $xy = 0$

***h)***
Let $x = y = 0$
Then $xy = 0$

Therefore $\exists x \: \exists y$ s.t $xy = 0$

### 11.7
For each of the statements prove or disprove them. Context: $x, y \in \mathbb{Z}$

> Recall $\exists !$ means "there exists unique"

![[c11p7.png]]

***a)***
True. Since $-2 \not \in \mathbb{N}$ or any other complex numbers. 

***b)***
False. Both $2, -2$ squared make 4. Therefore $x$ is not unique.

***c)***
False. There exists no whole number who's square is $3$. See that $1^2 = 1$ and $2^2 = 4$ and there exists no natural number between $1$ and $2$. 

***d)***
True. Only $0$ has this effect.

***e)***
True. Only $1$ has this effect.

## Divisibility
### HW4.1
**Statement**
Show that 
$$
\gcd (a, a+3) = \begin{cases}
	3 &\text{if}& 3\:|\:a \\
	1 &\text{if}& 3\nmid a
\end{cases}
$$
for any integer $a$

**Proof**
Let $d = \gcd (a, a+3)$. Then $d|a$ and $d|a+3$.
This implies that $d|(a+3)-a = 3$
Since $d \gt 0$ and $3$ is *prime*, $d$ must be 1 or 3.

Suppose $3|a$, 
Then $a = 3n$ for some integer $n$. 
Then $a+3 = 3n+3 = 3(n+1)$. Since $n+1\in\mathbb{Z}, 3|a+3$

$1$ also divides $a, a+3$ but because $1\lt 3$, $d = 3$ 

Suppose $3 \nmid a$
Then $d \neq 3$ since $3 \nmid a$.
Thus $d = 1$

Therefore, 
$$
\gcd (a, a+3) = \begin{cases}
	3 &\text{if}& 3\:|\:a \\
	1 &\text{if}& 3\nmid a
\end{cases}
$$