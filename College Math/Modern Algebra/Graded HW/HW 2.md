| Homework | Name        | TUID        |
| -------- | ----------- | ----------- |
| HW1      | Parth Patel | 915 805 716 | 

# HW 2
## Problem 2.1

### Forward $\implies$

Suppose $a, b \in \mathbb{Z} - \{0\}$ and $a|b$ 

Then $\exists c\in\mathbb{Z}$ such that $ac = b$

Then raise both sides to the $n$-th power: $a^nc^n = b^n$

Let $d = c^n$ : $a^nd=b^n$

Since $\exists d\in\mathbb{Z}$ such that $a^nd=b^n$ , $\boxed{a^n|b^n}$

### Backwards $(\Leftarrow)$

Suppose $a^n | b^n$

Under the unique factorization theorem:

$$
\begin{align}
a &= p_1^{a_1} p_2^{a_2} \dotso p_m^{a_m} \\
b &= p_1^{b_1} p_2^{b_2} \dotso p_m^{b_m} 
\end{align}
$$

Each $p_i$ represents a prime and $a_i, b_i$ represents the primes involved in the factorization of $a$ and $b$ respectively. 

Since  $a^n | b^n$ , $\exists k\in\mathbb{Z}$ such that $b^n = k\cdot a^n$

It follows that:

$$
b^n = p_1^{n \cdot b_1} p_2^{n \cdot b_2} \dotso p_m^{n \cdot b_m} = k ( p_1^{n \cdot a_1} p_2^{n \cdot a_2} \dotso p_m^{n \cdot a_m} )
$$

Then $k = p_1^{n(b_1 - a_1)}p_2^{n(b_2 - a_2)} \dotso p_m^{n(b_m - a_m)}$ .

Since $k\in\mathbb{Z}$ , it follows $b_i - a_i \geq 0$

Since each exponent on each side is a multiple of $n$ , we can take the $n$-root on each side:

$$
\sqrt[n]{b^n} = \sqrt[n]{k \cdot a^n}
$$

Looking into $\sqrt[n]{k}$ :

$$
\sqrt[n]{p_1^{n(b_1 - a_1)}p_2^{n(b_2 - a_2)} \dotso p_m^{n(b_m - a_m)}} = p_1^{(b_1 - a_1)}p_2^{(b_2 - a_2)} \dotso p_m^{(b_m - a_m)} 
$$

Call this integer $t$ .

Since $\exists t \in \mathbb{Z}$ such that $a|b$ .


## Problem 2.2

### 2.2.a

Suppose $n\in\mathbb{Z}$ and $n$ is odd

Let $a\in\mathbb{Z}$

Recall that when $n$ is odd $(-1)^n = -1$

This the integer $a^n+1$ can be written as $a^n - (-1)^n$

Since $a^n - (-1)^n = \biggr(a - (-1)\biggr)\sum_{i=0}^{n-1}a^ib^{n-1-i}$

Since $a - (-1) \in \mathbb{Z}$ it follows that $a+1 | a^n - (-1)^n = a^n + 1$

### 2.2.b

Given that $a, n \gt 1$

Then $a+1 \gt 2$ . It is required that $a+1$ since $1$ divides any integer.

Following from the result from $\bf{(2.2.a)}$ it follows that $a+1$ is a divisor of $a^n+1$ .

$\therefore a^n+1$ is **not** prime.

### 2.2.c

> Argument via contrapositive

Suppose an integer $m$ is not a power of $2$ . Since all other primes are odd $k$ must have odd factors. We can call one of these factors $w$ and the rest of the factorization $v$. Thus, $k=wv$ for $w, v\in\mathbb{Z}$

Given that we know that $w$ is odd:

$$
2^v + 1 = 2^v - (-1) | 2^{wv} + 1 = 2^{vw} - (-1)^w
$$


> Comment: I am using problem 2.2.a and using $a=2^v$ and $n=w$


Since $2^v + 1 | 2^{vw}+1 = 2^k+1$ it implies that $2^k+1$ is not prime if $k$ is not a power of 2.

By contradiction $k$ is required to be a power of $2$ if $2^{k}+1$ is prime.


## Problem 3
### 3.a
#### $n=5$

> Recall: A $a\in\mathbb{Z}_n$ is a unit if $\gcd(a, n)=1$

$$
\begin{align}
\gcd(1, 5) &= 1, \\
\gcd(2, 5) &= 1, \\
\gcd(3, 5) &= 1, \\
\gcd(4, 5) &= 1, \\ \\
&\implies \mathcal{U} = \{[1], [2], [3], [4]\}
\end{align}
$$

Given that $[0]$ is not a zero divisor, $\mathcal{Z} = \emptyset$

#### $n=6$

> Recall: A $a\in\mathbb{Z}_n$ is a unit if $\gcd(a, n)=1$

