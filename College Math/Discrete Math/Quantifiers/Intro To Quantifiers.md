# Intro To Quantifiers
The two Quantifiers in math are
> $\forall$ - "for all"
> $\exists$ - "there exists"

$\forall x\in U, P(x)$ reads "for all $x$ in $U$ property $P(x)$ is true".

$\exists$ is the same except it reads "there exists".

## Example
+ Forall
	-  $\forall a\in\mathbb{Z}, a|0$
	-  $\forall x\in\mathbb{R}, x^2 + 1 > 0$

+ Exists
	+ $\exists x\in\mathbb{N}, n^2-4$ is prime. We can take $n=3$

## Proofs
### $\forall$ Proofs
#### Ex.1
> Prove $$\forall a\in\mathbb{Z}, a|0$$

Let $a\in\mathbb{Z}$
then $0 = a*0$ and thus $a|0$

#### Ex.2
> Prove $$\forall x\in\mathbb{R}, x^2 + 1 > 0$$

Let $x\in\mathbb{R}$ then $x^2 \geq 0$
Then $x^2+1 \gt 0$ since $1 > 0$

### $\exists$ Proof
These proofs just require an example that the statement can be true under the right var setting. 

## Negation
### Universal
$$
\begin{align*}
	\lnot(\forall x\in U, P(x)) = \exists x\in U, \lnot P(x)
\end{align*}
$$

This is what is used to disprove a universal statement($\forall$), we must *prove* its negation.

### Example of Disproof Universal
> Disprove
> $$\forall x\in R, x^2 + x > 0$$

Let $x = -\frac{1}{2}$
Then $x^2+x = -\frac{1}{4}$ which is less than 0.

This is similar to a counter example to find.

### Existential
$$
\begin{align*}
	\lnot(\exists x\in U, P(x)) = \forall x\in U, \lnot P(x)
\end{align*}
$$
To disprove an existential we need to *prove* its negation.

> Disprove
> $$\exists x\in\mathbb{N}, x = 2x$$

Let $x\in\mathbb{N}$. Then $$2x - x = x \neq 0$$ 
since $0 \not \in \mathbb{N}$.
Since $2x - x \neq 0$, $x \neq 2x$.
Hence, $\exists x\in\mathbb{N}, x = 2x$ is false


> Disprove
> $$\exists a\in\mathbb{Z}, 4a+5 \text{ is even}$$

Let $a\in\mathbb{Z}$. 
$$4a+5 = 4a+4+1 = 2(2a+2)+1$$
$2a+2\in\mathbb{Z}$ since $a\in\mathbb{Z}$.
Hence $4a+5$ is odd for all $a\in\mathbb{Z}$. 
In other words there does not exist any number $a\in\mathbb{Z}$ such that $4a+5$ is even. 

## Several Quantifiers
### Examples
#### Ex.1
For any integer $a$, there exists $b$ such that they both add to $2022$.
> **Answer**
> $$\forall a\in\mathbb{Z}, \exists b\in\mathbb{Z}, a+b = 2022$$

#### Ex.2
> $$\exists x\in\mathbb{N}, \exists y\in\mathbb{N}, \exists z\in\mathbb{N}, x^2+y^2=z^2$$

This works for the any pythagorean triple like $(3, 4, 5)$. Yet if we raise the exponents $2\to 3$ the statement is *falsified*.