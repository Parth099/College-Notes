## 3.4.2.c
Used [python](https://github.com/Parth099/College-Notes/blob/main/College%20Math/Numerical%20Analysis%20I/snippets/hermite_dd.py)\* to produce this output. 

\* - Link to the code

```python
 -0.290050  +0.000000  +0.000000  +0.000000  +0.000000  +0.000000 
 -0.290050  -2.801998  +0.000000  +0.000000  +0.000000  +0.000000
 -0.560797  -2.707474  +0.945237  +0.000000  +0.000000  +0.000000
 -0.560797  -2.615920  +0.915537  -0.297000  +0.000000  +0.000000
 -0.814020  -2.532224  +0.836963  -0.392870  -0.479350  +0.000000
 -0.814020  -2.973404  -4.411800 -52.487630 -260.473800 -1299.972250
```


It represents the following polynomial:

$$
\begin{align}

H_5(x) &= -0.290050 \\

&\ \ \ \ \ -2.801998(x-0.1)\\ 
&\ \ \ \ \ +0.945237(x-0.1)^2 \\ 
&\ \ \ \ \ -0.297000(x-0.1)^2(x-0.2) \\ 
&\ \ \ \ \ -0.479350(x-0.1)^2(x-0.2)^2 \\ 
&\ \ \ \ \ -1299.972250(x-0.1)^2(x-0.2)^2(x-0.3) \\ 

\end{align}
$$

## 3.4.6.a

$$
\begin{align}
f(x)&=3xe^x - e^{2x} \\
f'(x)&= e^x(3+3x) - 2e^{2x}
\end{align}
$$

**DATA TABLE:**

	
| $x_k$  | $f(x_k)$   | $f'(x_k)$  |
| ------ | ---------- | ---------- |
| $1$    | $0.765789$ | $1.531578$ |
| $1.05$ | $0.835431$ | $1.242214$ | 

### Hermite Formula

$$
\begin{align}
H_3(x) &= \sum_{k=0}^1 f(x_k)H_{1, k}(x) + f'(x_k)\hat{H}_{1, k}(x) \\ \\
&= f(x_0)H_{1, 0}(x) + f'(x_0)\hat{H}_{1, 0}(x) + f(x_1)H_{1, 1}(x) + f'(x_1)\hat{H}_{1, 1}(x)
\end{align}
$$

#### $L_{1, k}(x), L'_{1, k}(x), L^2_{1, k}(x)$
$$
\begin{align}
L_{0}\left(x\right)\ &=\ \frac{\left(x-1.05\right)}{\left(1-1.05\right)} = 21-20x\\
L_{1}\left(x\right)\ &=\ \frac{\left(x-1\right)}{\left(1.05-1\right)}=20x-20\\
\end{align}
$$

$$
\begin{align}
L'_{0}(x) &= -20 \\
L'_{1}(x) &= 20 \\
\\ 
L^2_0(x) = 441-840x+400x^2 \\
L^2_1(x) = 400-800x+400x^2 \\
\end{align}
$$

#### $H_{1, k}(x)$

$$
\begin{align}
H_{0}(x) &= [1-2(x-1)L'_0(x)]L^2_0(x)\\
&= [1+40(x-1)](441-840x+400x^2)\\
&= [40x-39](441-840x+400x^2)\\
\\
H_{1}(x) &= [1-2(x-1.05)L'_1(x)]L^2_1(x)\\
&= [1-40(x-1.05)](400-800x+400x^2)\\
&= [43-40x](400-800x+400x^2)\\
\\ \\ 
\hat{H}_0(x)&= (x-1)(441-840x+400x^2) \\
\hat{H}_1(x)&= (x-1.05)(400-800x+400x^2)

\end{align}
$$

Final Function:

$$
H_{3}\left(x\right)=f\left(1\right)H_{0}\left(x\right)+f'(1)\hat{H}_{0}\left(x\right)+f\left(1.05\right)H_{1}\left(x\right)+f'\left(1.05\right)\hat{H}_{1}\left(x\right)
$$

$$\implies H_3(x) = \boxed{0.809324\dotso}$$

#### Error

$$\biggr|f(1.03) - H_3(x)\biggr|\approx0.0000012$$

Bound:

$$
\begin{align}
\biggr|f(1.03) - H_3(x)\biggr| \leq \biggr|\frac{(x-1)^2(x-1.05)^2}{4!}f^{(4)}(\xi(x))\biggr|
\end{align}
$$

$f^{(4)}(\xi(x)) = e^{\xi(x)}(3{\xi(x)}+12) - 16e^{2{\xi(x)}}$

##### Analysis
Taking a look at the polynomial $g(x)=\frac{{(x-1)^2(x-1.05)^2}}{4!}$ , its a **U** shaped curve with roots at $x=1$ and $x=1.05$. Since its parabola shaped and the end points of our interval are zeros the absolute max value lies at the vertex which is at the center: $x=1.025$

Given that the $|f^{(4)}(x)|$ is increasing ***graphically*** after $x=0$ increasing the max point would be at $|f(1.05)|$

Therefore the max error bound is $\left|f\left(1.05\right)g\left(1.025\right)\right| \approx 0.00000142$


## Additional Problems

Nodes: $\{(0, -2), (2, 1), (4, 4)\}$

### 1

$$
\begin{align}

L_{0}\left(x\right)&=\frac{\left(x-2\right)\left(x-4\right)}{-2\cdot-4} \\ \\

L_{1}\left(x\right)&=\frac{\left(x\right)\left(x-4\right)}{2\cdot-2} \\ \\

L_{2}\left(x\right)&=\frac{\left(x\right)\left(x-2\right)}{4\cdot2} \\ \\ \\

P_{2}\left(x\right)&=-2L_{0}\left(x\right)+\ 1L_{1}\left(x\right)+4L_{2}\left(x\right) \\ 
&=\boxed{1.5x-2}

\end{align}
$$

### 2

| $x_k$ | $f[x_k]$ | $f[x_k, x_{k+1}]$                | $f[x_k, x_{k+1}, x_{k+2}]$ |
| ----- | -------- | -------------------------------- | -------------------------- |
| 0     | -2       | -                                | -                          |
| 2     | 1        | $\frac{1-(-2)}{2-0}=\frac{3}{2}$ | -                          |
| 4     | 4        | $\frac{4-1}{4-2}=\frac{3}{2}$    | $0$                        |

This represents the polynomial:

$$
\begin{align}
P_2(x) = -2 + \frac{3}{2}(x-0) + 0(x-0)(x-1) = \boxed{1.5x-2}
\end{align}
$$

### 3
> Yes, the two polynomials are the same. 