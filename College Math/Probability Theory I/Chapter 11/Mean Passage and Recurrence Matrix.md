# Mean Passage and Recurrence Matrix
Recall the generalization made in [[Mean First Passage Time]] about recurrence back to $s_i$ denoted by $r_i$:

$$r_i = 1+ \sum_{j}p_{ij}\cdot m_{ji} $$
 
We can do a similar thing for $m_{ij}$. The expected time it takes from $s_i \to s_j$ .

$$
\begin{align}
	m_{ij} &= \sum_{k}p_{ik}\cdot (m_{kj}+1)
	\\
	m_{ij} &= 1+ \sum_{k}p_{ik}\cdot (m_{kj})
\end{align}

$$

Suppose we start at a state $s_i$ then we have some probability to go to some other state $s_k$. This is $p_{ik}$, and takes $1$ step.  Then we must get to $s_j$ which has an $m_{kj}$ number of expected steps. Thus the total number of steps is $1+m_{kj}$.

Consider the special case of $s_i\to s_j$ in $1$ step. This is represented by $p_{ij}(1+m_{jj})$. 

> Recall $m_{ii} = 0$

Lets make this process easier.

## Mean First Passage \& Recurrence Matrix

Lets define some matrices.
+ $\mathbf{M}$ - $m_{ij}$ represents the expected time from $s_i \to s_j$ if $i\neq j$. Thus for any $i$, $m_{ii} = 0$
+ $\mathbf{D}$ - $d_{ii} = r_i$; any non-diagonal entries are zero. This is the *Mean Recurrence Matrix*. 
+ $\mathbf{C}$ - all entries are $1$ 

Using the information above this heading we notice that 

$$
\mathbf{M} = \mathbf{MP} + \mathbf{C} - \mathbf{D}
$$

The $\mathbf{MP} + \mathbf{C}$ is easy to deduct after seeing the equation was about matrix multiplication. 

**Theorem**

For an ergodic chain, $r_i = \frac{1}{w_i}$ where $\vec{w}$ is that fixed vector. 