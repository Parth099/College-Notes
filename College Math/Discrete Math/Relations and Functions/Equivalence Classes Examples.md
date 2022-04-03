# Equivalence Classes Examples
## Functional General
> Suppose $f: A\to B$ is a function.
> Let $R$ be a relation on $A$ where for some $a, b\in A$, $a\:R\:b$ if $f(a) = f(b)$

#### Reflexivity
Notice that 
$$\forall a\in A, f(a) = f(a)$$
Since $a\:R\:a$ for any $a\in A$, $R$ is **reflexive**

#### Symmetric
Suppose $a\:R\:b$. Then $f(a) = f(b)$ which is the same as $f(b) = f(a)$. Hence, $b\:R\:a$ if $a\:R\:b$ and $R$ is **symmetric**. 

#### Transitivity
Suppose $a\:R\:b$ and $b\:R\:c$. Then $f(a) = f(b)$ and $f(b) = f(c)$.

Then $f(a) = f(c)$ and $a\:R\:c$
Thus $R$ is transitive. 

> From here on out we assume *any* function exhibits the properties of an equivalence relation.  

## Functional 2
> Let $R$ be a relation on $\mathbb{R}$. $$x\:R\:y\: \text{ iff }\sin x = \sin y$$

$$
\begin{align}
	[\:0\:] &= \{x\in\mathbb{R}, \sin 0 = \sin x\} \\
			&= \{\pi n: n\in\mathbb{Z}\}
			\\\\
			
	[\:1\:] &= \{x\in\mathbb{R}, 1\:R\:x\} \\
			&= \{x\in\mathbb{R}, \sin 1 = \sin x\} \\
			&= \{1+2\pi n: n\in\mathbb{Z}\} \:\cup\:\{(\pi-1)+2\pi n: n\in\mathbb{Z}\}
\end{align}
$$

This graphic should convey why we need two sets (one for each angle). 
![[eqviv_class_sin.png]]

## Congruence
> Let $R$ be a relation on $\mathbb{Z}$. $a\:R\:b$ if $a\equiv b \text{ mod } 5$

Then, $5|(b-a)$ if $a\:R\:b$
$$
\begin{align}
	[\:2\:] &= \{b\in\mathbb{Z}:2\:R\:b\} \\
			&= \{b\in\mathbb{Z}:2\equiv b\text{ mod } 5\} \\
			&= \{b\in\mathbb{Z}: 5|(b - 2)\}\\
\end{align}
$$

if $5|(b-2)$ then $5n = b-2$ for some integer $n$. 
Then $b$ is given by $5n+2

$$
\begin{align}
			&= \{5n+2:n\in\mathbb{Z}\}\\
\end{align}
$$