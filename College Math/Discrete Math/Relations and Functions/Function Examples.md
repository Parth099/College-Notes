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
## Example 4
$$
\begin{align}
	f&: \mathbb{R} \to \mathbb{R} \\
	f &= x^2+x+1
\end{align}
$$


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