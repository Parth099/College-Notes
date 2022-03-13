# Ordered Rings and Fields
## Definition: **Ordered Ring**
> An ordered Ring (or Field) is a ring $R$ or(Field $F$) such that
> $$R = {R}^- \cup \{0\} \cup {R}^+$$ 
> where three properties hold
> 1. The three sets above are pairwise disjoint
> 2. $R^- = \{-x:x\in R\}$
> 3. Closed under addition and subtraction

$\mathbb{Z}$ is an ordered Ring while $\mathbb{Q}$ is an ordered Field.

## Relations
Let $R$ be an ordered ring (or field $F$).
Let $a, b\in R$

Then $a$ is less than $b$ if $b-a \in R^+$.

## Properties of Inequalities 
> Let $R$ be an ordered ring and let $a, b \in R$

Then these Properties hold:
1. Only one of the three below is true
	+	$a<b$
	+	$a>b$
	+	$a=b$

2. Let $c \in R$. If $a<b$ and $b<c$ then $a<c$
3. If $a<b$ then $\forall c\in R, a+c<b+c$
4. if $a<b$, then $\forall c\in R, ac<bc$

## Proofs for 'Properties of Inequalities'

### Proof (1)
Let $a, b\in R$. 
Since $R = {R}^- \cup \{0\} \cup {R}^+$ and the three unions are disjoint $b-a$ is in one of the sets. 

Suppose $b - a \in R^+$, then $a < b$ .
Suppose $b - a \in \{0\}$, then $a = b$ .

Suppose $b - a \in R^-$. 
Then $b-a = -x$ for some $x\in R^+$. 
$$-(-x) = -(b-a) = a - b$$

Thus $a-b = x \in R^+$, thus by definition $a>b$

### Proof (2)
Suppose $a, b, c \in R$ and $a<b$ and $b<c$
Then 
$$
\begin{align}
	b - a &= x \\
	c - b &= y \\
\end{align}
$$
for $x, y \in R^+$ 

Then $x+y = (b-a) + (c-b) = c-a$
Since $x, y \in R^+$, $c-a \in R^+$ and thus $a<c$

### Proof (3)
Suppose $a, b, c \in R$ and $a<b$ and. Then $b-a\in R^+$.
Since $(b-c)-(a-c) = b-a \in R^+$, $a+c<b+c$ if $a<b$. 


### Proof (4)
Suppose $a, b, c \in R$ and $a<b$ and $c\in R^+$
Then $b-a\in R^+$ .
$$bc-ac = c(b-a) \in R^+ \text{ since R has additive closure}$$
Hence, $ac<bc$ if $a<b$ and $c\in R^+$

## Examples
> $R$ is an ordered Ring and  $a, b, c, d \in R$ 
### E1
> Show that if $a<b$ and $c<d$ then $a+c < b+d$

Since $a<b$ and $c<d$, then
$$
\begin{align}
	b - a &\in R+ \\
	d - c &\in R+ \\
\end{align}
$$

Then, 
$$(b+d)-(a+c) = (b-a) + (d-c) $$
Since $b-a\in R^+$ and $d-c\in R^+$ their sum $(b-a) + (d-c)\in R^+$.

Thus $(a+c) < (b+d)$

### E2
> Suppose $a, b, c, d \in R^+$
> Show that if $a<b$ and $c<d$ then $ac < bd$

Since $a<b$ and $c<d$, then

$$
\begin{align}
	b - a &\in R+ \\
	d - c &\in R+ \\
\end{align}
$$

Then, 
$$bd-ac = bd+(-bc+bc)-ac = b(d-c) + c(b-a) $$
Since $b-a, d-c, b, c \in R^+$ and $R^+$ is closed under addition, $ac<bd$

### E3
> Show that if $a, b \in F^+$ where $F$ is an ordered field and $a \lt b$ then $$\frac{1}{a} \gt \frac{1}{b}$$ (iff proof)

Suppose $a\lt b$
Then,  $b-a\in F^+$
See that:
$$
\frac{1}{a} - \frac{1}{b} = \frac{b-a}{ab} = \frac{1}{ab}(b-a)
$$

Since $a, b \in F^+$, $ab \in F^+$ via additive closure.
Thus $\frac{1}{ab} \in F^+$
Thus $\frac{1}{ab}(b-a) \in F^+$

Therefore, $\frac{1}{a} \gt \frac{1}{b} \in F^+$ and 
$$\boxed{\frac{1}{a} \gt \frac{1}{b}}$$
if $a, b \in F^+$ for $a, b \in F^+$

Conversely suppose $\frac{1}{a} \gt \frac{1}{b} in F^+$
Then 
$$
\frac{1}{a} \gt \frac{1}{b} = \frac{1}{ab}(b-a) \in F^+
$$

Since $\frac{1}{ab} \in F^+$, $b-a$ must be an element of $F^+$. 

Thus $a < b$ if $\frac{1}{a} \gt \frac{1}{b}$

### E3 - ALT PROOF
> Show that if $a, b \in F^+$ where $F$ is an ordered field and $a \lt b$ then $$\frac{1}{a} \gt \frac{1}{b}$$ (iff proof)

Suppose $a<b$
Since $a, b \in F^+$, it implies $ab \in F^+$ which implies $\frac{1}{ab} \in F^+$

Since $a, b \in F^+$, we can multiply by $\frac{1}{ab}$ as it wont alter the sign since all numbers are elements of $F^+$

$$\frac{1}{ab}a\lt\frac{1}{ab}b$$

Thus $\frac{1}{a} \gt \frac{1}{b}$ if $a<b$

Suppose $\frac{1}{a} \gt \frac{1}{b}$
Since $a, b \in F^+$, it implies $ab \in F^+$ 

$$ab\frac{1}{a} \gt ab\frac{1}{b}$$

Thus, $a<b$ if $\frac{1}{a} \gt \frac{1}{b}$

## ADV Examples