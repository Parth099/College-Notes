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

*Preface*
Let 
$$
\begin{align}
X_R &= \{r \in R\ |\ \exists0_R \neq r' \in R: rr^{\prime} = 0_R\} \\
S_R &= \{s \in S\ |\ \exists0_S \neq s' \in R: ss^{\prime} = 0_S\}
\end{align}
$$

---

Let

$$
\begin{align}
Z &= \{\text{all zero divisors of }T\} \\
Z^{\prime} &= \biggr((X_R \times S) \cup (R \times X_S)\biggr)
\end{align}
$$

Consider $(r, s) \in Z^{\prime}$ . Then either $(r, s) \in (X_R \times S)$ or $(r, s) \in (R \times X_S)$

Suppose $(r, s) \in (X_R \times S) \setminus \{0_T\}$ ,

Since $r\in X_R, \exists r^{\prime} \in X_R: rr^{\prime} = 0_R$ .
Then fix an $s^{\prime} \in S$ to $s^{\prime} = 0_S$ . Notice that $(r, s)(r^{\prime}, s^{\prime}) = 0_T$ meaning $(r, s) \in Z$

Suppose $(r, s) \in (R \times X_S) \setminus \{0_T\}$ ,

Since $s\in X_S, \exists s^{\prime} \in X_S: ss^{\prime} = 0_S$ .
Then fix an $r^{\prime} \in R$ to $r^{\prime} = 0_R$ . Notice that $(r, s)(r^{\prime}, s^{\prime}) = 0_T$ meaning $(r, s) \in Z$

$$
\therefore Z^{\prime} \subseteq Z
$$

---

Let $(r, s) \in Z$, then $\exists(r^{\prime}, s^{\prime}) \in Z: (r, s)(r^{\prime}, s^{\prime}) = 0_T$ with $(r^{\prime}, s^{\prime}) \neq (0_R, 0_S)$

Notice only one of $r$ and $s$ have to be a zero divisor for $(r, s)$ to a zero divisor or both can be. 

Suppose $r$ is the zero divisor, then $r \in X_R$ and $s$ can be any member of $S$ since $s \cdot 0_S = 0_S$ . Therefore, $\exists r^{\prime} \in X_R: rr^{\prime} = 0_R$ . Therefore $(r, s)(r^{\prime}, 0_S) = 0_T$. Therefore if $r$ is a zero divisor $(r, s) \in (X_R \times S)$ .

Suppose $s$ is the zero divisor, then $s \in X_S$ and $r$ can be any member of $R$ since $r \cdot 0_R = 0_R$ . Therefore, $\exists s^{\prime} \in X_S: ss^{\prime} = 0_S$ . Therefore $(r, s)(0_R, s^{\prime}) = 0_T$. Therefore if $s$ is a zero divisor $(r, s) \in (R \times X_S)$ .

Since $(r, s)\in (X_R \times S)$ or $(r, s)\in(R \times X_S)$ : 

$$
(r, s) \in (X_R \times S) \cup (R \times X_S)
$$

$$
\therefore Z \subseteq Z^{\prime}
$$

Since $Z^{\prime} \subseteq Z$ and $Z \subseteq Z^{\prime}$ , $\boxed{Z = Z^{\prime}}$

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