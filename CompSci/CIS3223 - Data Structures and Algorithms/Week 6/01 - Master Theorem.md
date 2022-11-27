# Master Theorem

> Helps us categorize the runtime of algorithms by how the divide problems 

The following bounds are tight, this means $\Theta$ can replace the $O$ notation.

## Divide and Conquer
For $a\geq1,\ b\gt1,\ d\geq0$ and $T(n)$ being defined as:

$$
T(n) = aT\biggr(\biggr\lceil\frac{n}{b}\biggr\rceil\biggr) + O(n^d)
$$

Then $T(n)$ satisfies the following asymptotic bounds:

$$
\begin{align}

d \gt \log_ba &\implies T(n) = O(n^d) \\
d = \log_ba &\implies T(n) = O(n^d\log n) \\
d \lt \log_ba &\implies T(n) = O(n^{\log_ba}) 

\end{align}
$$



## Subtract and Conquer

For $a,b\gt0,\ d\geq0$ and $T(n)$ being defined as:

$$
T(n) = aT(n-b) + O(n^d)
$$

Then $T(n)$ satisfies the following asymptotic bounds:

$$
\begin{align}

a \lt 1 &\implies T(n)=O(n^d) \\
a = 1 &\implies T(n)=O(n^{d+1}) \\
a \gt 1 &\implies T(n)=O(n^da^{n/b})
\end{align}
$$