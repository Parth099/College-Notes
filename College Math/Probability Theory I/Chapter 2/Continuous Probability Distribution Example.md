## Problem
Choose independently two numbers $B \ \& \ C$ at random from the interval
$$I = [-1, 1]$$

Consider Equation:
$$x^2+Bx+C = 0$$

Find Probability that roots of this equation are:
>a. real
>b. both roots greater than 0

### Real Roots
discriminant: $b^2-4ac$
For all 2 roots to be real we require 
$$\begin{align*}
B^2-4C &\geq 0 \\
4C &\leq B^2 \\
C &\leq \frac{B^2}{4}
\end{align*}$$

#### Graph
![[Pasted image 20220118161857.png]]
Area under $y=0$ is simply 2 because its a rectangle. 
The other area is
$$
\begin{align*}
&\int_{-1}^{1} \frac{x^2}{4}\mathop{dx}& \\
\frac{1}{2}&\int_0^1 x^2 \mathop{dx}& \\
& &=\frac{1}{6}
\end{align*}
$$

The total area seems to be $$A = \frac{1}{6} + 2 = \frac{13}{6}$$
$$P(E) = \frac{\text{Area}(E)}{2*2}$$
**$$\boxed{\frac{13}{24}}$$**

### Positive Roots
Positive means real so I can keep the discrim condition.
Sample Quadratic
$$x^2+Bx+C = 0$$
$C$ is the product of roots
$B$ is the negative sum of roots

Thus for Positive Roots  $C\geq0$ & $B \leq 0$
On a graph this means that $x$ is negative and $y$ is positive. This occurs only on Q2.

Referring to the picture above we can exploit symmetry. 
We need
$$\int_{-1}^{0}\frac{x^2}{4}\mathop{dx}$$
It will be $$\frac{\frac{1}{6}}{2} = \frac{1}{12}$$

The probability of the roots being positive seems to be
$$\frac{1/12}{4}$$
**$$\boxed{1/48}$$**
I divided by 4 because its the total area of our sample space$\Omega$ while $\frac{1}{12}$ is our area probability.