$$
\begin{align}
\gcd(1, 6) &= 1, \\
\gcd(5, 6) &= 1, \\
&\implies \mathcal{U} = \{[1], [5]\}
\end{align}
$$


Under $\mathbb{Z}_6$ :
$$
\begin{align}
[2][3] = [0] \\
[3][2] = [0] \\
[4][3] = [0] \\
&\implies \mathcal{Z} = \{[2], [3], [4]\}
\end{align}
$$

### 3.b

Firstly notice that $[0] \not\in \mathcal{U}$ and $[0] \not\in \mathcal{Z}$ :

+  $[0] \not\in \mathcal{U}$ by definition of $\mathcal{U}$
+  $[0] \not\in \mathcal{Z}$ since for any $[a] \in \mathbb{Z}$ , $[0][a] = [0]$


---

A zero divisor $[a]$ is defined such that $[a]\neq[0]$ and $\exists[b]\in\mathbb{Z}_n - \{[0]\}: [a][b] = [0]$

This means that $ab \equiv 0 \bmod n$.

This can be equivalently written as $n | ab - 0$ implying there exists an integer $y$ such that $ny = ab - 0$ .

Since there exists an integer such that $0 = ab - ny$ , $\gcd(a, n) \neq 1$ .

We can now rewrite set definitions.

$$
\begin{align}
\mathcal{U} &= \biggr\{[k]\ \biggr|\ [k] \in \mathbb{Z}_n,\ \gcd(k, n) = 1 \biggr\} \\ \\
\mathcal{Z} &= \biggr\{[k]\ \biggr|\ [k] \in \mathbb{Z}_n,\ \gcd(k, n) \neq 1 \biggr\} \\
\end{align}
$$

For every element $[e]$ in $\mathbb{Z}_n - \{[0]\}$ , $e$ can either be coprime to $n$ or not implying $[e]$ must belong to one of the sets $\mathcal{U}$ or $\mathcal{Z}$ yet not both. 

This means $\mathcal{U} \cup \mathcal{Z} = \mathbb{Z}_n - \{[0]\}$ , yet $\mathcal{U} \cap \mathcal{Z} = \emptyset$

Therefore $\mathcal{U}, \mathcal{Z}, \{[0]\}$ make up disjoint sets of $\mathbb{Z}_n$

## Problem 2.4

> Notice when taking remainders of an integer $a$ to some power $k$ , if you see a the same non-zero remainder twice you know it cannot be nilpotent.

### $n=4$

$$
\begin{align}
[0]^1&=[0]\\
[1]^1&=[1], [1]^2=[1]\neq[0]\\
[2]^1&=[2], [2]^2=[4]=[0]\\
[3]^1&=[3], [3]^2=[9]=[1], [3]^3=[3]\neq[0]\\
\end{align}
$$

Under $\mathbb{Z}_4$ only $[0], [2]$ are nilpotent.

### $n=5$

$$
\begin{align}
[0]^1&=[0]\\
[1]^1&=[1], [1]^2=[1]\neq[0]\\
[2]^1&=[2], [2]^2=[4]=[4], [2]^3=[8]=[3], [2]^4=[6]=[1], [2]^5=[2]\neq[0]\\
[3]^1&=[3], [3]^2=[9]=[4], [3]^3=[12]=[2], [3]^4=[6]=[1], [3]^5=[3]\neq[0]\\
[4]^1&=[4], [4]^2=[16]=[1], [4]^3=[4]\neq[0]\\
\end{align}
$$

Under $\mathbb{Z}_5$ only $[0]$ is nilpotent.

### $n=6$

$$
\begin{align}
[0]^1&=[0]\\
[1]^1&=[1], [1]^2=[1]\neq[0]\\
[2]^1&=[2], [2]^2=[4]=[4], [2]^3=[8]=[2]\neq[0]\\
[3]^1&=[3], [3]^2=[9]=[3]\neq[0]\\
[4]^1&=[4], [4]^2=[16]=[4]\neq[0]\\
[5]^1&=[5], [5]^2=[25]=[1], [5]^3=[5]\neq[0]\\
\end{align}
$$

Under $\mathbb{Z}_6$ only $[0]$ is nilpotent.

### $n=8$

$$
\begin{align}
[0]^1&=[0]\\
[1]^1&=[1], [1]^2=[1]\neq[0]\\
[2]^1&=[2], [2]^2=[4]=[4], [2]^3=[8]=[0]\\
[3]^1&=[3], [3]^2=[9]=[1], [3]^3=[3]\neq[0]\\
[4]^1&=[4], [4]^2=[16]=[0]\\
[5]^1&=[5], [5]^2=[25]=[1], [5]^3=[5]\neq[0]\\
[6]^1&=[6], [6]^2=[36]=[4], [6]^3=[24]=[6]=[0]\\
[7]^1&=[7], [7]^2=[49]=[1], [7]^3=[7]\neq[0]\\
\end{align}
$$

Under $\mathbb{Z}_6$ only $[0]$ is nilpotent.

