# Bayes' Theorem
> Given Events $A$ and $B$ where $P(B) \neq 0$ we have
> $$
> P(A|B) = \frac{P(B|A)P(A)}{P(B)}
> = \frac{P(B|A)P(A)}{P(B|A)P(A)+P(B|\bar{A})P(\bar{A})}
> $$
## Proof
This is the class **Proof**.

Recall from [[Discrete Conditional Probability]] that 
$$P(A|B) = \frac{P(A\cap B)}{P(B)}$$
This is the probability of event $A$ given we know $B$ **has** occurred. 

Multiply both sides by $P(B)$
$${P(A\cap B)} = P(A|B)P(B)$$

See that $$P(B|A) = \frac{P(A\cap B)}{P(A)}$$
This is $B$ given $A$
$$P(B|A)P(A) = P(A\cap B)$$
Now we have two definitions for $P(A \cap B)$
$$P(B|A)P(A) = P(A|B)P(B)$$

**$$\boxed{P(A|B) = \frac{P(B|A)P(A)}{P(B)}}$$**

Note this about $P(B)$
$$P(B) = P(B\mid A)P(A) + P(B\mid \overline{A}) P(\overline{A})$$

With this we can define the fill equation:
$$
\boxed{\frac{P(B\mid A)P(A)}{P(B\mid A)P(A) + P(B\mid \overline{A})P(\overline{A})}}
$$

## Book Explanation
Suppose we have a set of events that are **pairwise disjoint** such that

$$\Omega = {\cap}_{i = 0}^{m} H_i$$
These events are hypotheses. Then there is an event $E$ that gives us some information about which hypothesis is correct. This is called the evidence. 

Before this evidence event we have prior probabilities for each of the $H_i$: $P(H_i)$. We also know the $P(E|H_i)$. This is like knowing the chance of a **True** Positive [[3b1b - Redesigning Bayes' rule]]. What we really need is the $P(H_i|E)$, known as the *posterior probabilities*.

$$
\begin{align*}
	P(H_i|E) &= \frac{P(H_i \cap E)}{P(E)}\\
			 &= \frac{P(E|H_i)P(E)}{P(H_i)}&\text{by (1)}\\
			 &= \frac{P(E|H_i)P(H_i)}{\sum_{k=1}^{m}P(H_k)P(E|H_k)}&\text{by (2)}\\
\end{align*}
$$

+ $1$ - Recall this is the scaling here. $P(E|H_i)$ is what we are testing while $P(H_i)$ is the true value. In the disease example  $P(E|H_i)$ is the correct diagnosis from a positive test while $P(H_i)$ is the **actual** probability people have it based on the sample space. 
+ $2$ - This is the probability of $E$ based on all the $H_i$ 

**Important** Distinction
> $$1 - P(A \ | \ B) \neq P(A \ | \ \lnot B)$$

This is because we cannot be sure Events $A$ and $B$ **are** independent.