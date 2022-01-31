# Independent Events
## Definition
An Event $E$ is independent from Event $F$ and vice-versa if
$$P(F|E) = P(F) \text{ and } P(E|F) = P(E)$$
or if any one of them has probability 0

## Theorem
> Two events $E$ and $F$ are Independent iff
> $$P(E \cap F) = P(E)\times P(F)$$

## Examples
### Example A
> Suppose we have a coin who shows up heads at probability $p$ and tails $q$. 

> Now say it is tossed two times. The outcome $(H, H)$ has the probability $p^2$ and the outcome $(H, T)$ is $pq$.

> Let $E$ be the event that the first toss is heads and $F$ the event that tails turns up on the second toss. 

Lets see if the events are independent. 



$$
\begin{align*}
E &= \{HH, HT\} \\
F &= \{HT, TT\} \\
\\
P(E) &= p^2 + pq = p(p+q) &= p\\
P(F) &= pq + q^2          &= q\\
\\
P(E\cap F) &= P({HT}) &= pq \\
& &=P(E)P(F)
\end{align*}
$$
They are.

### Example B
Let $A$ be the event "Heads on the first toss" and $B$ the event "two outcomes are the same"

Lets see if they are independent
$$
P(B|A) = \frac{P(B \cap A)}{P(A)} = \frac{P(\{HH\})}{P(\{HH, HT\})} = \frac{1/4}{1/2} = \frac{1}{2} = P(B)
$$
Since $P(B|A) = P(B) \implies$ they are independent

### Example C 
Let $I$ be the event "heads on the first toss" and $J$ the event "two heads turn up"

$P(I) = \frac{1}{2}$, $P(J) = \frac{1}{4}$
$$I \cap J = \{HH\}, \ P(I \cap J) = \frac{1}{4}$$
$P(I \cap J) \neq P(I)P(J) \implies$ **NOT** independent.

All this to say that its hard to determine whats dependent and whats not. 

## Extension to $n$ Sets
> Definition of  ***mutually independent***