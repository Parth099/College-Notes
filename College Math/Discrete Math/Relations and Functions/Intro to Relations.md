# Relations
> Let $A, B$ be sets. The relation from $a$ to $b$ is a subset $$R\subseteq A\times B$$where $\times$ is the Cartesian Product

If $a, b\in R$ we state that $a$ is related to $b$ via $R$
We use the following notation for the above clause:
1. $a\:R\:b$
2. $a\sim b$

## The Main 3 Properties of Relations
> A relation on set $A$ is the subset $R$ such that $$R\subseteq A\times A$$
1. Reflexive: $\forall a\in R, a\:R\:a$
2. Symmetric: If $a\:R\:b$ then $b\:R\:a$ 
3. Transitive: If $a\:R\:b$ and $b\:R\:c$ then, $a\:R\:c$

### Equivalence Relations
An Equivalence Relation is a relation such that all three forementioned properties are **true**. 

## Congruence Relations
Let $n$ be a *positive* integer and let $a, b$ be integers. 
We say that a is congruent to $b$ mod $n$ if $n|(b-a)$

Notation: $a\equiv b \text{ mod } n$

Notice that this relation is an **Equivalence Relation**
### Reflexive
Let $a\in\mathbb{Z}$
Then, $a-a =0$
$n|0$ as $n\cdot 0 = 0$
Hence $a\equiv a \text{ mod } n$.
Since $a\:R\:a$, this relation is *reflexive*

### Symmetric
Suppose $a\:R\:b$. Then $a\equiv b \text{ mod } n$.
Thus $n|(b-a)$
Since $n|(b-a)$, $n|-(b-a) = a-b$

Since $n|a-b$, $b\equiv a \text{ mod } n$
This means that if $a\:R\:b$ then $b\:R\:a$
Thus the relation is *symmetric*.

### Transitive
Suppose $a\:R\:b$ and $b\:R\:c$
This means that $a\equiv b\text{ mod } n$ and $b\equiv c\text{ mod } n$
Then, $n|b-a$ and $n|c-b$
Since $n|b-a$ and $n|c-b$, $n|(b-a)+(c-b) = c-a$
Since $n|c-a$, $a\equiv c\text{ mod } n$
Thus, $a\:R\:c$
Therefore the relation is *transitive*.

Given that this relation is, *reflexive*, *symmetric*, and *transitive*. The congruence relation is an **Equivalence Relation**.