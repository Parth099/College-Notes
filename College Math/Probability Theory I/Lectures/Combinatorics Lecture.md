# The Questions
## #1
> Suppose we had $n$ identical pieces of candy to distribute among $k$ children and we have at give each child at-least one candy.
> What is the number of ways this can be done

Consider the $n=5$ and $k=3$ case. We can draw this diagram:
Each $*$ is a candy and each set of boundaries represents a child.
$$
\begin{align*}
	&\{*|*|***\}, \{*|**|**\}, \{*|***|*\} \\
	&\{**|*|**\}, \{**|**|*\}, \\
	&\{***|*|*\}
\end{align*}
$$
See that for $n=5$ and $k=3$ there are *six* possible ways this can happen.

This problem has transformed into a **new** arrangement problem:
> How many ways can we put the $k-1$ dividers into $n-1$ spaces

$$\text{Answer: }\binom{n-1}{k-1}$$
## #2
> #1 but with out the min of $1$ constraint dropped

## #3
> How many paths from $A \to B$ are possible if we can only go up or right. See image:

## #4
> What is the coefficient of $x^2y^3$ in $(x+y)^5$ 

## #5
> How many ways are there to make $2$ pairs from a group of $n$ people. 
> Let $n$ be $4, 6, 2k$ 