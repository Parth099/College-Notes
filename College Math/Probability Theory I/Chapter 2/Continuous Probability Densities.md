# Continuous Probability Densities
## Simulation
### Issue with an Infinite Sample Space
Construct a spinner with a radius of 1 unit.  We number the circle and spin the spinner and record the numbers it lands at. The sample space should be $[0, 1)$. We would prefer if each real. The issue here is that each number now has a outcome of 0, since there are infinite numbers.

The best we can do for now is only analyze an event E in which we consider a range of values for our outcome. This allows us to use the arc length to produce a viable probability.   

### Monte Carlo & Area
We can use a simulation to estimate values of a square-based shape. 

#### Details
Suppose we have a function: `rnd` that outputs a real number confined by $[0, 1]$. We use this function to output a coordinate pair $(x, y)$. See that this creates the sample space that is the 1 by 1 square. Any subset of this square will have an area **equal** to the probability that an arbitrary pair $(x,y)$ randomly falls in that subset area.

#### Usage
Suppose we wish to know the area of a region in the unit square:
$$E = \{(x, y) \rvert \ y  \leq x^2\}$$
See that the condition determines if a random pair is a member of the subset $E$ or not.

Running a simulation for a higher and higher number of trials will yield a number closer and closer to $\frac{1}{3}$ since: 
$$\int_{0}^{1} x^2 \mathop{dx} = \frac{1}{3}$$

Suppose we had a circle of $r=\frac{1}{2}$ centered at $(\frac{1}{2}, \frac{1}{2})$. The chance of a `rand` $(x, y)$ being in the circle is equal to its area: $$\pi(\frac{1}{2})^2 = \frac{\pi}{4}$$

## Continuous Density Functions
Its time to start assigning probabilities to the outcomes and events. The focus here will be sample space where they are a subset of a Euclidean space (line, place, ...).

### Example A
Recall the spinner, it had an interval $[0, 1)$ and we want a model where each number has an equal chance of occurring. We saw that the distribution function $m$ must output $0$ every time. But the issue of a 0 probability arises when we consider the event where the spinner lands on any number. 
$$
\begin{align*}
E &= \{X \ \rvert \ 0 \leq X \lt 1 \} \\
P(E) &= 1 \\
\end{align*}
$$
In General, the formula becomes:
$$P(c \leq X \lt d) = d - c$$
If we let $E = [c, d]$ then:
$$P(E) = \int_{E} f(x) \mathop{dx}$$
for $f(x) = 1$.

#### Analysis B 
See that the function being a constant has a meaning. This means that each "rectangle" in the integral is of height of 1. The width is the uniform $dx$. We can then note that the infinitesimal $f(x)\mathop{dx}$ is the probability of the outcome of $x \in [0, 1]$.

Here $1$ is the ***density function*** of the random variable $X$.  

### Example B
Lets explore the game of darts a game of probability. Our space will be circular region with a unit radius of 1.

