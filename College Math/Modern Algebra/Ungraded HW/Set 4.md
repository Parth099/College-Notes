# Set 4

## Quiz 1.5 Redo

Problem: 
Let $a, b$ be integers and both not zero[^1]. $a, b$ are relatively prime. Show that if $a|c$ and $b|c$ , then $ab|c$

Since $(a, b)=1$ it implies that $\exists x, y$ such that $ax+by=1$

Since $a|c$ and $b|c$ it implies that

$$
\begin{align}
c = as &\text{ for } s \in \mathbb{Z} \\
c = bt &\text{ for } t \in \mathbb{Z}
\end{align}
$$

Then 

$$
\begin{align}
c = c \cdot 1 = c(ax+by) &= cax+cby \\
&= (bt)ax + (as)by \\
&= ab \cdot xt + ab \cdot sy \\
&= \boxed{ab \cdot (xt+sy)}
\end{align}
$$

The last expression implies that $ab|c$ .

[^1]: One of them can be zero