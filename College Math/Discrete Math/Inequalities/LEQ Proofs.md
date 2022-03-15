# LEQ Proofs
## 1
> $$\text{Show } \forall x\in \mathbb{R}^+, x+\frac{1}{x} \geq 2$$

For this statement to be true,
$$(x+\frac{1}{x}) - 2\geq 0$$

$$
(x+\frac{1}{x}) - 2 = \frac{x^2 + 1 - 2x}{x} = \frac{(x+1)^2}{x}
$$

Since $x\in \mathbb{R}^+$, then $\frac{1}{x}\in R^+$ and $(x+1) \in \mathbb{R}^+$.

Thus
$$
\frac{(x+1)^2}{x} \geq 0
$$

Hence, $\forall x\in \mathbb{R}^+, x+\frac{1}{x} \geq 2$

## 2
> Find all $x\in \mathbb{R}$ such that $x \leq x^2$

See that $x \leq x^2$ **iff** $x^2 - x \geq 0$

$$x^2 - x = x(x-1)$$

Lets analyze the factors.
$x \leq 0$ for $x \leq 0$
$x - 1 \leq 0$ for $x \leq 1$

However both are negative or 0 for $x \leq 0$

Thus $x \leq x^2$ for $x \in (-\infty, 0] \cup [1,+\infty)$

## 2.1
> Find all $x\in \mathbb{R}$ such that $\frac{1}{x+1} \gt x-1$

Suppose $\frac{1}{x+1} \gt x-1$
Then $\frac{1}{x+1} - (x-1)\geq 0$

$$
\frac{1}{x+1} - (x-1) = \frac{1}{(x+1)} - \frac{(x+1)(x-1)}{x+1} = \frac{1 - (x^2 - 1)}{x+1} = \frac{2-x^2}{x+1}
$$

Thus we need to find where 
$$\frac{2-x^2}{x+1}\geq 0$$
or 
$$\frac{x^2-2}{x+1}\lt 0$$

Lets analyze the factors of the signs:
$$\frac{x^2-2}{x+1} = \frac{1}{x+1}(x-\sqrt{2})(x+\sqrt{2})$$

See that the sign of $\frac{1}{x+1}$ is the same as $x+1$

Here is a "Flag - Diagram"
![[flag-diag.png]]

See that the negative ranges are:
$$(-\infty, -\sqrt{2})\:\cup\:(-1, \sqrt{2})$$

Thus $\frac{1}{x+1} \gt x-1$ if $x\in(-\infty, -\sqrt{2})\:\cup\:(-1, \sqrt{2})$

# Extra Problems
For any problems stated below all variables unless stated belong to ordered field $F^+$

## EP 1
> Prove $$\frac{a}{b} \lt \frac{c}{d} \iff bc-ad \in F^+$$


Suppose $\frac{a}{b} \lt \frac{c}{d}$.
Then $$\frac{c}{d} - \frac{a}{b} \in F^+$$
$$
\frac{c}{d} - \frac{a}{b} = \frac{bc-ad}{bd}
$$

Since $b, d \in F^+$, $bd \in F^+$
Since $\frac{bc-ad}{bd} \in F^+$, $bc-ad \in F^+$

The reverse proof is the same thing but backwards. 
$$
\frac{1}{bd}(bc-ad) = \frac{bc-ad}{bc} = \frac{c}{d} - \frac{a}{b} = \dotso
$$

## EP 2
> Prove
> $$\frac{a}{b} \lt \frac{a+c}{b+d} \lt \frac{c}{d}$$
> given the following is **true**
> $$\frac{a}{b} \lt \frac{c}{d}$$

$$
\frac{a+c}{b+d} \lt \frac{c}{d} \iff \frac{c}{d} - \frac{a+c}{b+d} \gt 0
$$

See that 
$$
\frac{c}{d} - \frac{a+c}{b+d} = \frac{c(b+d) - d(a+c)}{d(b+d)} = \frac{bc-ad}{d(b+d)}
$$

Given that $b, d \in F^+$, $d(b+d) \in F^+$
Given that $\frac{a}{b} \lt \frac{c}{d}$ is true, $bc-ad \in F^+$ as developed in ***EP-1***.

Since both quantities are positive then 
$$
\frac{c}{d} - \frac{a+c}{b+d} \in F^+
$$
and subsequently  
$$
\frac{a+c}{b+d} \lt \frac{c}{d}
$$

Conversely, Suppose 
$$
\frac{a}{b} \lt \frac{a+c}{b+d} 
$$

Then 
$$
\frac{a+c}{b+d}  - \frac{a}{b} \in F^+
$$

See that 
$$
\frac{a+c}{b+d}  - \frac{a}{b} = \frac{b(a+c) - a(b+d)}{b(b+d)} = \frac{bc - ad}{b(b+d)}
$$

Since $b, d \in F^+$, $b(b+d) \in F^+$

Given that $b, d \in F^+$, $d(b+d) \in F^+$
Given that $\frac{a}{b} \lt \frac{c}{d}$ is true, $bc-ad \in F^+$ as developed in ***EP-1***.

Since both quantities are positive then 
$$
\frac{a+c}{b+d} - \frac{a}{b} \in F^+
$$

and thus
$$
\frac{a}{b} \gt \frac{a+c}{b+d}
$$

Since $\frac{a}{b}$ is a lower-bound and $\frac{c}{d}$ is the upper-bound then:

$$
\boxed{\frac{a}{b} \lt \frac{a+c}{b+d} \lt \frac{c}{d}} \text{ if } \frac{a}{b} \lt \frac{c}{d}
$$

## EP 3
> Find all $x \in \mathbb R$ s.t
> $$-\frac{1}{2} \leq \frac{x}{x^2 + 1} \leq \frac{1}{2}$$

**Consider** $\frac{x}{x^2 + 1} \leq \frac{1}{2}$, thus, 
$$
\frac{1}{2} - \frac{x}{x^2 + 1} = \frac{x^2 + 1 - 2x}{2x^2+2} = \frac{(x-1)^2}{2(x^2+1)} \in F_{\geq 0}
$$

Given that $(x-1)^2, x^2+1\in F_{\geq 0}$, $\frac{1}{2} - \frac{x}{x^2 + 1} \in F_{\geq 0}$ and thus:
$$
\frac{x}{x^2 + 1} \leq \frac{1}{2}
$$

**Consider** $-\frac{1}{2} \leq \frac{x}{x^2 + 1}$
By definition
$$\frac{x}{x^2 + 1} + \frac{1}{2} \in F_{\geq 0}$$
Then
$$
\frac{x}{x^2 + 1} + \frac{1}{2} = \frac{x^2+1+2x}{2(x^2+1)} = \frac{(x+1)^2}{2(x^2+1)} 
$$

Given that $(x+1)^2, x^2+1\in F_{\geq 0}$, $\frac{(x+1)^2}{2(x^2+1)}  \in F_{\geq 0}$ 

Thus, $-\frac{1}{2} \leq \frac{x}{x^2 + 1}$

Subsequently,
$$-\frac{1}{2} \leq \frac{x}{x^2 + 1} \leq \frac{1}{2}$$
is true for any $x \in \mathbb R$


<!-- needs improvement -->

