# Least Squares Approximations
## Motivations
1. Solve for $A\bar{z}=\bar{b}$ for **rectangular **$A$ .
2. fit data to a model

## Lecture 
Consider the system:

$$
\begin{align}
x_1 + x_2 &= 2 \\
x_1 - x_2 &= 1 \\
x_1 + x_2 &= 3
\end{align}
$$

Due to $(1)$ and $(3)$ the system is **inconsistent**. However we want a $\bar{x}^{*}$ that gets us close to $\bar{b}$ .

$$
A = 
\begin{bmatrix}
1 & 1 \\
1 & -1 \\
1 & 1 
\end{bmatrix}
= [\vec{v_1}\ \vec{v_2}]
$$

Notice in this example that we need a 3d vector in two dimensions. So we have a plane spanned by $\vec{v_1}$ and $\vec{v_2}$ . 

Therefore the vector that gets us closest to $\bar{b}$ is going to be on the plane. Since we need the closest vector the vector $\bar{x}^*$ is going to be perpendicular to $\bar{b}$ .

![hand_drawn_least_sq](../img/hand_drawn_least_sq.jpg)

$\bar{x}^*$ is the last squares solution s.t the residual vector 

$$
\bar{r} = \bar{b} - A\bar{x}^*
$$

is perpendicular to the hyperplane $\{A\bar{x}\ |\ \bar{x}\in\mathbb{R}^n\}$

This means $\forall \bar{x}\in\mathbb{R}^n,\ \bar{r}\perp A\bar{x} \to (\bar{b}-A\bar{x}^*)\perp(A\bar{x})$

This means that (dot product)

$$
\begin{align}
(A\bar{x})^T(\bar{b}-A\bar{x}^*) &= 0 \\
\bar{x}^T\underbrace{A^T(\bar{b}-A\bar{x}^*)}_{\text{want all vectors to be perp even itself}} &= 0 \\
&\implies A^T(b-A\bar{x}^*) = 0
\end{align}
$$

Then:

$$
A^T\bar{b} - A^TA\bar{x}^* = 0 \implies A^T\bar{b} = A^TA\bar{x}^* 
$$

> $$(A\bar{x})^T=\bar{x}^TA^T$$

## Example Cont. 

$$
A = 
\begin{bmatrix}
1 & 1 \\
1 & -1 \\
1 & 1 
\end{bmatrix}
\ \ \ \ \ \ \
A^T = 
\begin{bmatrix}
1 & 1 & 1\\
1 & -1 & -1
\end{bmatrix}
\ \ \ \ \ \ \
A^TA = 
\begin{bmatrix}
3 & 1\\
1 & 3
\end{bmatrix}
$$

Now lets find $A^T\bar{b}$

$$
A^T\bar{b} = \begin{bmatrix} 6 \\ 4 \end{bmatrix}
$$

Now we must solve for the system:

$$
A^T\bar{b} = A^TA\bar{x}^*
$$

$$
\begin{bmatrix}
3 & 1\\
1 & 3
\end{bmatrix}
\begin{bmatrix} x^*_1 \\ x^*_2 \end{bmatrix}
=
\begin{bmatrix} 6 \\ 4 \end{bmatrix}
\to 
\bar{x}^* = 
\begin{bmatrix} \frac{7}{4} \\ \frac{3}{4} \end{bmatrix}
$$

## Errors
See that there is no meaning of "forward error" as the $\bar{x}$ in 

$$
\|\bar{x}-\bar{x}^*\|
$$

does not exist.

There is the backwards error however:

$$
\|r\|=\|\bar{b}-A\bar{x}^*\|
$$

In this context, the Euclidean norm is used ( $\ell_2$ ). 

### Measures of Error
- $\|r\|_2$
- $\|r\|^2_2$ (squared error)
- $\sqrt{\frac{\|r\|^2_2}{m}} = \frac{\|r\|_2}{\sqrt{m}}$ 
	+ (RSM) - Root mean squared