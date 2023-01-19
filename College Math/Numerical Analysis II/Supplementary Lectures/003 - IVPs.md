# Initial Value Problems

Steps to solving:
1. Find or verify solution
2. Solve for $C$
3. Rewrite

## Example 1

$$
y'=2y;\; y(x) = Ce^{2x};\; y(0) = 3
$$

$$
y'(x) = 2Ce^{2x}
$$

Indeed $y$ is a solution to this equation. 

Notice that $y(0)$ should be $3$ . 

$$
3 = y(0) = Ce^{2(0)} = C \implies C = 3
$$

The particular solution is $y=3e^{2x}$ 

## Example 2

$$
e^yy'=1;\;y(x)=\ln{(x+C)};\;y(0)=0
$$

$$
y'=\frac{1}{x+C}
$$

$$
e^{\ln{(x+C)}}\cdot\frac{1}{x+C} = \frac{x+C}{x+C}=1\ \checkmark
$$

Find particular solution:

$$
0 = y(0) = \ln(0+C) \implies C = 1
$$

## Example 3 - Mildly Unrelated
Find all values of $r$ such that $y=e^{rx}$ is a solution to:

$$
4y'' = y
$$

$$
\begin{align}
y'&=re^{rx}\\y''&=r^2e^{rx}
\end{align}
$$

Thus, $4r^2e^{rx}= e^{rx}$

Since $e^{rx}\gt0$ , $4r^2 = 1$

$$
\implies r = \pm \frac{1}{2}
$$