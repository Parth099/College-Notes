# Geometric Distribution
Suppose we encounter a [[Random Variable]] $T$ that counts the number until the number of trials until the first success. Then $T$ is geometrically distributed. 

$$T \sim \text{Geom}(p) \text{ where } p=P(\text{Success})$$

## Formula
$$
\begin{align*}
	P(T = 1) &= p \\
	P(T = 2) &= pq \\
	P(T = 3) &= pq^2 \\
	\vdots\\
	P(T = k) &= pq^{k-1}
\end{align*}
$$
Verify that it **is** a distribution.
$$
\begin{align*}
	\sum_{n = 1}^{\infty} P(T = k) &= p + pq + pq^2 + \dotso \\
	
	&= p(1 + q + q^2 + q^3 + \dotso) \\
	
	&= p(\frac{1}{1-q})\text{ via Geom Seq}\\
	
	&= \frac{p}{p} \\ &= 1
\end{align*}
$$

## Observations
### Observation 1
Know: $q = 1 - p$. 
$p$: success
$$
\begin{align*}
P(T > k) &= \sum_{n = 1}^{\infty}P(T = k + n) \\
&= P(T = k + 1) + P(T = k + 2) + P(T = k + 3) + \dotso \\
&= pq^k + pq^{k+1} + pq^{k+2} + \dotso \\ 
&= pq^k(1 + q + q^2 + \dotso) \\
&= pq^k\frac{1}{1-q} \\
&= \boxed{q^k}
\end{align*}
$$

### Observation 2
$$
\begin{align*}
	P(T > r + s \ |\ T > r) &= \frac{P(T > r+s \cap T > r)}{P(T > r)}\\\\
	
	&= \frac{P(T > r+s)}{P(T>r)}\\
	
	&= \frac{q^{r+s}}{q^r}\\
	
	&= q^s
\end{align*}
$$
Notice that the conditional probability is **not** dependent on $r$. This means the trials faced before have no effect on trials after.

In Probability, this is known as \"memory-less\". 
