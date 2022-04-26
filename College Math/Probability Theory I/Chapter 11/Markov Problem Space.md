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
## 1
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

## 7
Make states 0 and 4 into absorbing states. 
Find the fundamental matrix $\mathbf{N}$, and also $\mathbf{N}\vec{c}$ and $\mathbf{B}$, for the resulting absorbing chain.

Then, interpret the results.

$$
\mathbf{P} = {
	\begin{pmatrix}
        0 & 1 & 0 & 0 & 0\\    
        1/4 & 0 & 3/4 & 0 & 0\\
        0 & 1/2 & 0 & 1/2 & 0\\
        0 & 0 & 1/4 & 0 & 3/4\\
        0 & 0 & 0 & 1 & 0      
	\end{pmatrix}
}
$$

Then we make states $0, 1$ absorbing.
$$
\mathbf{\hat{P}}_{0, 4} = {
	\begin{pmatrix}
        0 & 3/4 & 0 & 1/4 & 0\\    
        1/2 & 0 & 1/2 & 0 & 0\\
        0 & 3/4 & 0 & 0 & 1/4\\
        0 & 0 & 0 & 1 & 0 \\
        0 & 0 & 0 & 0 & 1      
	\end{pmatrix}
}
$$

The new state order is $\{1, 2, 3, 0, 4\}$

**Fundamental Matrix**:
$$
\begin{align}
	\mathbf{Q} &= 
		\begin{pmatrix}        
			0 & 3/4 & 0\\  
			1/2 & 0 & 1/2\\
			0 & 3/4 & 0    
		\end{pmatrix} \\\\
		
	\mathbf{I - Q} &= 
		\begin{pmatrix}        
			1 & -3/4 & 0\\  
			-1/2 & 1 & -1/2\\
			0 & -3/4 & 1    
		\end{pmatrix} \\\\
		
	\mathbf{N} = (\mathbf{I - Q})^{-1} &= 
		\begin{pmatrix}        
			2.5 & 3 & 1.5\\
			2 & 4 & 2\\    
			1.5 & 3 & 2.5   
		\end{pmatrix} \\\\
\end{align}
$$

The matrix $N$ has states ordered $\{1,2, 3\}$, the **non**-absorbing states. Each entry $\mathbf{N}_{ij}$ represents the time the system spends in state $j$ starting in state $i$.  

**Absorption Probability**
$$
\begin{align}
	\mathbf{NR} &= 
		\begin{pmatrix}        
			2.5 & 3 & 1.5\\
			2 & 4 & 2\\    
			1.5 & 3 & 2.5   
		\end{pmatrix}
		\begin{pmatrix}        
			.25 & 0  \\
			0   & 0  \\    
			0   & .25\\   
		\end{pmatrix}
	\\\\
	&= 	\begin{pmatrix}        
			.625   & .375 \\
			.5     & .5   \\    
			.375   & .625 \\   
		\end{pmatrix}
	\\ \\
	&= \mathbf{B}
\end{align}
$$

Each entry $\mathbf{B}_{ij}$ represents the probability that state $i$ will be absorbed into state $j$ . 

**Expected Time to Absorption**
$$
\mathbf{N}\vec{c} = 								 
		\begin{pmatrix}        
			2.5 & 3 & 1.5\\
			2 & 4 & 2\\    
			1.5 & 3 & 2.5   
		\end{pmatrix}
		\begin{pmatrix}        
			1 \\ 1 \\ 1
		\end{pmatrix}
		
		= 
		
		\begin{pmatrix}        
			7 \\ 8 \\ 7
		\end{pmatrix}
$$

Component $i$ of $\mathbf{N}\vec{c}$ represents the time till absorption for state $i$. On average, after $8$ steps, State $2$ will be absorbed. 

## 9
A process moves on the integers 1, 2, 3, 4, and 5. It starts at 1 and, on each successive step, moves to an integer greater than its present position, moving with equal probability to each of the remaining larger integers. State five is an absorbing state. Find the expected number of steps to reach state five.

$$
\mathbf{P} = {
	\begin{pmatrix}
	    0 & 1/4 & 1/4 & 1/4 & 1/4\\
        0 & 0 & 1/3 & 1/3 & 1/3\\
        0 & 0 & 0 & 1/2 & 1/2\\
        0 & 0 & 0 & 0 & 1\\
        0 & 0 & 0 & 0 & 1
	\end{pmatrix}
}
$$

Notice this is *already* in Canonical form.
$$
\begin{align}
	\mathbf{Q} &=  \begin{pmatrix}
        0 & 1/4 & 1/4 & 1/4\\
        0 & 0 & 1/3 & 1/3\\
        0 & 0 & 0 & 1/2\\
        0 & 0 & 0 & 0
