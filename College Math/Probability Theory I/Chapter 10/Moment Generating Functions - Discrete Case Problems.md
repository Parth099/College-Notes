# Examples 
> **Definition of Moment Generation**:
> $$g(t) = E(e^{tX})$$
## Example 1
> Suppose $X$ is distributed via over sample space $\{1, 2, 3, \dotso, n\}$ such that $P(X = j) = \frac{1}{j}$ for $1\leq j\leq n$

$$
\begin{align}
	g(t) &= \sum_{j = 1}^{n} e^{tj}\cdot[\frac{1}{n}] \\
	 &= \frac{1}{n} (e^t + \dotso + e^{nt}) \\
	 ^* &= \frac{e^t(e^{nt} - 1)}{n(e^t - 1)}
\end{align}
$$

> The uses the sum of a **finite** geometric sequence
> $$S_n = \frac{a(r^n - 1)}{r - 1}$$
> $r$ is the common ratio while $a$ is the first term 

Lets calculate some moments.
This version is easier to work with:
$$g(t) = \frac{1}{n} (e^t + \dotso + e^{nt}) 
$$

### $\mu_1$
$$\frac{d}{dt}g(t) = \frac{1}{n}(e^t + 2e^{2t} + \dotso + ne^{nt})$$
$$g^{\prime}(0) = \frac{1}{n}\frac{n(n+1)}{2} = \frac{n+1}{2}$$

### $\mu_2$
$$\frac{d^2}{dt^2}g(t) = \frac{1}{n}(1e^t + 4e^{2t} + \dotso + n^2e^{nt})$$
$$g^{\prime\prime}(0) = \frac{1}{n}\frac{n(n+1)(2n+1)}{6} = \frac{(n+1)(2n+1)}{6}$$

Since $\sigma^2 = \mu_2 - \mu_1^2$, 
$$\sigma^2 = (n^2-1)/12$$

## Example 2 - Binomial
> Suppose $X$ is Binomially distributed with $n$ trials with success $p$ and failure $q = 1-p$

$$
\begin{align}
	g(t) &= E(e^{tX}) \\
	     &= \sum_{k = 0}^{n} e^{tk} \binom{n}{k} p^k q^{n-k} \\
		 
		 &= \sum_{k = 0}^{n}  \binom{n}{k} e^{{k}^{t}} p^k q^{n-k} \\
		 
		&= \sum_{k = 0}^{n}  \binom{n}{k} (pe^t)^k q^{n-k} \\
		
		&= \boxed{(pe^t + q)^n}
\end{align}
$$
> This is attained via the **Binomial Theorem**
> $$(a+n)^n = \sum_{k = 0}^n \binom{n}{k} a^n b^{n-k}$$

### $\mu_1$
$$
\begin{align}
g^\prime(t) &= [(pe^t + q)^n]^\prime = n(pe^t + q)^{n-1}pe^t \\
g^{\prime}(0) &= n(p+q)^{n-1}p = np
\end{align}
$$


\* - $p+q=1$

### $\mu_2$
$$
\begin{align}
	g^{\prime\prime}(t) &= [(pe^t + q)^n]^{\prime\prime} \\
	
	[n(pe^t + q)^{n-1}pe^t]^{\prime} &= (n-1)(n)p^2 + np\\
\end{align}
$$

### $\sigma^2$
$$
\mu_2 - \mu_1^2 = (n-1)(n)p^2 + np - n^2p^2 = np - np^2 = npq
$$

## Example 3 - Geometric
> Suppose $X$ is distributed geometrically over the space $\mathbb{Z}^+$

The mass function is: $p_X(j) = pq^{j-1}$
$$
\begin{align}
g_X(t) &= \mathbb{E}(e^{tX})\\
	   &= \sum_{k = 1}^{\infty} e^{tk} pq^{k-1} \\
	   &= \frac{p}{q}\sum_{k = 1}^{\infty} e^{tk} q^{k} \\
	   &= \frac{p}{q}\sum_{k = 1}^{\infty} (e^tq)^k\\
	   &= \frac{p}{q} \frac{e^tq}{1 - e^tq} \\
	   
	   &= \frac{pe^t}{1 - e^tq}
	   
\end{align}
$$

### $\mu_1$
$$
g^{\prime}(t) = \frac{pe^t(1-e^tq) + pe^t\cdot qe^t}{(1-e^tq)^2} = \frac{pe^t}{(1-e^tq)^2}
$$
$$g^\prime(0) = \boxed{\frac{1}{p}}$$
### $\mu_2$
$$
\begin{align}
g^{\prime\prime}(t) &= \frac{pe^t(1-qe^t)^2 + 2pe^tqe^t(1-qe^t)}{(1-qe^t)^4} 
\\ \\
&= \frac{pe^t(1-qe^t)[(1-qe^t)+2qe^t]}{(1-qe^t)^4}
\\ \\
&= \frac{pe^t(1+qe^t)}{(1-qe^t)^3}

\\\\

g^{\prime\prime}(0) &= \frac{p(1+q)}{(1-q)^3} = \frac{1+q}{p^2}

\end{align}
$$
### $\sigma^2$
Since $$\sigma^2 = \mu_2 - \mu_1^2$$
$$\mu_2 - \mu_1^2 = \frac{1+q}{p^2} - (\frac{1}{p})^2$$

$$\sigma^2 = \boxed{q/p^2}$$
This lines up with information from 
## Example 4 - Poisson
> Suppose $X$ is Poisson distributed over the space $\mathbb{Z}_{\geq0}$

Then, 
$$
p_X(x, \lambda) = e^{-\lambda}\frac{\lambda^x}{x!}
$$

$$
\begin{align}
	g(t) &= \mathbb{E}(e^{tX}) \\
		 &= \sum_{k = 0}^\infty e^{tk} p_X(x) \\
		 &= \sum_{k = 0}^\infty e^{tk} e^{-\lambda}\frac{\lambda^k}{k!} \\
		 &= e^{-\lambda} \sum_{k = 0}^\infty  \frac{(e^{t}\lambda)^k}{k!} \\
		 
		 &= e^{-\lambda} e^{e^t\lambda} = e^{e^t\lambda - \lambda} \\
		 
		 &= e^{\lambda(e^t - 1)}
\end{align}
$$

### $\mu_1$
We now see that 
$$g(t) = e^{\lambda(e^t - 1)}$$

$$
\begin{align}
g^{\prime}(t) &= e^{\lambda(e^t - 1)}\lambda e^t \\
g^\prime(0) &= \lambda 
\end{align}
$$

### $\mu_2$
Given that 
$$
\begin{align}
g^{\prime}(t) &= e^{\lambda(e^t - 1)}\lambda e^t
\\
g^{\prime\prime}(t) &= \lambda e^t \cdot e^{\lambda(e^t - 1)} + e^{\lambda(e^t - 1)}\lambda e^t \lambda e^t \\
&= e^{\lambda(e^t - 1)}\lambda e^t (1 + \lambda e^t) \\\\

g^{\prime\prime}(0) &= (1)(\lambda)(1+\lambda) \\
&= \boxed{\lambda^2 + \lambda}
\end{align}
$$

We can note that this result aligns well with our **known** $\sigma^2$