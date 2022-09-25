# HW1
## Q1
### a
$$
\boxed{7} = \frac{35}{\gcd(15, 35)} = \frac{35}{5}
$$
### b

$$
\begin{align}
3^{2022} &= 9 * 3^{2020} &\stackrel{\text{Euler's theorem}}{\implies} & 9 * 3^{2020} \equiv_{11} 9 * 1 = \boxed{9}
\\
\phi(11) &= 11 - 1 = 10
\end{align}
$$
### c
$$\phi(33) = (3 - 1)(11 - 1) = 20$$
$$
\begin{align}
2^{2022} &= 4 * 2^{2020} &\stackrel{\text{Euler's theorem}}{\implies} &&4 * 2^{2020} \equiv_{33} 4 * 1 = \boxed{4}
\\
\end{align}
$$
### d
$$
\phi(31) = 31 - 1  = 30
$$
$$
\begin{align}
5^{30000} = 5^{{30}^{1000}} \ \ \ \ \stackrel{\text{Euler's theorem}}{\implies} \ \ \ \ 5^{{30}^{1000}} &\equiv_{31} = 1^{1000} = 1 \\ \\
6^{123,456} =6^6 6^{{30}^{4115}} \ \ \ \ \stackrel{\text{Euler's theorem}}{\implies} \ \ \ \ 6^6 6^{{30}^{4115}} &\equiv_{31} 6^6 \times 1
\\
&\equiv_{31} 5^3 = 4*31 + 1 \\
&\equiv_{31} = \boxed{1}
\end{align}
$$

Since $5^{30000} - 6^{123,456} \equiv_{31} 1-1=0$, $31|5^{30000} - 6^{123,456}$
## Q2
$$
\begin{align}
3^{2022}\equiv_{11} 9^{1011} \equiv_{11} 9\cdot 81^{505} \equiv_{11} 9\cdot 4^{505} &\equiv_{11} 9\cdot4\cdot 64^{125}
\end{align}
$$

**NOT DONE**

## 1.10
Given: 
+ (1) $a\equiv b\mod{N}$
+ (2) $M|N$

Since $a\equiv b\mod{N}$, $N|b-a$. This means that $\exists c\in\mathbb{Z}$ such that $cN = b-a$

Since $M|N$, $\exists k\in\mathbb{Z}$ such that $kM=N$

Therefore $cN = ck\cdot M = b-a$

Since $ck\in\mathbb{Z}$, $M|b-a$.
Therefore $a\equiv b\mod{M}$

## 2
$$
\begin{align}
	3^1 \equiv_3  3\\ \\
	3^2 \equiv_3  9\\ \\
	3^4 \equiv_3  7\\ \\
	3^8 \equiv_3 12\\ \\
	
	3 \times 1 &\equiv_3 3 \\
	&3 \\
	3 \times 7 \equiv_3 21 \\
	21 * 12 \equiv_3 30
\end{align}
$$

## 4
$$
\begin{pmatrix}
	0 & 1 \\ 1 & -3
\end{pmatrix}
\begin{pmatrix}
	0 & 1 \\ 1 & -13
\end{pmatrix}
=
\begin{pmatrix}
	 1 & -13 \\ -3 & 40
\end{pmatrix}
$$

## 5
$$
\begin{align}
	p &= 5 \\
	q &= 11 \\
	\implies \phi(N) &= 40 \\
	e &= 3 \\
	d &= -13 \\
\end{align}
$$

Since $d < 0$ we must consider $d\mod{40}$ which is **$27$**