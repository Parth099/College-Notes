# Euclidean Algorithm
## Background
> Recall this division identity $$\text{ if } d|a \text{ then } d|({\text -}a)$$

This means that 
$$
\text{gcd}(a, b) = \text{gcd}(-a, b) = \text{gcd}(a, -b) = \text{gcd}(-a, -b)
$$

## The Algorithm 
Let $a, b \in \mathbb{Z^+}$ such that $a\lt b$
To find the $\text{gcd}(a, b)$ perform these steps (division algorithm):
$$
\begin{align}
	&b = q_1a + r_1 \text{ for } 0\leq r_1 \lt a &\text{ if } r_1 = 0 \text{ STOP} \\
	
	&a = q_2r_1 + r_2 \text{ for } 0\leq r_2 \lt r_a &\text{ if } r_2 = 0 \text{ STOP} \\
	
	&r_1 = q_3r_2 + r_3 \text{ for } 0\leq r_3 \lt r_2 &\text{ if } r_3 = 0 \text{ STOP} \\
	&\vdots&\vdots \\
	&r_{n-2} = q_nr_{n-1} + r_n \text{ for } 0\leq r_n \lt r_{n-1} &\text{ if } r_n = 0 \text{ STOP}\\
	

	&r_{n-1} = q_{n+1}r_{n} + \mathbf{0} & \text{ STOP}
\end{align}	
$$

### Algo: Example
> Find $\text{gcd}(321, 123)$

$$
\begin{align}
	321 &= (2)123 + \mathbf{75} \\
	123 &= (1)75 + \mathbf{48} \\
	75 &= (1)48 + \mathbf{27} \\
	48 &= (1)27 + \mathbf{21} \\
	27 &= (1)21 + \mathbf{6} \\
	21 &= (3)6 + \mathbf{3} \\
	6 &= (2)3 + \mathbf{0} \\
\end{align}
$$

Employment of Neg Numbers:
$$
\begin{align}
	321 &= (3)123 - \mathbf{69} \\
	123 &= (2)69 - \mathbf{12} \\
	69 &= (6)12 - \mathbf{3} \\
	12 &= (4)3

\end{align}
$$

Either case the $\text{gcd}(321, 123) = 3$

## Algo Decon
### EX - Easy
> Find $\text{gcd}(102, 300)$ and express this $\text{gcd}$ in a linear combination of $102$ and $300$

$$
\begin{align}
	300 &= (3)102 - \mathbf{6} \\
	102 &= (17)6 + \mathbf{0} \\
\end{align}
$$

Thus $d = \text{gcd}(102, 300) = 6$

$$300 = (3)102 - \mathbf{6} \to \boxed{6 = 300 - (3)102}$$

### EX - Hard
> Find $\text{gcd}(300, 101)$ and express this $\text{gcd}$ in a linear combination of $101$ and $300$

$$
\begin{align}
	300 &= 
\end{align}
$$

$$\to (101)101 - (34)300 = 1$$
<!-- To  be finished -->