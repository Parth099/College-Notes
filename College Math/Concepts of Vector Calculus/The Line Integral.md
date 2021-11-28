# Line integral WRT Arc Length
The most basic type of Line integral is the Line integral with respect to Arc length. [[Arc Length]]
$$\int_C f(x,y) \mathop{ds}$$ where $ds = \sqrt{(\frac{dx}{dt})^2+(\frac{dy}{dt})^2} \mathop{dt}$.  Think about how this represents a triangle and how that can help you get the arc-length.

So: $\int_C f(x(t), y(t)) \sqrt{(\frac{dx}{dt})^2+(\frac{dy}{dt})^2} \mathop{dt}$

This sums up function values over a curve parameterized by $r(t)$. We also note that the sum of sections of the curve $C$ is in total also C. So C can be broken down when needed (ex: non-smoothness). 

Ex if C is broken down into 2 parts we have:

$$\int_{C1} f(x, y) \mathop{ds} + \int_{C2} f(x, y) \mathop{ds} = \int_C f(x, y) \mathop{ds}$$

This fact can be extended to any number of cuts, later be to exploited for valuable theorems. 