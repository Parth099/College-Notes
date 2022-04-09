# Time to Absorption
After learning about Absorbing chains we can now answer the question:
> How long until a state $s_i$ gets absorbed?


**Theorem**:

Let $t_i$ be the expected number of steps before a chain is absorbed given that it starts in state $s_i$, Let $\mathbf{t}$ be a **column** vector whose $i$th entry is $t_i$. Them:
$$\mathbf{t} = \mathbf{N}c$$
$c$ is a column vector of all $1$s.

**Breakdown**

Given that $c$ is a column vector of all $1$s what it is doing is summing up each row unto  a single value and creating a column vector out. 

> What will the sum of a row of $\mathbf{N}$ mean?

Recall how $\mathbf{N}$ represents the number of steps per $s_{ij}$ spent in transient states. If we add up a row (column wise), what we get is the total (expected )*time* spent in all transient states before absorption.

An example later will make this *clear*. 

## Absorption Probabilities
Let $b_{ij}$ be the probability that a system starting in $s_i$ will be absorbed in $s_j$. 

We will call this matrix $\mathbf{B}$
$\mathbf{B}$ is then $t\times r$
$$\mathbf{B} = \mathbf{N}\mathbf{R}$$

$\mathbf{N}$ is the Fundamental Matrix.
$\mathbf{R}$ is the Canonical form but only the part where transient states can transition into absorbing states. 

## Computational Example
Recall the one example from Absorbing Chains. 

$$
\mathbf{N} = \begin{pmatrix}
        3/2 & 1 & 1/2\\
        1 & 2 & 1\\
        1/2 & 1 & 3/2
\end{pmatrix}
$$
The states here were $s_1, s_2, s_3$ while $s_0$ and $s_4$ were *absorbing*.

$$
\mathbf{t} = \mathbf{N}c = \begin{pmatrix}
        3/2 & 1 & 1/2\\
        1 & 2 & 1\\
        1/2 & 1 & 3/2
\end{pmatrix}
\begin{pmatrix}
        1\\
        1\\
        1
\end{pmatrix}
=
\begin{pmatrix}
        3\\
        4\\
        3
\end{pmatrix}
$$
Lets look at $t_2$ for the sake of an example. 
$t_2$ corresponds to the time of being absorbed if we start in state $s_2$. It is intuitively the sum of the time we would spend in $s_1, s_2$ and $s_3$. This is what $\mathbf{N}$ provides. 

<!--
TO BE CONFIRMED
*Minor Detail*: We can also take a vector matrix product via row vector $(1\:\dotso\:1)$ here
-->

Then transient to absorbing transition matrix was:
> The absorbing states were $s_0, s_4$

$$
\mathbf{R} = 
\begin{pmatrix}
        1/2 & 0\\
        0   & 0\\
        0   & 1/2
\end{pmatrix}
$$
**Important**. The rows represent states $1, 2, 3$ while the columns represent states $0, 4$ .  
$$
\begin{align}
	\mathbf{B}&= \mathbf{N}\mathbf{R}\\
	&= \begin{pmatrix}
        3/2 & 1 & 1/2\\
        1 & 2 & 1\\
        1/2 & 1 & 3/2
\end{pmatrix}
\begin{pmatrix}
        1/2 & 0\\
        0   & 0\\
        0   & 1/2
\end{pmatrix}
\end{align}
$$
This will come out to:
![[time_to_abs_ex_main.png]]
Looking at row $2$ we notice that it an equal probability to end up in absorbing state $0$ or $4$ .
