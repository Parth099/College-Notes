# The Dot Product

The **Dot Product** is a measure of how similar 2 vectors are to each other based on direction.
> If the dot product is **0** then they are **perpendicular**


## Formula
Let
$$\vec{v} = <a, b, c>$$
$$\vec{u} = <x, y, z>$$
Then
$$\boxed{\vec{v}\cdot\vec{u} = ax+by+cz}$$

## Properties

1. $a\cdot a = \lvert a \rvert$
2. $a \cdot (b+c) = a\cdot c + a \cdot b$
3. $a \cdot b = b \cdot a$
4. $ca \cdot b = c(a \cdot b) = a \cdot cb$

All can be proven with elementary algebra. 

## Relation to Cosine
> $a \cdot b = \lvert a \rvert \lvert b \rvert \cos{\theta}$
> $0\leq\theta\leq\pi$

Notice at $\theta = \frac{\pi}{2}$, $\cos{\theta} = 0$ showing is that if $a \perp b \implies a \cdot b = 0$
### Observation
Suppose the angle is:
1. Acute: $a \cdot b \gt 0$
2. $\theta = 90$: $a \cdot b = 0$
3. Obtuse: $a \cdot b \lt 0$

## Projections
![[projectionExample.png]]

**Goal**: Find the length of the project of B *onto* A

### Derivation
Let **C** be the length of the projection of B onto A

Notice that 
$$\cos{\theta} = \frac{C}{\lvert b \rvert} \to \lvert b \rvert\cos{\theta} = C$$
Recall the 'Relation to Cosine' for the **Dot product**
$$C = \frac{a \cdot b}{\lvert a \rvert \lvert b \rvert}\lvert b \rvert$$
$$\text{comp}_\vec{b} \vec{a} = \frac{a \cdot b}{\lvert a \rvert}$$

$\text{comp}_\vec{b}\vec{a}$ is the length of this projection **C**.

To get a Vector Project we just multipy $\text{comp}_\vec{b} \vec{a}$ with the unit vector of $\vec{a}$
$$\text{proj}_\vec{b}\vec{a} = \text{comp}_\vec{b}\vec{a}(\frac{\vec{a}}{\lvert a \rvert})
$$
$$
\text{proj}_\vec{b}\vec{a} = \vec{a}\frac{a \cdot b}{(\lvert a \rvert)^2}
$$
---
### Projection Formulas
> $\text{comp}_\vec{b} \vec{a} = \frac{a \cdot b}{\lvert a \rvert}$
> 
>$\text{proj}_\vec{b}\vec{a} = \vec{a}\frac{a \cdot b}{(\lvert a \rvert)^2}$
---


# The cross Product
The **cross Product** produces a vector that is perpendicular to the 2 supplied.
## Formula 
Let
$$a = \langle a_1, a_2, a_3 \rangle$$
$$b = \langle b_1, b_2, b_3 \rangle$$

$$
a \times b = \text{det}
\begin{vmatrix}
\vec{i} & \vec{j} & \vec{k} \\ 
a_1 & a_2 & a_3 \\
b_1 & b_2 & b_3
\end{vmatrix}
$$
*Notation: The matrix inside the $det$ can also be transposed to give the same vector out*

Then:
> $(a \times b) \cdot a = 0$
> $(a \times b) \cdot b = 0$

Note if $\vec{a}$ and $\vec{b}$ are parallel **or** $\vec{a} = \vec{b}$ then:
$$a \times b = 0$$

Recall that the function **det**() gets the area of a parallelogram after a Linear Transformation T. This is why the vectors are loaded into a matrix and passed to the determinant.  

## Cross Product Geometry 
> $|a \times b| = \lvert a \rvert \lvert b \rvert \sin{\theta}$ 
> for $0 \leq \theta \leq \pi$

$|a \times b|$ represents the area of the parallogram spanned by $\vec{a}$ & $\vec{b}$

## Properties
1. $a \times b = -(b \times a)$ **antisymmetric**
2. $a \times (b + c) = (a \times b) + (a \times c)$
3. $ra \times b = r(a \times b) = a \times rb$
4. $(a + b) \times c = (a \times c) + (b \times c)$
5. $(a \times b)\cdot c = a \cdot (b \times c)$ **Triple Product**

### Triple Product
The Triple Product represents the volume spanned by the 3 vectors
$$\text{abs}(a \times b\cdot c) = V$$