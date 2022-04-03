# Equivalence Classes
> **Definition**
> Let $R$ be an *equivalence* relation on a set $A$ and let $a\in A$. The equivalence class of $a$ is $$[\:a\:] = \{b\in A: a\:R\:b\}$$

**A Basic Example**:
Let $R$ be an relation on $\mathbb{R}$
Then, $x\:R\:y$ iff $x^2 = y^2$

Notice that 
$$
\begin{align}
	[\:1\:] &=  \{x\in \mathbb{R}: 1\:R\:x\} \\
		&=  \{x\in \mathbb{R}: 1 = x^2\} \\
		&= \{-1, +1\}
	\\ \\	
	[\:x\:] &= \{y\in \mathbb{R}: x\:R\:y\} \\
			&= \{y\in \mathbb{R}: x^2 = y^2\} \\
		&= \begin{cases}
			\{-y, +y\} & \text{if} & x\neq 0\\
			\{0\} & \text{if} & x = 0 
			\end{cases}
\end{align}
$$

## Properties
> **Claim**: $[\:a\:] \neq \emptyset$
>  
> Given that equivalence classes are based on **equivalence** relations, we know that on a relation on a set $A$, $a\:R\:a$. Then, $$a\in[\:a\:]\neq\emptyset$$