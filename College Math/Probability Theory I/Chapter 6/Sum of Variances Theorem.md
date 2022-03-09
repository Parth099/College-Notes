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