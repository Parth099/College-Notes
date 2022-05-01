# Inverse of a Function
## Identity Function
$$
\begin{align}
	\text{id}_A &: A \to A \\
	\forall a\in A&, \text{id}_A(a) = a 
\end{align}
$$

Consider the function $f:A\to B$
Then the identity of $f$ is: 
$$f\circ \text{id}_A = f$$

Similarly, 
$$
\begin{align}
	\text{id}_B &: B \to B \\
	\text{id}_B \circ f &= f
\end{align}
$$

## The **Inverse**
Let $f:A\to B$ and $g:B\to C$.

**Left Inverse**

Then $g$ is the *Left Inverse* if $g \circ f = \text{id}_A$. This means that $$\forall a\in A,\:\: g(f(a)) = a$$

**Right Inverse**

Then $g$ is the *Right Inverse* if $f \circ g = \text{id}_B$. This means that $$\forall a\in A,\:\: f(g(b)) = b$$

**Double Sided Inverse**

$g$ is the Double Sided Inverse if it is both a *Left* and *Right* inverse. 
This means, 
$$
\forall a\in A,\:\: g(f(a)) = a 
$$
and
$$
\forall b\in B,\:\: f(g(b)) = b 
$$

## Examples and Motivations
### Example 1
Consider, 
$$
\begin{align}
	f&:\mathbb{R} \to \mathbb{R}
	\\
	f(x) &= x^2
\end{align}
$$

Does $f$ have an left inverse?
This means does there exist a $g$ such that $g(f(x)) = x?$

Suppose there exists $g:\mathbb{R} \to \mathbb{R}$ such that $g(f(x)) = x$.

Thus $g(x^2) = x$

Suppose then that $x = -1$.
Then $g((-1)^2)=g(1) = -1$

Suppose $x = 1$, then $g(1) = 1$ too.
Thus, $(1, 1)\in g$ and $(1, -1)\in g$
Thus $g$ is not a function and cannot exist. 

### Observation 1
$f$ has a left inverse iff $f$ is one-to-one.

### Example 1.2
Consider the same example on a restricted domain. 
$$
\begin{align}
	f&:[0, \infty) \to \mathbb{R}
	\\
	f(x) &= x^2
\end{align}
$$

Is there a $g$ now for the *left inverse*?

Yes, 
$$
g(x) = \sqrt{x}
$$

However this is a bit of a problem. Recall that 
$$
f:[0, \infty) \to \mathbb{R}
$$
Thus, $g$ must be 
$$
g:\mathbb{R} \to [0, \infty)
$$

Thus we modify $g$ to be
$$
g(x) = \begin{cases}
	\sqrt{x} & \text{if} & x \geq 0 \\
	0 & \text{otherwise}
\end{cases}
$$

See that this **does** fit the description of a *left inverse*
$$
\forall x\in[0, \infty),\:\: g(f(x)) = x
$$
For $x\not\in[0, \infty)$ we can do anything since they will not be *accessed* by $f$ anyways. 

> **Note**: If one left inverse exists, there exist *infinitely* many left inverses since we can vary the part of $g$ that $f$ cannot access. 

### Example 2
Consider, 
$$
\begin{align}
	f&:\mathbb{R} \to \mathbb{R}
	\\
	f(x) &= x^2
\end{align}
$$

Does $f$ have a right inverse? That is, does that exists a function $g:\mathbb{R} \to \mathbb{R}$ such that $f(g(x)) = x$

This means that $\forall x\in\mathbb{R} [g(x)]^2 = x$

No $g$ exists. To see why set $x = -1$.

> Recall $x^2\geq 0$ for any real valued $x$.

### Observation 2
$f$ has a right inverse iff $f$ is onto. 

### Example 2.2
$$
\begin{align}
	f&:\mathbb{R} \to [0, \infty)
	\\
	f(x) &= x^2
\end{align}
$$

The *new* image makes $f$ onto. 

Let $y\in\text{im }f = [0, \infty)$

Then we find the inverse image of $y$

$$
\begin{align}
f^{-1}(y) &= \{x\in\mathbb{R} : f(x) = y\} \\

&= \{x\in\mathbb{R}: x^2 = y\} \\
&= \{\pm\sqrt{y}\}
\end{align}
$$

Let 
$$
\begin{align}
	g_1(x) &= \sqrt{x}\\
	g_2(x) &= -\sqrt{x}
\end{align}
$$

Both of these are *right inverses*.

To see why compute $f\circ g$ for both of the $g$ functions. 

