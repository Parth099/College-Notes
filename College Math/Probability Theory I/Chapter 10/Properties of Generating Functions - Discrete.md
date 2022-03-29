# Properties of Generating Functions
## Shift and Scale
> Suppose $X$ is a discrete variable
> 1. $$Y = X + a$$
> 2. $$Z = bX$$

In Case one notice:

$$
\begin{align}
	g_Y(t) &= \mathbb{E}(e^{tY}) \\
		   &= \mathbb{E}(e^{t(X+a)}) \\
		   &= e^{ta}\mathbb{E}(e^{tX}) = e^{ta}g_X(t)
\end{align}
$$

Similarly in Case two:
$$g_Z(t) = \mathbb{E}(e^{tbX}) = g_X(t\cdot b)$$

## Adding Random Variables
> Suppose now $$Z = X + Y$$

$$
\begin{align}
	g_Z(t) &= \mathbb{E}(e^{tZ}) \\
		   &= \mathbb{E}(e^{t(X+Y)}) \\
		   &= \mathbb{E}(e^{tX}e^{tY}) \\
		   &= g_X(t) \cdot g_Y(t)
\end{align}
$$

## Using Properties
> Suppose $X$ and $Y$ are Binomially Distributed over the same range of $$\{0, 1, 2, \dotso, n\}$$ and the chance of success. 

Then $$p_X(k) = p_Y(k) = \binom{n}{k}p^k q^{n-k}$$

Then we know the range of $Z = X+Y$ is $$\{0, 1, 2, \dotso, 2n\}$$

The moment generator is:
$$
\begin{align}
	p_Z(j) = (p_X*p_Y)(j) = \binom{2n}{j}p^j q^{2n-j}
\end{align}
$$

### Verification
Recall Generator for Binomial Variables from [[Moment Generating Functions - Discrete Case Problems]]. 

We note that 
$$
g_X(t) = g_Y(t) = (pe^t + q)^n 
$$
Then, 
$$g_X(t) \times g_Y(t) =  (pe^t + q)^{2n} $$

We can re-expand this product if we really needed to:

$$
\begin{align}
	(pe^t + q)^{2n} &= \sum_{j = 0}^{2n}\binom{2n}{j} (pe^t)^j q^{2n-j} \\
	
	&=\sum_{j = 0}^{2n}e^{tj}\binom{2n}{j}p^{\:j} q^{2n-j}
	\\\\
	&= \mathbb{E}(e^{t(X+Y)})
\end{align}
$$

The addition of two binomial trials was not covered in this course but it is know as *convolution*.