\end{pmatrix}
\\\\
(\mathbf{I} - \mathbf{Q})^{-1} &= 
	\begin{pmatrix}
        1 & 1/4 & 1/3 & 1/2\\
        0 & 1 & 1/3 & 1/2\\  
        0 & 0 & 1 & 1/2\\    
        0 & 0 & 0 & 1        
	\end{pmatrix}
\\\\
\mathbf{N}\vec{c} &= \begin{pmatrix}
        25/12\\
        11/6\\
        3/2\\
        1
\end{pmatrix}
\end{align}
$$

Since we are given that the starting state is $1$, the expected number of steps to state $5$ is $$\frac{25}{12} = 2.08\overline{3}$$

# 11.3
## 2
$$
\mathbf{P} = \begin{pmatrix}
        1/2 & 1/3 & 1/6\\
        3/4 & 0 & 1/4\\
        0 & 1 & 0
\end{pmatrix}
$$

**Part 1**: Show $\mathbf{P}$ is regular.  
Observe that in $3$ steps we can hit every state and return back to 1. This should mean that each entry in $\mathbf{P}$ is non-zero.

$$
\mathbf{P}^3 = \begin{pmatrix}
        1/2 & 1/3 & 1/6\\
        9/16 & 1/4 & 3/16\\
        3/8 & 1/2 & 1/8
\end{pmatrix}
$$

**Part 2**: Given a start in state 1, what is the probability in two steps the system is in state 3?

$$
\text{Recall }\: \vec{u}^{(2)} = \vec{u}\mathbf{P}^2
$$

In this case $\vec{u} = \langle 1, 0, 0 \rangle$

Then, 
$$
\vec{u}\mathbf{P}^2 = \langle \frac{1}{2}, \frac{1}{3}, \frac{1}{6} \rangle
$$

If the system starts with $\langle 1, 0, 0 \rangle$ after two steps the state distribution is $\langle \frac{1}{2}, \frac{1}{3}, \frac{1}{6} \rangle$. Thus the answer is $\frac{1}{6}$

**Part 3**: Find the fixed vector $\vec{w}$

$$
\text{Recall }\: \langle w_1, w_2, w_3 \rangle\mathbf{P} =  \langle w_1, w_2, w_3 \rangle
$$

Thus we can form the following equations:

$$
\begin{align}
(1)& & \frac{1}{2}w_1 + \frac{3}{4}w_2 &= w_1 \\
(2)& & \frac{1}{3}w_1 + w_3 &= w_2 \\
(3)& & \frac{1}{6}w_1 + \frac{1}{4}w_2 &= w_3\\
\end{align}
$$

Scale to $w_1 = 1$
Then $w_2 = \frac{2}{3}$
Since we have $w_1, w_2$; $w_3 = \frac{1}{3}$

Thus,  
$$
\vec{w} = \langle 1,\:2/3,\:1/3  \rangle
$$

Since we need a fixed vector such that $w_1 + w_2 + w_3 = 1$, we can divide each component of $\vec{w}$ by the sum of them. Thus 
$$
\vec{w} = \langle 1/2,\:1/3,\:1/6 \rangle
$$

## 3
$$
\begin{align}
	\mathbf{P} = \begin{pmatrix}  
        1-a & a\\
        b & 1-b  
	\end{pmatrix}    
\end{align}
$$

**Questions**
**Q1** : When is $\mathbf{P}$ absorbing?
Suppose we make state $s_1$ absorbing. Then
$a = 0$. For state $s_2$ to *eventually* absorb into $s_1$, $0\lt b \leq 1$

Suppose we make $s_2$ absorbing.
Then $b = 0$ and $0\lt a \leq 1$

If $a, b = 0$ then $\mathbf{P} = {I}_2$. Thus $\mathbf{P}$ will be trivially absorbing.

**Q2.1**: When is $\mathbf{P}$ ergodic? 
Notice that it cannot be absorbing. Thus $\mathbf{P}$ is ergodic if $a, b \gt 0$

**Q2.2**: When is $\mathbf{P}$ ergodic but not regular?  
If $a, b = 1$ it is ergodic yet not regular. 
Recall this development:
$$
\mathbf{P}^n = 
\begin{cases}
	\mathbf{P} & \text{if} & 2\nmid n \\
	\mathbf{I} & \text{if} & 2\:|\:n \\
\end{cases}
$$

Both contains $0$s.

**Q3** When is $\mathbf{P}$ regular?
$\mathbf{P}$ is regular if $a, b \in(0, 1)$

## 6
Using the matrix in *3* with $a = b = 1$, find stable probability vector and show that 
$$A_n = \frac{1}{n}\sum_{k = 0}^{n}\mathbf{P}^k$$
converges.

**Finding Stable Vector**: $\vec{w}$ 

$$\langle w_1, w_2 \rangle\mathbf{P} = \langle w_1, w_2 \rangle$$
Then, 

