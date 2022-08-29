| Date    |
| ------- |
| 8-29-22 |

# Fib Matrix
## Inductive Proof

Show $\forall n\geq 1$
$$
\begin{pmatrix}
	1&1\\1&0
\end{pmatrix}^n = 

\begin{pmatrix}
	F_{n+1} & F_{n}\\ F_{n} & F_{n-1}
\end{pmatrix}
$$

**Base case** $n = 1$
$$
\begin{pmatrix}
	1&1\\1&0
\end{pmatrix}^1 = 

\begin{pmatrix}
	1&1\\1&0
\end{pmatrix}

=

\begin{pmatrix}
	F_{2} & F_{1}\\ F_{1} & F_{0}
\end{pmatrix}
$$
Therefore the formula is *valid* for $n = 1$

**Inductive step**: Assume 
$$\forall k \geq 1, \begin{pmatrix}
	1&1\\1&0
\end{pmatrix}^k = 

\begin{pmatrix}
	F_{k+1} & F_{k}\\ F_{k} & F_{k-1}
\end{pmatrix}$$

Consider, $\begin{pmatrix}1&1\\1&0\end{pmatrix}^{k+1}$

$$
\begin{align}
	\begin{pmatrix}1&1\\1&0\end{pmatrix}^{k+1} &= \begin{pmatrix}1&1\\1&0\end{pmatrix}^k\cdot\begin{pmatrix}1&1\\1&0\end{pmatrix}
	\\ \\
	&\stackrel{\text{IH}}{=} 
		\begin{pmatrix}
		F_{k+1} & F_{k}\\ F_{k} & F_{k-1}
		\end{pmatrix}
		\cdot\begin{pmatrix}1&1\\1&0\end{pmatrix}
		
	\\ \\ 
	&= \begin{pmatrix}
		F_{k+2} & F_{k+1}\\ F_{k+1} & F_{k}
		\end{pmatrix}
\end{align}
$$

Therefore $\forall n\geq1, \ \begin{pmatrix}1&1\\1&0\end{pmatrix}^n = \begin{pmatrix}F_{n+1} & F_{n}\\ F_{n} & F_{n-1}\end{pmatrix}$

---

