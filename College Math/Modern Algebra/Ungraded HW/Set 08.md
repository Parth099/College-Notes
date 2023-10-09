# Set 8

## 2.1.14

### a)

> Prove or disprove: If $ab = 0 \mod n$, then $a = 0 \mod n$ or $b= 0 \mod n$.


Suppose $a=2, b=3, n=6$

Then $ab = 6 \equiv 0 \mod 6$ yet $a = 2 \not\equiv 0 \mod 6$ and $b = 3 \not\equiv 0 \mod 6$

### b)

By the assumption $n|ab$ . Given that $n$ is prime either $n|b$ or $n|a$ which is equivalent to $a \equiv 0 \mod n$ or $b \equiv 0 \mod n$ .

## 2.1.15

> If $(a, n) = 1$ , prove that there is an integer $b$ such that $ab = 1 \mod n$ .

Since $\gcd(a, n)=1,\ \exists x, y \in\mathbb{Z}: ax+ny=1$ . 

$$
\begin{align}
ax + ny = 1 \to 1 - ax = ny
\end{align}
$$

Since $n|1 - ax$ , $ax\equiv1\mod n$

Let $b=x$ .

Therefore, if $(a,n)=1$ , then $\exists b\in\mathbb{Z}: ab=1\mod n$ .

## 2.1.17

> Prove that $10^n \equiv (-1)^n \mod 11$ for every positive $n$.

Know that $10 \equiv -1 \mod 11$

Since, this fact is true we can use the multiplicative property[^1] of residues to stat that:

$$10^n \equiv (-1)^n \mod 11$$ 

for any $n \in \mathbb{Z}^+$

## 2.1.19

> Prove or disprove: If $[\ a\ ]_n = [\ b\ ]_n$ in $\mathbb{Z}_n$ then $(a, n) = (b, n)$ . 

Since $[\ a\ ]_n = [\ b\ ]_n$ , it implies $a \equiv b \mod n$ meaning $a=b+nk$

Notice via a previous equality:

$$
(a, n) = (b+nk, n) = (b, n)
$$

[^1]: Theorem 2.2