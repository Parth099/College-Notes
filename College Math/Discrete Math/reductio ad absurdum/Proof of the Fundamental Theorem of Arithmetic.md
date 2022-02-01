# Proof of the Fundamental Theorem of Arithmetic (FTA)

We will employ [[Proof By Contradiction]] and [[Infinite Decent]].

> **Fundamental Theorem of Arithmetic**
> $\forall n\geq2\in\mathbb{Z}$, $n$ can be decomposed as a product of primes. 

## Proof
Assume this statement is false.
> **Negation:**
> $\lnot\exists n\geq2\in\mathbb{Z}$ where n can be decomposed as a product of primes. 

Recall that all numbers share one of two states. A number $n\in\mathbb{Z}$ is either composite or prime itself.

### Case 1: $n$ is *prime*
If $n$ is prime we are done. Since $n = 1 * p$. This is already a product of primes ($p$)

### Case 2: $n$ is *composite*
If $n$ is composite, then   $\exists(a_1, b_1)\in\mathbb{Z^+}$ where $1\lt a_1, b_1\lt n$ s.t $n = a_1\times b_1$

We can repeat this argument onto $a_1, b_1$. Then we further factor $a_1, b_1$:
$$
\begin{align*}
	a_1 &= p_1p_2\dotso p_r\\
	b_1 &= q_1q_2\dotso q_k
\end{align*}
$$
$\implies n=p_1p_2\dotso p_rq_1q_2\dotso q_k$

Then suppose we state that one of $a_1$ or $b_1$ say $a_1$ cannot be broken down into primes. We repeat the argument with 
$$
\begin{align*}
a_1&=a_2b_2, (a_2, b_2)\in\mathbb{Z^+}\\
1\lt a_2&, b_2 \lt a_1
\end{align*}
$$

This will descend into an infinite chain of integers. 
$$n \gt a_1 \gt a_2 \gt \dotso$$
This cannot occur. 

Thus none of the factors of $n$ ($a_1, b_1$) can remain composite.
$$\implies \forall n\geq2\in\mathbb{Z} \text{ there exists a prime representation}$$