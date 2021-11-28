# EigenValues

A EigenValues denoted by $\lambda$ is a scalar (including 0) such that a Transformation $A$ maps a vector $\vec{v}$ to $\lambda\vec{v}$.

$$A\vec{v} = \lambda\vec{v}$$

$$A\vec{v} - \lambda\vec{v} = 0$$

$$(A -\lambda I)\vec{v} = 0 $$

$$det(A -\lambda I) = P(\lambda)$$

The zeros of $P(\lambda)$ are the eigenvalues of A. We require $det(A -\lambda I)$ = 0 to make sure the new transform is mapping to a lower subspace.



# EigenVectors
The $\vec{v}$ in the above equation is the EigenVector.
$\vec{v} = \vec{0}$ is not a valid Eigenvector

# EigenVectors of The Transpose
Ex: $A = \begin{bmatrix} -2 & -14 \\ -1 & 3 \end{bmatrix}$

$$P(\lambda) = (\lambda - 5)(\lambda + 4) \implies \boxed{\lambda_{1} = 5, \lambda_{2} = -4}$$

$$\lambda_1 = 5 \implies \begin{bmatrix} -2 \\ 1 \end{bmatrix}$$

$$\lambda_2 = -4 \implies \begin{bmatrix} \ 7 \ \\ \ 1 \ \end{bmatrix}$$

### Transposed A

$A^T = \begin{bmatrix} -2 & -1 \\ -14 & 3 \end{bmatrix}$
$$P_T(\lambda) = (\lambda - 5)(\lambda + 4) \implies \boxed{\lambda_{1} = 5, \lambda_{2} = -4}$$
*Same EigenValues*

$$\lambda_1 = 5 \implies \begin{bmatrix} 1 \\ -7 \end{bmatrix}$$

$$\lambda_2 = -4 \implies \begin{bmatrix} \ 1 \ \\ \ 2 \ \end{bmatrix}$$


Observe that for all $A$, $A$ and $A^T$ have the EigenValues.

### Inverse of A

$A^{-1} = \begin{bmatrix} -2 & -14 \\ -1 & 3 \end{bmatrix}^{-1}$

$A^{-1} = \begin{bmatrix}-\frac{3}{20}&-\frac{7}{10}\\ -\frac{1}{20}&\frac{1}{10}\end{bmatrix}$

$$P_{-1}(\lambda) = (\lambda + \frac{1}{4})(\lambda - \frac{1}{5})$$

**Notice that if** $\lambda_n$ is an eigenvalue for $A$, then $(\lambda_n)^{-1}$ is an eigenvalue for $A^{-1}$

In the end we see that $A^{-1}$ has the same eigenvectors as $A$.