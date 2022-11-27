# Karatsubu Algorithm
This aims to improve the runtime of grade school multiplication. 

## Recursive Algorithm

See that for any $x\in\mathbb{Z}_{\geq0}$ :

$$
x = 2^{n/2}x_L + x_R
$$

### Example

$$
23 = 010111_2 = (010_2) \times 2^3 +  111_2 
$$

---

## Algorithm - Suboptimal

Let $x, y$ be the numbers you need to multiply:

$$
\begin{align}
xy &= (2^{n/2}x_L + x_R)(2^{n/2}y_L + y_R) \\
&= 2^nx_Ly_L +  2^{n/2}x_Ly_R +  2^{n/2}x_Ry_L + x_Ry_R\\
&= 2^nx_Ly_L +  2^{n/2}(x_Ly_R + x_Ry_L) + x_Ry_R\\
\end{align}
$$

**Algorithm**:
```txt
if n == 1:
	return xy
else:
	compute recursive mult as defined above then perform binary shifts as needed
```

### Analysis

$$
T(n) = \overbrace{4T(n/2)}^{\text{4 mults per single mult}} + \underbrace{O(n)}_{\text{Cost of Addition and Shifts}}
$$

Sadly, $T\in O(n^2)$ 

## Karatsubu Algorithm
See that in 

$$
(x_L + x_R)(y_L + y_R) = x_Ly_L + (x_Ly_R + x_Ry_L) + x_Ry_R
$$

Thus cost us $4$ multiplications as shown above. 

However,

$$
(x_Ly_R + x_Ry_L) = (x_L + x_R)(y_L + y_R) - x_Ly_L - x_Ry_R
$$

After storing $x_Ly_L, x_Ry_R$ it seems we can compute the wanted result with 2 additional additions and a multiplication.

This reduces the multiplication $4\to3$ and the runtime[^1] to $O(n^{\log_2{3}})$ .


[^1]: Master Theorem (see [[01 - Master Theorem]])