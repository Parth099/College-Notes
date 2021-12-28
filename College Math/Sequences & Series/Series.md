# Intro To Series

Series are just sums of [[Sequences]]. This is denoted by:
$$\sum_{n = k}^{\infty} a_n \text{ or } \sum a_n$$

## Partial Sums
Let $a_n$ be a Sequence.
This is its series:
$$\sum_{n = 1}^{\infty} a_n = a_1+a_2+a_3+\dotso$$

Then $s_n$ will denote its partial sum:
$$s_k = \sum_{n = 1}^{k} a_n$$

The convergence status of $s_n$ determines the status of $\sum a_n$.

## Geometric Sum
$$\sum_{n=1}^{\infty} ar^{n-1} = a + ar + ar^2 + \dotso + ar^{n-1} + \dotso = \boxed{\frac{a_0}{1 - r}}$$

Note: We use the power $n-1$ for ease of proof and the fact that when we take a partial sum $s_n$, it will have  $n$ terms.

The convergence of a Geometric Sum depends on the ratio **r**.
It converges if:
$$|r| \lt 1 $$
else, it is divergent.

[Derivation](https://www.youtube.com/watch?v=MBY4WqbOkJg) of $s_n$

$$s_n = \frac{a(1-r^n)}{1-r}$$
$$\lim_{n \to \infty} s_n = \sum ar^{n-1} = \frac{a}{1-r}$$

Here is an alternate geometric intuition & similar triangles for *converging* geometric sums.
![[geoSeries.png]]
## Telescoping Sums
A series in which a set of cancellations lead to a result about the series. 

Consider  : $a_n = \frac{1}{n^2 + n}$,  $\sum_{n = 1}^{\infty} a_n$

$$a_n = \frac{1}{n} - \frac{1}{n+1} \ \text{via partial defrac}$$

$$s_n = (\frac{1}{1} - \frac{1}{2}) - (\frac{1}{2} - \frac{1}{3})- (\frac{1}{3} - \frac{1}{4}) - \dotso - (\frac{1}{n-1} - \frac{1}{n}) - (\frac{1}{n} - \frac{1}{n+1})
$$

Notice each term from $\frac{1}{2}$ to $\frac{1}{n}$ is *canceled* due to subtractions.

$$
\begin{align*}
s_n &= 1 - \frac{1}{n+1} \\
\lim_{n \to \infty} s_n &= 1
\end{align*}
$$

**$\sum a_n$ is convergent**

## Harmonic Series

The harmonic series is defined as:

$$\sum_{n = 1}^{\infty} \frac{1}{n}$$
This is a known **divergent** series. Lets see why:

$$
\begin{align*}
s_2 &= 1 + \frac{1}{2} \\
s_4 &= s_2 + \frac{1}{3} + \frac{1}{4} > s_2 + (\frac{1}{4} + \frac{1}{4}) = 2 \\
s_8 &= s_4 + \frac{1}{5} + \frac{1}{6} + \frac{1}{7} + \frac{1}{8} > s_4 + 4(\frac{1}{8}) = 2\frac{1}{2}
\end{align*}
$$

Thus we see that:
$$s_{2^n} \geq 1 + \frac{n}{2}$$
$$\lim_{n \to \infty} s_{2^n} \to \infty \implies \boxed{\text{divergent}}$$

## Divergence Theorem

If a $\sum a_n$ **is** convergent then:
$$\lim_{n \to \infty} a_n = 0$$

Realize thus statement is in $p \to q$ form and says nothing about $q \to p$. By reading the inverse we can state the Divergence Theorem as:

If
$$\lim_{n \to \infty} a_n \neq 0 \text{ or DNE} $$
then $\sum a_n$ is **divergent**.

## Evaluating Convergence Status Tools

1. $\sum ca_n = c\sum a_n$
2. $\sum a_n \pm b_n = \sum a_n \pm \sum b_n$