# 11. 1
## 2
> Recall Example 4 from [[Markov Examples]]
> Let $a = 0$ and $b = \frac{1}{2}$
> Find $\mathbf{P}, \mathbf{P}^2, \mathbf{P}^3$ and $\mathbf{P}^n$ for $n\to\infty$

Note the state order $S = \{$ flips yes to no, flips no to yes $\}$
$$
\mathbf{P} = \begin{pmatrix}  
1 & 0\\  
\frac{1}{2} & \frac{1}{2}
\end{pmatrix}
$$

$$
\mathbf{P}^2 = \begin{pmatrix}  
1 & 0\\  
\frac{3}{4} & \frac{1}{4}
\end{pmatrix}
$$

$$
\mathbf{P}^3 = \begin{pmatrix}  
1 & 0\\  
\frac{7}{8} & \frac{1}{8}
\end{pmatrix}
$$

$$
\mathbf{P}^n = \begin{pmatrix}  
1 & 0\\  
1-\frac{1}{2^n} & \frac{1}{2^n}
\end{pmatrix} \to

\begin{pmatrix}  
1 & 0\\  
1 & 0
\end{pmatrix}
$$

Lets look at the state changes here. A yes has a $100\%$ probability to stay a yes. Now a *no* has a $100\%$ chance of being turned into a yes. This means that what ever the candidate decides, each person will **always** hear "yes" they are running.  
## 7
Analyze the powers of 
$$
\mathbf{P} =
\begin{pmatrix}  
	0 & 1\\  
	1 & 0
\end{pmatrix}
$$
Notice this represents the transformation of $\vec{i}\to\vec{j}$ and $\vec{j}\to\vec{i}$. 
This is a $180\deg$ rotation. 

Hence we can assume the following:
$$
\mathbf{P}^n =
\begin{cases}
	I_2 & \text{if n is even} \\
	\mathbf{P} & \text{if n is odd} \\
\end{cases}
$$

## 8
![[Pasted image 20220406220412.png]]

States $S = \{0, 1\}$
$$
\mathbf{P} =
	\begin{pmatrix}  
		1-p & p\\  
		p & 1-p
	\end{pmatrix}
	=
	\begin{pmatrix}  
		q & p\\  
		p & q
	\end{pmatrix}
$$

Note this is the *initial* matrix.

Even though its not in the scope of the problems lets look at $\mathbf{P^2}$

$$
\mathbf{P^2} = 
	\begin{pmatrix}  
		q^2+p^2 & 2pq\\  
		2pq & q^2+p^2
	\end{pmatrix}
$$

Notice that 
$$q^2+p^2+2pq = (q+p)^2 = 1^2 = \boxed{1}$$
Lets look at $p_{11}^{(2)}$. This is the fact that a we see a zero after two iterations. 

This can occur if $0\to0$ or $1\to0$.
Event $A$ has probability $q^2$ 
Event $B$ has probability $(1-q)^2 = p^2$ 
Since the events are independent, the probability of $A$ or $B$ is $p^2+q^2$. 
