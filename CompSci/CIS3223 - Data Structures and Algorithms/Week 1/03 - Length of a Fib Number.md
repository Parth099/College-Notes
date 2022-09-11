# Length of a Fib Number
## Inductive Proof
**Statement**:
$$
\forall n\geq 6, \ F_n \gt 2^{\frac{n}{2}}
$$

### Base Case
$n = 6$ 
$$
\begin{align}
F_6 &= 8 
\\
2^{6/2} = 2^3 &= 8
\end{align}
$$

Since $F_6 \geq 2^{\frac{6}{2}}$ the formula is valid for $n=6$

$n = 7$ 
$$
\begin{align}
F_7 &= 13 
\\
2^{7/2} = 2^{3}\sqrt{2} = 8 \sqrt{2} &\approx 11.31371
\end{align}
$$

Since $F_7 \geq 2^{\frac{7}{2}}$ the formula is valid for $n=7$

### Inductive step
Assume $\forall k\geq 6, \ F_k \gt 2^{\frac{k}{2}}$

Consider $F_{k+1}$ where $F_{k+1} = F_k + F_{k-1}$

$$
\begin{align}
	\mathbf{F_{k+1}} = F_k + F_{k-1} &\geq 2^{\frac{k}{2}} + 2^{\frac{k-1}{2}}
	\\
	&= 2^{\frac{k-1}{2}}2^{\frac{1}{2}} + 2^{\frac{k-1}{2}}
	\\ \\
	&= 2^{\frac{k-1}{2}} \biggr(\sqrt{2} + 1  \biggr)
	\\ \\
	&\geq 2^{\frac{k-1}{2}} (1 + 1) = 2^{\frac{k-1}{2}}\cdot 2
	\\
	&= 2^{\frac{k+1}{2}}
\end{align}
$$

Therefore, $\forall n\geq 6, \ F_n \gt 2^{\frac{n}{2}}$

Since we are bounding $F_n$ below by a power of two we can assume that for all $n\geq6$ the number of binary digits in $F_n$ is greater then $\frac{n}{2}$

## Computational Complexity 
Let $T(n)$ represent the *Computational Complexity* of computing the $n$th Fibonacci number. 

$$
{T}(n) = 
\begin{cases}
	1 & \text {if}  & n \in \{0, 1\} 
	\\
	T(n-1) + T(n-2) + 1 & \text {otherwise}
\end{cases}
$$

For $F_0, F_1$ the cost is simply one since those are the initial values.
For $T(n-1) + T(n-2) + 1$, we attain the cost of computing the previous numbers then the $+1$ cost to add them.

We can see that since $T_n \geq F_n$, $$T_n \in \Omega(2^{\frac{n}{2}})$$