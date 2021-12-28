# Notation
A sequence can be though of an ordered list of numbers that adheres to some rule:
$$a_1, \ a_2, \ a_3, \ a_4, \ \dotso, \ a_n, \ \dotso$$

A sequence is usually denoted by curly braces.
Ex: 
$\{a_n\}$ or $\{a_n\}_{n = k}^{\infty}$

## Examples
| Notation                      | Formula                         | Terms                                                         |
| ----------------------------- | ------------------------------- | ------------------------------------------------------------- |
| $\{\frac{(-1)^n(n+1)}{3^n}\}$ | $a_n = \frac{(-1)^n(n+1)}{3^n}$ | $\{\frac{-2}{3}, \ \frac{3}{9}, \ \frac{-4}{27}, \ \dotso \}$ |
| $\{\cos{\frac{n\pi}{6}}\}_{n=0}^{\infty}$    | $a_n = \cos{\frac{n\pi}{6}}$    | $\{1,\frac{\sqrt{3}}{2},\frac{1}{2},0,\dotso,\cos{\frac{n\pi}{6}},\dotso\}$                                                              |

Example 2 has an internal reoccurring pattern and thus the formula is mentioned in the terms section.

## The Limit of a Sequence

The limit of a Sequence is the number it approaches when $a_n$ tends to infinity.

$$\lim_{n \to \infty} a_n$$

If this limit has a concrete number $L$ that it tends to, this Sequence is **convergent**, else it is **divergent**.

If the Sequence is **convergent**, then the Limit laws(addition, subtraction ...) apply to it.

### Limit Example:
Is $\{\frac{\ln{n}}{n}\}$ convergent?
$$\lim_{n \to \infty} \frac{\ln{n}}{n} \to \frac{\infty}{\infty} \ {\text{L'Hôpital}}$$

$$\lim_{n \to \infty} \frac{1/n}{1} = 0$$


## Useful Theorems
### Squeeze Theorem
**IF**:
$$
\begin{align*} 
a_n \leq b_n \leq c_n \text{ for } n \geq n_0 \\
\text{and } \lim_{n \to \infty} a_n = L \\
\lim_{n \to \infty} c_n = L
\end{align*}
$$
Then:
$$\lim_{n \to \infty} b_n = L$$


### Absolute Value Theorem
$$
\lim_{n \to \infty} |a_n| = 0 \implies \lim_{n \to \infty} a_n = 0
$$

## Monotonicity

Let $\{a_n\}$ be a Sequence.
If $\{a_n\}$ is decreasing or increasing $\forall n \geq 1$ then its monotonic.

We can show Monotonicity by comparing $a_n$ and $a_{n+1}$.

### Monotonicity Example
$$a_n = \frac{n}{n^2+1}$$
From its formula we can see its likely decreasing.
$$a_{n+1} = \frac{n+1}{(n+1)^2 + 1}$$

#### Work:
$$
\begin{align*}
\frac{n}{n^2+1} &\gt \frac{n+1}{(n+1)^2 + 1} \\
\frac{n}{n^2+1} &\gt \frac{n+1}{n^2 + 2n + 2} \\

n(n^2 + 2n + 2) &\gt (n+1)(n^2+1) \\ 
n^3 + 2n^2 + 2n &\gt n^3 + n^2 + n + 1 \\
n^2 + n &\gt 1
\end{align*}
$$

This fact is true for $n \gt 1$ and thus $a_n$ is decreasing.
