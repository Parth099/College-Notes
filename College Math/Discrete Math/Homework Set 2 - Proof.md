# Chapter 1
## Section 5
##### 5.13 Let x be an integer. Prove that x is odd if and only if x + 1 is even.
###### Proof: x is odd $\implies$ x+1 is even
Let $x\in\mathbb{Z}$ be odd. Thus 
$$\begin{align*}
x&=2n+1, \ n\in\mathbb{Z} \\
x+1&=2n+2
\end{align*}$$

Since $2n+1$ is an integer $2n+2$ is also an integer. 
$$x+1 = 2n+2 = 2(n+1)$$
By definition $2(n+1)$ is ***even*** and so is $x+1$ 
###### Proof: x+1 even $\implies$ x is odd
Let $x+1 \in\mathbb{Z}$ be even.
$$\begin{align*}
x+1&=2n, \ n\in\mathbb{Z} \\
x&=2n-1 \\
x&=2n+(2-2)-1 \\
x&=2n-2+1 \\
x&=2(n-1)+1
\end{align*}$$
By definition since $2(n-1)+1$ is odd and that means $x$ is ***odd***.

##### 5.14 Let $x\in\mathbb{Z}$. Prove that x is odd if and only if there is an integer b such that $x = 2b-1$

Proof for $$x = 2b-1\implies x \text{ is odd}$$ is similar to 5.13.2 above from block equation line 2

###### Proof: $x \text{ odd} \implies x = 2b-1, \ b\in\mathbb{Z}$
$$
\begin{align*}
x&=2b-1\\
x&=2b-1+(2-2)\\
x&=2b-2-1+2\\
x&=2b-2+1\\
x&=2(b-1)+1
\end{align*}
$$
Thus by Definition since $2(b-1)+1$ is odd, $x$ is by consequence also ***odd***.

##### 5.15 Let $x\in\mathbb{Z}$. Prove that  $0\rvert x\iff x=0$ 
###### Proof: $0|x \implies x=0$
$$\begin{align*}
0\rvert x \implies 0c&=x , \ c\in\mathbb{Z}\\
0&=x
\end{align*}
$$

##### 5.18 Prove that the difference between consecutive squares is odd.
Let $n\in\mathbb{Z}$. Then by definition $n^2, (n+1)^2\in\mathbb{Z}$
$$\begin{align*}
(n+1)^2 - n^2 &= n^2 + 2n + 1 - n^2 \\
&= 2n+1
\end{align*}
$$
Since $$(n+1)^2 - (n^2) = 2n+1$$ this difference is *by definition* **odd**.

###### Why?
See that the sum of the first $k$ odd numbers is $k^2$.
Let an odd number be defined by $2n+1$
$$
\begin{align*}

\sum_{n=1}^{k}2n-1 &= 2\sum_{n=1}^{k}n - \sum_{n=1}^{k}1 \\
&= 2\frac{k(k+1)}{2} - k \\
&= k^2 + k - k\\
&= \boxed{k^2}

\end{align*}
$$

See that
$$[\sum_{n=1}^{k}2n-1] - [\sum_{n=1}^{k-1}2n-1] = 2k-1$$
because 
$$\begin{align*}
\sum_{n=1}^{k-1}2n-1 &= 2\frac{(k-1)k}{2} - (k-1) \\
&= k^2-k-k-1 \\
&= k^2 - 2k - 1
\end{align*}
$$
---
9:29pm @1/19/22