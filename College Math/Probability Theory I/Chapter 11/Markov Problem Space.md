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
![[c11_1p8.png]]

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

# 11.2
## 2
**Q**: For values of $a, b$ is the following matrix absorbing. 

$$
\mathbf{P} = 
\begin{pmatrix}  
        1-a & a\\
        b & 1-b  
\end{pmatrix}
$$

We can force state $2$ to be absorbing if $a\in(0, 1)$. Then both $1-a$ and $a$ will be non-zero. This means that $p_{11}, p_{12} \gt 0$. Then $b = 0$. This will cause state two to be an absorbing state. 

Also if $1$ then state two is also a absorbing state.

To make $s_2$ absorbing we have the following set of values.
$$\{(a, b):a\in(0, 1], b = 0\}$$

To make $s_1$ absorbing we must route all  entries in $s_2$ back to $s_1$. 

Thus $b = 1$ and $a\in(0, 1]$

In the end we note that either one of these conditions must be met (not both).
1. $a$ is 0
2. $b$ is 0

## 4
Find the fundamental Matrix for 
$$
\mathbf{P} = \begin{pmatrix}        
        1 & 0 & 0\\    
        0.5 & 0.5 & 0\\
        0 & 1 & 0
\end{pmatrix}
$$

First we take it to Canonical form
$$
\mathbf{C} = \begin{pmatrix}         
        0.5 & 0 & 0.5\\
		1 & 0 & 0\\  
        0 & 0 & 1
\end{pmatrix}
$$

The new state order is $S = \{s_2, s_3, s_1\}$

Then 
$$
\begin{align}
	\mathbf{Q} &= \begin{pmatrix}         
			0.5 & 0 \\
			1 & 0 
	\end{pmatrix}
	\\ \\ 
	\mathbf{I-Q} &= \begin{pmatrix}       
			0.5 & 0 \\
			-1 & 1
	\end{pmatrix}\
	\\ \\
	\mathbf{(I-Q)}^{-1} &= \frac{1}{0.5}\begin{pmatrix}   
			1 & 0 \\
			1 & 0.5
	\end{pmatrix}
	\\ \\
	\mathbf{N} &= \begin{pmatrix}   
			2 & 0 \\
			2 & 1
	\end{pmatrix}
\end{align}
$$

> The next few problems will be about utilizing this matrix $\mathbf{N}$

## 6
If
$$
\mathbf{P} = \begin{pmatrix}
        1 & 0 & 0\\
        0.5 & 0 & 0.5\\
        0.25 & 0.25 & 0.5
\end{pmatrix}
$$
Find $\mathbf{N}, \mathbf{N}\vec{c}, \mathbf{N}\mathbf{R}$. What do each of these mean?

**Canonical Form**
State order $S = \{s_2, s_3, s_1\}$

$$
\mathbf{C} = \begin{pmatrix}
        0 & 0.5 & 0.5\\
        0.25 & 0.5 & 0.25 \\
		0 & 0 & 1\\
\end{pmatrix}
$$

Then 
$$
\begin{align}
	\mathbf{Q} &= \begin{pmatrix}         
			0 & 0.5 \\
			0.25 & 0.5 
	\end{pmatrix}
	\\ \\ 
	\mathbf{I-Q} &= \begin{pmatrix}       
			1 & -0.5 \\
			-.25 & 0.5
	\end{pmatrix}\
	\\ \\
	\mathbf{(I-Q)}^{-1} &= \frac{1}{0.5-0.125}\begin{pmatrix}   
			0.5 & 0.5 \\
			0.25 & 1
	\end{pmatrix}
	\\ \\
	\mathbf{N} &= \begin{pmatrix}   
			4/3 & 4/3 \\
			2/3 & 8/3
	\end{pmatrix}
\end{align}
$$

The matrix $\mathbf{N}$ represents the expected time spent in state $s_{ij}$ before being absorbed to one of the absorbing states (there is only one here anyways). 

$$
\mathbf{N}\vec{c} = \begin{pmatrix}   
			4/3 & 4/3 \\
			2/3 & 8/3
	\end{pmatrix}\begin{pmatrix}   
		1\\1
	\end{pmatrix} = 
	\begin{pmatrix}   
			8/3 \\
			10/3 
	\end{pmatrix}
$$

The **vector** $\mathbf{N}\vec{c}$ represents the expected time spent in state $s_i$ before absorbing. 

$$
\mathbf{N}\mathbf{R} = \begin{pmatrix}   
			4/3 & 4/3 \\
			2/3 & 8/3
	\end{pmatrix}\begin{pmatrix}   
			1/2 \\
			1/4 \\
	\end{pmatrix}
	= 
	\begin{pmatrix}   
			1 \\
			1 \\
	\end{pmatrix}
$$

Given that $\mathbf{N}\mathbf{R}_{ij}$ represents state $s_i$ absorbing into $s_j$ this result of $\binom{1}{1}$ is trivial since there is only **one** absorbing state anyways. 