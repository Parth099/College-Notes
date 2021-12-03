# Equation of a Line

Equation of a Line defined by a Vector function 
> $r(t) = \vec{v_0} + \vec{v}t$

$v_0$ is the steady point while $\vec{v}$ sweeps the rest of the space.

## Parametric Equations
Notice that the line equation looks like: 
$$r(t) = \langle x_o + ta, y_0 + tb, z_0 + tc \rangle$$

With components: 
$$x = x_0 + ta$$
$$y = y_0 + tb$$
$$z = z_0 + tc$$
These are called the **Parametric Equations**

## Symmetric Equations

Lets solve for $t$

$$t = \frac{x - x_0}{a} = \frac{y - y_0}{b} = \frac{z-z_0}{c}$$

Note if a variable does not ever change we just write if off to the side like:
$$t = \frac{x - x_0}{a} = \frac{y - y_0}{b}, z = z_0$$

## Line Segment given 2 points
Suppose we have 2 points $r_0$ and $r_1$ that define the start and end of segment **S**.

recall $r(t) = r_0 + \vec{v}t$
Realize that: $\vec{v} = \vec{r_1} - \vec{r_0}$

$$r(t) = r_0 + (\vec{r_1} - \vec{r_0})t$$
$$r(t) = r_0(1-t) + r_1t$$

This function spans segment **S** when $0 \leq t \leq 1$

# Equation of a Plane

A plane is defined a normal vector. This means its defined by a vector $\vec{n}$ such that for any point $\vec{r}$ on the plane $n \perp r \implies n\cdot r = 0$

## Derivation 
![[EqOfPlane.png]]
Suppose Point/*Vector* $R_0$ exists on the plane with coordinates $(x_0, y_0, z_0)$. Then also suppose point $R = (x, y, z)$ exists on the plane. 

**Then:**
$$\vec{n} \cdot (R - R_0) = 0$$
$\vec{n}$ is the normal vector to the plane with scalar entries $\langle a, b, c \rangle$

$$\langle a, b, c \rangle \cdot \langle x-x_0,y-y_0,z-z_0 \rangle = 0$$
This then simplifies to 
> $ax+by+cz+d = 0$

The $d$ comes from all the constants produced by $R_0$.