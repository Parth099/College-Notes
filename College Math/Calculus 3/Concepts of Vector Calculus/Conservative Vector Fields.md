# Conservative Vector Fields
[[The Line Integral]] of Conservative [[Vector Fields]] depends only on the end points and thus:

A field $\vec{F}$ is Conservative if:
$$\int_C \vec{F} \cdot d{\vec{r}}$$
is the same for any path $C$ when end points $A, B$ are the same. 

### Gradients
recall that if $\nabla f$ is one of many [[Vector Fields]].

A field $\vec{F}$ is Conservative $\Leftrightarrow \vec{F} = \nabla f$ 

Recall Clairaut's Theorem:
$$ f_{xy} = f_{yx}$$

for a 'nice' $f$. Nice meaning defined and continuous in a region where the partial is taken. 

Now we can see $\vec{F}$ is Conservative. Since $\vec{F} = \ <P, Q>$ 
For $\vec{F}$ to have a potential function $f$ such that $\nabla f = \vec{F}$ we must find: 
$$\frac{\partial P}{\partial y} = \frac{\partial Q}{\partial x}$$

This is a property of all multivariable functions. 

In the end we not that if a field $\vec{F}$ is conservative then we can employ the [[The Fundamental Theorem of Line Integrals]]

$$\int_C \nabla f \cdot d\vec{r} = f(r(b)) - f(r(a))$$
