# Velocity and Acceleration#

Extension to [[005 - Solving with Integrals]] (single derivative)

> This lesson covers multiple derivatives

$$
\dfrac{d^2y}{dx^2} =  g(x)
$$

$$
\begin{align}
\dfrac{dy}{dx} &= \int g(x) \mathop{dx} \\
&= G(x) + C\\ \\
y &= \int \biggr[ G(x) + C \biggr] \mathop{dx} \\
&= \int \biggr[ G(x) + C \biggr] + Cx + K
\end{align}
$$

This will require *more* ICs to get a particular solution.

## Example 

$$
a(t) = -20, \, v_0 = -15, \, x_0 = 5
$$

Notice that $a(t)$ is a constant.

Since $\dfrac{dv}{dt}=a$ then $dv = a\mathop{dt}$

Then $v(t) = -20t+C_0$ after integration

$$
v(0) = -15 = -20(0) + C_0 \implies C_0 = -15
$$

$$
\boxed{v(t) = -20t -15}
$$

Integrate again to get $x(t)$ (position)

$$
x(t) = \int v(t) \mathop{dt} = -10t^2 - 15t + C 
$$

Since $x_0 = x(0) = 5 \implies C = 5$

Therefore:

$$
\text{Position: }\boxed{x(t) = -10t^2 - 15t + 5}
$$

Note if you solve this generally where $a(t) = \mathbf{a}$ (constant) then, 

$$
\begin{align}
v(t) &= \mathbf{a}t + v_0\\
x(t) &= \frac{1}{2}\mathbf{a}t^2 + v_0t + x_0
\end{align}
$$

> If $a(t)$ is non-constant the process is the same but the formula above **will not work**. 