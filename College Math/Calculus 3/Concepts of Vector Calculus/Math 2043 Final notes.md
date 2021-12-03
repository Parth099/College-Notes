# Final notes

The contents of this note will have no explanation/proof since they were beyond  my understanding at the time.  **:(**

# Surface Integral
## Surface Integral of a Function 
$$\iint_S f(x, y, z)\mathop{dS} = \iint_D f(x, y, g(x, y))\sqrt{1+\dfrac{\partial g}{\partial x} + \dfrac{\partial g}{\partial y}}\mathop{dA}$$

The surface $S$ is drawn by $z = g(x, y)$ which is replaced to make the change from integrating 3-D region $S$: Surface to $D$: 2-d *Domain*

## Surface Integral of a Vector Field [FLUX]
Pre-Assertion: The Surface **MUST** be the graph of a function $f(x, y)$
$$\text{recall: } \vec{F} = \langle P, Q, R \rangle$$
$$\iint_S \vec{F}\cdot\mathop{d\vec{S}} = \iint_D -P\dfrac{\partial g}{\partial x} - Q \dfrac{\partial g}{\partial y} + R\mathop{dA} $$

**Orientation**: The Direction of the normal vectors.  

This formulation stands for $S$ for upwards orientation. For a negative orientation multiply RHS by -1.

Ex: ![[FluxEx1.png]]

Notice the Flux of this this object is:
$$F_T = F_T + (-F_B)$$
The bottom is subtracted since positive orientation means outward flow but the normal vectors on $S_2$ point up if calculated directly   

$$\iint_S \vec{F}\cdot\mathop{d\vec{S}} = \iint_{S_1} \vec{F}\cdot\mathop{d\vec{S}} - \iint_{S_2} \vec{F}\cdot\mathop{d\vec{S}}$$


## Stokes' Theorem  

Recall [[Curl and Divergence]]
$$\text{curl }\vec{F} = \nabla \times \vec{F}$$
$$
\oint\vec{F}\cdot\mathop{d\vec{r}} = \iint_S\text{curl}(\vec{F})\cdot\mathop{d\vec{S}}
$$

Note that the RHS is a **SURFACE** Integral. 

It says that if we need the Double Integral of the curl we can just look at the boundry's line integral.  

### Stokes' Theorem & Orientation
If we use this Theorem to exploit the LHS *(line integral)*. We **MUST** be careful of orientation. From the direction of the orientation of the object, the curve for the line integral parameterized by **$\vec{r}(t)$** must be going CCW(counter-clock-wise) on the 2D plane.  

## Divergence Theorem
Recall [[Curl and Divergence]]
$$\text{div }\vec{F} = \nabla \cdot \vec{F}$$

$$\iint_S \vec{F}\cdot\mathop{d\vec{S}} = \iiint_E \text{div} \vec{F}\mathop{dV}$$

Used to find the Flux where the graph of the function has too many Surface/Line Integrals to Calculate. Also, in this class when the flux requires a specific angle. 