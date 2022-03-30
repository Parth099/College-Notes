# Relatively Prime and Divisibility
Recall from a previous note that for any $a,b \in\mathbb{Z}$ not both zero, $a, b$ are relatively Prime **if** $\text{gcd}(a, b) = 1$

## Theorem of Relative Primality
> Two non-zero integers $a, b$ are relatively Prime **iff** $$\exists n, m\in\mathbb{Z} \text{ s.t } an+mb=1$$

## Theorem 
> Let $a, b, c\in\mathbb{Z}$. 
> If $a|bc$ and $a, b$ are relatively Prime then $a|c$

### Proof
Since $a, b$ are relatively Prime, $\exists n, m\in\mathbb{Z} \text{ s.t } an+mb=1$

Thus,
$$
c = c\cdot 1 = c(an+mb) = n(ac) + m(bc)
$$

Since $a|(ac)$ and $a|(bc)$, $a|n(ac) + m(bc)$
Since $n(ac) + m(bc) = c$, $a|c$

### Example
> Let $x \in\mathbb{Z}$. 
> Show $7|4x + 21$ **iff** $7|x$

Suppose $7|x$, then $x = 7n$ for some $n\in\mathbb{Z}$

Then
$$4x + 21 = 4(7n) +21 = 28n+21 = 7(4n+3)$$

Since $4n+3\in\mathbb{Z}$, $7|4x+21$ if $7|x$ 

Suppose $7|4x+21$

Since $7|21$, $7|4x+21 + (-1)21$
Thus $7|4x$

Since $\text{gcd}(7, 4) = 1$ and $7|4x$, $x$ contains a factor of $7$ or we can say $7|x$

## Property 
> Let $a, b, c$ be non-zero integers. Suppose $a|c$ and $b|c$ and $a,b$ are relatively Prime. **Then** $ab|c$ 

### Proof: 
Since $a|c$ then, $c=an$ for some integer $n$.
Since $b|c$, $b|an$

Given that $\text{gcd}(a, b) = 1$ and $b|an$, $b|n$
Thus $n = bm$ for an integer $m$

Now $c = a(bm)$
Since $m\in\mathbb{N}$, $ab|c$

### Example
We know that 
> $$\begin{align}
> \forall n\in\mathbb{Z},\: 2&|n(n+1)\\
\forall n\in\mathbb{Z},\: 3&|n(n+1)(n+2)\\
> \end{align}$$

Thus 
$$\forall n\in\mathbb{Z},\: 2|n(n+1)(n+2)$$

$$\text{Since gcd}(2, 3) = 1$$

$$6|n(n+1)(n+2)$$

## **Fundamental** Theorem of Arithmetic
> Any integer $\geq2$ can be written as a **unique** product of primes. The factorization is **unique** except for the order of the factors.  

### Prime Properties
> Assume $p$ is a prime
1. Only one is true:
	+	$p|a$
	+	$\text{gcd}(a, p) = 1$

2. if $p|ab$ then either $p|a$ or $p|b$
#### Proof for \#1
Since $p$ is prime the only possible divisors of $p$ are $1$ or $p$ *itself*. 

Let $d = \text{gcd}(a, p)$
Thus $d|a$ and $d|p$

Hence, $d\in\{1, p\}$

#### Proof \#2
Suppose $p|ab$. 
If $p|a$ we are done. 
If $p\nmid a$, then $\text{gcd}(a, p) = 1$
Since $p|ab$, then $p|b$

Thus either $p|a$ or $p|b$

## Theorem
> Let $p$ be a prime and let $a_1, \cdots, a_n\in\mathbb{Z}$ for $n \geq 2$
> Suppose $p|a_1, \cdots, a_n$
> Then, $p|a_i$ for some $i\in\{1, \cdots, n\}$


### Proof - Inductive (Weak)
For $n = 1$
Suppose $p|a_1 a_2$. By a previous argument we note that either $p|a_1$ or $p|a_2$

Assume if $p|a_1 \cdots a_n\in\mathbb{Z}$ for $n \geq 2$ then $\exists i\in\{1, \cdots, n\}$ s.t $p|a_i$

Suppose $p|a_1 \cdots a_n a_{n+1}$

Notice that $p|a_1 \cdots a_na_{n+1}$ is the same as $p|(a_1 \cdots a_n)(a_{n+1})$

Thus, either $p|a_1 \cdots a_n$ or $p|a_{n+1}$

If $p|(a_1 \cdots a_n)$, $\exists i\in\{1, \cdots, n\}$ s.t $p|a_i$
if $p|a_{n+1}$ then, $p|a_i$ for $i = n+1$

Therefore $\forall n\geq 2$, if $p|a_1 \cdots a_n$ then, $\exists i\in\{1, \cdots, n\}$ s.t $p|a_i$

### Example 
#### Example A
> Show that if $p|a^n$ then $p|a$

Suppose $p|a^n$
Then $p|\:\underbrace{a \times \cdots \times a}_{n\text{ times}}$

Thus $p|a$

#### Example B
> Show that $\sqrt[n]{p}$ is irrational for any prime $p$ and $n\geq2$

We can employ the same line of reasoning we used for $\sqrt{2}$

Suppose $\sqrt[n]{p}$ **is** rational
Then, $\sqrt[n]{p} = \frac{a}{b}$ for integers $a, b$ such that $\text{gcd}(a, b) = 1$. They are **fully** reduced. 

Then, 
$$
\begin{align}
	p &= \frac{a^n}{b^n} \\
	p(b^n) &= a^n \\
\end{align}
$$

Since $p, b\in\mathbb{Z}$, $p|a^n$
Since $p|a^n$, $p|a$
Since $p|a$, $a = pc$ for some integer $c$

Then, $pb^n = (pc)^n = p^n c^n$
Then, $b^n = p^{n-1}c^n$

Since $n\geq2$, $n-1\geq 1$

This means that $p|p^{n-1}c^n$ and by extension $p|b^n$
This also means that $p|b$

Since $p|a$ and $p|b$, then $\text{gcd}(a, b) = p \neq 1$

This contradicts our initial assumption about $\sqrt[n]{p}$ being rational. 

Thus $\sqrt[n]{p}$ is **irrational**