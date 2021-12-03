# Partial Derivatives
A multivariate function has several inputs such as $x, y, z$ . This implies that the instantaneous rate of change at any point **P** has dependencies on which variable we are looking to example the rate of change. 

So, at any point there exists more than one derivative each with respect to a different variable. 

The **rule for computation** is treating all non differentiation variables as constants. So if we are computing WRT $x$, all other vars like $y$ or $z$ are constants    

## Limit Definition

Assume for all definitions $z = f(x, y)$
> $f_x = \lim_{h \to 0} \frac{f(x + h,\ y) - f(x,\ y)}{h}$ 

> $f_y = \lim_{h \to 0} \frac{f(x,\ y+h) - f(x,\ y)}{h}$ 

## Notation
$$\dfrac{\partial f}{\partial x} = f_x = D_xf$$

### Second Level Notation

$$\dfrac{\partial^2 f}{\partial x \ \partial y} = f_{xy}$$
$$\dfrac{\partial^2 f}{\partial x^2} = f_{xx}$$
