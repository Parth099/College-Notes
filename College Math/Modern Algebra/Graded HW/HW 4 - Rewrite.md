# HW 4 - Rewrite
## Problem 4.4

> Let $R$ be an integral domain with $a, b \in R$ associates. Show $$a \text{ irreducible} \iff b \text{ irreducible}$$

By Symmetry it suffices to prove the forwards implication ($\implies$)

Suppose $a$ is irreducible, then it is not a unit or the additive identity.

Since $a, b$ are associates, $b=xa$ for a $x \in R^{\times}$ .

Whenever $a$ is factorized into $u, v \in R: a=uv$ **only**[^1] one of $u$ or $v$ is a unit because $a$ is irreducible. Both $u, v$ are non zero.

Then all factorizations of $b$ look like:

$$
b = \mathbf{x} \cdot \underbrace{uv}_a
$$

For each of these factorizations fix $u$ to be the unit. Then let $c=\mathbf{x}u$ and see that $c \in R^{\times}$ .

Thus all factorizations of $b$ look like $b=cv$ for $c \in R^{\times}$. Since $R$ is an integral domain with $c, v \neq 0$ , $b \neq 0$ .

Suppose $b \in R^{\times}$

Since $b$ and $a$ are associates $a=yb$ for $y \in {R}^{\times}$ . Since both $y$ and $b$ are units it follows that $a$ is a unit. However $a$ cannot be a unit since $a$ is irreducible.

$$
\therefore b \not \in R^{\times}
$$

Notice the characteristics of $b$
+ any factorization of $b$ contains one unit  
+ $b \neq 0_R$
+ $b \not \in R^{\times}$

it follows that $b$ is irreducible.



[^1]: Both $u$ and $v$ cannot be units at the same time, otherwise $a \in R^{\times}$ . 