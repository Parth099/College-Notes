# Inductive Proofs
## 1
> Show for all positive integers $n$, 
> $$\sum_{k = 1}^n k! * k = (n+1)! - 1$$

For $n = 1$ 

$$
\begin{align}
	\displaystyle\sum_{k = 1}^n k! * k &= 1 \times 1 = \mathbf{1}
	\\
	(n+1)! - 1 &= 2! - 1 = 1
\end{align}
$$

Thus the formula is valid for $n = 1$.

Assume $\sum_{k = 1}^n k! * k = (n+1)! - 1$ for some $n \gt 0$

Then

$$
\begin{align}
	\sum_{k = 1}^{n+1} k! * k &= [(n+1)(n+1)!]+\sum_{k = 1}^{n} k! * k \\
	&= [(n+1)(n+1)!]+[(n+1)! - 1] \\
	&= [(n+1)(n+1)!+[(n+1)!] - 1 \\
	&= (n+1)! \times (n+1+1) - 1 \\
	&= (n+2)! - 1
\end{align}
$$

Therefore $\forall n\in\mathbb{N}, \sum_{k = 1}^n k! * k = (n+1)! - 1$

## 2
In each *part* the domain of $n$ is $\mathbb{N}$
### Part 1
> Show $\forall n$
> $$\sum_{k=1}^n 3k-2= \frac{n(3n-1)}{2}$$

For $n = 1$

$$
\begin{align}
	\sum_{k = 1}^n 3k - 2 &= 1 \\
	\frac{n(3n-1)}{2} = \frac{2}{2} &= 1\\
\end{align}
$$
Thus the formula works for $n = 1$


Assume $\sum_{k=1}^n 3k-2= \frac{n(3n-1)}{2}$ for some $n\in\mathbb{N}$
$$
\begin{align}
\sum_{k=1}^{n+1} 3k-2 &= 3(n+1) - 2 +\sum_{k=1}^{n} 3k-2 \\
&= 3n + 1 + [\frac{n(3n-1)}{2}]\\
&= \frac{3n^2+5n+2}{2} \\
&= \frac{(n+1)(3n+2)}{2} \\
\end{align}
$$
Therefore $\forall n, \sum_{k=1}^n 3k-2= \frac{n(3n-1)}{2}$

### Part 2
> Show $\forall n$
> $$\sum_{k = 1}^n k^3 = \biggr[\frac{n(n+1)}{2}\biggr]^2$$

For $n = 1$

$$
\begin{align}
\sum_{k = 1}^n k^3 = 1^3 &= \mathbf{1}\\
\biggr[\frac{n(n+1)}{2}\biggr]^2 = \biggr[\frac{1(2)}{2}\biggr]^2 = 1^2 &= \mathbf{1}
\end{align}
$$
Thus the formula works for $n = 1$

Assume $\sum_{k = 1}^n k^3 = \biggr[\frac{n(n+1)}{2}\biggr]^2$ for any $n \in \mathbb{N}$

$$
\begin{align}
	\sum_{k = 1}^{n+1} k^3 &= (n+1)^3 + \sum_{k = 1}^{n} k^3 \\
	&= (n+1)^3 + \biggr[\frac{n(n+1)}{2}\biggr]^2 \\
	&= (n+1)^2 [n+1 + \frac{n^2}{4}] \\
	&= \frac{1}{4}(n+1)^2 (n+2)^2\\
	&= \biggr[\frac{(n+1)^2(n+2)^2}{4}\biggr] \\
	&= \biggr[\frac{(n+1)(n+2)}{2}\biggr]^2
\end{align}
$$

Therefore, $\sum_{k = 1}^n k^3 = \biggr[\frac{n(n+1)}{2}\biggr]^2$ for **any** $n\in\mathbb{N}$

### Part 3
> Show $\forall n\in\mathbb{N}$
> $$\sum_{k=1}^n \frac{1}{n(n+1)} = 1 - \frac{1}{n+1}$$

For $n = 1$
$$
\begin{align}
	\sum_{k=1}^n \frac{1}{n(n+1)} = \frac{1}{1(1+1)} &= \frac{1}{2} 
\\
	1 - \frac{1}{n+1} = 1-\frac{1}{2} &= \frac{1}{2}
\end{align} 
$$
Thus the formula works for $n = 1$

Assume $\sum_{k=1}^n \frac{1}{n(n+1)} = 1 - \frac{1}{n+1}$ for some $n\in\mathbb{N}$
$$
\begin{align}
	\sum_{k=1}^{n+1} \frac{1}{n(n+1)} &= \frac{1}{(n+1)(n+2)} + \sum_{k=1}^{n}\frac{1}{n(n+1)} \\
	&= \frac{1}{(n+1)(n+2)} + (1 - \frac{1}{n+1} ) \\
	&= \frac{1}{(n+1)(n+2)} - \frac{1}{n+1} + 1 \\
	&= \frac{1}{(n+1)(n+2)} - \frac{1(n+2)}{(n+1)(n+2)} + \frac{(n+1)(n+2)}{(n+1)(n+2)} \\ \\
	&= \frac{1 - (n+2) + (n+1)(n+2)}{(n+1)(n+2)} \\ \\
	&= \frac{1 - n - 2 + n^2 + 3n+ 2}{(n+1)(n+2)} \\ \\
	&= \frac{n^2 + 2n+ 1}{(n+1)(n+2)} \\ \\
	&= \frac{(n+1)^2}{(n+1)(n+2)} \\ \\ 
	&= \frac{n+1}{n+2} \\ \\
	&= \frac{n+2 - 1}{n+2} \\ \\
	&= 1 - \frac{1}{n+2}
\end{align}
$$

Therefore $\sum_{k=1}^n \frac{1}{n(n+1)} = 1 - \frac{1}{n+1}$ is true all **any** $n\in\mathbb{N}$

## 3
> $$\text{Prove }\forall n\geq 4,\: n^3 \lt 3^n $$

For $n = 1$
$$
\begin{align}
	n^3 = 4^3 &= 64 \\
	3^n = 3^4 &= 81 \\
\end{align}
$$
Since $64 \lt 81$, the formula holds for $n = 1$ 

Assume $n^3 \lt 3^n$ for some $n \geq 4$ 
Observe that
$$
\begin{align}
\frac{(n+1)^3}{n^3} &= \biggr(1+{\frac{1}{n}}\biggr)^3
\end{align}
$$

Since $n\geq 4$, $0\lt\frac{1}{n}\leq\frac{1}{4}$
Then, $1+\frac{1}{n}\leq 1+\frac{1}{4}$
Thus:
$$
\biggr(1+{\frac{1}{n}}\biggr)^3 \leq \biggr(1+{\frac{1}{4}}\biggr)^3 = (\frac{5}{4})^3 = \frac{125}{64} \lt \frac{192}{64} = 3 
$$



Then, 
$$
\begin{align}
	\biggr(1+{\frac{1}{n}}\biggr)^3n^3 &\lt 3^n \times 3\\ \\
	(n+1)^3 &\lt 3^{n+1}
\end{align}
$$

Therefore $\forall n\geq4,\: n^3 \lt 3^n$