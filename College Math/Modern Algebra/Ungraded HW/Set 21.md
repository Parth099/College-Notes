# 21
> **Exercises**: 4.4 #9, 10 (see also #15), 11, 12, 13, 15, 19

## 4.4.9

> List all monic irreducible polynomials of degree 2 in $\mathbb{Z}_3[x]$. Do the same in $\mathbb{Z}_5[x]$ .


### $\mathbb{Z}_3[x]$

+ $x^2$ (reducible)
	+  $x^2+x$ (reducible)
		+  $x^2+x+1$
		+  $x^2+x+2$
	+  $x^2+2x$ (reducible)
		+  $x^2+2x+1$ (reducible)
		+  $x^2+2x+2$


## 4.4.10

> Find a prime $p > 5$ such that $x^2 + 1$ is reducible in $\mathbb{Z}_p[x]$.


$x^2+1$ is reducible in $\mathbb{Z}_p[x]$ if $x^2 = -1$ this is true when $-1$ is a square in $\mathbb{Z}_p[x]$ .


Consider a prime $p$ where its in the form $a^2+1$ then $[a]$ is a root.

One of these primes is 17 as $17=4^2+1$


## 4.4.11
>Find an odd prime $p$ for which $x - 2$ is a divisor of $f=x^4 + x^3 + 3x^2 + x + 1$ in $\mathbb{Z}_p[x]$ .

Via the remainder theorem the remainder of $x-2$ dividing $f$ is the same as $f(2)$ which is $39$

Notice that $39=13*3$ implying $x - 2 | f$ under $\mathbb{Z}_{13}$

## 4.4.12

![4.4.12](../Problems/4.4.12.png)

Let $f$ be the first function and $g$ be the second function.

We know that $f(a)=0_F$ . 


...


## 4.4.13
![4.4.13](../Problems/4.4.13.png)
 
Given the equivalence class of associates. If $f, g$ are associates then $f R g$ , pick $h$ a monic representative of the equivalence class of $f$ and $g$ .

Since $h, f$ and $g$ only differ by a constant (as per the definition of associates) it is evident that they contain the same roots. 


## 4.4.15
![4.4.15](../Problems/4.4.15.png)

Let $f = x^2+1 \in \mathbb{Z}_p[x]$

### $\Leftarrow$

Suppose there exists integers $a, b \in \mathbb{Z}_p$ such that $p=a+b$ with $ab \equiv 1 \bmod p$ .

Then consider $(ax+1)(bx+1)$

$$
\begin{align}
(ax+1)(bx+1) &= abx^2+(a+b)x+1 \\
&= x^2+1
\end{align}
$$

Since there exists a factorization where each factor is non-constant and a lower degree than $f$ it is reducible.

### $\Rightarrow$

Suppose $x^2+1$ is reducible under $\mathbb{Z}_p[x]$ then it follows there exists a factorization $(ax+c)(bx+d)$ since $\deg f = 2$ .

$$
(ax+c)(bx+d) = abx^2 + (ad+bc)x + cd
$$

It follows that $cd=1$ implying $c=d=1$

Thus it is required that $ab=[1]_p$ and $a+b=[0]_p$

## 4.4.19
![4.4.19](../Problems/4.4.19.png)


### a)

#### $\Rightarrow$
Suppose $f$ has a multiple root at $a$ with multiplicity $k\geq 2$ . Then $f$ looks like:

$$
f = (x-a)^k q(x) + \underbrace{r(x)}_{0_F}
$$

This means that $f^\prime$ looks like:

$$
(x-a)^kq^{\prime}(x) + k(x-a)^{k-1}q(x)
$$

Notice that $f'(a)=0$

#### $\Leftarrow$

Suppose both $f, f^\prime$ have a root at $a$

Since $f^\prime$ has a root at $a$ it looks like:

$$
f^\prime = (x-a)^kq(x)
$$

for $k\geq 1$

...