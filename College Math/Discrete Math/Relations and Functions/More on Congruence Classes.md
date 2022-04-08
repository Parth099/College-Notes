# The Ring of Integers mod $n$
> Let $R$ be relation $\equiv\text{ mod }n$ for a positive integer $n$.

The distinct congruence class here are 
$$
[\:0\:], [\:1\:] \dotso [\:n-1\:]
$$

Let
$$\text{Let }\mathbb{Z}_n = \biggr\{[\:0\:], [\:1\:] \dotso [\:n-1\:]\biggr\}$$

Lets define $+$ and $*$ on $\mathbb{Z}_n$
## Defining Operations
### Relational Setup
> Let $a, b, c, d\in\mathbb{Z}$. 
> Suppose $a\equiv b\text{ mod }n$ and $c\equiv d\text{ mod }n$. Then we can prove via the divisibility definition: 
> 1. $$a+c\equiv b+d\text{ mod }n$$
> 2. $$ac\equiv bd\text{ mod }n$$

> **Side Note**: The facts above can help us compute modular arithmetic faster

### Definition
*Note*: any variables like $a, b, c, d, \dotso$ are representers of the equivalence class. 
$$
\begin{align}
	[\:a\:] + [\:b\:] &= [\:a+b\:]\\
	[\:a\:] [\:b\:] &= [\:ab\:]
\end{align}
$$

This is mildly confusing. 
How do we know that if $[\:a\:] = [\:b\:]$ and $[\:c\:] = [\:d\:]$, then $[\:a+b\:] + [\:c+d\:]$?

#### Proof
Suppose $[\:a\:] = [\:b\:]$ and $[\:c\:] = [\:d\:]$

Then, $a\equiv b\text{ mod }n$ and $c\equiv d\text{ mod }n$.

Hint: ($[\:a\:] + [\:b\:]$ iff $a\:R\:b$ which is true here)

Then both  $a+c\equiv b+d\text{ mod }n$ and $ac\equiv bd\text{ mod }n$ are true. (We didn't prove it here)

Then $a+c\:R\:b+d$ and $ac\:R\:bd$.
Therefore, 
$$
\begin{align}
	[\:a+c\:] &= [\:b+d\:]\\
	[\:ac\:] &= [\:bd\:]\\
\end{align}
$$

## The Ring of Integers is *Commutative*
This means:
$$
\begin{align}
	\biggr([\:a+b\:]\biggr)+[\:c\:] &= [\:a\:]+\biggr([\:b+c\:]\biggr) \\
	&= [\:a+b+c\:]
\end{align}
$$

## Divisibility 
Much like integers, 
> For $[\:a\:], [\:b\:]\in\mathbb{Z}_n$ we say that $[\:a\:]$ divides $[\:b\:]$ if $$\exists [\:c\:]\in\mathbb{Z}_n\text{ s.t } [\:b\:] = [\:c\:][\:a\:]$$

This is denoted by $[\:a\:]\biggr|[\:b\:]$

### Examples of Divisibility 
> $$\text{Context = }\mathbb{Z}_{10}$$

Notice that $[\:2\:]\biggr|[\:4\:]$ since $[\:4\:] = [\:2\:][\:2\:]$

However notice that $[\:4\:]\biggr|[\:2\:]$ since  $[\:4\:][\:3\:]= [\:12\:] = [\:2\:]$
Even more weird is the fact that $[\:7\:]\biggr|[\:4\:]$

> **Important**: Unlike the integers the 'quotient' here is not unique. For examples there exist many $c$ that make this statement true $[\:4\:] = [\:2\:][\:c\:]$. Notice that $c = 2, 7, 102, \dotso$

## The Inverse $[\:x\:]^{-1}$
> $[\:a\:]\in\mathbb{Z}_n$ is called a unit if it has a multiplicative inverse in $\mathbb{Z}_n$
> This means that $\exists[\:b\:]\in\mathbb{Z}_n$ s.t $[\:a\:][\:b\:]=[1]$

Notation : $[\:b\:] = [\:a\:]^{-1}$

> **Important**: If this inverse exists it is ***unique***.

The proof is almost as same as the proof for the uniqueness of the inverse for *square* matrices. We have to exploit the commutative property defined above.

## Existence of the Unit
>  $[\:a\:]\in\mathbb{Z}_n$ is a unit iff $\text{gcd}(a, n) = 1$

Suppose  $[\:a\:]\in\mathbb{Z}_n$  is a unit.
Then by definition $\exists[b]\in\mathbb{Z}_n$ such that $[a][b] = [ab] = 1$.

We know that $[ab] = 1$ if and only if $ab \equiv 1\text{ mod } n$.
Then, $n|(1-ab)$. Since $n|(1-ab)$ then $1-ab = kn$ for some integer $k$. 
Then $kn+ab = 1$
Since $k, b\in\mathbb{Z}$, $\text{gcd}(a, b) = 1$

Suppose $\text{gcd}(a,n) = 1$. Then $\exists k, m\in\mathbb{Z}$ s.t $ak + nm = 1$
Then $mn = 1-ak$ and by extension $n|(1-ak)$.

Since $n|(1-ak)$, $ak\equiv1\text{ mod }n$
This means that $ak\:R\:1$ and thus $[ak] = [a][k] = [1]$
Thus $[a]$ is a unit. 

Therefore $[\:a\:]\in\mathbb{Z}_n$ is a unit iff $\text{gcd}(a, n) = 1$

> **Property**:
> If $[\:a\:]$ **is** a unit then, $\forall [\:b\:]\mathbb{Z}_n$, $[\:a\:]\biggr|[\:b\:]$.
<!-- 
UNSURE IF THIS IS TRUE
 For each division $[a]/[b]$ where $[\:a\:]$ is a unit, the quotient: $[\:c\:]$ is unique.
-->
## Example: Division in the Ring
> Find $[\:11\:]\biggr/[\:19\:]$ in $\mathbb{Z}_{23}$

We need to find a $[\:a\:]\in\mathbb{Z}_{23}$ such that $[\:19\:][\:a\:] = [\:11\:]$ or equivalently we need to find $$[\:19\:]^{-1}[\:11\:]$$

We need to find the inverse of $[\:19\:]$ which means we need to find a $[\:b\:]\in\mathbb{Z}_{23}$ such that $[\:19\:][\:b\:] = [\:19b\:] = [\:1\:]$

This implies that $19b\:R\:1$ under the $\equiv\text{mod }23$ relation

Then, $23|(1-19b)$
Then $1-19b=23k$ for some integer $k$
Then, $1 = 23k+19b$

Asking for constants $k, b$ is the reverse of the Euclidean algorithm. We need to form $1$ with the $\text{gcd}(19, 23)$.

**The Algorithm**:
$$
\begin{align}
	23 &= 19(1) + 4 \\
	19 &= 4(4)  + 3 \\
	4  &= 3(1)  + 1
\end{align}
$$
This was a given fact since both $19, 23$ are prime. 

We can work back from here
$$
\begin{align}
	4 &= 23 - 19   \\
	3 &= 19 - 4(4) = 19 - 4(23 - 19) = 5(19) - 4(23)\\
	1 &= 4 - 3 = (23 - 19) - 5(19) - 4(23) \\
	&= 5(23) + (-6)(19)
\end{align}
$$

Then $1\equiv-6*19\text{ mod }23$
$$[\:19\:]^{-1} = [\:-6\:]$$
Then $[\:-6\:][\:11\:] = [\:-66\:] = [\:3\:]$

$$
[\:11\:] \biggr/ [\:19\:] = [\:3\:]
$$