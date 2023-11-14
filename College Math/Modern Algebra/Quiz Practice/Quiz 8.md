# Quiz 8
## P1

> Is $f=x^3-2\in \mathbb{Z}_5$ irreducible?

No, see that $f(0)$ is a root. Irreducible polynomials have no roots. 

## P2

> Using the fact that $a^3=a$ for all $a\in \mathbb{Z}_3$ show that $f=x^3+a$ is reducible for any $a$ in $\mathbb{Z}_3$ .

Notice that $f(-a)=(-a)^3+a=\underbrace{(-a)}_{\text{given}}+a=0$ 

Since $f$ contains a root, it is reducible.

## P3

> Let $F$ be a field, and let $f, g\in F[x]$ be irreducible and not associated to each other. Show: $f$ and $g$ are relatively prime.


**ANSWER GIVEN**
Let $d=(f, g)$

Since $d|f$ and $f$ is *irreducible* $d$ is an associate of $1$ and $f$ . Since $d$ is required to be monic notice $d$ can only be $1$ of $\tilde{f}$

By a similar argument using $g$ , $d$ can only be $1$ or $\tilde{g}$ .

Consider if $d\neq 1_F$ then it implies that $d$ is an associate of $f$ and $g$ .  Since *associate* is an equivalence relation, $f, g$ are associates. This cannot be true[^1]. 


$$\boxed{d=1}$$


[^1]: See given statement.