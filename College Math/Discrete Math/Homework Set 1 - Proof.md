# Chapter 1
## Section 3
### Definition For Divisibility
> Let $a, b \in \mathbb{Z}$. $a$ is **divisible** by $b$ provided there is an $c \in \mathbb{Z}$ s.t $bc = a$. 
> 
> Notation $b \rvert a \implies b\text{ divides } a$

$3|12$ means $3$ divides $12$.

### Exercises
##### 3.1.a 
$3 | 100$ - *false*
See that $3 * 33 = 99$ and $3 * 34 = 102$. $$99\lt 100\lt 102$$
This means that if $3|100$ and $3c=100$ then $$33\lt c\lt34$$
Since no Integer between 3 or 4 (Exclusive or), 
**$$3 \nmid 100$$**

##### 3.1.b
$3|99$ - *true*. $3*33=99$

##### 3.1.c
$-3|3$ - *true*. $-3 * -1 = 3$

##### 3.1.e
$-2|-7$ - *false*
Same logic as **3.1.a**

##### 3.1.f
$0|4$ - *false*
Statement: $0$ divides $4$ $\implies 0c=4$
$\lnot \exists c\in\mathbb{Z}$ s.t $0 \times c = 4$

##### 3.1.g
$4|0$ - *true*, $4 * 0 = 0$

##### 3.1.h
$0|0$ - *true*
Statement $0$ divides $0$, $\implies 0c = 0$
$\forall c\in\mathbb{Z} \ 0c=0$

## Section 5
### Exercises
##### 5.1 Prove that the sum of two odd integers is even
Let $a, b \in\mathbb{Z}$ be odd. 
This means that:
$$
\begin{align*}
a &= 2n+1\\
b &= 2m+1
\end{align*}
$$
for $n, m \in\mathbb{Z}$.
$$\begin{align*}
a+b&=(2n+1)+(2m+1)=2n+2m+1+1 \\
&= 2n+2m+2\\
&= 2(n+m+1)
\end{align*}$$
Since $2|2(n+m+1)$ as $2 * (n+m+1)= 2(n+m+1)$
and $2(n+m+1) = a+b$ then 
**$$\boxed{2|a+b}$$**

##### 5.2
Skipped since its alike 5.1
##### 5.3 Prove that if $n$ is an odd integer, then -$n$ is also odd
$$n = 2a+1, a\in\mathbb{Z}$$
This means that $$n*-1 = -n = -(2a+1)$$
$$
\begin{align*}
-n &= -2a-1 \\
&= -2a -2 +1 \\
&= 2(-a-1)+1
\end{align*}
$$
then by definition $-n$ is odd

##### 5.4 Prove that the product of two even integers is even
Let $a, b\in\mathbb{Z}$ be even.
$$\begin{align*}
a &= 2n \\
b &= 2m
\end{align*}
$$
for $n, m\in\mathbb{Z}$
$$\begin{align*}
a * b &= 2n * 2m\\
&= 4nm
\end{align*}
$$

Since $2|4nm$ as $2*2nm = 4nm$. $4mn$ is **even**. 
$$4nm = a * b \implies 2|a*b$$

##### 5.5 Prove that the product of an even integer and an odd integer is even
Let $a, b \in\mathbb{Z}$. $a$ is *even*, $b$ is *odd*.
$$\begin{align*}
a &= 2n \\
b &= 2m + 1 
\end{align*}
$$
for $n, m\in\mathbb{Z}$
$$\begin{align*}
a*b &= (2n) * (2m+1) \\
&= 4nm + 2n \\
&= 2n(m+1)
\end{align*}
$$

Since $a*b = 2n(m+1)$ and $2|2n(m+1)$ as $$2 *n(m+1)*=2n(m+1)$$
The product of even and odd integers is **even**.

##### 5.7 Prove that the square of an odd integer is odd.
Let $p\in\mathbb{Z}$ and odd. 
Thus:
$$p=2n+1, \ n\in\mathbb{Z}$$
$$\begin{align*}
p^2 &= (2n+1)^2 \\
&= 4n^2 + 4n + 1 \\
&= 2(2n^2 + 2n) + 1
\end{align*}
$$
Since $n\in\mathbb{Z}$, $2n^2+2n$ is also an integer. We will call this integer $k$.
$$k = 2n^2+2n \implies p^2 = 2k+1$$
Since $p$ is $2$ times an integer $k$ and one more it is **odd**.

##### 5.10 
> Suppose $a, b$, and $c$ are integers. Prove that if $a|b$, then $a|bc$

Since we know $a|b$ then $$b = ad,\ d\in\mathbb{Z}$$
$$a|bc \implies a|adc$$
$a|adc$ because $a*dc = adc \implies a|adc$.

##### 5.12
> Suppose a, b, c, and d are integers. Prove that if a|b and c|d then$$(ac)|(bd)$$

Since we know $a|b$ and $c|d$ we can state:
$$
\begin{align*}
b &= n*a \\
d &= m*c
\end{align*}
$$
$\implies ac|(na * mc)$    by Substitution
$\implies ac|(ac * nm)$    by Commutative Prop 

$ac * nm = acnm \implies ac|acnm$
$$\implies ac|bc$$
