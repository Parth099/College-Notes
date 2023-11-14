# HW 4
## Problem 4.1
Let $R$ be a commutative ring and let $r\in R$ be given. Define:

$$
\begin{align}
\rho&: R[x] \to R \\
\rho&(a_nx^n + a_{n-1}x^{n-1} + \,\dotso\, + a_0) := a_nr^n + a_{n-1}r^{n-1} + \,\dotso\, + a_0
\end{align}
$$

where each $a_i \in R$

### $4.1.a)$

> Show $\rho$ is a ring epimorphism (*onto*)


Notice that $\rho(1_{R[x]})=1_R$ since $1_{R[x]} = 1_R$ .

$1_{R[x]}$ is obtained from taking all $a_i$ but $a_0$ to be $0$ and fixing $a_0 = 1_R$ .

Let $f, g \in R[x]$ 

Then 

$$
\begin{align}
f &= a_nx^n + a_{n-1}x^{n-1} + \ldots + a_1x + a_0 \\
g &= b_mx^m + b_{m-1}x^{m-1} + \ldots + b_1x + b_0
\end{align}
$$

Consider $\rho(f-g)$ for some $r \in R$ then:


$$
\begin{align}
\rho(f-g) &=  \rho([a_{n-1}x^{n-1} + \ldots + a_1x + a_0] - [b_mx^m + b_{m-1}x^{m-1} + \ldots + b_1x + b_0]) \\
&= \biggr(\underbrace{[a_{n-1}r^{n-1} + \ldots + a_1r + a_0]}_{\rho(f)} - \overbrace{[b_mr^m + b_{m-1}r^{m-1} + \ldots + b_1r + b_0]}^{\rho(g)}\biggr) \\
&= \boxed{\rho(f) - \rho(g)}
\end{align}
$$

Consider $\rho(fg)$ for some $r \in R$ then:

$$
\begin{align}
\rho(fg) &= \rho\biggr(\sum_{k=0}^{m+n} \biggr[ \sum^{i+j=k}a_ib_j \biggr]x^k \biggr) = \sum_{k=0}^{m+n} \biggr[ \sum^{i+j=k}a_ib_j \biggr]r^k
\end{align}
$$

Then consider $\rho(f)\cdot \rho(g)$

$$
\begin{align}
\rho(f)\cdot \rho(g) &= [a_{n-1}r^{n-1} + \ldots + a_1r + a_0] \cdot [b_mr^m + b_{m-1}r^{m-1} + \ldots + b_1r + b_0] \\
&= \sum_{k=0}^{m+n} \biggr[ \sum^{i+j=k}a_ib_j \biggr]r^k
\end{align}
$$

Notice
+ The identity is mapped by $\rho$
+ $\rho$ respects subtraction and multiplication 

$$
\therefore \rho \text { is a homomorphism}
$$
 
--- 
 
Consider an constant element $a \in R$ . This same element $a$ is a constant polynomial in $R[x]$. Therefore for any $r \in R$ there exists a element $r^{\prime}$ in $R[x]$ such that $\rho(r^{\prime})=r$ . This $r^{\prime} \in R[x]$ is equal to $r\in R$ . 


### $4.1.b)$

Fix $r$ to be $0_R$

Let $f, g\in R[x]$ defined as:

$$
\begin{align}
f &= a_1x + a_0 \\
g &= b_1x + a_0 \text{ for } a_i, b_i \in R
\end{align}
$$

Notice that:

$$
\begin{align}
\rho(f) &= a_1(0_R) + a_0 = a_0 \\
\rho(g) &= b_1(0_R) + a_0 = a_0
\end{align}
$$

Since $\rho(f) = \rho(g)$ yet $f \neq g$ , $\rho$ is **not** injective and subsequently not a ring isomorphism. 

## Problem 4.2

### $4.2.a)$

Since $(f, g)=1_F$ , $\exists u,v \in F[x]: fu+gv=1_F$

Since $f|h$ , $\exists a \in F[x]: fa=h$ and since $g|h$ , $\exists b \in F[x]: gb=h$

$$
\begin{align}
h = h \cdot 1_F &= h (fu + gv) \\
&= hfu + hgv = (gb)fu + (fa)gv \\
&= fg (bu+av)
\end{align}
$$

Since there exists a polynomial $bu+av \in F[x]$ such that its product with $fg$ results in $h,\ fg|h$ .

### $4.2.b)$

Suppose $h|f$ then there exists $a \in f[x]$ such that $ha=f$ .

Since $(f, g)=1_F$ , $\exists u,v \in F[x]: fu+gv=1_F$

Then via substitution:

$$
(h\underbrace{a)u}_{b}+gv=1_F = hb + gv =1_F
$$

Since $\exists b,v \in F[x]: hb + gv = 1_F$ , $(h, g) = 1_F$ 

## Problem 4.3

Let $R$ be an integral domain and let $a, b \in R$ .

### $\Rightarrow$

Suppose $a$ and $b$ are associates.  This means that there exists $u\in R^{\times}$ such that: $b=ua$

With this definition it is clear that $a|b$ since $\exists u \in R: au=b$ .

Since $u$ is a unit $\exists u^{\prime} \in R: u^{\prime}u=1_R$ . Then,

$$
u^{\prime}b = (u^{\prime})ua = a \implies \boxed{u^{\prime}b=a}
$$

Since there exists $u^{\prime} \in R$ such that $u^{\prime}b=a$ , $b|a$

### $\Leftarrow$

Suppose $a|b$ and $b|a$ .

Then there exists $c_1, c_2 \in R$ such that 

$$
\begin{align}
ac_1 &= b \\
bc_2 &= a
\end{align}
$$

Then via substitution: 

$$
(bc_2)c_1 = b \stackrel{*}{\implies} c_1c_2 = 1_R
$$ 

The "cancellation" is permitted since $R$ is an integral domain. Note if $a$ or $b$ were zero the statement "$a$ and $b$ are associates" would be trivially true. 

Since $c_1c_2 = 1_R$ then $c_1, c_2 \in R^{\times}$ .

$$
\therefore a \text{ and } b \text{ are associates}
$$

## Problem 4.4

Let $R$ be an integral domain and let $a, b \in R$ such that $a, b$ are associates.

Suppose $a$ is irreducible, since $a$ and $b$ are associates then there exists a unit $u$ where

$$
b = au
$$

Let $a$ be factored down where $a=pq$ and since $a$ is irreducible, one of $p$ or $q$ are units. For brevity, let $q$ be the unit.

Then $b=pqu$ . Let $s=qu$ and since $q$ and $u$ are units, $s$ is a unit. Then $b=ps$ and since $s$ is a unit $b$ is irreducible since one of its factors is a unit.

Therefore $b$ is irreducible if $a$ is under $R$ being an integral domain and $a,b$ associates.

The converse of this statement which is

$$
b \text{ irreducible} \implies a \text{ irreducible}
$$

is also true since the proof for it is symmetric to $a$ as $u^{-1}b = a$

$$
\boxed{\therefore a \text{ irreducible} \iff b \text{ irreducible}}
$$