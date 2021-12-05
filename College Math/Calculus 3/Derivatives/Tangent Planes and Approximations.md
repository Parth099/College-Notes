# Tangent Planes of 3D Functions

## Mild Derivation
Much like a line tangent to a Curve from single variable Calculus. A tangent plane compasses 2 tangent lines at a point and forms a plane. The 2 tangent lines are formed by the 2 separate [[Partial Derivatives]].

Recall from [[Equations of Lines and Planes]] that any point passing through the plane is in the form:

> $A(x - x_0) +B(y - y_0) + C(z - z_0) = 0$

We can reformat this to be 

> EQ **P**: 
> $z - z_o = a(x - x_0) +b(y - y_0)$

Notice the constants have changed.

If ***P*** represents the tangent plane then it must contain the 2 tangent lines formed by the 2 partials.

Consider $y = y_0$

This reduces to 
$$z - z_o = a(x - x_0)$$
See that after considering $y = y_0$, this is the equation of a line with initial point $(x_0, y_0, z_0)$. The slope of this line must be $f_x(x_0, y_0)$

## Tangent Line Equation

$$\boxed{\large z - z_0 = f_x(x_0, y_0)(x - x_0) + f_y(x_0, y_0)(y - y_0)}$$

### Linear Approximations
Suppose we want to estimate function values around the point $(a, b, f(a, b))$

Then we have: 
$$
L(x, y) = f(a, b) + f_x(a, b)(x - a) + f_y(a, b)(y - b)
$$
which is a restatement of the TL EQ from above.


The equation above when subbed in for values reduces to:
$$L(x, y) = Ax + By + C$$
This *linear* equation can be used to Approximate functional output "*near*" the original point **$(x_0, y_0)$**.

### Total Differential (Bonus)
The total differential is the overall approximated change in $z$ WRT an initial point $(x, y, z)$

$$dz = \dfrac{\partial z}{\partial x}dx + \dfrac{\partial z}{\partial y}dy$$

The $dx, dy$ represents the distance from the input.