# Homework 5
## Q1

$$
\begin{align}
a &= 2 \\
b &= 3 \\
d &= 0
\end{align}
$$

Since $d < \log_b{a} = \log_3 2 \approx 0.6309, T\in \Theta(n^{log_32})$

## Q2

$$
\begin{align}
a &= 5 \\
b &= 4 \\
d &= 1
\end{align}
$$

Since $d \lt \log_{4}{5} \approx 1.16096$, 

$$
T \in \Theta(n^{\log_45})
$$

## Q3

$$
\begin{align}
a &= 9 \\
b &= 3 \\
d &= 2
\end{align}
$$

Since $d = \log_b{a} = \log_3 9 = 2, T\in \Theta(n^{2}\log_3n)$

## 2.4.a
$$
\begin{align}
a &= 5 \\
b &= 2 \\
d &= 1
\end{align}
$$

Since $d < \log_b{a} = \log_2 5 \approx 2.3219, T\in \Theta(n^{\log_25})$

## 2.4.b
Subtract and conquer

$$
\begin{align}
a &= 2 \\
b &= 1 \\
d &= 0
\end{align}
$$

Since $a > 1,\ T\in \Theta(n^{d}a^{n/b}) = \Theta(2^{n})$

## 2.4.c
divide and conquer

$$
\begin{align}
a &= 9 \\
b &= 3 \\
d &= 2
\end{align}
$$

Since $d = \log_b{a} = \log_3 9 = 2, T\in \Theta(n^{2}\log_3n)$

I would pick algorithm $C$ to solve the problem since for larger $n$ it is more runtime efficient.

## 3.a
$$
\begin{align}
a &= 1 \\
b &= 1 \\
d &= 0
\end{align}
$$

Since $a=1$, $T\in \Theta(n^{d+1}) = \Theta(n)$ 

## 3.b
$$
\begin{align}
a &= 4 \\
b &= 2 \\
d &= 1
\end{align}
$$

Since $a>1$, $T\in \Theta(n^{d}a^{n/b}) = \Theta(n\cdot 4^{\frac{n}{2}}) =  \Theta(n\cdot 2^{n})$

## Q4
Consider the following equality: $\log_3{n} \leq x \leq 1+\log_3{n}$ for $n\in\mathbb{Z}^+$

We can note that $x\in\mathbb{Z}^+$ since there must exists an integer between two numbers that differ by one. Either the end points are integers *or* they are decimals where since they differ by 1 there is an integer between them. 

Using properties of logs we can note that: 

$$
\log_3{n} \leq x \leq \log_3{3}+\log_3{n}
$$

Combine logs:

$$
\log_3{n} \leq x \leq +\log_3{3n}
$$

Raise to third power:

$$
n \leq 3^x \leq 3n
$$

Since $x\in\mathbb{Z}^+$ we can say that an power of $3$ exists in the interval $[n, 3n]$


## Q5 - 1.38.a (textbook p=49)
### $p=13$
Since $p=13$, $p-1=12$ 
Therefore $s\in\{2, 3, 4, 6, 12\}$

$$
\begin{align}
10^2 &= 100 = 13(7) + 9 \equiv_{13} 9 \\
10^3 &= 10\cdot10^2 \equiv_{13} 9*10 = 13(6) + 12 \equiv_{13} 12 \\
10^6 &= 10^{3^2} \equiv_{13} 12^2 = 144 = 13(11) + 1 \equiv_{13} \boxed{1} 
\end{align}
$$

Suppose $a=10$, since $13$ is prime $a\in\mathbb{Z}_{13}^*$

The smallest $r\in s$ s.t $10^r$ is $6$. 

Therefore the groupings must be size $6$

### $p=17$
Since $p=17$, $p-1=16$ 
Therefore $s\in\{4, 16\}$

Suppose $a=10$, since $17$ is prime $a\in\mathbb{Z}_{17}^*$

$$
\begin{align}
10^4 = 10000 = 588(17) + 4 &\equiv_{17} 4 \\
10^{16} = 10^{4^4} \equiv_{17} (4)^4 = 256 = 15(17) + 1 &\equiv_{17} 1
\end{align}
$$

The smallest $r\in s$ s.t $10^r$ is $16$. 

Therefore the groupings must be size $16$
