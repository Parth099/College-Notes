# Function Properties
## Definitions
Let $f:A\to B$ be a function. 

1. $f$ is one-to-one (injective) if $$\forall a_1,a_2\in A \text{ with } a_1\neq a_2, f(a_1)\neq f(a_2)$$ This also means that "no two elements" map to the same element. 
2. $f$ is onto (surjective) if $$\forall b\in B\:\:\exists a\in A\text{ s.t }f(a) = b$$
3. $f$ is bijective if it is both one-to-one and onto. 



## How to Prove *One-to-One* or *Onto*

Since both statements require a '*forall*' proof, the disproof is trivial. 

> Notice that if we prove both Onto and one-to-one we have shown that $f$ is **bijective**. 


### One-to-One
To prove a function $f$ is one-to-one we can show directly if $a_1\neq a_2$ then $f(a_1)\neq f(a_2)$ .
A more common method is to argue via contrapositive.

We must show that if $f(a_1) = f(a_2)$ then $a_1 = a_2$

### Onto
To show a function is onto we must show that each element of the image has a valid mapping in the domain. 
This means that we must show that for any $b \in B$ there exists $a\in A$ such that $f(a) = b$.

> $f$ is onto iff $\text{im }f = B$

## Proof Examples

> For each example below we will determine whether it is one-to-one, onto, both or none.  

### Example 1
$$
\begin{align}
	f &: \mathbb{R} \to \mathbb{R} \\
	f(x) &= 3x-2
\end{align}
$$
#### Claim: $f$ is one-to-one
Suppose $f(x_1) = f(x_2)$
Then $3x_1 - 2 = 3x_2 - 2$
Then, $3x_1 = 3x_2$.

Since $x_1 = x_2$ if $f(x_1) = f(x_2)$, $f$ is one-to-one. 

#### Claim: $f$ is onto
Let $y\in\mathbb{R}$
Let $x = \frac{y+2}{3}$. Then $x\in\mathbb{R}$

Then, $$f(x) = 3x-2 = 3\biggr(\frac{y+2}{3}\biggr) - 2 = y$$

Since there exists an element in the domain for an arbitrary $y$ in the image, $f$ is onto. 

Since $f$ is both onto and one-to-one, $f$ is bijective. 

### Example 2
$$
\begin{align}
	f &: \mathbb{Z} \to \mathbb{Z} \\
	f(x) &= 3x-2
\end{align}
$$

By the same proof in Example 1, $f$ is one-to-one. 

#### Claim $f$ is *not* onto
Let $y = 0$
Then $3x-2 = 0$ and $x = \frac{2}{3}$.
Since $x\not\in\mathbb{Z}$, $f$ is not onto. 

> An alternate argument is knowing that this function represents $[\:1\:]\in\mathbb{Z}_3$ . Since $[\:1\:]\neq\mathbb{Z}$, $f$ **cannot** be onto. 

### Example 3
$$
\begin{align}
	f &: \mathbb{R} \to \mathbb{R} \\
	f(x) &= \frac{1}{x^2 + 1}
\end{align}
$$

#### Claim $f$ is *not* one-to-one
$f$ is not onto because $f(1) = f(-1) = 1$. Since $1\neq-1$, $f$ is not onto. 

#### Claim $f$ is *not* onto
Let $y=-1$
Then, $y=f(x)$, 
$$-1 = \frac{1}{x^2 + 1}$$

Thus $-1 = x^2 + 1$ and then $x^2 = -2$. But there is no $x\in\mathbb{R}$ such that $x^2 = -2$. So $f$ is **not** onto. 

### Example 4
$$
\begin{align}
	f &: \mathbb{Z} \to \mathbb{Z} \\
	f(n) &= \begin{cases}
		\frac{n}{3} & \text{if} & 3\:|\:n \\
		n+3 & \text{if} & 3\nmid n \\
	\end{cases}
\end{align}
$$
#### Claim $f$ is *not* One-to-one
Since $f(-2) = f(3) = 1$ and $-2 \neq 3$, $f$ is not one-to-one. 
#### Claim $f$ is Onto
Suppose $n\in\mathbb{Z}$. 
Let $k = 3n$. Then $k\in\mathbb{Z}$ and $3|k$

Thus, 
$$
f(k) = \frac{k}{3} = \frac{3n}{3} = n
$$
Then, $\forall n\in\mathbb{Z}\:\:\exists k\in\mathbb{Z}$ s.t $f(k) = n$. 
Thus $f$ **is** onto. 

### Horizontal Line Test
$f:\mathbb{R} \to \mathbb{R}$ **is** one-to-one if it passed the *Horizontal Line Test*. 