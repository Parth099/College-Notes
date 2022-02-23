# Seq Identity Proof EX
> Show 
> $$(A\cup B)\cap(A \cup C) = A \cup (B \cap C)$$

Suppose $x\in(A\cup B)\cap(A \cup C)$
Then, $x\in(A\cup B)$ or $x\in(A\cup C)$ by definition of intersect. 

*Case* 1: $x\in A$
We are done since this means $A \cup (B \cap C)$

*Case* 2: $x\not\in A$ 
Since $x\not\in A$, yet $x \in (A\cup B)$, $x\in B$. By Similar logic $x \in C$. This implies $x \in B \cap C$.

Hence $x\in A \cup (B \cap C)$ and thus
$$(A\cup B)\cap(A \cup C) \subseteq A \cup (B \cap C)$$

Suppose $x \in A \cup (B \cap C)$
$x \in A$ or $x \in (B \cap C)$

*Case* 1: $x \in A$
Since $x \in A$, then $x \in A \cup B$ and $x \in A \cup C$ and thus $x \in (A\cup B)\cap(A \cup C)$

*Case* 2: $x \in B \cap C$
Then $x \in B$ and $x \in C$
This means that $x \in (B \cap A)$ and $x \in (B \cap C)$
thus: $x \in (A\cup B)\cap(A \cup C)$

Hence, $A \cup (B \cap C) \subseteq (A\cup B)\cap(A \cup C)$

Since $(A\cup B)\cap(A \cup C) \subseteq A \cup (B \cap C)$ and $A \cup (B \cap C) \subseteq (A\cup B)\cap(A \cup C)$, then
$$\boxed{A \cup (B \cap C) = (A\cup B)\cap(A \cup C)}$$

# Set Equality Proof 12.21.c
> Prove or disprove the following:
> 
> ![[s12p21_c.png]]

Attempt of proof its validity:
## Work
> Suppose $x \in (A \cup B) - C$

Then:
$$
\begin{align}
	x \in (A \cup B) - C &= \{x: x \in (A \cup B) \text{ and } x\not\in C\} \\
	&= \{x: x \in A \text{ or } x\in B \text{ and } x\not\in C\}
\end{align}
$$

> Suppose $x \in (A-C)\cap(B-C)$

Then:
$$
\begin{align}
	x \in (A-C)\cap(B-C) &= \{x : x\in(A-C) \text{ and } x\in(B-C)\}
\end{align}
$$
This expanded is equivalent to
$$
\{
x : 
(x \in A \text{ and } x\not\in C) 
\text{ and } 
(x \in B \text{ and } x\not\in C)
\}
$$
These do not seem logically equivalent.
We can try a proof via counter example.
### Counter Example
Suppose the following are the sets involved 
$$
\begin{align}
	A &= \{1, 2\}\\
	B &= \{3\}\\
	C &= \{1, 2\}
\end{align}
$$

On the left hand side:
$$
(A \cup B) - C = \{3\}
$$
On the right hand side:
$$
(A  - C) \cap (B - C) = \emptyset
$$

Since they are not equal for this example the aren't equal sets. 
%%Proof via Counter-example%%
