---
title: Intro to Markov Chains
mathjax: true
---

# Intro to Markov Chains
Everything we have learned so far has been an independent process. Each previous trial does not effect the probabilities of the next trial. This where Markov Chains differ. 

## Markov Chain
A Markov chain has a set of *states*:
$$S = \{s_1, \dotso, s_r\}$$
The process starts in one of these states and moves to another state. This change in states is a *step*. Suppose the current state is $s_i$ and it moves to $s_j$. The probability of this event is denoted by $p_{ij}$ ($i \to j$). This probability is called the *transition probability* and does not depend on the previous states (before $s_i$ this case). Note that the state **does not** have to change. This is denoted by the transition probability $p_{ii}$

## Basic Example
![[markov_be.png]]
**Key** for Weather:

| Symbol | Key  |
| ------ | ---- |
| R      | Rain |
| N      | Nice |
| S      | Snow     |

This **is** a *transition matrix*. It shows the chances of weather tomorrow given that of today. 

For example if it is a nice day now the next day cannot be nice ($p_{NN} = 0$). 

We can ask a question like: given that the matrix is at state $i$ now what will its state be in 2 days called state $j$? We denote this is $p_{ij}^{(2)}$

### Example
> If it rains today, what is the chance it snows in two days?

*Assume day today is named day 1*

Notice that this can happen in three ways: (Day 1 is locked to Rain, Day 3 is locked to snow). 
1. Day 2 is rain
2. Day 2 is nice
3. Day 2 is snow

Lets look at event $1$:
We need the probability it will rain tomorrow $p_{11}$. And then the probability it snows if it rains the day previous: $p_{13}$. 
The probability of these two events occurring is $p_{11}p_{13}$.

Lets look at event $2$:
If it rains now then the chances of the next day being nice is $p_{12}$. If its nice the next day snowing is $p_{23}$. This event happens with probability $p_{12}p_{23}$ 

By this logic event $3$ has probability: $p_{13}p_{33}$ 

Then, 
$$p_{ij}^{(2)} = p_{11}p_{13} + p_{12}p_{23} + p_{13}p_{33}$$

This operation (summation of products) is like a dot product ([[Types of Vector Products]]). This is 
$$\text{row 1}\cdot\text{col 3}$$

Based on matrix multiplication, this is the $M_{(1, 3)}$ entry.

## Theorem (Important)
> Let $P$ be a transition matrix, the $ij$-th entry of $p_{ij}^{(n)}$ of the matrix $P^{n}$ gives the probability that the Markov chain starting in state $s_i$  will be in the state $s_j$ after $n$ iterations.  

## Convergence of a Matrix: "A *regular* Markov Chain"

If we take successive powers of $P$ above by the *sixth* power we hit this matrix:
$$
\mathbf{P}^6 = 
\begin{pmatrix}
        .400 & .200 & .400\\
        .400 & .200 & .400\\
        .400 & .200 & .400\\
\end{pmatrix}
$$
This is where applying powers doesn't change the matrix.

**Note**: Not all chains have this *feature*. 

## The *Probability Vector*
The sum of the components of a Probability Vector $u$ sum to $1$. The Probability Vector is the distribution of states $P$ can be in. The $i$-th component of $u$ represents the probability $P$ starts in state $s_i$ .

Notice that if we only want to examine state $s_k$, we set the vector's $k$th component to $1$ and all else to $0$. 

> **Theorem**:
> Let $P$ be the transition matrix of a chain. Let $\vec{\mathbf{u}}$ be the Probability Vector. Then the probability that the chain is in the state $s_i$ after $n$ iterations is $$\vec{\mathbf{u}}^{n} =  \vec{\mathbf{u}}P^n$$ 

Recall the last example with the weather.
Suppose we has this Probability Vector: 
$$
\vec{\mathbf{u}} = \begin{pmatrix}
        1/3 & 1/3 & 1/3\\
\end{pmatrix}
$$

Now we can ask what will happen to our probability vector after $3$ days.

$$
\begin{align}
\vec{\mathbf{u}}^{3} &= \vec{\mathbf{u}}P^3 \\

&= \begin{pmatrix}
        1/3 & 1/3 & 1/3\\
\end{pmatrix}
\begin{pmatrix}
        .406 & .203 & .391\\
        .406 & .188 & .406\\
        .391 & .203 & .406\\
\end{pmatrix}
 \\ \\ 
&= \begin{pmatrix}
        0.401 & .198 & .401\\
\end{pmatrix}
\end{align}
$$

Notice how they started out equal but they are no longer equal (each state $s_k$)