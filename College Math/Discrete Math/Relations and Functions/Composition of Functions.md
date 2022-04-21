# Composition of Functions
**Definition**

Let $f:A\to B$ and $g:B\to C$.
Then, $$g \circ f\:(a) = g(f(a))$$

"$g$ composed with $f$"

## Example of Composition
**Statement**

$$
\begin{align}
	f&:\mathbb{Z}\to\mathbb{Z} \\
	f(x) &= 3n+1 \\\\
	
	g&:\mathbb{Z}\to\mathbb{Z} \\
	g(x) &= \begin{cases}
			\frac{n}{3} & \text{if} & 3|n
			\\
			n+3 & \text{if} & 3\nmid n
		\end{cases}
\end{align}
$$

Find both $g \circ f$ and $f \circ g$

**Work**

$g \circ f(n) = g(f(n)) = g(3n+1)$ 
Since $3\nmid 3n+1$, $$g \circ f(n) = 3n+4$$

$f \circ g(n) = f(g(n))$
Then, 
$$
f\biggr(g(n)\biggr) = \begin{cases}
		n+1 & \text{if} & 3|n
		\\
		3n+10 & \text{if} & 3\nmid n
	\end{cases}
$$

## Associativity of Composition
Consider three functions:
$$
\begin{align}
	f&:\mathbf{A}\to\mathbf{B} \\
	
	g&:\mathbf{B}\to\mathbf{C} \\

	h&:\mathbf{C}\to\mathbf{D} \\

\end{align}
$$

Consider the function $$h\circ g \circ f$$

First lets see what $(h\circ g) \circ f (n)$ is

Now, $(h\circ g) = h(g(n))$
Then, $h(g(n))\circ f = h(g(f(n)))$

Then look at $h\circ (g \circ f) (n)$ 
$(g \circ f) = g(f(n))$

Finally, $h \circ g(f(n)) = h(g(f)))$

**Compositions are *Associative***

## Properties and Compositions
Consider the functions:
$$
\begin{align}
	f&:\mathbf{A}\to\mathbf{B} \\
	g&:\mathbf{B}\to\mathbf{C} 
\end{align}
$$

### Prop 1
If $f, g$ are one-to-one then so is $g \circ f$

**Proof:**

Suppose $g(f(a_1)) = g(f(a_2))$
Since $g$ is one-to-one, $f(a_1) = f(a_2)$.
Since $f$ is one-to-one, $a_1 = a_2$.

Therefore, $g \circ f$ is one-to-one if $f, g$ are. 

### Prop 2
If $f, g$ are onto then so is $g \circ f$

**Proof:**

Suppose $f, g$ are both onto.
Let $c \in C$. Then since $g$ is into, $\exists b\in B$ s.t $g(b) = c$.
Then, $\exists a\in A$ s.t $f(a) = b$.

Then $g(f(a)) = c$.
Thus $\forall c \in C\: \exists a\in A$ s.t $g(f(a)) = c$ and therefore $g \circ f$ is onto. 

### Prop 3
If $f, g$ are bijective then so is $g \circ f$
