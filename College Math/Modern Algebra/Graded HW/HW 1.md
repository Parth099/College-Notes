# HW 1

## Problem 1.1

Assume $k \in \mathbb{Z}$

Using the division algorithm via $k$ as the dividend and $3$ as the divisor, $k$ can be represented as:

$$
\begin{align}
k = 3q+r \text{ where } &q, r \in \mathbb{Z} \\
\text{ and }& 0 \leq r \lt 3
\end{align}
$$

---

Suppose $r = 0$ ,

Since $k = 3q$ then it follows that $3|k*(k+1)*(k+2)$ since $3$ is a divisor of $k$.

---

Suppose $r = 1$ ,

Then $k = 3q+1$ implying that $k+2 = 3q+3 = 3(q+1) = 3p$ for some $p\in\mathbb{Z}$ .

Since $k+2$ can be represented as $3p$ it means $3|k+2$ and it logically follows that $3|k*(k+1)*(k+2)$

---

Suppose $r = 2$ , 

Then $k = 3q+2$ implying that $k+1 = 3q+3 = 3(q+1) = 3p$ for some $p\in\mathbb{Z}$ .

Since $k+1$ can be represented as $3p$ it means $3|k+1$ and it logically follows that $3|k*(k+1)*(k+2)$

---

Therefore $3|k*(k+1)*(k+2)$ for any $k\in\mathbb{Z}$

## Problem 2
### $n=8$

+ $\gcd(\mathbf{1}, 8)=1$ 
	+ $1(-7) + 8(1) = 1$ 
+ $\gcd(\mathbf{3}, 8)=1$ 
	+ $3(3) + 8(-1) = 1$ 
+ $\gcd(\mathbf{5}, 8)=1$ 
	+ $5(5) + 8(-3) = 1$ 
+ $\gcd(\mathbf{7}, 8)=1$ 
	+ $7(7) + 8(-6) = 1$ 

### $n=12$

+ $\gcd(\mathbf{1}, 12)=1$ 
	+ $1(-11) + 12(1) = 1$ 
+ $\gcd(\mathbf{5}, 12)=1$ 
	+ $5(-7) + 12(3) = 1$ 
+ $\gcd(\mathbf{7}, 12)=1$ 
	+ $7(7) + 12(-6) = 1$ 
+ $\gcd(\mathbf{11}, 12)=1$ 
	+ $11(11) + 12(-10) = 1$ 

### $n=20$

+ $\gcd(\mathbf1, 20)=1$ 
	+ $1(1) + 20(0) = 1$
+ $\gcd(\mathbf3, 20)=1$
	+ $3(7) + 20(-1) = 1$
+ $\gcd(\mathbf7, 20)=1$
	+ $7(3) + 20(-1) = 1$
+ $\gcd(\mathbf9, 20)=1$
	+ $9(9) + 20(-4) = 1$
+ $\gcd(\mathbf11, 20)=1$
	+ $11(-9) + 20(5) = 1$
+ $\gcd(\mathbf13, 20)=1$
	+ $13(-3) + 20(2) = 1$
+ $\gcd(\mathbf17, 20)=1$
	+ $17(-7) + 20(6) = 1$
+ $\gcd(\mathbf19, 20)=1$
	+ $19(-1) + 20(1) = 1$

### $n=25$

+ $\gcd(\mathbf1, 25)=1$
	+ $1(1) + 25(0) = 1$
+ $\gcd(\mathbf2, 25)=1$
	+ $2(-12) + 25(1) = 1$
+ $\gcd(\mathbf3, 25)=1$
	+ $3(-8) + 25(1) = 1$
+ $\gcd(\mathbf4, 25)=1$
	+ $4(-6) + 25(1) = 1$
+ $\gcd(\mathbf6, 25)=1$
	+ $6(-4) + 25(1) = 1$
+ $\gcd(\mathbf7, 25)=1$
	+ $7(-7) + 25(2) = 1$
+ $\gcd(\mathbf8, 25)=1$
	+ $8(-3) + 25(1) = 1$
+ $\gcd(\mathbf9, 25)=1$
	+ $9(-11) + 25(4) = 1$
+ $\gcd(\mathbf11, 25)=1$
	+ $11(-9) + 25(4) = 1$
+ $\gcd(\mathbf12, 25)=1$
	+ $12(-2) + 25(1) = 1$
