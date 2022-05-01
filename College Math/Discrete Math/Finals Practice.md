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

**Claim**: $f$ is *one-to-one*

Suppose $f(a_1) = f(a_2)$

***Case 1***: Both $a_1, a_2$ are even.

Then, 
$$
\frac{a_1}{2} = \frac{a_2}{2}
$$
Thus $a_1 = a_2$

***Case 2***: Both $a_1, a_2$ are odd.
Then, 
$$
\frac{1-a_1}{2} = \frac{1-a_2}{2}
$$
Thus $1-a_1 = 1-a_1$ and $a_1 = a_2$

***Case 3***: One of $a_1, a_2$ is even, namely $a_1$. $a_2$ is odd. 

Then, 
$$
\begin{align}
	\frac{a_1}{2} &= \frac{1-a_2}{2} \\
	a_1 &= 1 - a_2 \\ \\
	a_1 + a_2 &= 1
\end{align}
$$

Since the smallest element of $\mathbb{N}$ is 1, $a_1 + a_2 \geq 2$. Thus $a_1, a_2$ must be of the same order, even or odd. 

Thus $f$ is *one-to-one*

**Claim**: $f$ is  *onto*

## Function Book Problems
### p24.14
Try to find Left and Right inverses. 
#### Part 1
$$
\begin{align}
	f : \mathbb{Z} &\to \mathbb{Z} \\
	f(n) &= 2x
	
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
Thus $y = x + 10$ and $x = y - 10$
Then, 
$$
f(x) = x-10 = y - 10 + 10 = y
$$

Therefore $\forall x\in\mathbb{Z}, \exists y\in\mathbb{Z}$ s.t $f(x) = y$

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
Then $f(x) = x+10 = 5$ for $x=-5$.
Since $-5 \not\in \mathbb{N}$, $f$ is *not* onto. 

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
Suppose $f$ is one-to-one. 
Then by definition $f(a_1) = f(a_2)$ if and only if $a_1 = a_2$

**Q2**
Suppose $f$ is onto.
Then, $\forall a_1\in A, \exists a_2\in A$ such that $f(a_2) = a_1$

However this does not say that $a_2$ is unique. Several $a \in A$ could map to a given $a_0$. Thus a function need not be one-to-one given that it is onto. 

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