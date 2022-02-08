# Sets
## Set Builder Notation
### Notation 1
$$
\begin{align}
(1) \ A = \{a \in U: P(a)\} 
\end{align}
$$
$U$ stands for some set like $\mathbb{R, Z, N, U, \dotso}$ while the $P(a)$ is a `boolean` expression where we throw out a number based on whether it fits a property $p$ or not.

#### Example 
$$
\begin{align}
A &= \{a \in \mathbb{Z} : |a| \leq 5\}\\
&= \{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5\}
\end{align}
$$

---
### Notation 1
$$
\begin{align}
(2) \ A = \{f(n): n\in U\} 
\end{align}
$$
$f$ is a function that helps to describe the set.
#### Example 
$$A = \{2x : x\in \mathbb{Z}\}$$
The set of all even numbers. 

# Chapter 2 
## Section 10
### 10.10
> $A = \{x\in\mathbb{Z}:4|x\}$, $B = \{x\in\mathbb{Z}:2|x\}$
> Show $$A \subseteq B$$

Let $a\in A$. Then  $a\in\mathbb{Z}$ and $4|a$.
By definition $a = 4c$ for some $c\in\mathbb{Z}$
$$a = 4c = 2(2c)$$
Since  $c\in\mathbb{Z}$, $2c\in\mathbb{Z}$.
This means that $2|a$ since $a$ is shown to be even by set definition.

This means $\boxed{A \subseteq B}$
### 10.11
![[s10p11.png]]
> **Statement**:
> For $a, b\in\mathbb{Z}$, $A\subseteq B$ if and only if $b|a$

#### Proof 
Suppose $A\subseteq B$
We know that $a\in A$ since $a|a$. From the assumption we see that $a$ must also be an element of $B$. Thus $b|a$. 

Suppose $b|a$
By definition $a \in A$. But since $b|a$, $a\in B$ too. 

Hence $A\subseteq B \iff a|b$

## 10.12 - 10.13
![[s10p12p13.png]]
### 10.12 - Specific
Let  $c \in C$. This means $c|12$ by set definition. This means that $c\times x = 12$ for some integer $x$. 
**Multiply** both sides by $3$:
$$
\begin{align*}
3c \times x &= 3 \times 12 \\
c \times 3x &= 36 
\end{align*}
$$
Since $c \times 3x = 36$ for an integer $3x$, $c|36$ and by extension $\boxed{c\in D}$. 
### 10.13 - Generalization
> **Statement**:
> For $c, d\in\mathbb{Z}$, $C\subseteq D$ if and only if $c|d$

### Ext - 1
Let
$$
\begin{align*}
A &= \{3n+2: n \in\mathbb{Z}\}\\
B &= \{6n-5: n \in\mathbb{Z}\}\\
\end{align*}
$$
> Show $B\subseteq A$ and $A\neq B$

Suppose $b\in B$. Then by definition
$$b = 6n-5 = 6n-4$$

%%finishup%%

### Ext 2
Let
$$
\begin{align*}
A &= \{3m+2: n \in\mathbb{Z}\}\\
B &= \{3m-10: n \in\mathbb{Z}\}\\
\end{align*}
$$
> Show $A = B$


### Ext 3
Let
$$
\begin{align*}
A &= \{15n+33m: n \in\mathbb{Z}\}\\
B &= \{n \in\mathbb{Z}: 3|n\}\\
\end{align*}
$$
> Show $A = B$