Suppose we want to know how many of these darts land on the top half.
$$
\begin{align*}
\Omega &= \{(x, y)\ \rvert \ x^2 + y^2 \leq 1 \\
E &= \{(x, y) \ \rvert \ y \gt 0\}
\end{align*}
$$

This time randomly in picking  $(x, y)$ `rnd` will have the range $[-1, 1]$. If $(x, y) \not\in \Omega$ it will not count. 

For any $E$:
$$
\begin{align*}
P(E) &= \frac{\text{Area}(E)}{\text{Area}(\Omega)} = \frac{\text{Area}(E)}{\pi} \\
\implies\\
P(E) &= \int_{E}f(x)\mathop{dx}\\
f(x) &= \frac{1}{\pi}
\end{align*}
$$

#### Analysis
Why $\frac{1}{\pi}$?
It is $\frac{1}{\pi}$ because the area of the circle is itself $\pi$. So for this distribution function to satisfy the fact:
$$\int_{\Omega} f(x) \mathop{dx} = 1\to \int_0^\pi f(x) \mathop{dx} = 1$$
$$\boxed{f(x) = \frac{1}{\pi}}$$

See that if $$E = \{(x, y) \ \rvert \ x^2+y^2\leq a^2, \ a \lt 1\}$$
then
$$P(E) = \frac{\pi a^2}{\pi} = \boxed{a^2}$$ 

**NOTE**: The density function is based on area and NOT points collected in E.

### Example **C**
Recall darts from above but now instead of observing where a dart lands, we will track its distance from the center. 

Our Sample Space $\Omega$ is the set of call circles with a radius that defines the distance to that point. Think of this idea as seeing where a dart lands and seeing what circle its a part of that is *also* centered at the origin. Our sample space will be circles with a radius in $[0, 1]$
$$\Omega = [0, 1]$$
Suppose $$E = \{r \ \rvert \ 0 \leq r \leq a \}$$
How can we assign probabilities for $E$ ?

Recall this from above. $(a \lt 1)$
$$P([0, a]) = a^2$$
We want to know in general $P([a, b])$
$$
\begin{align*}
	P([a, b]) &= P([0, b]) - P([0, a]) \\
	P([a, b]) &= b^2 - a^2
\end{align*}
$$

#### Analysis
We can breakdown $b^2 - a^2$ into: 
$$2(b-a)\frac{(b+a)}{2}$$
$$2(\text{Length})(\text{midpoint})$$
We note that the $E$ depends on both length of the region & its midpoint. The midpoint is "where it is", like close to the origin or the rim.

This means the density function will not be constant. In this case its given to be 2r based on simulations.  

## Sample Space Coordinates
The examples above suggest that experiments of this sort should correlate an integral & probability.   

Generally we wish to regard $\Omega$ as a subset of $\mathbb{R}^n$. A sample space of this nature is called a ***continous sample space***. Then $X$ is a random var that represents the outcome of the experiment. Such a var is called a ***continous random varible***. 

> A random variable X is continuous if possible values  
comprise either a single interval on the number line or a  
union of disjoint intervals.

## Density Functions of Continuous Random Variables

Let $X$ be a *continuous random variable*. A density function for $X$ is a real-valued function $f$ which satisfies
$$P(a\leq X \leq b) = \int_a^b f(x)\mathop{dx}$$
$\forall a, b \in\mathbb{R}$

Not all random variables contain density functions.

If $E \subset \mathbb{R}$
then
$$P(X \in E) = \int_E f(x)\mathop{dx}$$

### Concrete Examples
#### Example A
Recall Example B - The attempt to mapping a probability for a subset in a circle ($r=1$)  
![[densityFunc1.png]]

What we wanted to know was if we have a sub-region $E$ and a circular Sample Space $\Omega$ what is $P(E)$? What are the chances of a dart landing in $E$ WRT $\Omega$. 
Turns out $$P(E) = \iint_E \frac{1}{\pi} \mathop{dx}\mathop{dy}$$

##### Analysis
We know that $$\iint_E 1 \mathop{dx} \mathop{dy}$$ gets the area of $E$. With $\frac{1}{\pi}$ we normalize it to get it to fit the standard of being 1 when $\Omega$ is integrated.

###### Calculus 3 Interpretation 
The simplest way to see it is that $\pi$ is the total area and the integral gets the area of the region $E$ via $\iint E \mathop{dA}$. By dividing regional area and total possible area we arrive at percent area or the probability that the dart will land in the sub-region $E$.  


#### Example B
Recall Example C
We observed how far a dart would land from the center. We saw that it was more likely to land in regions near the rim of the length of the region was the same. 

We saw the density function was $2r$. 
![[densityFunc2.png]]
If $E$ represents the region of rings with radii $[a, b]$ then
$$P(E) = \int_a^b{2r}\mathop{dr}$$

### The Calculus of Density Functions
--Save 
--Page 70/520