| Homework | Name        | TUID        |
| -------- | ----------- | ----------- |
| HW3      | Parth Patel | 915 805 716 | 

# HW 3
## Problem 3.1
### 3.1a
<!--
Since $M$ is a subset of $R$ closed under subtraction, $0_R \in M$ .

Notice the following is true:

Let $m=0_R$


$$
m \in M, \forall r \in R, m\cdot r = 0_R \in M
$$

This means that $S$ contains all element of $R$ and is equivalent to $R$. 

The above is true because  no further elements can be added since $M \subseteq R$ and multiplication and subtraction is closed under ring $R$ . This closure implies that for any $m\in M$ and $r\in R$ , $m \cdot r$ cannot generate anymore elements not already in $S$ when $S$ is constructed by taking $m=0_R$ .

Since $S=R$ it follows that $S$ is closed under multiplication and subtraction. 

$S$ is then only a subring of $R$ if $R$ contains a multiplicative identity $1_R$ . 
-->

$$
S = \{r \in R\ |\ rm \in M \text{ for all } m\in M\}
$$

*Showing:* $(\mathbf{1})\ 1_R \in S$
Consider $1_R$ . Since $M \subseteq R$ , for any $m \in M$ , $1_R\cdot m = m \in M$ . Thus $\boxed{1_R \in S}$

---

*Showing:* $(\mathbf{2})\ S$ is closed under Subtraction.

Let $r_1, r_2 \in S$ . Then **for any** $m \in M$ $r_1m, r_2m\in M$

Now $r_1m - r_2m = (r_1-r_2)m \in M$ since $M$ is closed under subtraction.  Let $r=r_1-r_2 \in R$ then the above is equivalent to $rm \in M$ . Since we started with any $m$ , $r = r_1-r_2 \in S$ since $rm \in M$ for any $m$ .

---

*Showing:* $(\mathbf{3})\ S$ is closed under Multiplication.

Let $r_1, r_2 \in S$ . Then **for any** $m \in M$ $r_1m, r_2m\in M$ .

Let $n=r_2m$ . Then $n \in M$ Since $n \in M$ , $r_1\cdot n = r_1r_2m \in M$ for any $m$ .


Since $r_1r_2m \in M$ for any $m$ , $r_1r_2 \in S$ implying $S$ is closed under Multiplication.

---

$$
\therefore S \text{ is a subring of } R
$$

### 3.1b
Suppose $M$ was not closed under addition and $M = \{1_R\}$ . Then $1_R \in S$ since for any $m$ , $1_R\cdot m \in M$ . Yet $0_R$ not in $S$ since $0_R \cdot 1_R = 0_R \not \in R$ . For $S$ to be a subring $0_R \in S$ , thus $S$ cannot be a subring. 


## Problem 3.2 
**Defining Operations**

Let $t_1 \in T$ such that $t_1=(r_1, s_1)$ for $r_1\in R$ and $s_1 \in S$
Let $t_2 \in T$ such that $t_2=(r_2, s_2)$ for $r_2\in R$ and $s_2 \in S$

Then we can define component operations via:

$$
\begin{align}
t_1 \oplus t_2 &= (r_1, s_1) \oplus (r_2, s_2) = (r_1+r_2, s_1+s_2)  \\
t_1 \odot t_2 &= (r_1, s_1) \odot (r_2, s_2) = (r_1 \cdot r_2, s_1 \cdot s_2) 
\end{align}
$$

Notice in by definition

$$
\begin{align}
0_T &= (0_R, 0_S) \\
1_T &= (1_R, 1_S)
\end{align}
$$

> I am assuming multiplicative ring identities exist as the problem states $1 \neq 0$ for both rings $S$ and $R$ .

$$
\begin{align}

\end{align}
$$

**Defining Sets**
**Units**
$$
\begin{align}
T^{\times} &=\ \biggr\{ t \in T\ \biggr|\ \exists t^{\prime} \in T : t t^{\prime} = 1_T  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists (r^{\prime}, s^{\prime}) \in R \times S : (r, s)\cdot (r^{\prime}, s^{\prime}) = (1_R, 1_S)  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists (r^{\prime}, s^{\prime}) \in R \times S : (r\cdot r^{\prime}, s\cdot s^{\prime}) = (1_R, 1_S)  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists (r^{\prime}, s^{\prime}) \in R \times S : r\cdot r^{\prime} = 1_R , s\cdot s^{\prime} = 1_S \biggr\}
\end{align}
$$