$$
\langle w_1, w_2 \rangle = \langle 1, 1 \rangle \implies \vec{w} = \biggr\langle \frac{1}{2}, \frac{1}{2} \biggr\rangle
$$

This makes sense, we spend half of our time in both states since this chain just cycles between them.

**Showing Convergence**
Recall
$$
\mathbf{P}^n = 
\begin{cases}
	\mathbf{P} & \text{if} & 2\nmid n \\
	\mathbf{I} & \text{if} & 2\:|\:n \\
\end{cases}
$$

Looking at, 
$$A_n = \frac{1}{n}\sum_{k = 0}^{n}\mathbf{P}^k$$
Suppose $n$ is odd.
Then we have
$$A_n = \frac{1}{n+1}\biggr[
	I + \mathbf{P} + \dotso + I + \mathbf{P}
\biggr]$$

Then 
$$
A_n = \frac{1}{n+1}\begin{pmatrix}    
        n/2 & n/2\\
        n/2 & n/2  
\end{pmatrix} 
$$
This happens because there are $\frac{n}{2}$ $I, P$ involved in the summation. Notice that since $n$ is odd and sum index starts at 0, the number of elements is even. 

The logic for $n$ even is nearly the same. 

Then, 
$$
\begin{align}
	\lim_{n\to\infty} A_n &= \lim_{n\to\infty} \frac{1}{n+1}
\begin{pmatrix}    
	n/2 & n/2\\
    n/2 & n/2 
\end{pmatrix} 
\\ \\
&=
\begin{pmatrix}    
	1/2 & 1/2\\
    1/2 & 1/2 
\end{pmatrix}
\end{align}
$$

This is the same matrix we got above; it has$\vec{w}$ as each row.

## 7
Using $\mathbf{P}$ from 3, find stable $\vec{w}$ with params $a = 0, b = 1/2$

$$
\mathbf{\hat{P}} = 
\begin{pmatrix}  
        1 & 0\\  
        1/2 & 1/2
\end{pmatrix}  
$$

After perform the '*algorithm*' we see that 
$$
\vec{w} = \langle 1,0 \rangle
$$

The zero violates the definition of a stable probability vector. 

# 11.5
## 2
A study of the strengths of Ivy League football teams shows that if a school has a strong team one year it is equally likely to have a strong team or average team next year; if it has an average team, half the time it is average next year, and if it changes it is just as likely to become strong as weak; if it is weak it has 2/3 probability of remaining so and 1/3 of becoming average.

+ Just for fun I will try to compute these numbers without the matrix $\mathbf{Z} = (I - \mathbf{P} + \mathbf{W})^{-1}$

$$
\mathbf{P} = {
	\begin{pmatrix}
        1/2 & 1/2 & 0\\  
        1/4 & 1/2 & 1/4\\
        0 & 1/3 & 2/3    
	\end{pmatrix}
}
$$
State Configuration: **\{** Strong, Average, Weak **\}**

**Q1** If a team is already strong, how long till it is string again?

See *Q2* for calculations.
We have seen that 
$$
\begin{align}
	m_{21} &= 7 \\
	m_{31} &= 10 \\	
\end{align}
$$

Recall for recurrence, 
$$
m_{11} = \sum_{k = 0}^{n}p_{1k}(m_{k1} + 1)
$$

For this example,
$$
m_{11} = \frac{1}{2}(0+1) + \frac{1}{2}(7+1) + 0(10+1) = \boxed{4.5}
$$

The mean return time from Strong Team to String Team is $4.5$ Seasons.

*Alternate Solution*: Calculate the stable vector $\vec{w}$ and recall $r_i = \frac{1}{w}$


**Q2** If a team is currently weak, how long must they wait till their team is strong.

We need the *Mean First Passage Time* here. 

Set Strong to absorbing
$$
\mathbf{\hat{P}}_s = {
	\begin{pmatrix}
        1/2 & 1/4 & 1/4\\  
        1/3 & 2/3 & 0\\
        0 & 0 & 1   
	\end{pmatrix}
}
$$
 
*New* State Configuration: **\{** Average, Weak, Strong **\}**

The Fundamental Matrix is:
$$
\mathbf{N} = (\mathbf{I} - \mathbf{Q})^{-1} = \begin{pmatrix}4&3\\ 4&6\end{pmatrix}
$$

The *expected* time spent in each state before absorbing is:

$$
\mathbf{N}\vec{c} = \binom{7}{10}
$$

| Index | Meaning |
| ----- | ------- |
| 1     | Strong  |
| 2     | Average |
| 3     | Weak    |

Thus we have $m_{2, 1} = 7, m_{3, 1} = 10,$

Since $m_{3, 1}$ represents the return time from weak $\to$ strong, it will take 10 seasons on average for a weak team to become strong. 