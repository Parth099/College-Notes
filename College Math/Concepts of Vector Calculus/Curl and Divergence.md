## Curl

Let $\vec{F} = <P, Q, R>$
$$Curl(\vec{F})= \nabla \times \vec{F}$$
*$\times$ is the cross product*
*$\nabla$ is the gradient derivative operator:*

$$\nabla = \ <\frac{\partial}{\partial x}, \frac{\partial}{\partial y}, \frac{\partial}{\partial z}>$$


$$
Curl(\vec{F}) = \begin{vmatrix} 
\vec{i} & \vec{j} & \vec{k} \\ 
\frac{\partial}{\partial x} & \frac{\partial}{\partial y} & \frac{\partial}{\partial z} \\   
P & Q & R\end{vmatrix}
$$


$$Curl(\vec{F}) = (\frac{\partial R}{\partial y} - \frac{\partial Q}{\partial z})\vec{i} + (\frac{\partial P}{\partial z} - \frac{\partial R}{\partial x})\vec{j} + (\frac{\partial Q}{\partial x} - \frac{\partial P}{\partial y})\vec{k}$$

We can note that if $\vec{F} = \nabla f$ then:
$$Curl(\nabla f) = \vec{0}$$
*The zero Vector*

This gives us a way to see if a field is conservative.

### Curl of  Conservative Fields
if $Curl(\vec{F}) = \vec{0}$ then: $\vec{F}$ **is** conservative ([[Vector Fields]]).

# Divergence
$$div(\vec{F}) = \nabla \cdot \vec{F}$$

The divergence of a field $\vec{F}$ which is the curl of some field $\vec{f}$ is 0.
$$\vec{F} = curl \ {\vec{f}}$$
$$div \ {\vec{F}} = 0$$
$$div \ curl \ \vec{f} = 0 $$

![[divCurlZeroEx.png]]

## Alternate form of Green's Theorem
$$\oint \vec{F}\cdot\mathop{d\vec{r}} = \iint_D \text{curl}(\vec{F})\cdot \vec{k} \ dA$$