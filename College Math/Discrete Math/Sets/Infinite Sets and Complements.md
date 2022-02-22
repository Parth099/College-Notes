# Infinite Set \& Problems
## Context of Infinite Sets
Suppose $\{A_i : i\in I\}$ is a collection of Sets.
The primary questions we have are 
$$
\begin{align*}
\bigcup_{i\in I}A_i & =? & \bigcap_{i\in I}A_i =?
\end{align*}
$$

### Infinite Union
$$
\begin{align}
	\bigcup_{i\in I}A_i &= \{x : x \in A_i \text{ for some } i\in I\}\\
	&= \{x : \exists i\in I, x\in A_i\}
\end{align}
$$

### Infinite Intersection
$$
\begin{align}
	\bigcap_{i\in I}A_i &= \{x : x \in A_i \text{ for any } i\in I\}\\
	&= \{x : \forall i\in I, x\in A_i\}
\end{align}
$$
### Example Problem - 1
> **Consider** Interval $I_n = (\frac{1}{n}, 2n)$

$$I_n = \{x\in\mathbb{R} : \frac{1}{n} \lt x \lt 2n\}$$

Investigate
$$
\begin{align}
	\bigcup_{n = 1}^{\infty}I_n & & \text{and} & & \bigcap_{n = 1}^{\infty}I_n
\end{align}
$$
#### Union
$$
\begin{align}
	I_1 &= (1, 2)\\
	I_2 &= (\frac{1}{2}, 4)\\
	I_3 &= (\frac{1}{3}, 6)\\
	&\vdots\\	
\end{align}
$$
From the pattern above we can deduce that:
$$
\bigcup_{n = 1}^{\infty}I_n = (0, \infty) = \mathbb{R}^+
$$
#### Intersect
Looking at $I_n$ for $n = 1, 2, 3$ above we notice that
$$I_1 \subseteq I_2 \subseteq I_3 \subset \dotso$$
This means that
$$\bigcap_{n = 1}^{\infty}I_n = I_1 = (1, 2)$$
### Example 2
> **Consider** Interval $I_n = [-\frac{1}{n}, \frac{n-1}{n}]$
#### Union
$$
\begin{align}
	I_1 &= [-1, 0]\\
	I_2 &= [-\frac{1}{2}, \frac{1}{2}]\\
	I_3 &= [-\frac{1}{3}, \frac{2}{3}]\\
	I_4 &= [-\frac{1}{4}, \frac{3}{4}]\\
	    &\vdots\\	
\end{align}
$$

Notice $\forall n\in\mathbb{R}^+, \frac{n-1}{n} \lt 1$ yet $\frac{n-1}{n}\to1$ as $n\to\infty$. This means $1 \not \in \bigcup_{n = 1}^{\infty}I_n$ for the right end point. 

$$\bigcup_{n = 1}^{\infty}I_n = [-1, 1)$$

#### Intersect
$$
\begin{align}
	I_1 \cap I_2 &= [-\frac{1}{2}, 0] \\
	I_1 \cap I_2 \cap I_3 &= [-\frac{1}{2}, 0] \cap [-\frac{1}{3}, \frac{2}{3}] = [-\frac{1}{3}, 0]
\end{align}
$$

As $n\to\infty$, $-1/n\to 0^{-}$, this means the left bound contains $0$, thus the final interval is $[0, 0]$
From the pattern we can attain:
$$\bigcap_{n = 1}^{\infty}I_n = \{0\}$$

---
# Set Complement
Let $A \in U$. This $U$ is the **context** for $A$. It is the universal set that $A$ is in. $U$ is the set of all elements being analyzed. 

The complement of $A$ is 
$$U - A = \{x \in U : x \not\in A \}$$
> **Notation** for *Set Complement*
> $\overline{A}$ or $A^C$

## Example 1 - *Set Complement*
Let $U = \mathbb{R}$ and $A = [0, 1]$
$$U - A = \overline{A} = (-\infty, 0) \cup (1, \infty)$$

## Example 1 - *Context*
Suppose $A = \{x \in U : 2|x\}$
Think about the ramifications of $\overline A$ if 
+ $U = \mathbb{Z}$
+ $U = \mathbb{R}$
# Set Complement Union \& Intersect 
> **Preface**
> Suppose $A_1, A_2 \subseteq U$
> + What is $(A_1 \cup A_2)^C$?
> + What is $(A_1 \cap A_2)^C$?

## The Complement Union
>  What is $(A_1 \cup A_2)^C$?

$$
\begin{align}
	(A_1 \cup A_2)^C &= U - (A_1 \cup A_2) \\
	\\
	U - (A_1 \cup A_2) &= \{x : x\in U \text{ and } x \not\in(A_1 \cup A_2)\}\\
	
	^*&= \{x : x\in U \text{ and } x \not\in A_1 \text{ and } x \not\in A_2\}
