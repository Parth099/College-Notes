e# Continuous Probability Densities
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
\Omega &= \{(x, y)\ \rvert \ x^2 + y^2 \leq 1\} \\
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

This means the density function will not be constant. In this case its given to be 2r based on simulations. Notice that circles that are closer to the rim are also *longer* in circumference and thus have a higher chance of being hit.

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
We notice that unlike discreet sample spaces the value of $f(x)$ of the density function for an outcome $x$ is **not** the   probability of $x$ occurring.

A Density function can only derive the probability of events.
$$\begin{align*}
E &= [a, b] \\
P(E) &= \int_a^{b} f(x) \mathop{dx}
\end{align*}$$

We see that an event's probability is the same as its area under *density function* $f(x)$. This implies the close connection between areas & probabilities. 

If $dx$ is small the probability of occurrence of an event in the form $[x, x+dx]$ where $dx$ is very small is  approximated by
$$P([x, x+dx]) \approx f(x)\mathop{dx}$$

Notice that with the integral & the approximation that 
$$dx \to 0 \implies P(E) = 0$$
The probability of a event of a single element is 0.

### Continuous Probability Distributions Summary


## Cumulative Distribution Functions of Continuous Random Variables

Let $X$ be a continuous real-valued random variable.
The cumulative distribution function of X is defined by:
$$F_X(x) = P(X \leq x)$$
If $X$ is a cts real-valued var which has a density function then it also has a cumulative distribution function. 

Here is this function.

Let $X$ be a CTS RV Var with density function $f(x)$. Then the ***Cumulative Distribution*** function $F(x)$ is defined by
$$F(x) = \int_\infty^x f(t)\mathop{t}$$
Note that 
$$\dfrac{d}{dx}F(x) = f(x)$$

### What does this all mean?
A CDF (Cumulative Distribution Function) is used to calculate the area under the curve to the left of a given endpoint as shown above. 

This is different from a PDF (Probability Density Function) since it quite literally gives you the shape of a distribution via $f(x)$ 

A concrete example would be asking a question like:
> How many people are 150 cm tall

A PDF would tell you an exact number
A CDF would tell you how many are 150 and below.

Realize that for some PDFs a CDF will output 1 after some value $x_0$

#### Non Concrete Example
![[CFD_1.png]]
Lets convert this to a Piece Wise CDF.

Lets consider the first interval $0\leq x \leq 2$
The area in this part will be in the form:
$$\frac{1}{8}\int_0^{x_0} x^2\mathop{dx} = \frac{1}{24}x_0^3$$

So far can calculate $F(x)$ for any $x$ in  $0\leq x \leq 2$.

Lets consider the next part of the interval: $2\leq x \leq 4$.
Notice that this is $F(2)$ plus some other area. (I am referring to the CDF )

The area for this interval is:
$$\begin{align*}
F(x_0) &= F(2) + \int_2^{x_0} \frac{1}{8}x(x-4)\mathop{dx} \\

F(x_0) &= \frac{1}{3} + \int_2^{x_0} \frac{1}{8}x(x-4)\mathop{dx} \\

F(x_0) &= \frac{1}{3} + [\frac{1}{4}x^2 - \frac{1}{24}x^3]\biggr\rvert_2^{x_0} \\

F(x_0) &= \frac{1}{4}{x_0}^2 - \frac{1}{24}{x_0}^3 - \frac{1}{3}
\end{align*}$$

Finally we can say that: 
![[CDF_1_SOL.png]]

##### Alternate Method
We will use the same PDF from before.

The function for the interval $0\leq x \leq 2$ is $\frac{1}{8}x^2$

Integrate to find the area under the function.
$$\int \frac{1}{8}x^2\mathop{dx} = \frac{1}{24}x^3 + C$$
We must find C.  $$F(0) = 0 \implies C = 0$$

Now for $2\leq x \leq 4$
$$\int \frac{1}{8}x(4-x)\mathop{dx} = \frac{1}{4}x^2 - \frac{1}{24}x^3 + D$$
We must find D. $$F(2) = \frac{1}{3} \implies D = -\frac{1}{3}$$

$D = -\frac{1}{3}$ ensures the values produced by the 2 formulas are equal at $x_0 = 2$

And thats it.

#### Book Problems

##### P1
A real number is chosen from $[0, 1]$ and then squared. Let $X$ represent this value. What is the PDF, CDF of $X$?

Let $U$ be the random real number.
$$\begin{align*}
F_X(x) &= P(X \leq x) \\
&= P(U^2 \leq x) \\ 
&= P(U \leq \sqrt{x}) \\
&= \sqrt{x}
\end{align*}$$

##### Analysis
The probability of a number being less than $\sqrt{x}$ is $\sqrt{x}$
Think length of the interval divided by the length of $\Omega$ 

##### P2
Let $I$ be the interval $[0, 1]$. We pick two random variables $X, Y$ from this interval $I$. Let $Z = X + Y$. 

Derive the *cumulative distribution function*.

Notice that $\Omega$ is the unit square in $\mathbb{R}^2$ with a uniform density. We know that $$0 \leq Z \leq 2$$
Let $E_z$ denote the event $Z \leq z$

$$\begin{align*}
F_Z(z) &= P(Z \leq z) \\
&= \text{Area}(E_z)
\end{align*}$$

###### Analysis
Why is it the area?

We want the probability that $Z \leq z$. This means all numbers equal or less than Z. Many numbers can produce this. Think of the fact that 2 numbers adding up to 2 can be modeled with: 
$$x+y = 2 \to y = 2-x$$


![[Pasted image 20220118154255.png]]
Sample Space: $\Omega$
![[Pasted image 20220118154513.png]]
$$x+y\leq1$$
![[Pasted image 20220118154918.png]]
$$x+1\leq1+c, \ c\in[0, 1]$$
See that for the second picture with $c$. There is a bit of an overshoot with the integral.

For $0\leq Z \leq 1$
We can say say that:
$$P(E_Z) = \int_0^Z x\mathop{dx} $$
The probability that $X+Y\leq1$ is $\frac{1}{2}$ as defined both by the picture and the direct integral.

For $1\leq Z \leq 2$ its a bit different.
See in picture 2 that the black gradient. See that the integrand will be $$f(x) = 2-x$$
for these values for $Z$.

Simply because it fits our integration scheme. Its quite hard to get this in words but I will update this when I can.