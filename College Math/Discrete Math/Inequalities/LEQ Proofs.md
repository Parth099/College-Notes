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
