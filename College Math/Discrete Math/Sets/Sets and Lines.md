# Sets
## Sets \& Lines
Suppose we have a regular line like:
![[set_line.png]]
We can describe the set of points on this Line $L$ as
$$
\begin{align*}
L &= \{(x, y) : y = mx+b\} \\
L &= \{(x, y) : ax+by = c\} \\
\end{align*}
$$
### Vector Formation
Recall the vector equation of a line from [[Equations of Lines and Planes]].
Given two points of the line we can form the parametric equation.  

Let there be two points on the line $(x, y)$ and $(x_0, y_0)$. We will call these $P$ and $Q$
Then
$$
\begin{align*}
\langle x, y \rangle - \langle x_0, y_0 \rangle &= \langle a, b \rangle \\
\langle x, y \rangle &= \langle a, b \rangle + \langle x_0, y_0 \rangle \\
\langle x, y \rangle &= \langle a+x_0, b+y_0 \rangle

\end{align*}
$$

We can draw then entire like with a parameter $t$, $t\in \mathbb{R}$
$$\vec{PQ} = \langle x_0+ta, y_0+tb \rangle$$

### Example
Prove $A = B$ for
$$
\begin{align*}
	A &= \{(x, y)\in\mathbb{R}^2: y=3x+2\}\\
	B &= \{(t-1, 3t-1):t\in\mathbb{R}^2\}
\end{align*}
$$

Suppose $(x, y)\in B$. Then
$$
\begin{align*}
	x &= t-1 \\
	y &= 3t-1
\end{align*}
$$
for $t\in\mathbb{R}$
We know that in Set A, $y = 3n+2$ for $n\in\mathbb{R}$
$$3n+2 = 3(n-1) + 2 = 3m-1 = y$$
Hence $B \subseteq A$

Suppose $(x, y)\in A$. Then $(x, y)\in\mathbb{R}^2$, 
Let $t = x + 1$, then  $t\in\mathbb{R}$ and $x = t-1$
Since $y = 3x+2$ for elements in $A$ and $x = t-1$, 
$$y = 3(t-1)+2 = 3t-1$$

Hence $A \subseteq B$.

Since $A \subseteq B$ **and** $B \subseteq A$, $A = B$

## Set Operations, Cardinality and The Power Set
### Cardinality
> **Cardinality**
> The number of elements in a Set $S$.

The vertical bars is the Cardinality notation

#### Example
> Find $|B|$ if 
> $$B = \{n\in\mathbb{N} = n\leq 100 \text{ and } 3\nmid n\}$$

See that there exists a $100$ numbers in $\mathbb{N}$ such that $n\leq100$. 

This means that 
$$|B| = 100 - |\{n\in\mathbb{N} = n\leq 100 \text{ and } 3| n\}|$$

$|\{n\in\mathbb{N} = n\leq 100 \text{ and } 3| n\}|$ is much easier to compute. The smallest multiple of $3$ is $3$ and the largest is $99$. This means there is $33$ multiples of $3$ between 1 and 100.

$$|B| = 100 - 33 = \boxed{67}$$

### Power Set
Let $S$ be a set.
This is a **set** of all the subsets of $S$.
#### Examples
##### Ex - 1
$A = \emptyset$
$\mathbb{P}(A) = {\emptyset}$
##### Ex 2
$A = \{1\}$
$\mathbb{P}(A) = \{\emptyset, \{1\}\}$

##### Ex - 3
$A = \{1, 2\}$
$\mathbb{P}(A) = \{\emptyset, \{1\}, \{2\}, \{1, 2\}\}$

See that $|\mathbb{P}(A)| = 2^{|A|}$

> **Notation**
> Often times instead of $\mathbb{P}(A)$ we write $2^A$. This is $2$ raised to the power of a set.


### Set Operations
Set union / intersect are trivial
#### Set Minus
$A - B = \{n \in A \text{ and } n\not\in B\}$
> **Notice**
> $$A - B \neq B - A$$
##### Example
$$
\begin{align*}
	A &= \{c, o, n, e, p, t, s\}\\
	B &= \{b, a, s, i, c\}\\
	
	\\
	
	A - B &= \{o, n, e, p, t\}\\
	B - A &= \{b, a, i\}
\end{align*}
$$
## *Some* Set Operational Properties
1) $A \subseteq A \cup B$, same applies for $B$
2) $A \cap B \subset A$ and $A \cap B \subset B$
3) $A \cap (B \cap C) =  (A \cap B) \cap C$ same applies for set union $\cup$
4) $A - B = A - (A \cup B)$

### Proofs for $IV$
Suppose $x\in A-B$. Then by definition $x \in A \text{ and } x\not\in B$
Since $x\not\in B$ then $x \not \in A\cup B$

This is because $x \not \in A\cup B$ is a subset of $B$, hence if $x\not\in B$ then by extension $x \not \in A\cup B$
Since $x\in A$ and $x \not \in A\cup B$ we see that 
$$A - B \subseteq A - (A \cup B)$$

Suppose $x\in A - (A \cup B)$, Then $x\in A$ and $x \not \in A\cup B$

Since $x \not \in A\cup B$, $x \not \in B$
This is because if $x \in A$ and yet $A$ shares no common elements with $B$ then $x\not\in B$
Hence $A - (A \cup B) \subseteq A-B$

Since $A - (A \cup B) \subseteq A-B$ **and** $A - B \subseteq A - (A \cup B)$, 
$$\boxed{A - B = A - (A \cup B)}$$