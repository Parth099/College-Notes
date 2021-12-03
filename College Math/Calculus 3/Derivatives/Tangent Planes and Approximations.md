# Tangent Planes of 3D Functions

## Mild Derivation
Much like a line tangent to a Curve from single variable Calculus. A tangent plane compasses 2 tangent lines at a point and forms a plane. The 2 tangent lines are formed by the 2 separate [[Partial Derivatives]].

Recall from [[Tangent Planes and Approximations]] that any point passing through the plane is in the form:

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