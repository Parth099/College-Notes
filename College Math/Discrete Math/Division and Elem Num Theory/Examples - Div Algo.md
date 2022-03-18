# Examples of the Division Algo
## Notation
> Let $N\in\mathbb{Z}$
> $$b \text{ div } N: \text{quotient}$$
> $$b \text{ mod } N: \text{remainder}$$

## Examples
### EX 1
> Find all integers $N$ such that $$N \text{ div } 200 = 5$$

What this is asking is that what number when divided by 200 have a quotient of $5$

Using [[The Division Algorithm]],
$$N = 200(5) + r$$
Thus $N = 1000 + r$

Since $0\leq r\leq 199$ , 
$$\boxed{1000 \leq N \leq 1199}$$

### EX 2
> Find all **positive** integers $N$ such that $$1000 \text{ div } N = 5$$ 

This is asking which numbers divided by N have a quotient of $5$

Using *the algorithm* we note
$$1000 = 5N + r$$

Notice that 
$$1000 = 5N + r \geq 5N$$

Thus $N \leq 200$

Observe that 
$$1000 = 5n+r \lt 5n+n = 6n$$

This means $N \gt 166\frac{2}{3}$

Thus $\boxed{167 \leq N \leq 200}$

### EX - 3
> Find all $N$ such that $200 \text{ mod } N = 5$ 

This implies we need to find all $N$ such that 
$$
\begin{align}
	200 &= Nq + 5 \\
	195 &= Nq
\end{align}
$$
This task is the same as finding all $N$ such that $N|195$

Notice that $195 = 3 * 5 * 13$
The positive divisors of $195$ are 
$$
\{1, 3, 5, 13, 15, 39, 65, 195\}
$$

Notice that our remainder is $5$ thus 
$$N\in\{13, 15, 39, 65, 195\}$$
because $0\leq r\lt N$