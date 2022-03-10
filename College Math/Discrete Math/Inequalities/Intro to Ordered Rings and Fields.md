# Intro to Ordered Rings and Fields
## Intro
> Consider Ring $\mathbb{Z}$

We notice that $\mathbb{Z}$ will decompose into
$$\mathbb{Z} = \mathbb{Z}^- \cup \{0\} \cup \mathbb{Z}^+$$
All there sets are **mutually pairwise disjoint**.

$$
\begin{align}
	\mathbb{Z}^+ &= \mathbb{N} \\
	\mathbb{Z}^- &= \{-n : n \in \mathbb{Z}^+\}
	
\end{align}
$$

Observe that $\mathbb{Z}^+$ is closed under addition and multiplication. That is, 

$$\forall a, b \in \mathbb{Z}^+, a + b \in \mathbb{Z}^+, ab \in \mathbb{Z}^+$$

## Defining 'Less than'

Let $a, b\in \mathbb{Z}$, we say that $a \lt b$ if  $b-a\in \mathbb{Z}^+$

Example: Try $a = 3, b = 5$

## The Rational Field
Same setup as before:
$$\mathbb{Q} = \mathbb{Q}^- \cup \{0\} \cup \mathbb{Q}^+$$
Where 
$$
\begin{align}
	\mathbb{Q}^+ &= \{\frac{a}{b} : a, b\in\mathbb{Z}^+, b\neq0\} \\
	\mathbb{Q}^- &= \{-\frac{a}{b} : n \in \mathbb{Q}^+\}
\end{align}
$$

Lets prove closure under addition and multiplication on $\mathbb{Q}^+$

### Proof: Addition Closure
Suppose $\alpha, \beta\in\mathbb{Q}^+$

Then 
$$
\begin{align}
	\alpha &= \frac{a}{b} \\
	\beta &= \frac{c}{d} \\
\end{align}
$$
for $a, b, c, d \in \mathbb{Z^+}$

Then, 
$$
\alpha + \beta = \frac{a}{b} + \frac{c}{d} = \frac{bd+ac}{bc}
$$

Since, $a, b, c, d \in \mathbb{Z^+}$,  $ac, bd, bc \in \mathbb{Z^+}$

Thus $$\boxed{\alpha + \beta \in \mathbb{Q}^+}$$
### Proof: Multiplication Closure
Suppose $\alpha, \beta\in\mathbb{Q}^+$

Then 
$$
\begin{align}
	\alpha &= \frac{a}{b} \\
	\beta &= \frac{c}{d} \\
\end{align}
$$
for $a, b, c, d \in \mathbb{Z^+}$

Then, 
$$
\alpha \beta = \frac{a}{b}\frac{c}{d} = \frac{ac}{bd}
$$

Since, $a, b, c, d \in \mathbb{Z^+}$,  $ac, bd\in \mathbb{Z^+}$
Thus $$\boxed{\alpha\beta \in \mathbb{Q}^+}$$

We can apply the same idea to $\mathbb{R}$

