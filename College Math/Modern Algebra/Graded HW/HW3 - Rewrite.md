# HW3 - Rewrite

> The only changes I have made to this problem occur below the heading [Defining Sets](#Defining-Sets).

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

### Defining-Sets
**Units**
$$
\begin{align}
T^{\times} &=\ \biggr\{ t \in T\ \biggr|\ \exists t^{\prime} \in T : t t^{\prime} = 1_T  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists (r^{\prime}, s^{\prime}) \in R \times S : (r, s)\cdot (r^{\prime}, s^{\prime}) = (1_R, 1_S)  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists (r^{\prime}, s^{\prime}) \in R \times S : (r\cdot r^{\prime}, s\cdot s^{\prime}) = (1_R, 1_S)  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists (r^{\prime}, s^{\prime}) \in R \times S : r\cdot r^{\prime} = 1_R , s\cdot s^{\prime} = 1_S \biggr\} \\
&= R^{\times} \times S^{\times}
\end{align}
$$

**Zero Divisors**

$$
\begin{align}
Z &=\ \biggr\{ t \in T\setminus \{0_T\} \ \biggr|\ \exists t^{\prime} \in T \setminus \{0_T\} : t t^{\prime} = 0_T  \biggr\} \\
&=\ \biggr\{ (r, s) \in T \setminus \{0_T\} \ \biggr|\ \exists (r^{\prime}, s^{\prime}) \in R \times S \setminus \{(0_R, 0_S)\} : (r, s)\cdot (r^{\prime}, s^{\prime}) = (0_R, 0_S)  \biggr\} \\
&=\ \biggr\{ (r, s) \in T \setminus \{0_T\} \ \biggr|\ \exists (r^{\prime}, s^{\prime}) \in R \times S \setminus \{(0_R, 0_S)\} : (r\cdot r^{\prime}, s\cdot s^{\prime}) = (0_R, 0_S)  \biggr\} \\
&=\ \biggr\{ (r, s) \in T \setminus \{0_T\} \ \biggr|\ \exists (r^{\prime}, s^{\prime}) \in R \times S \setminus \{(0_R, 0_S)\} : r\cdot r^{\prime} = 0_R , s\cdot s^{\prime} = 0_S \biggr\}
\end{align}
$$

Define the following sets: These are the units in $R$ and $S$ respectively and they contain their neutral element $0$ too as per the set definition.

$$
\begin{align}
Z_r &= \{r \in R | \exists r'\in{R}\setminus\{0_R\}: rr' = 0_R\} \\
Z_s &= \{s \in S | \exists s'\in{S}\setminus\{0_S\}: ss' = 0_S\} \\
\end{align}
$$

Notice that $Z = Z_r \times Z_s \setminus \{(0_R, 0_S)\}$

> *Comment*: I do not understand why my definition of $Z$ is different from the one on the answer sheet. I did not just want to put the answer on the answer sheet because I did not understand how it was derived.  

**Nilpotent**

$$
\begin{align}
N &=\ \biggr\{ t \in T\ \biggr|\ \exists n \in \mathbb{Z}_{\gt 0} : \underbrace{t \odot \dotso \odot t}_{n \text{ times}} = 0_T  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists n \in \mathbb{Z}_{\gt 0} : \underbrace{(r, s) \odot \dotso \odot (r, s)}_{n \text{ times}} = 0_T  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists n \in \mathbb{Z}_{\gt 0} : (r^n, s^n) = (0_R, 0_S)  \biggr\} \\
&=\ \biggr\{ (r, s) \in T\ \biggr|\ \exists n \in \mathbb{Z}_{\gt 0} : r^n = 0_R,\ s^n = 0_S  \biggr\} \\
\end{align}
$$

Define the following sets:

$$
\begin{align}
N_r &= \{r \in R | \exists n\in\mathbb{Z}_{\gt0}: r^n = 0_R\} \\
N_s &= \{s \in S | \exists n\in\mathbb{Z}_{\gt0}: s^n = 0_S\} \\
\end{align}
$$

Then $N = N_r \times N_s$ . 