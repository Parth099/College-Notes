# Absorbing Chains
> A state $s_i$ is absorbing if it is impossible to leave it, meaning $p_{ii} = 1$. A Markov chain is called absorbing if it contains at least one absorbing state **and** each non absorbing state has a non zero probability to *reach* an absorbing state. This does not mean it must be one iteration away it can be any $n$ steps away. A good way to see this is to draw a graph. 

If a transition matrix **is** absorbing, then each non absorbing state is called *transient*.

Consider this matrix:
![[drunk_walk.png]]
States $0, 1, 2, 3$ are transient but $4$ is absorbing. 

## Conical Form 
> The **Conical Form** is when the transient states are at the start and all absorbing states proceed them. 

Suppose there are $t$ transient states and $r$ absorbing states. Then we can partition the matrix like this:

![[partition_absorb.png]]

**Note**: I am not using the word partition in its *technical* sense

In this case $\mathbf{R}$ is a $t\times r$ real-valued matrix, well confined to $[0, 1)$.

Also,  $\mathbf{0}$ is a $r\times t$ matrix full of zeros.

### Powers of The *Conical Form*
![[Conical_Form_powers .png]]
While explaining $\mathbf{Q}^n$ is not easy the $I$ is. Notice how the Conical Form orders the absorbing states. They are at the bottom. This means that each absorbing row only has an entry on the main diagonal. When multiplied with it self it will not change by rules of matrix algebra.  

To see why compute this product and notice how each entry in the left matrix corresponds to that entry times the row it corresponds to.


$$
\begin{pmatrix}
        1 & 2
\end{pmatrix}
\begin{pmatrix}
        0 & 1\\
        6 & 7
\end{pmatrix}
	=
\begin{pmatrix}
        12 & 15
\end{pmatrix} 
$$

Notice how the end product is $1$ times row $1$ plus $2$ times row $2$

## Important Theorems
### Theorem 1 
Recall how we partitioned
![[partition_absorb.png]]

> Regarding $\mathbf{P}^n$, as $n\to\infty$, $\mathbf{Q}^n \to \mathbf{0}$ 

$0$ is a matrix with all $0$ entries. 
This makes logical sense. Given infinite steps and non-zero probabilities for a transition into an absorbing state, it follows that  $\mathbf{Q}^n \to \mathbf{0}$ if $n\to\infty$

### The Fundamental Matrix
> For an absorbing Markov chain, $\mathbf{I} - \mathbf{Q}$ has an inverse namely $\mathbf{N}$. 
> $$\mathbf{N} = \sum_{n = 0}^{\infty}\mathbf{Q}^{k} = \mathbf{I} + \mathbf{Q} + \mathbf{Q}^2 \dotso$$

**Important**: When we say $\mathbf{I} - \mathbf{Q}$, The $\mathbf{I}$ is the identity with respect to $\mathbf{Q}$. Its the identity that is of $\mathbf{Q}$'s dimensions. It is not the same identity that refers to the absorbing states.   

The $n_{ij}$ entry is interesting in $\mathbf{N}$. It is the expected number of times that the chain is in $s_j$ given it starts in $s_i$. We can also consider $i = j$ . We call $\mathbf{N}$ the fundamental matrix. 

## Example 
Recall the matrix from above. 
![[drunk_walk.png]]

Here is its canonical version. 
We will first arrange the states. $0$ and $4$ will be last. $1,2,3$ will be first. 

$$
\mathbf{C} = \begin{pmatrix}
        * & * & * & * & *\\
        * & * & * & * & *\\
        * & * & * & * & *\\
        0 & 0 & 0 & 1 & 0\\
        0 & 0 & 0 & 0 & 1
\end{pmatrix}
$$

We can just fill in the table by looking up what values are $P_{ij}$


$$
\mathbf{C} = \begin{pmatrix}
        0   & 1/2 & 0   & 0 & 0\\
        1/2 & 0   & 1/2 & 0 & 0\\
        0   & 1/2 & 0   & 0 & 0\\
        0   & 0   & 0   & 1 & 0\\
        0   & 0   & 0   & 0 & 1
\end{pmatrix}
$$

Then, 
$$
\begin{align}
	\mathbf{Q} &= 
	\begin{pmatrix}
		0 & 1/2 & 0\\
		1/2 & 0 & 1/2\\
		0 & 1/2 & 0
	\end{pmatrix}
		
		\\ \\
		
	\mathbf{I - Q} &= 
		\begin{pmatrix}
			1 & -1/2 & 0\\
			-1/2 & 1 & -1/2\\
			0 & -1/2 & 1
		\end{pmatrix}
		\\
\end{align}
$$

Inverse:
$$
(I-Q)^{-1} = 
\begin{pmatrix}
        3/2 & 1 & 1/2\\
        1 & 2 & 1\\
        1/2 & 1 & 3/2
\end{pmatrix} = \mathbf{N}
$$

Suppose we start in $s_2$. Then the expected iterations before being absorbed is $2$.
