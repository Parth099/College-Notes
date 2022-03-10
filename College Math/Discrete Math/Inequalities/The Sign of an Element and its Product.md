# The Sign of an Element and its Product(s)
Let $R$ be a ring ($F$: Field), be an **ordered** ring. 
Let $x, y\in R$

If $x, y \in R^+$, then $xy\in R^+$
If either one (or both) of $x, y$ is in $\{0\}$, then $xy = 0$
If $x, y \in R^-$ then $-x, -y\in R^+$.
Thus
$$xy = (-x)(-y) \in R^+ \text{ since }R^+\text{ is closed under mult}$$


If one of them is in $R^-$ say $y \in R^-$
Then, $-y\in R^+$ and $x(-y) > 0 \in R^+$ But then $-(x)(-y) < 0 \in R^-$ and this $xy \in R^-$.

## Extensions

### Collary 1
> Let $x\in R$ for $x\neq 0$, then $x^2 \gt 0$

Suppose $x\in R^+$
Then $x\cdot x \in R^+$ via closure and thus $x^2 > 0$

Suppose $x\in R^-$
Then, $xx > 0$ as product of two negatives is positive as shown in the above heading. 

### Collary 2
> The multiplicative identity $1$ is positive and $-1$ is negative. 

Since $1 = 1^2$, $1>0$ and thus $1\in R^+$ 
Since $1\in R^+$ , $-1 \in R^-$ via set Definition of $R^-$
$$R^- = \{-x:x\in R^+\}$$

### Proof 
> **Definition**
> Suppose $F$ is an ordered field.
> Let $x\in F$ for $x\neq 0$
> Then there exists a multiplicative inverse $x^{-1} \text{ or } \frac{1}{x}$ such that $$xx^{-1} = 1$$

> Show that if $x \gt 0$ then $\frac{1}{x} \gt 0$

Suppose $x>0$ and $\frac{1}{x} \lt 0$
Then  $x\frac{1}{x} = 1$
Since a positive times a negative makes a negative $1\in R^-$. 
**\[contradiction\]**

Hence, if $x\gt 0$ then, $\frac{1}{x} \gt 0$