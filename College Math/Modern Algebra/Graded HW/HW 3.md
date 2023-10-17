| Homework | Name        | TUID        |
| -------- | ----------- | ----------- |
| HW3      | Parth Patel | 915 805 716 | 

# HW 3
## Problem 3.1
### 3.1a
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

## Problems 3.2 
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