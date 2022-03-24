# Homework Set 8 - GCD
> Find
> 1. $\text{gcd}(54321, 50)$
> 2. $\text{gcd}(1739, 29341)$
> 
> Then find **each** Linear Combination

##  1) $(54321, 50)$
### GCD
$$
\begin{align}
	54321 &= (1086)50 + \mathbf{21} \\
	50    &= (2)21    + \mathbf{8}  \\
	21    &= (2)8     + \mathbf{5}  \\
	8     &= (1)5     + \mathbf{3}  \\
	5     &= (1)3     + \mathbf{2}  \\
	3     &= (1)2     + \boxed{\mathbf{1}}  
\end{align}
$$
### DECON

---
<!-- TBF -->
##  2) $(1739, 29341)$
### GCD
$$
\begin{align}
	29341 &= (16)1739  + \mathbf{1517}\\
	1739  &= (1)1517   + \mathbf{222} \\
	1517  &= (6)222    + \mathbf{185} \\
	222   &= (1)185    + \boxed{\mathbf{37}} \\
	185   &= (5)37     + \mathbf{0}   \\
\end{align}
$$

The $\text{gcd(1739, 29341)} = 37$
### DECON
<!-- TBF -->