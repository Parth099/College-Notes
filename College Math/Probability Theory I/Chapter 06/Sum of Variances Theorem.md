# Sum of Variances Theorem
Recall that if $X, Y$ are independent then
$$V(X+Y) = V(X) + V(Y)$$

This Theorem can be applied to many variables.
## Theorem (Discrete Case)
> Let $X_1, \dotso, X_n$ be an independent trials process with each trial having an expected value of $\mu$ . and variance $\sigma^2$ .

Lets investigate:
+ Total Expectation
+ Total Variance and Deviation

We denote $S_n$ as the sum of all the trial processes, and $A_n$ as the average value. 
$$
\begin{align}
	S_n &= \sum_{i = 1}^n X_i \\\\
	
	A_n &=^{*} \frac{S_n}{n}
\end{align}
$$

\* - Just the average value of each trial

### **Total** Expected Value
$$
\begin{align}
	E(S_n) &= E\biggr(\sum_{i = 1}^n X_i\biggr) \\\
	&= E(X_1) + \dotso + E(X_n) \\
	&= \mu + \dotso + \mu \\
	&= n\mu
\end{align}
$$

### **Total** Variance
$$
\begin{align}
	V(S_n) &= V\biggr(\sum_{i = 1}^n X_i\biggr) \\\
	&= V(X_1) + \dotso + V(X_n) \\
	&= \sigma^2 + \dotso + \sigma^2 \\
	&= n\sigma^2
\end{align}
$$

Since $D(S_n) = \sqrt{V(S_n)}$ , $D(S_n) = \sqrt{n\sigma^2}$
$$D(S_n) = \sigma\sqrt{n}$$

### Average Expectation
The question here is that what is the expected value of $A_n$
Recall that 
$$E(cX) = cE(X)$$
$$E(A_n) = E(\frac{S_n}{n}) = \frac{1}{n}E(S_n) = \mu$$

This makes sense logically that each trial usually holds the value $\mu$ .
Moreover, each trial has weight $1/n$ and thus 
$$A_n = \sum_{i=0}^{n}\frac{1}{n}X_i$$

### Average Variance
$$V(A_n) = V(\frac{A_n}{n}) = \frac{1}{n^2}V({S_n}) = \frac{\sigma^2}{n}$$

#### Deviation 
$$D(A_n) = \sqrt{\frac{\sigma^2}{n}} = \frac{\sigma}{\sqrt{n}}$$

#### Deviation Observation
Notice how the deviation tends to 0 when the number of trials $n$ tends to $\infty$. See Chapter 8: LLN for more information. 

## Standardization
Suppose $$S_{n}^{*} = \frac{S_n - n\mu}{\sqrt{n\sigma^2}}$$

Then 
$$
\begin{align}
	E(S_{n}^{*}) &= 0 \\
	V(S_{n}^{*}) &= 1
\end{align}
$$

The above properties $E(X) = 0, V(X) = 1$ is what Standardization is about. 

Given that $X \sim \text{Normal}(\mu, \sigma)$
We can standardized $X$ via
$$
\frac{X - \mu}{\sigma}
$$



### E($S_n^*$)
> Suppose $X_1, \dotso, X_n$ are independent for 
> $E(X_i) = \mu$ and $V(X) = \sigma^2$
$$
\begin{align}
	E(S_n^*) &= E(\frac{S_n - n\mu}{\sqrt{n\sigma^2}}) \\
	         &= \frac{1}{\sqrt{n\sigma^2}}E({S_n - n\mu}) \\
			 &= \frac{1}{\sqrt{n\sigma^2}}[E(S_n) - E(np)] \\
			 &= \boxed{0}
\end{align}
$$

### V($S_n^*$)
$$
\begin{align}
	V(S_n^*) &= V(\frac{S_n - n\mu}{\sqrt{n\sigma^2}})\\
	         &= \frac{1}{{n\sigma^2}}V({S_n - n\mu}) \\
			 &= \frac{1}{{n\sigma^2}}V({S_n}) \\
			 &= \boxed{1}
\end{align}
$$
