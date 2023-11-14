# Quiz 6
## P1

Let $f: R\to S$ be a homomorphism of rings and let $T$ be a subring of $S$ .

Let 

$$
P = \{ r\in R\ |\ f(r) \in T \}
$$

Show $P$ is a subring of $R$ .

---

We know that $1_S \in T$ and $f(1_R) = 1_S$ . Thus $f(1_R)\in T$ implying $1_R \in P$

Let $r, s \in P$ . Since $r, s\in P$ it is evident that $r, s \in R$ and more importantly $f(r), f(s) \in T$  .

Since $T$ is a subring (closed under Mult/Sub) we have:

$$
\begin{align}
f(r)+f(s)&=f(r+s) \\
f(r)f(s)&=f(rs) 
\end{align}
$$

Thus $P$ is a subring of $R$ .