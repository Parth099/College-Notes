# Mean Passage Times
## Mean First Passage Time
The point of this note is to discuss two events:
1. The mean time to return to a state
2. The mean time to go from state $i$ to state $j$

Let $\mathbf{P}$ be Ergodic with $r$ states. Let $\mathbf{\vec{w}}$ be the unique probability vector. Via the law of large numbers of Markov chains, for a large amount of iterations, the process will spend $w_j$ proportional time in state $s_j$.  

**Interpretation**
Suppose we form a new Markov chain from the old one above. However in this chain, $p_{jj} = 1$ . If we restart the process the chain will behave the same **up to** the first time it gets absorbed in state $j$. Since the chain was ergodic, we will always hit $j$ . 

Let $\mathbf{N}$ be the Fundamental matrix for this *new* chain. 

$$
\text{ Recall } \mathbf{N} = (\mathbf{I}-\mathbf{Q})^{-1} 
$$

Since the entries of $\mathbf{N}$ give the expected time to absorption given a starting point and ending point for the transient starts, the $i$th component of $\mathbf{N}c$ will give the expected time spent in state $i$ **before** being absorbed. 

> See that this is counting what we wanted initially. The components of $\mathbf{N}c$ will count the number of iterations before absorbing to state $j$.  

**Theorem**
If an ergodic chain started in $s_i$, the expected number of steps to reach $s_j$ is called ***Mean First Passage Time*** from $s_i$ to $s_j$, denoted by $m_{ij}$. 

> $m_{ii} = 0$

**Steps For Computation**

Suppose you want to investigate the *Mean First Passage Time* for some state $j$. Create a new matrix with that state $j$ as absorbing. Then compute the fundamental matrix $\mathbf{N}$ . Then, find $\mathbf{N}c$. See above for interpretation for $\mathbf{N}c$

### MFPT Example
If we start in state $2$ what is the mean time to hit state $1$. 
$$
\mathbf{P} = \begin{bmatrix}
0 & 1/3 & 2/3 \\
1/2 & 0 & 1/2 \\
1 & 0 & 0
\end{bmatrix}
$$

First we make $s_1$ an absorbing state. 
$$
\mathbf{P}_1 = \begin{bmatrix}
1 & 0 & 0 \\
1/2 & 0 & 1/2 \\
1 & 0 & 0
\end{bmatrix}
$$

To find $\mathbf{N}$ we must get to Canonical form

State order $S = \{s_2, s_3, s_1\}$

$$
\mathbf{C} = \begin{bmatrix}
0 & 1/2 & 1/2 \\
0 & 0 & 1 \\
0 & 0 & 1
\end{bmatrix}
$$

**Finding** $\mathbf{N}$
$$
\begin{align}
	\mathbf{Q} &= 
		\begin{bmatrix}
			0 & 1/2 \\
			0 & 0 
		\end{bmatrix}

\\ \\

	\mathbf{I - Q} &= 
		\begin{bmatrix}
			1 & -\frac{1}{2} \\
			0 & 1 
		\end{bmatrix}

\\ \\

	(\mathbf{I - Q})^{-1} &= \begin{bmatrix}
	1 & \frac{1}{2}\\ 
	0 & 1
	\end{bmatrix} = \mathbf{N}
\\ \\ 

	\mathbf{N}c &= 
		\begin{bmatrix}
			1&\frac{1}{2}\\ 
			0&1
		\end{bmatrix}
		\begin{bmatrix}
			1\\ 
			1
		\end{bmatrix} \\
		
 &= \begin{bmatrix}
 		\frac{3}{2}\\ 
		1
		\end{bmatrix}
 
 \end{align}
$$

Now we can answer the question.
See that we are in $s_2$. The time to absorption from state $s_2$ to $s_1$ is $3/2$ as provided by $\mathbf{N}c$
## Mean Recurrence Time
**Definition**

Let $\mathbf{P}$ be an ergodic chain that started in state $s_i$. The expected number of iterations to return back to $s_i$ is known as the ***Mean Recurrence Time*** for $s_i$. It is denoted by $r_i$. 

> Note $r_i$ exists due to the precondition of the chain being ergodic. 

<!-- PAGE 464 -->