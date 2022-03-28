# Moment Generating Functions
After learning about Expected value and Variance in Chapter 6 we notice that they **do not** paint the entire picture. While these help us gain intuition on the distribution of a random variable they do not help us understand the density of a random variable. 

Lets consider random variables $X$ and $Y$ with
$$
\begin{align}
	p_X &= \begin{pmatrix}  
				1 & 2 & 3 & 4 & 5 & 6\\  
				0 & \frac{1}{4} & \frac{1}{2} & 0 & 0 & \frac{1}{4}\\  
			\end{pmatrix} 
			\\\\
	p_Y &= \begin{pmatrix}  
				1 & 2 & 3 & 4 & 5 & 6\\  
				\frac{1}{4} & \frac{1}{4} & \frac{1}{2} & 0 & \frac{1}{4} & 0\\  
			\end{pmatrix}
			
		\\\\
		
		E(X) &= 7/2 = E(Y)\\
		V(X) &= 9/4 = V(Y)
\end{align}
$$

Notice the same values for mean and variance but different densities. 

The rising question here is that if we know of $E(X)$ and $V(X)$ what more do we need to determine $p_X$ ?

## Moments
A moment of $X$ is defined to be: 
$$
\begin{align}
	\mu_k &= k\text{th moment of }X \\
		  &= E(X^k) =\sum_{i = 1}^{\infty} (x_i)^kp(x_i)
\end{align}
$$

Notice that the first two moments are just $\mu$ and $\sigma^2$ .

## Moment Generating Functions
> Recall $$e^t = \sum_{k = 0}^{\infty} \frac{t^k}{k!}$$

$$
\begin{align}
	g(t) &= E(e^{tX}) \\
		 &= E\biggr(\sum_{k=0}^{\infty} \frac{(tX)^k}{k!}\biggr) \\
		 &= 1 + tE(X) + \frac{t^2}{2!}E(X^2) + \frac{t^3}{3!}E(X^3) + \dotso
		 \\
		 &= \sum_{k = 0}^{\infty} \frac{\mu_k t^k}{k!}\\
		 &= \sum_{k = 0}^\infty e^{tx_k} p(x_k)
\end{align}
$$
<!-- FILL IN WHY index jumps -->

> **Important:** Notice that differentiating $n$ times gives you $\mu_n$
> $$\dfrac{d^n}{dt^n} g(t) \biggr|_{t = 0} = \mu_n$$

## Moment Generation and Density 
> **Theorem**
> Let $X$ be a discrete random variable with finite range with distribution function $p$ and generation function $g$. 
> *Then*, the $g$ is dependent on $p$ and vice-versa. 

## Ordinary Generating Functions
The is the case such that each $x_j = j$ where $j$ is a positive integer **or** Zero.

Recall that $p$ is the distribution function. 

In this case, 
$$g(t) = \sum_{j = 0}^n e^{tj}p(j)$$

Let $z(t) = e^t$
The, 
$$h(z) = \sum_{j = 0}^n z^j p(j)$$

Here is the relation between $g$ and $h$
$$
\begin{align}
	g(t) &= h(z(t)) = h(e^t) \\
	h(z) &= g(\ln z)
\end{align}
$$

$h$ is known as the Ordinary Generating Function. 

Observe that 
$$
\begin{align}
	h(1) &= g(0) = \sum_{j=0}^\infty e^{0j}p(j) = 1\\
	\\
	h^\prime(1) &= g^\prime(0) = \mu_1 = E(X)
	\\
	h^{\prime\prime}(1) &= g^{{\prime\prime}}(0) - g^\prime(0) = \mu_2 - \mu_1
\end{align}
$$

