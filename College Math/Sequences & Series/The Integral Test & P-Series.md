# The Integral Test
The Integral Test is a convergence test to determine the status [[Series]] by comparing it to its integral equivalent.

## Theorem
 Let $a_n$ be a sequence with its series $\sum a_n$. The convergence status of $\sum a_n$ depends on $\int f(x) \mathop{dx}$ where $f(x)$ is the functional equivalent of $a_n$.
 
 Intuition: The *Integral* and the *series* aren't very different. See that an infinite series is just an  *Integral* where $dx = 1$. By this I mean that the with of the rectangular approximations used by the Integral has the width 1. 
 Generally a Left Riemann sum is used to geometrically represent this picture.  
 
 ## Use
 Evidently, we use the Integral Test when a series when represented as a function is easy to integrate.  
 
 # Special Use: P-Series 
 
Problem: For which values of $p$ is the series $a_n$ convergent?
$$a_n = \frac{1}{n^p}$$

Well we can solve this by asking a similar question of integrals:
For which values of $p$ is the below integral convergent?
$$\int_{1}^{\infty} \frac{1}{x^p} \mathop{dx}$$

## Solution
$$
\begin{align*}
\int_{1}^{\infty} \frac{1}{x^p} \mathop{dx} &= \lim_{t \to \infty} \int_{1}^{t} x^{-p} \mathop{dx} \\

&= \lim_{t \to \infty} \frac{x^{1-p}}{1 - p}\biggr\rvert_{1}^{t} \\

&= \lim_{t \to \infty} \frac{t^{1-p}}{1-p} - \frac{1}{1-p} \\

&= \frac{1}{1-p} \lim_{t \to \infty} [t^{1-p} - 1] \\

&= \frac{1}{1-p} \lim_{t \to \infty} [\frac{1}{t^{p-1}} - 1] \\
\end{align*} 
$$

Suppose now $p \gt 1 \implies p - 1 \gt 0$
Since $p - 1 \gt 0$:
$$\lim_{t \to \infty} \frac{1}{t^{p-1}} \to 0$$

Anything lesser than 1 causes the limit to hit $\infty$ causing the integral to be divergent. 

# P-Series Conclusion
From the above work we can conclude that: 

The series $$\sum \frac{1}{n^p}$$ is **convergent** if $p \gt 1$ and otherwise **divergent**.

### Addition of Finite terms to a Sum.

See that the sum: 
$$\sum_{k}^{\infty} a_n$$
starts at index *k*.

We can start the integral test at any value $c$ such that $c \geq k$ as long as there is any functional problems in the interval $[k, c]$. This would be like holes or discontinuities. 

This fact is valid because the addition of **finite** terms will not alter the convergence state of an **infinite sum**.