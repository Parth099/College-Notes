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