\end{align}
$$
See that the last line says this when we expand it:
> $(x\in U \text{ and } x \not\in A_1)$ and  $(x\in U \text{ and } x \not\in A_2)$

This is the same as $U - A_1$ and $U - A_2$
This is the set complement for $A_1^C$ and $A_2^C$

$$
\begin{align}
	(A_1 \cup A_2)^C &= \{x: x\in A_1^C \text{ and } x\in A_2^C\} \\ 
	&= \{x: (x\in A_1^C \cap A_2^C)\} \\
	&= \boxed{A_1^C \cap A_2^C}
\end{align}
$$

Hence, $\overline{A_1 \cup A_2} = \overline{A_1} \cap \overline{A_2}$
## The Complement Union
>  What is $(A_1 \cap A_2)^C$?

$$
\begin{align}
	(A_1 \cap A_2)^C &= U - (A_1 \cap A_2) \\
	\\
	U - (A_1 \cap A_2) &= \{x: x\in U \text{ and } x\not\in(A_1 \cap A_2)\} \\
	^*&=\{x\in U : x\not\in A_1 \text{ or } x\not\in A_2\} \\
	  &=\{x : x\in U \text{ and } x\not\in A_1 \text{ or  } x\in U \text{ and } x\not\in A_2\} \\
	  &= \{x : x \in (U - A_1) \text{ or } x \in (U - A_2)\} \\
	   &= \{x : x \in A_1^C \text{ or } x \in A_2^C\} \\
	   &= A_1^C \cup A_2^C
\end{align}
$$

\* - Logical negation of an expression using or/and

# Infinite Set Complement Union \& Intersect
> Let $$A_i\subseteq U,\ i\in I$$
> $I$ is an indexing set. 

## Infinite Union Complement Derivation
$$
\begin{align}
	(\ \bigcup_{i \in I}A_i \ )^C &= \{x \in U : x \not \in [\ \bigcup_{i \in I}A_i \ ]\}
\end{align}
$$

Recall that 
$$
x \in (\ \bigcup_{i \in I}A_i \ ) \iff \exists i\in I, x\in A_i
$$
lets Negate this statement
$$
x \not\in (\ \bigcup_{i \in I}A_i \ ) \iff \forall i\in I, x\not\in A_i
$$

Back to original statement:
$$
\begin{align}
	(\ \bigcup_{i \in I}A_i \ )^C &= \{x \in U : x \not \in [\ \bigcup_{i \in I}A_i \ ]\} \\
	  &= \{x \in U : \forall i\in I, x\not\in A_i\} \\
^{**} &= \{x \in U : \forall i\in I, x\in A_i^C\} \\
 	  &= {\bigcap_{i \in I}A_I^C}
\end{align}
$$

\*\* - Note that we know $x \in U$ and $x \not \in A_i$. Thats the complement! 

With the same process we can learn that
$$(\ \bigcap_{i\in I}A_i\ )^C = \bigcup_{i\in I}A_i^C$$

## Theorem: Demorgans Laws
> Let $$A_i\subseteq U,\ i\in I$$
> $I$ is an indexing set.

Then:
$$
\begin{align}
	1\biggr| \ \ \ (\ \bigcap_{i\in I}A_i\ )^C &= \bigcup_{i\in I}A_i^C \\
	2\biggr| \ \ \ (\ \bigcup_{i\in I}A_i\ )^C &= \bigcap_{i\in I}A_i^C
\end{align}
$$

### Applying Demorgans Example
Recall the example above from [[#Intersect]].
> **Consider** Interval $I_n = [-\frac{1}{n}, \frac{n-1}{n}]$
> and Interval $J_n = (-\infty, \frac{1}{n}) \cup (\frac{n-1}{n}, +\infty)$

**Find**
$$
\begin{align}
	1\biggr| \ \ \  \bigcup_{n=1}^{\infty}J_n\  \\
	2\biggr| \ \ \  \bigcap_{n=1}^{\infty}J_n\  
\end{align}
$$
Recognize that 
$$J_n = (I_n)^C$$
Using this fact we can use the previous results to our advantage.
#### Infinite Union - Demorgans
$$
\begin{align}
	\bigcup_{n=1}^{\infty}J_n &= \bigcup_{n=1}^{\infty}(I_n)^C \\
	&= (\ \bigcap_{n=1}^{\infty}I_n \ )^C \\
	&= \{0\}^C \\
	&= \mathbb{R} - \{0\}
	
\end{align}
$$
#### Infinite Intersect - Demorgans
$$
\begin{align}
	\bigcap_{n=1}^{\infty}J_n &= \bigcap_{n=1}^{\infty}(I_n)^C \\
	&= (\ \bigcup_{n=1}^{\infty}I_n \ )^C \\
	&= (\ [-1, 1)\ )^C \\
	&= (-\infty, -1) \cup [1, \infty)
	
\end{align}
$$