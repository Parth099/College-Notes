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

## VIT : Very Important Theorem
> **Theorem**: 
> Let $R$ be an equivalence relation on a set $A$. Let $[\:a\:]$ and $[\:b\:]$ be equivalence classes. Then either $[\:a\:] = [\:b\:]$ or $[\:a\:]\cap[\:b\:]=\emptyset$
> > Distinct equivalence classes are *disjoint*

> Restatement of the **Theorem** above. 
>  Let $R$ be an equivalence relation on a set $A$. Let $a, b\in A$. Then $[\:a\:] = [\:b\:]$ iff $a\:R\:b$

### Example A
> Suppose $R$ is a relation on $\mathbb{R}^2$. $$(x, y)\:R\:(u, v) \text{ iff } x^2+y^2 = u^2+v^2$$
> Find all $y$ such that $[\:(\frac{1}{\sqrt{2}}, y)\:] = [\:(1, -1)\:]$

Thus means we must find all values where $$(\frac{1}{\sqrt{2}}, y)\:R\:(1, -1)$$
This only occurs when $$(1/\sqrt{2})^2 + y^2 = 2$$
Hence $y = \pm \sqrt{\frac{3}{2}}$

What this means that if $y = \pm \sqrt{\frac{3}{2}}$, the two equivalence classes (sets) are the same and by extension contain the same elements. 

### Example B 
> Consider the relation $\equiv \text{ mod } 5$ on the integers. 
> Compare $[\:7\:]$ and $[\:-2022\:]$

Let $a = 7$ and $b = -2022$
Then $a\:R\:b$ if $a \equiv b \text{ mod } 5$ or equivalently: $5|(a-b)$

Notice that $5\nmid(7-(-2022)) = 2029$
Then the two sets are **disjoint**.