**Zero Divisors**

$$
\begin{align}
Z &=\ \biggr\{ t \in T\ \biggr|\ \exists t^{\prime} \in T : t t^{\prime} = 0_T  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists (r^{\prime}, s^{\prime}) \in R \times S : (r, s)\cdot (r^{\prime}, s^{\prime}) = (0_R, 0_S)  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists (r^{\prime}, s^{\prime}) \in R \times S : (r\cdot r^{\prime}, s\cdot s^{\prime}) = (0_R, 0_S)  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists (r^{\prime}, s^{\prime}) \in R \times S : r\cdot r^{\prime} = 0_R , s\cdot s^{\prime} = 0_S \biggr\}
\end{align}
$$

**Nilpotent**

$$
\begin{align}
N &=\ \biggr\{ t \in T\ \biggr|\ \exists n \in \mathbb{Z}_{\gt 0} : \underbrace{t \odot \dotso \odot t}_{n \text{ times}} = 0_T  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists n \in \mathbb{Z}_{\gt 0} : \underbrace{(r, s) \odot \dotso \odot (r, s)}_{n \text{ times}} = 0_T  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists n \in \mathbb{Z}_{\gt 0} : (r^n, s^n) = (0_R, 0_S)  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists n \in \mathbb{Z}_{\gt 0} : r^n = 0_R,\ s^n = 0_S  \biggr\} \\
\end{align}
$$

## Problem 3.3
### 3.3a
> I will focus on $\bar{R}$ for this problem.

$$
\bar{R} = R \times \{0_S\}
$$

See that each element of $\bar{R}$ will look like $(r, 0_S)$ for $r \in R$ . 

Also notice that $\{0_S\}$ is the zero ring.

Under ***Theorem 3.1***, $\bar{R}$ is a ring under component-wise binary operations since $R$ and $\{0_S\}$ are rings. 

### 3.3b

Let $f: R \to \bar{R}$ where $r \mapsto (r, s_0)$ for $r \in R$ and $(r, s_0) \in \bar{R}$

**Homomorphism**

If $1_R \in R$ notice $f(1_R)=(1_R, 0_S)$ which is $1_\bar{R}$

Let $a, b \in R$

Then:

$$
\begin{align}
f(a + b) = (a+b, 0_S) &= \underbrace{(a, 0_S)}_{f(a)} + \overbrace{(b, 0_S)}^{f(b)} = f(a)+f(b) \\
f(a \cdot b) = (a \cdot b, 0_S) &= \underbrace{(a, 0_S)}_{f(a)} \cdot \overbrace{(b, 0_S)}^{f(b)} = f(a) \cdot f(b)
\end{align}
$$

Thus, $f$ is a valid ring homomorphism. 

**Isomorphic Proof**

*Injective*
Suppose $f(a_1)=f(a_2)$

Then $(a_1, 0_S)=(a_2, 0_S)$ implying that $a_1=a_2$ and $0_S=0_S$

Since $f(a_1)=f(a_2)$ implies $a_1=a_2$ , $f$ is a injective map.

*Surjective*

Suppose $\bar{r} \in \bar{R}$ where $\overline{r} =(r, 0_S)$ for $r\in R$

Then for $r \in R$ , $f(r) = (r, 0_S) = \overline{r}$ .
Thus $f$ is surjective.

*Bijective*
Since $f$ is both injective and surjective $f$ is bijective. 


### 3.3c

$\overline{R}$ is not a subring of $T$ since $1_T = (1_R, 1_S) \not\in \overline{R}$

## Problem 3.4

Let $R$ be any ring. 

Let $f: \mathbb{Z}\to R$ be a ring homomorphism.

Then by definition of homomorphism, $f(0) = 0_R$ and $f(1) = 1_R$ .

Then, $f(0) = f(1+(-1)) = f(1)+f(-1)$ . By uniqueness of additive inverses $f(-1) = -f(1)$ which we can call $-1_R$ .

If $n > 0$ then it must follow

$$
f(n) = f(1+\dotso+1) = f(1)+\dotso+f(1)
$$

If $n < 0$ then it must follow

$$
f(n) = f\biggr((-1)+\dotso+(-1)\biggr) = f(-1)+\dotso+f(-1) = (-1_R) + \dotso + (-1_R) 
$$

This shows that $f(n) = n \cdot 1_R$

Since no specific $f$ was chosen to be the ring homomorphism it must follow that this one is unique.