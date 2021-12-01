Greens Theorem is used to evaluate [[The Line Integral]]

# Green's Theorem

Statement: Let $C$ be a positively oriented, piecewise-smooth, simple
closed curve in the plane and let $D$ be the region bounded by $C$. If $P$ and $Q$ have
continuous partial derivatives on an open region that contains $D$, then


$$\oint_C \vec{F}\cdot d\vec{r} = {\iint}_{D} \dfrac{\partial Q}{\partial x} - \dfrac{\partial P}{\partial y} dA$$





## Positively Oriented
 Positively Oriented means that for all points on a closed curve $C$ the region it encloses $D$ is **always** on the right. 
 
 As a sidenote, see that 
 $$
 -\int_C \vec{F}\cdot d\vec{r} = \int_{-C}\vec{F}\cdot d\vec{r}
$$

The work example works well with this Property. 

## Derivation
![[GreensT-fig1.png]]
Note that the cut at $C_1, C_2$ is irrelevant. This is shown by the property in the above section: 

These cuts can be made infinitely small such that:
$$
\oint_C \vec{F}\cdot d\vec{r} = \sum_{i = 0}^{\infty} \int_{C_i} \vec{F}\cdot d\vec{r}
$$
Hence the double integral. We add up the internal curves inside the boundary curve $C$. 
The $\dfrac{\partial Q}{\partial x} - \dfrac{\partial P}{\partial y}$ will be explained below.


### Derivation of Circular Density

 $\dfrac{\partial Q}{\partial x} - \dfrac{\partial P}{\partial y}$ represents that infinitely small pieces we are summing up.
 
 Recall we are summing up all the points and their contribution in D to find the Line Integral of Curve c.
 
 For each point $(x, y)$ we need to find its mini Line Integral. (The small piece we are adding up)
 
 https://www.youtube.com/watch?v=gWbfdPUynz0
 
 #### The "Tiny" Piece
 
![[GreensTinyPiece.png]]

*Note: The $\Delta$ imperfections stem from the fact that limits were taken to obtain $\partial$ derivatives.

---

