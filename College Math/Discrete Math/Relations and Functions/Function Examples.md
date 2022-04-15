# Examples of Functions and Non-Functions
## Example 1
$$
f = \{(x, y)\in\mathbb{R}^2: xy = 1\}
$$

This **is** a function. 
$$\forall x\neq0, \exists!y\in\mathbb{R}\text{ s.t } xy=1$$
This number is namely $1/x$ .

For $x = 0$ there does not exists a number $y$ such that $xy=1$

Therefore for any $x$ there exists **at most** one $y$ such that $xy=1$ and thus $f$ is a function.

The domain and range are:
$$
\begin{align}
	\text{dom }f &= \mathbb{R}-\{0\} \\
	\text{im }f &= \{\frac{1}{x}: x\in\mathbb{R}, x\neq 0\}\\
	&= \{\frac{1}{x}: x\in\text{dom }f\}
\end{align}
$$

## Example 2
$$f = \{(x, y)\in\mathbb{Z}^2: 2x+y=3\}$$

$$
\forall x\in\mathbb{Z}, \exists!y\in\mathbb{Z} \text{ s.t } 2x+y = 3
$$

The integer $y$ is namely $3-2x$

$$
\begin{align}
	\text{dom }f &= \mathbb{Z} \\
	\text{im }f &= \{3-2x: x\in\mathbb{Z}\}\\
	&= \{y\in\mathbb{Z}: 2\nmid y\}
\end{align}
$$

That last step may seem like a leap of logic but see that $3-2x = 1+2-2x = 1+2(1-x)$ is always odd.

This is clearly a function. 

## Example 3
$$
f = \{(x, y)\in\mathbb{R}^2: x^2+y^2=1\}
$$

Suppose $x = 0$.
Then, $(0, -1)\in f$ since $0^2 +(-1)^2 =1$

And, $(0, 1)\in f$ since $0^2 + 1^2 =1$

Since $1\neq-1$, there exists more than one value for $0$ in $f$

Thus $f$ is **not** a function. 

# Proving Images
> Each example is using the **alternate** definition

In each of the examples below, there is a pattern.
To show that a set is the image of a function we must prove two things:
1. Given a random element of the image it fits the set description of the image set (proposed).
2. Given a random element of the image, there exists an element in the domain to create the domain-range pair. 
## Example 4
$$
\begin{align}
	f&: \mathbb{R} \to \mathbb{R} \\
	f(x) &= x^2+x+1
\end{align}
$$

Prove that $\text{im } f = \{y\in\mathbb{R}: y\geq 3/4\}$

Observe that $$x^2+x+1 = (x+\frac{1}{2})^2+\frac{3}{4}$$

Let $y\in\text{im } f$
Then $y = x^2+x+1 = (x+\frac{1}{2})^2+\frac{3}{4}$
For any $x\in\mathbb{R}, (x+\frac{1}{2})^2\geq 0$, hence $y\geq \frac{3}{4}$
Thus, $\text{im } f\subseteq \{y\in\mathbb{R}: y\geq 3/4\}$

Suppose $y\geq\frac{3}{4}$. 
Then $y-\frac{3}{4}\geq0$ and $\sqrt{y-\frac{3}{4}}\geq0$

$$\text{Let }\:x = \sqrt{y-\frac{3}{4}}+\frac{1}{2}$$

Then, $x\in\mathbb{R}$ and $f(x) =  (x+\frac{1}{2})^2+\frac{3}{4}$

$$f(x) = (\sqrt{y-\frac{3}{4}})^2+\frac{3}{4} = y$$

Hence $y\in\text{im } f$ and $\{y\in\mathbb{R}: y\geq 3/4\} \subseteq \text{im } f$
This proves the two sets are equal and thus proves that $\{y\in\mathbb{R}: y\geq 3/4\}$ is the image of $f$. 

> Notice what happened here: 
> First we showed that a random element in the image is in the set and then we showed than a random element of the set is in the image set. 

## Example 5
$$
\begin{align}
	f&: \mathbb{Z} \to \mathbb{Z} \\
	f(x) &= 3-2x\\ \\
	\text{Show that im }f&= \{y\in{\mathbb{Z}}: 2\nmid y\}
\end{align}
$$
Suppose $y\in\text{im }f$
Then $y = f(x) = 3-2x$ for some integer $x$.
See that 
$$3-2x=1+2-2x=1+2(1-x)$$
Since $1-x\in\mathbb{Z}$, $y$ is odd. 
This, $\text{im }f\subseteq \{y\in{\mathbb{Z}}: 2\nmid y\}$

Suppose $y$ is odd
Then $y=2n+1$ for integer $n$
Let $x=1-n$. Then $x$ is an integer. 
Then, 
$$
f(x) = 3-2x = 3-2(1-n) = 3 - 2 + 2n = 2n+1 = y
$$
Thus $y\in\text{im }f$ and $\{y\in{\mathbb{Z}}: 2\nmid y\}\subseteq\text{im }f$
Thus the two sets are equal. 
> Much like Ex-4 we shows that the image is a subset of the proposed set. Then we took the definition of the new set and showed that an output from $f$ can be created thus proving image. 


## Ex 6
$$
\begin{align}
	f&: \mathbb{Z} \to \mathbb{Z} \\
	f(x) &= 3x-2\\ \\
	\text{Show that im }f&= \{y\in{\mathbb{Z}}: y\equiv1\text{ mod }3\}
\end{align}
$$

Suppose $y\in\text{im} f$
Then $y = 3x-2$ for some integer $x$
See that $y = 3x-2=3x-3+1 = 3(x-1)+1$
Thus, $y-1 = 3(x-1)$
Since $x\in\mathbb{Z}$, $3|(y-1)$
Since $3|(y-1)$, $y\equiv1\text{ mod }3$
Hence $\text{im} f\subseteq\{y\in{\mathbb{Z}}: y\equiv1\text{ mod }3\}$

Suppose $y\equiv1\text{ mod }3$
Then, $3|(y-1)$.
Then $3n = y-1$ for some integer $n$ and $y = 3n+1$
Let $x = n+1$. Since $n\in\mathbb{Z}$ , $x\in\mathbb{Z}$
Then,
$$
f(x) = 3x-2 = 3(n+1)-2 = 3n-1 = y
$$
Thus $y\in\text{im} f$
Therefore the two sets are equal. 

<!-- 
$$
\begin{align}
	f&: \mathbb{R}-\{0\} - \mathbb{R} \\
	f &= \frac{1}{x}
\end{align}
$$

Show $\text{im }f =\{y\in\mathbb{R}: y\neq0\}$

**Proof**:
$\text{im }f =\{\frac{1}{x}: x\in\mathbb{R}: x\neq0\}$

Since $x\cdot\frac{1}{x} = 1\neq0$
$\text{im }f \subseteq \{x\in\mathbb{R}: x\neq0\}$

At this we have shown that the function is in the range. We must also prove the reverse. 

Suppose $y\neq0$. Then $\frac{1}{y}\in\mathbb{R}$. 
Let $x = \frac{1}{y}$
then $$f(x) = 1\biggr/\frac{1}{y} = y$$
Thus $y\in\text{im }f$
-->