# February 8th
## Variation and Deviation

$$
\begin{align}
V(x) &= \overbrace{\frac{1}{n}\sum_{i=1}^n(x_i - \mu)^2}^{\text{Underestimate}}\\ \\
V(x) &= \underbrace{\frac{1}{n+1}\sum_{i=1}^n(x_i - \mu)^2}_{\text{Overestimate}} \\ \\
D(x) &= \sqrt{V(x)}
\end{align}
$$

There an idea of a absolute deviation too:

$$
\frac{1}{n-1}\sum_{i=1}^n |x_i - \mu|
$$

Reasons to use STD.DEV over ABS.DEV
+ $|f(x)|$ is not differentiable
+ STD.DEV is more sensitive to outliers

My understanding is that if we want outliers to have a lower effect we should use ABS.DEV.