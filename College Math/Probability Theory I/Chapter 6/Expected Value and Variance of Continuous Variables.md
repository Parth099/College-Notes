# Expected Value of Continuous Variables
Given  the definition of Variance of Discrete Variables (See. '[[Expected Value of Discrete Random Variables]]')

We can assume the same for continuous variables:
$$
\begin{align}
	E(X) &= \int_{-\infty}^\infty xf(x) \mathop{dx}
\end{align}
$$

The precondition for this is the fact that 
$$\int_{-\infty}^\infty |x|f(x) \mathop{dx} \text{ converges}$$

The Linearity of expectation **still** applies to cts variables.
See: [[Expected Value of Discrete Random Variables]]

## Examples
### EX - A
> Suppose $X$ is uniformly distributed on $[0, 1]$.
> $$\text{Find }E(X)$$


By Definition
$$\mu = \int_0^1 xf(x) \mathop{dx}$$
Since $f(x) = \frac{1 - 0}{1}$ given the uniform distribution, $$E(X) = \frac{1}{2}$$

---
### EX - B
> Let $Z = (x, y)$ denote a point on the unit circle. What is the expected value $\mu$ for the distance between $Z$ and the center of the circle. 

Let $X$ be the distance from $Z = (x, y)$ to $(0, 0)$ .
Then: 
$$X = \sqrt{(x - 0)^2 + (y - 0)^2} = \sqrt{x^2 + y^2}$$

To obtain the expect value we need the density function $f(x)$

Lets investigate $F(X)$, 
$$F(X) = P(X < x)$$

Logically little $x$ represents a smaller circle with radius $x$ and area $\pi x^2$

We can compare this to the total area of $\pi$
$$\frac{\pi x^2}{\pi} = x^2$$

Finally:
$$\frac{d}{dx} F(X) = f(X) = 2x$$

Thus
$$\mu = \int_0^2 x(2x) \mathop{dx} = \frac{2}{3}$$

## Expectation of a Function of a Random Variable
Much like [[Expected Value of Functions of Random Variables]], 
> Let $X$ be a random variable and $\phi(x)$ be a **continuous** real-to-real function, then
> $$E(\phi(X)) = \int_{-\infty}^{+\infty} \phi(x)f_X(x)\mathop{dx} $$ 

This assumes the integral is convergent to a value. 
See that this is very similar to our discrete edition
$$E(g(X)) = \sum g(k) \cdot P(X = k)$$
However the PDF (PMF in our discrete case) is abstracted away under $P(X = k)$ .

## Expectation of the Product of Two Random Variables

Generally for continuous variables $$E(XY) \neq E(X)E(Y)$$ since integrals **do not** multiply.

> **However,**
> $$E(XY) = E(X)E(Y)$$
> if $X$ and $Y$ are independent.

The proof is Simple when we start with this:
\* - assumes $X$ and $Y$ are contained by an interval
$$E(XY) = \int_{x = a}^{x = b}\int_{y = c}^{y = d} xyf_X(x)f_Y(y)\mathop{dx}\mathop{dy}$$

We can employ the properties of multiple integrals to break this down into the product of 2 separate integrals. 

# Variance
Recall the functional expectation from 2 headings ago.
We can define continuous **Variance** as
$$\sigma^2 = \int_{-\infty}^{+\infty} (x - \mu)^2 f(x) \mathop{dx}$$
Given that this integral exists and $E(X) = \mu$

## Properties 
Same as [[Variance of Discrete Variables]]
### Prop 1
$$
\begin{align}
	V(cX) &= c^2V(X) \\
	V(X+c) &= V(X)
\end{align}
$$

### Prop 2
$$V(X) = E(X^2) - \mu^2$$

### Prop 3
If $X, Y$ are real-valued and independent then:
$$V(X+Y) = V(X)+V(Y)$$

## Example: The Variance of the Exponential Dist
See [[Important Densities]] for more info on Exp Dist

> Let $X$ be an exponentially distributed random variable with parameter $\lambda$. Then:
> $$f_X(x) = \lambda e^{-\lambda x}$$
> **Note**: The distribution is only defined for $x \geq 0$

Work:
![[var_expo_1.jpg]]
![[var_expo_2.jpg]]

Given that we know
$$
\begin{align}
	E(X) &= \frac{1}{\lambda} \\
	E(X^2) &= \frac{2}{\lambda^2}\\
	\\
	V(X) &= \frac{2}{\lambda^2} - (\frac{1}{\lambda})^2 \\
	&= \boxed{\frac{1}{\lambda^2}}
\end{align}
$$

> **Additional Class Problem**:
> Find $V(X)$ if $X$ is uniformly distributed on interval $[a, b]$ 