# Line Integrals Over Vector Fields

Recall [[Vector Fields]] & [[The Line Integral]]

The Line Integral over a Vector Field **represents** the *sameness* of the vector WRT to the curve C. How much is the vector field pointing the in direction of C. Hence we integrate over the parameterized curve $r(t)$ from $a$ to $b$ and *dot* the tangential vector $r^{\prime}(t)$ with the vector defined at that point defined by the vector field.  

$$\int_C \vec{F} \cdot d\vec{r} = \int_a^b \vec{F}(\ \vec{r}(t) \ ) \ r^{\prime}(t) = \int _C \vec{F} \cdot T \ ds$$

## Derivation
TBA

## Line Integral with respect to Variable 

Sometimes the Line Integral is show as: 

$\int_C P\ dx + Q\ dy + R\ dz$, where $F(x, y, z) = \langle P, Q, R \rangle$.

$P, Q, R$ are all vector functions based on $(x, y, z)$

Recognize that $r^{\prime}(t) = \langle \ \dfrac{dx}{dt}, \dfrac{dy}{dt}, \dfrac{dz}{dt} \ \rangle$ $\implies$ $r^{\prime}(t) \mathop{dt} = \langle \ dx, dy, dz \ \rangle$

$$\dfrac{d\vec{r}}{dt} = r^{\prime}(t)$$
$$\int_C \vec{F} \cdot d\vec{r} \ \to \int_C \vec{F} \cdot r^{\prime}(t) \mathop{dt}$$
$$\int_C \vec{F} \cdot \langle \ dx, dy, dz \ \rangle$$

$$\boxed{\int_C P\ dx + Q\ dy + R\ dz}$$

### Interpretation of missing differentials

Suppose the Line Integral is $\int_C P\ dx$.

Firstly it means that the vector function is defined as $\vec{F}(x, y) = \langle \ P, 0 \ \rangle$
What this means is that we are only taking in only the influence of the $x$ direction.   Then we can do the standard # parametrizations and solve the Integral.

Suppose $\vec{F} = \langle \ P, Q \ \rangle$, $P, Q \neq 0$. 
In 2D we can view taking the Integral WRT $dx$ as measuring the projection of the Line Integral on the XZ plane.