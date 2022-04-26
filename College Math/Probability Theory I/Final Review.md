# Final Review
Problems from each chapter I thought were interesting.

## Chapter 1
### Problem 1.2.26
**Statement**:

Two cards are drawn successively from a deck of 52 cards. Find the probability that the second card is higher in rank than the first card.

**Solution**
Suppose we pick two cards $s_1, s_2$ from a deck. There are three states of these cards.
$$
\begin{align}
	s_1 &\gt s_2 \\
	s_1 &\lt s_2 \\
	s_1 &= s_2 \\\\
	
	P(s_1 \gt s_2) + P(s_1 &\lt s_2) + P(s_1 = s_2) = 1 
\end{align}
$$

See that $P(s_1 \gt s_2) + P(s_1 \lt s_2)$ is the same as $2P(s_1 \gt s_2)$ since the situations are symmetric. 

Why *symmetric*?
Suppose we pick two cards. If $s_1 \gt s_2$ we can flip the order and get $s_1 \lt s_2$


What is $P(s_1 = s_2)$?
Suppose we pick a card. Then there are three other cards equal to it left after **we take one** card out. Thus, $$P(s_1 = s_2) = \frac{3}{51} = \frac{1}{17} $$

Thus
$$
2P(s_1 \gt s_2) = 1 - \frac{1}{17} 
$$

Finally we see that $P(s_1 \gt s_2) = 8/17$

## Chapter 3
### 3.1.7
**Statement**

Five people get on an elevator that stops at five floors. Assuming that each has an equal probability of going to any one floor, find the probability that they all get off at different floors.

**Work**

The number of ways to put $5$ people on diff floors is $5!$. We can let one out of 5 on floor 1, one of out 4 on floor 2, $\dotso\:$ .

Now what is the total number of ways we can arrange people?
In stead of elevators think of 5 boxes to put 5 objects in. There are $5\times5\times5\times5\times5$ ways to put items in each box.

$$\boxed{\frac{5!}{5^5}}$$

### 3.2.3
How many seven-element subsets are there in a set of nine elements?

Answer **without** Combinatorics
See that there are $9!$ to write each element out in a block of 9. 

But we only have $7$ slots so to say. 
Thus we have
$$
9\times8\times7\times6\times5\times4\times2 = \frac{9!}{2!}
$$
ways to write out the sets in groups of $7$. Recall that a set of 7 elements is the same as another set of 7 iff the elements internally are the same. The number of ways to write a set of $7$ is $7!$. 

Now $\frac{9!}{2!}$ contains redundant sets we only divide by $7!$ to get rid of them. 

$$
\boxed{\frac{9!}{2!7!}={\binom{9}{2}}}
$$