# Discrete Conditional Probability
## Conditional Probability
This section answers questions about dependent events. We want to find the Probability that given $E$ what about $F$? 

> This is denoted by $$P(F|E)$$
> It reads, probability of $F$ given $E$
> $|$ is known as *given*

## Formula \& Context
$$
P(F|E) = \frac{P(F \cap E)}{P(E)}
$$
The top part $F \cap E$ will represent the Event Space where Both $F$ and $E$ have occurred.   

See that this boils down to 
> What is the probability that both $E$ and $F$ occur divided by the probability of $E$. As $E$ has been presumed to occur already.

%%
## Mild Derivation
In the example below we assigned a distribution function and then after being given new information we determined a new sample space which were outcomes that were still possible which called for a new distribution function. 

Let $\Omega = \{\omega_1, \omega_2, \dotso, \omega_r \}$ be the original sample space with a distribution function $m(\omega_j)$

Then we learn Event $E$ has occurred. We must assign a new distribution function $m(\omega_j|E)$

See that $\omega_j \not\in E \implies m(\omega_j|E) = 0$

Moreover we assume that even thought Event $E$ is known, all probabilities $\omega_k \in E$ should have the same magnitudes that they had before we learned of $E$.

So $m(\omega_j|E) = cm(\omega_j)$

The definition of a PDF must still apply $\forall w_k\in E$
$$\sum_{E}m(\omega_k|E)= c\sum_{E}m(\omega_k) = 1$$

Then 
$$c = \frac{1}{\sum_{E}m(\omega_k)} = \frac{1}{P(E)}$$
%%
## Examples
### Example A
Roll  a die once. Let $X$ be its outcome. Let the event $$F = \{X = 6\}$$
and let $$E = \{X > 4\}$$
The distribution function $m(\omega)$ outputs $\frac{1}{6}$ for all $\omega = 1, 2, \dotso, 6$
Then $P(F) = \frac{1}{6}$

Suppose we roll the dice and learn $E$ has occurred. This means the dice rolled has been either a $5$ or $6$.

See that because we know $E$ has occurred. 
$$
\begin{align*}
P(F|E) &= \frac{P(F \cap E)}{P(E)} \\\\
&= \frac{P(X = 6)}{P(X \in \{5, 6\})} \\\\
&= \frac{\frac{1}{6}}{\frac{2}{6}} \\
&= \frac{1}{2}
\end{align*}
$$

### Example B
A survey found that $89.935\%$ of women will live to $60$ while $57.062\%$ will love to $80$. Given that a woman is **already** 60, what are the chances she will live to $80$? The sample space was $100\ 000$ women.

Let $E$ be the subset of women alive at 60. $|E| = 89,935$
$F$ is the subset of women alive at 80, $|F| = 57,062$

See that this woman has already lived to $60$. This means that she has passed the 'First Filter'.

$$P(F|E) = \frac{|F|}{|E|} = .6352$$
We divide by $E$ because we know she didn't die.

### Example C
Recall the election example from Chapter 1:
It reads
> three candidates A, B, and C are running for office. We decided that A and B have an equal chance of winning and C is only 1/2 as likely to win as A.

We can assign probabilities as
$$
\begin{align*}
	P(A) &= P(B) &= \frac{2}{5}\\
	P(C) &= &= \frac{1}{5}
\end{align*}
$$
Suppose $A$ drops the race. 
If we follow the example rules we define
$$
\begin{align*}
	P(B|A) &= \frac{2}{3}\\
	P(C|A) &= \frac{1}{3}
\end{align*}
$$

This of course does **not** apply to real life. We cannot just assume all of $A$'s supporters will follow this $2:1$ ratio.

### Example D
Let there be $2$ bags. Bag$_1$ has 2 black balls and 3 white, while Bag$_2$ has 1 back and 1 white. A bag and ball is chosen at random. 

Let $B$ be the event that a *Black* ball has been chosen and $I$ be the event Bag$_1$ is chosen. Find $P(I|B)$

We need to find the chance of picking Bag$_1$ if we know a back ball came out. 
$$
\begin{align*}
	P(I|B) = \frac{P(I \cap B)}{P(B)}
\end{align*}
$$
$P(B)$ is the probability that a black ball is chosen. This can happen from any Bag. 
$$P(B) = P(B \cap I)+P(B \cap II)$$
We now need to find these probabilities. 
$P(B \cap I) = \frac{1}{2}\frac{2}{5}$ since $\frac{1}{2}$ chance of choosing bag and then $\frac{2}{5}$ of choosing the black ball.

Likewise $P(B \cap II) = \frac{1}{2}\frac{1}{2}$
$$\implies P(B) = \frac{1}{5}+\frac{1}{4}$$

$$\text{Answer: } \frac{1/5}{1/5+1/4} = \boxed{\frac{4}{9}}$$
![[condit_prob_d_tree.png]]
