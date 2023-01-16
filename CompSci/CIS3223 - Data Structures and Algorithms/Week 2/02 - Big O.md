| Date    |
| ------- |
| 8-29-22 |

# Big O
## More Theorems

### Intro to Big O
$$
1,\, \log{n},\, n^a,\, n^b,\, a^n,\, b^n,\, n!,\, n^n 
$$

Suppose $f$ and $g$ are functions such that the function $f$ is found to the left of $g$. Then we can conclude that $f \in o(g)$ or 
$$
\lim_{n\to\infty} \frac{f(n)}{g(n)} = 0
$$

### Dominates
If
$$
f \prec g \prec h
$$
where the symbol $\prec$ means "dominated by", then, 
$$
f\times g \in O(h)
$$

**Example**:
See that $3^n + n2^n \in O(3^n)$
This is a result of the above theorem. 

### Sums
$$
\sum_{k = 0}^n f(k) = \Theta\biggr(\int_1^n f(x) \mathop{dx} \biggr)
$$
\* - For $f$ increasing

**Example**:

$$
\begin{align}
\sum_{k = 0}^n \log{k} &= \Theta\biggr(\int_1^n \log{x} \mathop{dx} \biggr)
\\ \\ \\
	\int_1^n \log{x} \mathop{dx} &= \biggr( x\cdot\log{x} - x \biggr)\biggr|_{x=1}^{x=n} \\
	&= n\log{n} - n + 1
	
	\\ \\
	\sum_{k = 0}^n \log{k} &\in \Theta(n\log{n} )

\end{align}
$$

> Notice how this sum can help approximate the number of binary digits in $n!$