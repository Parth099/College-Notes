# Midterm Note Sheet
## Chapter 1 
### GCD 

**T1.2**: Let $a, b$ be integers both not zero with $\gcd(a, b)=d$ . Then $\exists x, y\in\mathbb{Z}: ax+by=d$ .

**IMPORTANT**: The converse, $q \to p$ , does not hold true unless $d=1$

---

**T1.4**: if $a|bc$ with $(a, b)=1$ then $a|c$ . (To Prove: see that $c=c\cdot 1$)

### Primes
$p$ is prime if and only if it has this property:

$$
p|bc \implies p|b \text{ or } p|c
$$

---

**Fundamental theorem of arithmetic**: Any integer $n$ except $0, 1$ is a product of primes. It can be written as:

$$
n = \pm p_1p_2\dotso p_t \text{ for } t\geq0
$$

Each $p_i$ is unique up to their order. This factorization above is unique if we arrange the prime factors in an order where: $p_i \leq p_{i+1}$

---

**T1.10**: Let $n \gt 1$ , if $n$ has no positive factor $a \leq \sqrt{n}$ , then $n$ is prime. 

## Chapter 2
### Congruence
Let $a, b, n$ be integers with $n\gt0$ . Then: $a \equiv b \bmod n \iff n | a - b$ 

Recall this is an equivalence class and know they have the following properties:
$$
\begin{align}
a &R a \\
a &R b \implies b R a \\
a &R b \text{ and } b R c \implies a R c
\end{align}
$$

---

If $a\equiv b \bmod n$ and $c\equiv d \bmod n$

$$
\begin{align}
a+c\equiv b+d\bmod n \\
ac \equiv bc \bmod n
\end{align}
$$

---

Let $[a], [c] \in \mathbb{Z}_n$

$$
\begin{align}
[a]+[c] &= [a+c] \\
[a][c]  &= [ac]
\end{align}
$$

---

**T2.8**

The following are logically equivalent:
1. $p$ is prime
2. For any $a\neq 0$ in $\mathbb{Z}_p$ the equation $ax=1$ has a solution in $\mathbb{Z}_p$ . `[units]`
3. Whenever $bc=0$ in $\mathbb{Z}_p$ , $b=0$ or $c=0$ 

**T2.9**

Let $a, n$ be integers with $n\gt1$ :

The equation $[a]x=[1]$ has a solution under $\mathbb{Z}_n$ if and only if $(a, n)=1$ in $\mathbb{Z}$

This is the same as:

$$
[a] \text{ is a unit in }\mathbb{Z}_n \iff (a, n)=1
$$

> $[a] \in \mathbb{Z}_n$ is a zero divisor if $[a] \neq [0]$ and $\exists [b]\in\mathbb{Z}_n \setminus {[0]}$ such that $[a][b]=[0]$

## HW Theorems

+ $a|b \iff a^n | b^n$
+ Units, Zero Divisors, and $\{[0]\}$ are disjoint sets of $\mathbb{Z}_n$ that form a partition. 
+ $a^n-b^n = (a-b)\sum_{i=0}^{n-1}a^ib^{n-1-i}$