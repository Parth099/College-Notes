# HW 10
## 7.1
### Q6.c
$$
\begin{align}
\|A\|_\infty
&= \max_{1\leq i \leq n}\sum_{j=1}^n |a_{ij}| \ \text{ (max absolute row sum)}
\end{align}
$$

$$
A = 
\begin{bmatrix}
\frac{\sqrt2}{2} & -\frac{\sqrt2}{2} & 1\\ 1 & 0 & 0\\ \pi & -1 & 2
\end{bmatrix}
$$

$\ell_\infty$ :

$$
\max
\begin{align}
\begin{pmatrix}
\sqrt{2} + 1 \\
1 \\
\pi + 3
\end{pmatrix}
\end{align}
= \boxed{\pi + 3}
$$

### Q6.d

$$
A = 
\begin{bmatrix}
\frac{1}{3} & -\frac{1}{3} & \frac{1}{3}\\
-\frac{1}{4} & \frac{1}{2} & \frac{1}{4}\\
2 & -2 & -1
\end{bmatrix}
$$

$\ell_\infty$ :

$$
\max
\begin{align}
\begin{pmatrix}
1 \\
1 \\
5
\end{pmatrix}
\end{align}
= \boxed{5}
$$


### Q7

$$
A = \begin{pmatrix}0.04&0.01&-0.01\\ 0.2&0.5&-0.2\\ 1&2&4\end{pmatrix}
\ \ \ \
\vec{b} = \begin{pmatrix}0.06\\ 0.3\\ 11\end{pmatrix}
$$

$$
\vec{\mathbf{x}} = \begin{pmatrix}1.827586\\ 0.6551724\\ 1.965517\end{pmatrix}
\ \ \ \
{\tilde{x}} = \begin{pmatrix}1.8\\ 0.64\\ 1.9\end{pmatrix}
$$

---

$$
\begin{align}
\|\vec{\mathbf{x}} - {\tilde{x}}\|_\infty &= \ \biggr\|
\begin{pmatrix}
1.827586\\ 0.6551724\\ 1.965517
\end{pmatrix} - 
\begin{pmatrix}1.8\\ 0.64\\ 1.9\end{pmatrix}
\biggr\|_\infty
\\ \\
&= \ \|\begin{pmatrix}0.027586\\ 0.0151724\\ 0.065517\end{pmatrix}\|_\infty \\ \\
&= \boxed{0.065517}
\end{align}
$$

---

$$
\begin{align}
\|A\tilde{x} - {\vec{b}}\|_\infty &= \
\end{align}
$$

Firstly:

$$
\begin{pmatrix}0.04&0.01&-0.01\\ 0.2&0.5&-0.2\\ 1&2&4\end{pmatrix}\begin{pmatrix}1.8\\ 0.64\\ 1.9\end{pmatrix}=\overbrace{\begin{pmatrix}0.0594\\ 0.3\\ 10.68\end{pmatrix}}^{A\tilde{x}}
$$

Then:

$$
\begin{align}
A\tilde{x} - \vec{b} &= 
\begin{pmatrix}-0.0006\\ 0\\ -0.32\end{pmatrix} \\ \\
\implies \|A\tilde{x} - \vec{b}\|_\infty &= \boxed{0.32}
\end{align}
$$
