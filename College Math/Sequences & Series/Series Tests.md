# The Comparison Test
[[Series]] & [[Sequences]]
## Theorem
> Suppose $a_n$ and $b_n$ are strictly positive 

If $\sum b_n$ is convergent and $a_n \leq b_n \ \forall n \gt k$ then $\sum a_n$ **is** convergent

If $\sum b_n$ is divergent and $a_n \geq b_n \ \forall n \gt k$ then $\sum a_n$ **is** divergent

# The Limit Comparison Test
## Theorem

Let $a_n, b_n$ be strictly positive sequences
If 
$$\lim_{n\to\infty}\frac{a_n}{b_n} = c$$
where $c \gt 0$ then both series have the same convergence status.

# Alternating Series Test
An Alternating Series is a series in which each term *alternates* between positive and negative. 

Let $a_n$ be Alternating Sequence
Let $b_n = \lvert a_n \rvert$

$a_n$ is convergent **if**
$$b_n > b_{n+1} \text{ and } \lim_{n\to\infty}{b_n} = 0$$

Additionally realize this:
$$\rvert a_n \vert \geq a_n \ \forall{n}$$
This shows that if $\rvert a_n \vert$ is convergent then so is $a_n$ via comparison.

# Ratio Test 
Let $a_n$ be a sequence.
$$\text{Let } \lim_{n\to\infty}\lvert\frac{a_{n+1}}{a_n}\rvert = L$$

| L Condition | Convergence Status |
| ----------- | ------------------ |
| $L < 1$     | **Convergent**     |
| $L = 1$     | **Inconclusive**   |
| $L > 1$     | **Divergent**      | 

# Root Test
Let $a_n$ be a sequence.
$$\text{Let } \lim_{n\to\infty}\sqrt{\lvert a_n\rvert} = L$$

| L Condition | Convergence Status |
| ----------- | ------------------ |
| $L < 1$     | **Convergent**     |
| $L = 1$     | **Inconclusive**   |
| $L > 1$     | **Divergent**      | 