# Midterm Revision 1
## HW2 P2.2.c: Contrapositive Proof

> Show if $2^m+1$ prime for an integer $m > 1$ then it is required $m$ be a power of $2$ ( i.e $m=2^n$ )

Suppose $m$ is not some power of $2$ . Then there exists some prime $p$ such that $p>2$ and $p|m$ . Thus, $\exists q \in \mathbb{Z}: m=q\cdot p$ . 

Notice that since $m>0,p>0$ then it follows $q>0$ .

Let $a=2^q$ 

Then $2^m+1 = a^p+1$

> Notice ${a}^p = {2^{q}}^{p} = 2^m$

From previous problems we know $a^p+1$ can be factorized non trivially implying it[^1] cannot be prime.

You can see that $2^q+1 | 2^m+1$ . 

---

Remarks on ***P2.2.c***

We realize that if we allow $m$ to be a power of $2$ it will not allow the $2^m+1$ to be factor-able. 

You can see that $2^q+1 | 2^m+1$ explained:

See that $2^q + 1 = 2^q - (-1)$
Then: $$2^m + 1 = ({2^{q}})^p - (-1)^p$$

See that since $a-b|a^n-b^n$ ,

$$
2^q - (-1)\ |\ ({2^{q}})^p - (-1)^p = 2^m+1
$$


<!--
## HW2 P2.2.c: Direct Proof

$$
\begin{align}
\mathcal{U} &= \biggr\{ a \in \mathbb{Z}_n \biggr| \exists b \in \mathbb{Z}_n : ab=1 \biggr\} \\ \\
\mathcal{Z} &= \biggr\{ a \in \mathbb{Z}_n \biggr| a\neq 0,\  \exists b \in \mathbb{Z}_n \setminus \{0\} : ab=0\biggr\} \\
\end{align}
$$

> Show that the sets $\{0\}, \mathcal{U}, \mathcal{Z}$ are pairwise disjoint in $\mathbb{Z}_n$
-->

## HW1 P3 : $\Leftarrow$ (backwards)

> Show that:
> $$\exists u, v \in \mathbb{Z}: au+bv=1 \implies (a, b)=1$$


Let $d = (a, b)$

Then $d|a$ and $d|b$ . Subsequently we can write $a=da^{\prime}$ and $b=db^{\prime}$ for integers $a^{\prime}, b^{\prime}$ .

See that:

$$
1 = au+bv = da^{\prime}u+db^{\prime}v = d(a^{\prime}u+b^{\prime}v)
$$
 
This shows that $d|1$. Since $d$ is a greatest common divisor, $\boxed{d=1}$ 

## Quiz 1 P5

> Show that:
> $$(a, b)=1,\ a|c,\ b|c \implies ab|c$$

By T1.2, $\exists u, v \in\mathbb{Z}: au+bv=1$

We also have $c=as, c=bt$ for integers $s, t$ given by the premise. 

Then:

$$
\begin{align}
c = c \cdot 1 &= c \cdot (au+bv) \\
&= cau + cbv \\
&= (bt)au + (as)bv \\
&= ab \cdot (tu+sv) 
\end{align}
$$

The last statement shows that $ab|c$ .

## Quiz 3 P2

> Show that:
> $$[a][b]=[1] \text{ for some } [b]\in\mathbb{Z}_n \iff (a, n) = 1$$ 

### Forwards $\Rightarrow$

Suppose $[a][b]=[1]$ for some $[b]\in\mathbb{Z}_n$ .

Then it follows that $ab \equiv 1 \bmod n$ and consequently $n|ab-1$ .

This means: $\exists y\in\mathbb{Z}: ny=ab-1$ .

This statement is equivalent to $ab-ny=1$ . Since $\exists b, y\in\mathbb{Z}$ such that $ab-ny=1$ it implies $\gcd(a, n)=1$ .  

### Backwards $\Leftarrow$

Suppose $(a, n)=1$

Then there exists $b, y \in \mathbb{Z}$ such that 

$$
ab+ny=1
$$

This statement is equivalent to $ab-1=-ny$ implying that $n|ab-1$ implying $ab\equiv1\bmod n$ 

Therefore $\exists[b]\in\mathbb{Z}_n: [a][b]=[1]$ if $(a, n)=1$

[^1]: Recall its equal to $2^m+1$