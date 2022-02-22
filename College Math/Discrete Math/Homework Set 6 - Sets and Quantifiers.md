# Sets and Quantifiers
## Section 11
### 11.7
![[s11p7.png]]
#### 11.7.d
> There exists a unique integer $x$ such that for any integer $y$, $$x\times y = x$$
> **Notation**: $$\exists!x\in\mathbb{Z},\forall y\in\mathbb{Z}, xy=x$$

Let $x = 0$
Then for any integer $y$, 
$$x\times y = 0y = 0 = x$$
Hence an $x$ exists with the property $\forall y\in\mathbb{Z},xy = x$
Suppose $x_1$ and $x_2$ satisfy $\forall y\in\mathbb{Z},xy = x$.
Then Suppose $y = 2$
$$
\begin{align}
	x_1y &= 2x_1 \\
	x_2y &= 2x_2 \\
\end{align}
$$
$$
\begin{align}
	2x_1 &= x_1 \\
	2x_2 &= x_2 \\
\end{align}
$$
$$
\begin{align}
	x_1 &= \frac{x_1}{2} \\
	x_2 &= \frac{x_2}{2} \\
\end{align}
$$

This equality is only true for $x_1=x_2=0$ since the left side will grow faster than the right and they will never be equal after $x_1=x_2=0$.
Hence $x$ is unique and $x=0$.
#### 11.7.e
> There exists a unique integer $x$ such that for any integer $y$, $$x\times y = y$$

Let $x = 0$. Then
$xy = 1y = y$
Hence we have shown that at-least one such $x$ exists.

Suppose $x_1$ and $x_2$ satisfy $\forall y\in\mathbb{Z},yx = y$.
Suppose $y = 1$
$$
\begin{align}
	x_1y &= y = x_1(1) = 1\\
	x_2y &= y = x_2(1) =1\\
\end{align}
$$
Since $x_1 = x_2 = 1$ in this case there exists only one unique $x$ and its $1$. Thus, the statement is true. 
## Bonus
For information on Infinite Sets see [[Infinite Sets and Complements]]
### Bonus Problem
Lets define a set $B_n$
$$B_n = \{x\in\mathbb{Z}:x|n\}$$
#### Questions
##### Infinite Union
Find $\bigcup_{n=k}^{\infty}B_n$ for $k = 1, 2, 3$
Lets start by giving some example of $B_n$

$$
\begin{align*}
	B_1 &= \{x\in\mathbb{Z}:x|1\} = \{-1, 1\} \\
	B_2 &= \{x\in\mathbb{Z}:x|2\} = \{-2, -1, 1, 2\} \\
	B_3 &= \{x\in\mathbb{Z}:x|3\} = \{-3, -1, 1, 3\} \\
	B_6 &= \{x\in\mathbb{Z}:x|8\} = \{-6, -3, -2, -1, 1, 2, 3, 6\} \\
\end{align*}
$$

Notice that each $B_n$ contains at-least contains $\{-n, n\}$. Yet no $0$ since no non-zero integer $p$ has the property $0|p$
$$\bigcup_{n=1}^{\infty}B_n = \mathbb{Z} - \{0\}$$

Lets consider $k=2, 3$

Notice that $B_2\cup B_3 \subseteq B_6$. Thus removal of either will not change the answer. 

We can generalize this to 
$$B_n\cup B_m \subseteq B_{nm}$$
This is true because anything that divided $n$ or $m$ will divide $n\times m$ hence the union. The subset is because new numbers will divide $nm$ that were not in $B_n$ or $B_m$. 

##### Infinite Intersection
$B_n$ is a set such that it contains all integers that divide $n$.
There exists only two numbers that divide any number: $\{-1, 1\}$

This is because 
$$
\begin{align}
	1 \times n &= n\\
  	-1 \times -n &= n
\end{align}
$$

Hence, 
$$\bigcap_{n = k}^\infty B_n = \{-1, 1\}$$
Notice that the choice of $k$ is irrelevant. 