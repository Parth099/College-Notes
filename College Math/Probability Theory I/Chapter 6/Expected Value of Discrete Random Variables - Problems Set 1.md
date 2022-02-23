# Expected Value of Discrete Random Variables - PS1
## 1
![[cp6_1p1.png]]
$$\Omega = \{-1, 1\}$$
$$
\begin{align*}
	m(-1) &= \frac{5}{9} \\
	m(1) &= \frac{4}{9}
\end{align*}
$$
Expected Calculation:
$$
\begin{align*}
E(X) &= \sum_{x\in\Omega} xm(x)\\
	 &= -1(\frac{5}{9}) + 1(\frac{4}{9}) \\
	 &= -\frac{1}{9}
\end{align*}
$$

This *adds* up since we have more even($+1$) elements than odd.
## 2
![[cp6_1p2.png]]
$$
\begin{align}
	\Omega &= \{+1, -2\} \\
	m(+1)  &= \frac{1}{2} \\
	m(-2)  &= \frac{1}{2} \\
\end{align}	
$$
$$E(X) = 1\frac{1}{2} + (-2)\frac{1}{2} = -\frac{1}{2}$$

## 16
![[cp6_1p16.png]]
### (a) - w/o dist
We can employ the (magical) Linearity of Expectation Theorem.
> Let $X_i$ hold the value of the $i$th dice roll.
> $$E(X_i) = i\frac{1}{6}$$
> This is because only one slot is filled with a number $i$

Let $X = X_1+X_2+X_3+X_4+X_5+X_6$, then
$$
\begin{align}
E(X) &= E(X_1+X_2+X_3+X_4+X_5+X_6) \\
	 &= E(X_1) + E(X_2) + E(X_3) + E(X_4) + E(X_5) + E(X_6)\\
  ^* &= \sum_{i = 1}^{6}i\frac{1}{6} \\
	 &= \frac{1}{6}(21) = 7/2
\end{align}
$$
I wrote it like this to make it fit into a single line and to make a point about how $$E(X_i) = i\frac{1}{6}$$ due to the numbers (or lack thereof) on the dice. 
### (b)
Let $X$ be the sum of the $6$ dice
It is very hard to win. See that 5 out of 6 sides of the dice are $0$.
$$P(X = 0) = (5/6)^5 \approx .3348$$
$$P(X = 21) = (1/6)^5 \approx 2.143 \times 10^{-5}$$

We conclude that getting 0 is higher probability than any other non-zero value.

## 17
![[cp6_1p17.png]]
### Part a
$X$ is counting failure now.
$$
\begin{align}
	P(X = 1) &= q\\
	P(X = 2) &= qp\\
	P(X = 3) &= qp^2\\
	&\vdots	\\
	P(X = k) &= qp^{k-1}
\end{align}
$$

### Part b
$$
\begin{align}
	\sum_{k = 1}^\infty P(X = k) &= q + qp + qp^2 + \dotso\\
		&= q(1 + p + p^2 + p^3 + \dotso) \\
		&= q(\frac{1}{1-p}) \\
		&= q\frac{1}{q} \\
		&= 1 
\end{align}
$$
### Part c
We need to find $E(X)$
$$
\begin{align}
	E(X) &= \sum_{x = 1}^{\infty} xP(X = x)\\
	     &= 1q + 2qp + 3qp^2 + \dotso \\
		 &= q(1 + 2p + 3p^2 \dotso) \\
	  ^* &= q\frac{1}{(1-p)^2} \\
	     &= q/q^2 \\
		 &= \boxed{\frac{1}{q}}
\end{align}
$$
\* - Attained by differentiating the Geometric series:
$$a + ar + ar^2 \dotso = \frac{a}{1- r}$$
## 21 - Interesting
![[cp6_1p21.png]]

$$X\sim\text{Poisson}(\lambda)$$
$$\text{Recall }P(X = k) = e^{-\lambda}\frac{\lambda^k}{k!}$$

$$
\begin{align*}
	E(X) &= \sum_{k = 0}^{\infty} kP(X = k) \\
	
		 &= \sum_{x = 0}^{\infty} ke^{-\lambda}\frac{\lambda^k}{k!} \\
		 
		 &= e^{-\lambda}\sum_{x = 0}^{\infty} k\frac{\lambda^k}{k!} \\
		 
		 &= e^{-\lambda}(\frac{\lambda}{0!}+\frac{\lambda^2}{1!}+\frac{\lambda^3}{2!}+\frac{\lambda^4}{3!}+\dotso)\\
		 
		 &= \lambda e^{-\lambda}(\frac{1}{0!}+\frac{\lambda}{1!}+\frac{\lambda^2}{2!}+\frac{\lambda^3}{3!}+\dotso)\\
		 
		 &= \lambda e^{-\lambda}(e^{\lambda})\\ \\
		 
		 &= \lambda
\end{align*}
$$
