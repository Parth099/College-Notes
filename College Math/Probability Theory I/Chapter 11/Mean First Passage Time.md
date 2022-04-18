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
\text{ Recall }\: \mathbf{N} = (\mathbf{I}-\mathbf{Q})^{-1} 
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

### Example of MRT
**Statement**

Find the mean recurrence time back to $s_1$
#### Sub Example of Mean Passage

Lets ask a easier **question**:
Find the mean time per state to $s_1$

$$
\text{Let }\:\mathbf{P} = \begin{bmatrix}
1/3 & 1/3 & 1/3 \\
1/2 & 1/4 & 1/4 \\
1 & 0 & 0
\end{bmatrix}
$$
The state order is $S = \{s_1, s_2, s_3\}$

Transform $s_1$ into absorbing. 

$$
\text{Let }\:\hat{\mathbf{P}}_1 = \begin{bmatrix}
1/4 & 1/4 & 1/2 \\
0 & 0 & 1 \\
0 & 0 & 1 
\end{bmatrix}
$$
The state order is $S = \{s_2, s_3, s_1\}$ and $\hat{\mathbf{P}}_1$ is in canonical form with an absorbing state $s_1$. 

> Skipping calculation typesetting 

Then 
$$
\begin{align}
	\mathbf{N} &= \begin{bmatrix}
		4/3 & 1/3 \\
		0 & 1 
	\end{bmatrix} 
	\\
	\\
	\mathbf{N}\vec{c} &= \begin{bmatrix}
		5/3 \\
		1 
	\end{bmatrix} 
\end{align}
$$

We know how to interpret this part. The mean passage time from $s_2$ to $s_1$ is $m_{21}=5/3$ while $s_3$ to $s_1$ is $m_{21}=1$ .

> **Notice** that $m_{ij} \geq 1$ for any $(i, j)$

### Back to MRT
See that
$$
\begin{bmatrix}
		m_{21} \\
		m_{31}
\end{bmatrix} =
	
\begin{bmatrix}
		5/3 \\
		1 
\end{bmatrix} 
$$

Now we just need to get from $s_1$ to one of these states. We know the probabilities of getting to one from these states. They are namely $p_{12}$ and $p_{13}$ .

> Also note that $p_{11} = \frac{1}{3}$

We can define mean return time as going to some other state (not $s_1$) and then returning to back to $s_1$ or just landing in $s_1$ again from $s_1$

See that 
$$
r_1 = P(s_1\to s_1)(1) + P(s_1\to s_2)m_{21} + P(s_1\to s_3)m_{31}
$$

The $(1)$ appears because it takes $1$ step to move back $s_1$ from $s_1$

See that $r_1$ is not quite right.
Looking at going to state 2 and then returning takes $1$ step and then returning takes $m_{21}$ steps. Thus we can **finally** define $r_1$ as:
$$
p_{11}(1+m_{11}) + p_{12}(1+m_{21}) + p_{13}(1+m_{31})
$$

> Recall $m_{ii} = 0$ by convention. 

**Actual Calculation**

$$
\begin{align}
	r_i &= p_{11}(1+m_{11}) + p_{12}(1+m_{21}) + p_{13}(1+m_{31}) \\ \\
	&= \frac{1}{3}\biggr[1+\frac{5}{3}+1+1+1\biggr] = \boxed{\frac{17}{9}}
\end{align}
$$

> Notice the issue here. To find $r_i$ for a new $i$ re will have to find the $m_{ij}$ values every time.

### Mean Recurrence Time *Generalization*
Notice from the example that we the return times are usually calculated like this:  
$$
\begin{align}
	r_i &= \sum_{j}p_{ij}(m_{ji}+1) \\
	    &= \sum_{j}p_{ij}\cdot m_{ji}+p_{ij} \\
		
		&= \sum_{j}p_{ij}\cdot m_{ji}+\sum_{j}p_{ij} \\
		
		&= 1+ \sum_{j}p_{ij}\cdot m_{ji} \\
\end{align}
$$

> The of a row in a Markov Chain is **1** 

This product looks like $1 +$ an entry in a matrix multiplication. 