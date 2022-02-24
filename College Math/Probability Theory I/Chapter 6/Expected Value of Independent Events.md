# Expected Value of **Independent** Events
> **Theorem**
> Let $X$ and $Y$ be random variables. 
> If $X$ and $Y$ are **independent** then:
> $$E(XY) = E(X)E(Y)$$

## Proof
The proof of this concept is not hard to follow.
Let $X$ and $Y$ be random variables. 
Then consider their sample spaces:
$$
\begin{align}
	\Omega_X &= \{x_1, x_2, \dotso\}\\
	\Omega_Y &= \{y_1,\ y_2, \dotso\}
\end{align}
$$
Applying the definition of Expected value we attain:
$$
\begin{align}
	E(X\cdot Y) &= \sum_i \sum_j x_i y_jP(X = x_i \text{ and } Y = y_k) \\
	^*&= \sum_i \sum_j x_i y_jP(X = x_i)P(Y = y_k) 
	\\
	&= [\sum_i x_iP(X = x_i)][\sum_j y_iP(Y = j_i)] \\
	&= E(X)E(Y)
\end{align}
$$
\* - it is know $X$ and $Y$ are **independent**

## Examples
### EX 1
> Suppose $X_i$ *indicates* a coin-toss resulting in *heads*.
> We then know that $X_1$ and $X_2$ are independent. 

What is $E(X_1X_2)$ ?

$$E(X_1) = 1\frac{1}{2} + 0\frac{1}{2}$$
$$E(X_2) = 1\frac{1}{2} + 0\frac{1}{2}$$

Then
$$E(X_1X_2) = E(X_1)E(X_2) = \frac{1}{4}$$

### EX 2
> Let $X$ indicate a coin toss being heads. Then we define 
> $$Y = X - 1$$

We note by looking at the conditional
$$P(Y = 1 | X = 0) = 1$$
that these events are **not** independent.

$$E(X) = E(Y) = \frac{1}{2}$$
Yet $E(XY) = 0$
