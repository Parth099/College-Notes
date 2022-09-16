# Hw2
## SECTION 2.1 - 2.b
```python
ITERATION: 0  a=-1.25 | b=2.5     | p_0 = 0.625    | F(p_0) = -0.228515625
ITERATION: 1  a=0.625 | b=2.5     | p_1 = 1.5625   | F(p_1) = 4.594482421875
ITERATION: 2  a=0.625 | b=1.5625  | p_2 = 1.09375  | F(p_2) = 0.3496398925781
ITERATION: 3  a=0.625 | b=1.09375 | p_3 = 0.859375 | F(p_3) = -0.281902313232
```

## SECTION 2.1 - 18
$$
\begin{align}
	\text{TOL} &= 10^{-3}\\
	f(x) &= x^3 + x - 4 \\
	[a, b] &= [1, 4]
\end{align}
$$

We know the upper bound for error:
$$
|p - p_0| \lt \frac{b-a}{2^n}
$$

Upper bound required $\text{TOL} = 10^{-3} = \frac{4-1}{2^n}$

$$
\begin{align}
	\frac{3}{2^n} &\leq 10^{-3} \\ \\
	\frac{2^n}{3} &\geq 1000 \\ \\
	{2^n} &\geq 3000 \\ \\
	
	n &\geq \log_{2}{3000} \approx 11.55
	
	\\ \\
	
	\implies n&\geq 12
\end{align}
$$

Theoretically the bisection method will require 12 iterations to conform $10^{-3}$ units within the actual root. The real iteration count may be less.   

