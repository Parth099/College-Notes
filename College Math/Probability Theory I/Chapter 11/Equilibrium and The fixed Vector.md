# Probability Vector
The fixed Probability Vector was covered before but this well contain more detail.

For now, $\mathbf{P}$ is regular. 

If $\vec{u}$ is a Probability Vector representing the starting probabilities for each state then:
$$
\begin{align}
	\vec{u}^{(1)} &= \vec{u}\mathbf{P} \\
	\vec{u}^{(2)} &= \vec{u}^{(1)}\mathbf{P} = \vec{u}\mathbf{P}^2 \\
	&\vdots \\
	\vec{u}^{(k)} &= \vec{u}\mathbf{P}^k 
\end{align}
$$

This is intuitive, the entry $\vec{u}_{i}^{(k)}$ represents the probability of being in state $i$ after $k$ steps.  
## Probability Vector and $\mathbf{W}$
If $\mathbf{P}$ is regular and $n$ is very large then, 
$$\mathbf{P}\approx\mathbf{W}$$
Recall what $\mathbf{W}$ looks like:
$$
\mathbf{W} = \begin{bmatrix} 
    w_{1} & w_{2} & \dots & w_n \\
    \vdots & \vdots & \ddots & \vdots\\
	w_{1} & w_{2} & \dots & w_n 
\end{bmatrix}
$$

If $\vec{u}$ gives the starting state then, 
$$
\begin{align}
	\vec{u}^{(n)} &= \vec{u}\mathbf{P}^n = \vec{u}\mathbf{W} \\
	&= 
	\begin{bmatrix} 
    	u_{1} & u_{2} & \dots & u_n \\
	\end{bmatrix}
	\begin{bmatrix} 
    	w_{1} & w_{2} & \dots & w_n \\
    	\vdots & \vdots & \ddots & \vdots\\
		w_{1} & w_{2} & \dots & w_n 
	\end{bmatrix}
\\
&= \begin{bmatrix} 
    w_{1} & w_{2} & \dots & w_n \\
	\end{bmatrix} = \boxed{\vec{w}}
\end{align}
$$

**Important**: Notice that it does not matter the initial state distribution ($\vec{u}$), in the long run the distribution approaches the stationary vector $\mathbf{\vec{w}}$ . It should be obvious why we would be interested in this $\vec{w}$.

### Example : Non Regular, Ergodic Interpretation

$$
\mathbf{P} = 
\begin{pmatrix}
        0 & 1\\
        1 & 0  
\end{pmatrix} 
$$

Notice that this is non-regular yet Ergodic. 
$$
\begin{bmatrix}
        w_1 & w_2
\end{bmatrix} \mathbf{P} = \begin{bmatrix}
        w_1 & w_2
\end{bmatrix}
$$

After solving these systems we see that $$\mathbf{\vec{w}} = \begin{pmatrix}
        1/2 & 1/2
\end{pmatrix}$$

This is odd behavior.
Suppose the number of steps we take is an integer $n$, 
If $n$ is even we are always in state $1$ and if $n$ odd then we are always in state $2$. 

It seems as if $\mathbf{\vec{w}}$ does not have the same meaning it does for **regular** chains. In regular chains, $\mathbf{\vec{w}}_i$ represents the probability of being in  state $i$ after a large number of steps. 

Actually, for non-regular **Ergodic** chains, $\mathbf{\vec{w}}$ represents the proportional time spent in each state.  
