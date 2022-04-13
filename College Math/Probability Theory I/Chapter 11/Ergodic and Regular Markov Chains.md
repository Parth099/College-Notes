# Ergodic Markov Chains
A Markov chain is *Ergodic* or *irreducible* if any state is possible from any state. This does not have to be in one step. 

Then, a chain is called *regular* if some power of it contains **only** non-zero elements. See that not all Ergodic chains are regular. This means there exists some power $n$ such that we can visit any state regardless of what state we are in now. 

These two definitions are very important. 

> For the rest of the notes we will refer to row and col as state $s_i$. This means row $i$ and col $i$ will correspond to state $s_i$.

Lets look this matrix:
$$
\mathbf{P} = 
\begin{pmatrix}
        0 & 1\\
        1 & 0  
\end{pmatrix}  
$$

It is obvious that we can visit any state($s_1, s_2$) from here. 

Lets look at its powers:
$$
\mathbf{P}^n =
\begin{cases}
	\begin{pmatrix}
        1 & 0\\
        0 & 1
	\end{pmatrix}
	& n\text{ is even} 
	\\ \\
	\begin{pmatrix}
        0 & 1\\
        1 & 0  
	\end{pmatrix} 
	& n\text{ is odd}
\end{cases}
$$
Seeing as how each power of $\mathbf{P}$ **will** contain zeros, this matrix is **not** regular. Notice that in an odd number of steps $s_1$ cannot transition back to $s_1$. This chain is Ergodic because we can visit any state *eventually* any where we start.

# Regular Markov Chains
**Theorem**:
Let $\mathbf{P}$ be a transition matrix for a regular chain. As $n\to\infty$ the powers of $\mathbf{P}$, $\mathbf{P}^n$ will approach a matrix $\mathbf{W}$ where all the **rows** will be the same vector $\vec{\mathbf{w}}$ which will be a probability vector. 

> A probability vector is a vector such that each component is bounded by $0$ and $1$ and the sum of components is one.

None of this is straight forward. Why should we converge to a matrix where each row is the same? This statement of equivalent rows is the same as constant columns.  

**Theorem**: (Ext of Above Theorem)
Let $\mathbf{P}$ be a regular transition matrix. Then $$\mathbf{W} =\lim_{n\to\infty} \mathbf{P}^n,$$
Let $\vec{w}$ be that common row of $\mathbf{W}$ and let $c$ be the column of all ones. Then, 
1. $\vec{w}\mathbf{P} = \vec{w}$ 
2. $\mathbf{P}\vec{c}= \vec{c}$

Note any of $\vec{w}, \vec{c}$ can be replaced with constant multiple versions of themselves.

## Fixed Vectors
Any row vector with property: $\vec{w}\mathbf{P} = \vec{w}$ is a fixed row vector while $\mathbf{P}\vec{x}= \vec{x}$ is a fixed column vector.

## Example
> Find the limiting vector $\vec{w}$ for the following matrix. 

$$
\mathbf{P} = 
\begin{pmatrix}
        1/3 & 1/3 & 1/3\\
        1/2 & 1/4 & 1/4\\
        0 & 1 & 0
\end{pmatrix}
$$
Looking at the theorems above we know that 
$$
\vec{w}\mathbf{P} = \vec{w}
$$

Lets find this left eigenvector $\vec{w}$
$$
\begin{align}
\vec{w}\mathbf{P} &= 
(x\:\: y\:\: z)
\begin{pmatrix}
        1/3 & 1/3 & 1/3\\
        1/2 & 1/4 & 1/4\\
        0 & 1 & 0
\end{pmatrix} \\
&=
\begin{pmatrix}
	\frac{1}{3}x + \frac{1}{2}y & \frac{1}{3}x + \frac{1}{4}y + z &
	\frac{1}{3}x + \frac{1}{4}y
\end{pmatrix}
\end{align}
$$

Since $\vec{w}$ is a probability vector and $\vec{w}\mathbf{P} = \vec{w}$ these properties hold true:
$$
\begin{align}
	x+y+z&=1\\
	\frac{1}{3}x + \frac{1}{2}y &= x \\
	\frac{1}{3}x + \frac{1}{4}y + \frac{1}{1}z &= y\\
	\frac{1}{3}x + \frac{1}{4}y &= z
\end{align}
$$

Lets assume $x = 1$ (state $1$)

Then after solving we see that: 
$$
(x\:y\:z) = (1\:\frac{4}{3}\:\frac{2}{3})
$$
To get the vector we divide by the sum of all the components which is $3$  in this case:
$$
(x\:y\:z) = (1/3\:\:4/9\:\:2/9)
$$