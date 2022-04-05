# Conditional Expectation
> **Definition** 
> If $F$ is any event and $X$ has a sample space of $$\Omega = \{x_1, x_2, \dotso\}$$then the **conditional expectation** given by $F$ is given by
> $$E(X|F) = \sum_i x_i\times P(X = x_j | F)$$

Surprisingly this is intuitive. 

# The Law of Total Expectation
We are required to understand the Total Probability Theorem beforehand. 
## Total Probability Theorem
Suppose we have an  $B$. Here is one way to find $P(B)$

This model is powerful because it allows us to **divide and conquer** a total probability field into smaller sub-models which can be easier to investigate. 

Now Consider event $B$ and its sample space $A$.
We can divide $A$ into $n$ disjoint subsets and then investigate the probability of $B$ given $A_i$. It is important to know that the union of all $A_i$ will give out $A$, this means the sub-sample-spaces exhaust all possibilities. 

Here is $n = 3$. Src: [MIT OpenCourseWare](https://www.youtube.com/watch?v=GnEyIawrWBg)

![[submodel_n__3.png]]

We split $A$ into 3 subsets and investigate $B$ under each subset. 

$$
\begin{align}
	P(B) &= P(A_1)P(B|A_1) + \dotso + P(A_n)P(B|A_n)\\
		 &= \sum_{i = 1}^{n}P(A_i)P(B|A_i)
\end{align}
$$
$n$ is the amount of disjoint splits we commit on $A$, the given sample space.

Here, we attain the probability under **each**  *scenario* and weigh them by the probability of each scenario.

## Total Expectation Theorem
The logic is the same for Expected values of random variables.
> Let $X$ be a random variable with sample space $\Omega$. 
> If $F_1, F_2, \dotso ,F_r$ are pairwise disjoint then and $E(X)$ exists:
> $$E(X) = \sum_j E(X|F_i)P(F_j)$$




