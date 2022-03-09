# Problem One 
## Statement
> Suppose we pick a point $(X, Y)$ from the unit circle. 
> 1. Find $E(X)$
> 2. Find $E(|X|)$

Graphic:
![[icevp_cir_p1.png]]
### Answer to \#1
By argument of Symmetry,  $E(X)$ is simply $0$. Looking at the unit disc above, note that each point has its additive inverse. In other words consider a PDF of $X$, call it $f_X(x)$
$$E(X) = \int_{-1}^1 x \cdot f_X(x) \mathop{dx} = 0$$
Since the circle is symmetric about the line $y = 0$

The integral proposition isn't required just helps to think about the additive inverse
$$x + (-x) = 0$$

### Answer to \#2
To attain $E(|X|)$ we can attempt to get the PDF of $X$. Notice that it is not uniform since $x$ being closer to the endpoints $-1$ or $1$ is lower than $x$ being close to 0.

Also we can think of the product $$[0, 1]\times[0, 1]$$
and then removing the points that are not contained in the circle.

Lets try to find the CDF.

$$
\begin{align}
	F_X(r) &= P(X < r) \\
	    ^* &= \frac{\int_{-1}^r 2\sqrt{1-x^2} \mathop{dx} }{\pi}
\end{align}
$$

\* - we used an integral because it obtains the area under a curve for a given $r$. Also the division by $\pi$ is done to keep the CDP under $1$ at all times. The integral will compute the area but we need to divide by the total area to keep it an actual *probability* .

We can look at a concrete value or $r$
![[icevp_cir_p2.png]]
Looking at the range it is $[-1, r]$
and the function we are integrating is $\sqrt{1 - x^2}$ since that is the distance from the the $x$-axis to the circle height. 
We multiply by 2 to add in the bottom half.

After developing this fact:
$$F_X(r) = \frac{2}{\pi}\int_{-1}^r \sqrt{1-x^2} \mathop{dx}$$

We can differentiate to obtain the PDF
$$\dfrac{d}{dr} F_X(r) = f_X(r) =  \frac{2}{\pi}\sqrt{1 - r^2}$$

All left to do now to find $E(|X|)$ is evaluate this:
$$E(|X|) = \frac{2}{\pi}\int_{-1}^{1} |x|\sqrt{1 - x^2} \mathop{dx}$$

Know that this function is Even since $f(x) = f(-x)$

$$
\begin{align}
	\frac{2}{\pi}\int_{-1}^{1} |x|\sqrt{1 - x^2} \mathop{dx} &= 2\frac{2}{\pi}\int_{0}^{1} x\sqrt{1 - x^2} \mathop{dx} \\
	
	^{*}&= \frac{2}{\pi}\int_{0}^{1}\sqrt{u}\mathop{du} \\
	&= \frac{2}{\pi}\biggr[\frac{2}{3}u^{3/2}\biggr]_{u = 0}^{u = 1} \\
	&= \boxed{\frac{4}{3\pi}}
	
\end{align}
$$

\* - $u$-sub for $u = 1 - x^2$ 
Thus, 
$$E(|X|) = \frac{4}{3\pi}$$
## Problem 2
> Suppose $X \sim \text{Exp}(\lambda)$
> 1. Find $E(X)$
> 2. if $\mu = E(X)$, is the probability of $X \gt \mu$ the same as  $X \lt \mu$. In other words, is $\mu$ some sort of divider?

---

### Work for \# 1
Recall
$$
f(x) = 
\begin{cases}
	\lambda e^{-\lambda x} & \text{ if } 0 \leq x \lt \infty \\
	0 & \text{ otherwise}
\end{cases}
$$

With a Integration by Parts (2 step) we see that
$$E(X) = \int_{0}^{\infty}x\cdot\lambda e^{-\lambda x}\mathop{dx} = \frac{1}{\lambda}$$

### Work for \#2 
The answer is visually no. However since we know that $\mu = 1/\lambda$ can we compare these two integrals:

$$
\int _0^{\frac{1}{\lambda }}x\lambda e^{-\lambda \:\:x}\:dx\:$$
and
$$
\int _{\frac{1}{\lambda }}^{\infty }x\lambda e^{-\lambda \:\:x}\:dx\:
$$

These represent $P(X < \mu)$ and $P(X > \mu)$ respectively.  I used an online calculator to see that they are not equal and thus $\frac{1}{\lambda}$ is **not** a divider. 