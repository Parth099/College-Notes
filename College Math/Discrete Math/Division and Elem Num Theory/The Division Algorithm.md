# The Division Algorithm
## *Theorem*
> Let $a\in\mathbb{Z}^+$
> Then for any  $b\in\mathbb{Z}$ there exists unique  $q\in\mathbb{Z}$ and  $r\in\mathbb{Z}^+$ such that
> 1. $b = qa+r$
> 2. $0\leq r \lt a$

See that $q$ is the quotient and $r$ is the remainder. 

### Examples
#### EX A
Let $a = 10$ and $b = 23$
$$23 = 10(2) + 3$$
Thus $q = 2, r=3$
#### EX B
Let $a = 5$ and $b = -37$
$$-37 = 5(-8) + 3$$
Thus $q = -8, r=3$

**Note**: $q \neq -7$ since we require that $0\leq r \lt 5$

## Proof: Division Algorithm
Prereq: Well-Ordering Principle over $\mathbb{N}+\{0\}$

### Proof: Existence of $q, r$
> The key idea for this proof is the fact that $r$ is the smallest number $\geq0$ we can achieve from subtracting multiples of $a$ from $b$

Let $b, a \in\mathbb{Z}$ and $a\gt0$
$$
\text{Let } S = \{
	b-qa: q\in\mathbb{Z}, b-qa\geq0
\}
$$
This is the set of all remainders. Since we need $r\geq0$ we append the conditional: $b-qa\geq0$

> Suppose $b = 11, a = 3$
> Then $$S = \{2, 5, 8, 11, 14,\dotso\}$$
> Notice the least element: $2$

We now need to prove that $S \neq \emptyset$ to apply the well ordering principle. 

Suppose $q = -|b|$ since $b\lt0$ is possible
Then,
$$b-qa = b+|b|a \geq b+|b| \geq 0\text{ since } a\geq 1$$

Notice the quantity satisfies $b-qa\geq 0$ and thus $|S|\neq 0$ 

Now that we have shown $S$ is non empty we can employ the well ordering principle. 

Notice that all elements of $S$ are $\geq 0$. Since $r \in S$, this means $r\geq0$

$$r\in S \subseteq q\in \mathbb{Z}_{\geq0}$$
Thus $r = b-qa$ for some $q\in \mathbb{Z}$
We will let $r$ be the smallest element in $S$

Now we must show that $r\lt a\in\mathbb{Z}^+$

Suppose that $r\geq a$ and subsequently $r-a\geq0$
Since $r = b-qa$, then
$$r-a = b-qa-a = b-(q+1)a $$
for $q+1\in\mathbb{Z}$

See that this fits the description of $S$
Our quotient ($q+1 \in \mathbb{Z}$) is valid and $r-a\geq 0$. 

**Thus** $r-a\in S$ 
Recall that $a\in \mathbb{Z}^+$ and this means that $r-a\lt r$. Yet this will contradict the fact that $r$ is the least element of $S$. Hence, $r\lt a$

At this point we have show that: 

$$\exists q, r\in\mathbb{Z}, b=qa+r ,0\leq r\lt a$$

Now for uniqueness: 
We need this Lemma: [[Lemma - Divisor ABS Value]]

Suppose $q, r$ is **not** unique:
Suppose $b = q_1a+r_1$ and $b = q_2a+r_2$ for $0\leq r_1,r_2 \lt a$

Then
$$
q_1a+r_1 = q_2a+r_2 
$$

Thus 
$$(q_1-q_2)a = r_2 - r_1$$

Since $(q_1-q_2)a \in \mathbb{Z}$, $a|(r_2 - r_1)$

Recall that $0\leq r_1,r_2 \lt a$

We can note that
$$
0 - a \lt r_2 - r_1 \lt a - 0
$$

So $$|r_2-r_1|\lt a$$

However, $a|(r_2 - r_1)$.
Since the difference of the two $r_2-r_1$ can be at most $a-1$ and if $a|(r_2 - r_1)$, their difference is **0**.

$r_2 - r_1 = 0$ implies that $q_1=q_2$ and both $b$'s are the same.

Subsequently, $q, r$ are unique.