+ $\gcd(\mathbf13, 25)=1$
	+ $13(2) + 25(-1) = 1$
+ $\gcd(\mathbf14, 25)=1$
	+ $14(9) + 25(-5) = 1$
+ $\gcd(\mathbf16, 25)=1$
	+ $16(11) + 25(-7) = 1$
+ $\gcd(\mathbf17, 25)=1$
	+ $17(3) + 25(-2) = 1$
+ $\gcd(\mathbf18, 25)=1$
	+ $18(7) + 25(-5) = 1$
+ $\gcd(\mathbf19, 25)=1$
	+ $19(4) + 25(-3) = 1$
+ $\gcd(\mathbf21, 25)=1$
	+ $21(6) + 25(-5) = 1$
+ $\gcd(\mathbf22, 25)=1$
	+ $22(8) + 25(-7) = 1$
+ $\gcd(\mathbf23, 25)=1$
	+ $23(12) + 25(-11) = 1$
+ $\gcd(\mathbf24, 25)=1$
	+ $24(-1) + 25(1) = 1$

## Problem 3

> **Bézout's identity**:
> Let $a, b \in\mathbb{Z}$ such that both are not zero. Then, 
> $$\exists u, v\in\mathbb{Z}: (a, b) = au+bv$$

### Forwards $(\Rightarrow)$

Given $(a, b)=1$ we can use Bézout's identity (Theorem 1.2) we can ensure there exists  $\exists u, v \in \mathbb{Z}$ such that $au+bv=1$ . 

### Backwards $(\Leftarrow)$

Suppose $\exists u, v \in \mathbb{Z}: au+bv=1$ 

Assume that $\gcd(a, b)=d \gt 1$

Since $d$ is the largest integer that divides $a$ and $b$ :

$$
\begin{align}
a = dn &\text{ for } n \in \mathbb{Z} \\
b = dm &\text{ for } m \in \mathbb{Z}
\end{align}
$$

Thus:

$$
1 = au+bv = dnu + dmv = d(nu+mv)
$$

Notice the product $d \cdot (nu+mv)$ is equal to 1. Therefore $d$ cannot be greater than one (***contradiction***).

Thus, $d = \boxed{\gcd(a, b)=1}$

## Problem 4
### Part *a*
#### Existence

Suppose $a, b \in\mathbb{Z}$ such that both are not zero and $d=\gcd(a, b)$

Since $d|a$ and $d|b$ :

$$
\begin{align}
a = da^{\prime} &\text{ for } a^{\prime} \in \mathbb{Z} \\
b = db^{\prime} &\text{ for } b^{\prime} \in \mathbb{Z}
\end{align}
$$


#### Uniqueness
Suppose there exists another set of integers $a^{\prime}_1$ and  $b^{\prime}_1$ such that

$$
\begin{align}
a &= d \cdot a^{\prime}_1\\ 
b &= d \cdot b^{\prime}_1\\ 
\end{align}
$$

Since $a = da^{\prime}$ and $b = db^{\prime}$ (see **Existence** above):

$$
\begin{align}
da^{\prime} &= d \cdot a^{\prime}_1\\ 
db^{\prime} &= d \cdot b^{\prime}_1\\ 
\end{align}
$$

Since $d\gt0$ , $d$ can be divided from both sides:

$$
\begin{align}
a^{\prime} &= a^{\prime}_1\\ 
b^{\prime} &= b^{\prime}_1\\ 
\end{align}
$$

Notice both qualities are equal.

Therefore, exists unique $a^′, b^′ \in\mathbb{Z}$ such that $a = da^′$ and $b = db^′$.

### Part *b*

**Preface**:

$$
\begin{align}
a &= d \cdot a^{\prime}_1\\ 
b &= d \cdot b^{\prime}_1\\ 
\end{align}
$$

**Proof**:

Since $d=(a, b)$ and $a, b$ both not $0$,  

$$\exists u, v \in \mathbb{Z}: au+bv=d$$

Sub in $a$ and $b$ from *Part a*:

$$
\mathbf{d} = au+bv = (da^′)u + (db^′)v = d(a^′u+b^′v)
$$

Since $d \gt 0$ both sides can be divided by $d$ :

$$
a^′u+b^′v = 1
$$

Since there exists a integer linear combination such that the linear combination equals 1, ${(a^′, b^′) = 1}$