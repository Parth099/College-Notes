# Densities
For: [[Probability Theory 1]]
## Continuous Uniform Densities
Suppose we wanted to pick a real number from the interval $[a, b]$. We would choose this density function.
$$ 
f(\omega) = 
\begin{cases} 
	\frac{1}{b-a}, & \text{if } a\leq\omega\leq b \\
	0 & \text{otherwise}
\end{cases}
$$

## Exponential and Gamma Densities
The Exponential Density function is defined by:
$$
f(x) = 
\begin{cases}
	\lambda e^{-\lambda x} & \text{ if } 0 \leq x \lt \infty \\
	0 & \text{ otherwise}
\end{cases}
$$

Note that $\lambda$ > 0 but its actual value depends on the experiment. It is used to answer questions of the form 
> How long till something happens?

### Exponential Cumulative Distribution Function
Recall from [[Continuous Probability Densities]] that a CDF measures the cumulative output of a density function

$$
\begin{align}
F(x) &= P(T \leq x)\\
&= \int_{0}^{x} \lambda e^{-\lambda t} \mathop{dt} \\
&= -e^{\lambda t}\biggr|_{x = 0}^{t = x}\\
&= 1 - e^{\lambda t}
\end{align}
$$

### Example
![[cp5ex7.png]]

Let us assume the arrival times of customers are given by random variables $X_1, X_2, \dotso, X_n$, that are mutually independent and identically distributed with an exponential cumulative distribution function given by

$$F_X(t) = 1 - e^{-\lambda t}$$
Then lets assume service times are given by the same types of random variables: $Y_1, Y_2, \dotso, Y_n$ with CDF:
$$F_Y(t) = 1 - e^{-\mu t}$$

See that both $\lambda$ and $\mu$ represent a sort of average of time. Specifically for $\mu$, it represents the average time a customer takes to get serviced. The smaller $\mu$ is the faster people get serviced. 
