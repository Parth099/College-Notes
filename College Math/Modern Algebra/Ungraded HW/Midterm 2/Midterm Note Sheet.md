# Midterm Note Sheet

```
define FIELDS
define Integral Domains

define when which is which
```

## 3.1 Rings
**DEF**
A Ring $R$ is a non-empty set equipped with two operations: $+, \cdot$ . They satisfy these following axioms:

For $a, b, c \in R:$

$$
\begin{align}
a \in R \text{ and } b \in R &\implies a+b \in R \text{ and } ab \in R \\
a+(b+c) &= (a+b)+c \\
a+b &= b+a \\
\exists 0_R \in R&: a+0_R=a \\
\forall a\in R, &\exists x\in R: a+x=0_R \\
a(bc) &= a(bc) \\
a\cdot(b+c) &= ab+ac
\end{align}
$$

+ A ***commutative ring*** is a ring where $ab=ba$
+ A ring with an *identity* is a ring $R$ where $\exists 1_R \in R: a\cdot1_R = a = 1_R a$

**T3.2**
Let $R$ be a ring and $S \subseteq R$ such that

For $a, b \in S$

$$
\begin{align}
a, b \in S &\implies a+b\in S \\
a, b \in S &\implies a\cdot b\in S \\
&0_R \in S \\
\forall a \in S,  &\exists x\in S : a+x=0_R
\end{align}
$$

then $S$ is a subring of $R$ .

## 3.2 Properties of Rings
**T3.3**: For any $a\in R$ the solution $x$ for $a+x=0_R$ is unique. 
**T3.4**: $a+b=a+c \implies b=c$
**T3.6**:

Let $R$ be a ring and $S \subseteq R$ such that $S\neq \emptyset$ .

If:
1. $S$ is closed under subtraction
2. $S$ is closed under multiplication
3. $1_R \in S$   

$$
\implies S \text{ subring of } R
$$

**DEF**
**UNIT**: If $\exists u \in R$ where $au=1_R=ua$ then $a$ is an unit.  

**DEF**
Integral Domain: Product of non-zero is non-zero (ex: $\mathbb{Z}, \mathbb{Z}_p$) (no zero divisors). This implies that any product that is zero implies one of the elements involved is a zero.

**DEF**
Field: Each element $0_R \neq a \in R$ has a unit.  (ex: $\mathbb{R}$). Each field is an Integral Domain.
Every finite Integral Domain is a field. 

**List of Known c-Ring Rules**
+ $a\cdot 0 = 0$
+ $a(-b)=-ab$
+ $-(-a)=a$
+ $-(a+b)=-a+-b$
+ $(-a)(-b)=ab$

## 3.3 Homomorphisms and Isomorphisms 