# Inclusion Exclusion Principle

**Statement**:
$$
\begin{align}
	\biggr| \ \bigcup_{i = 1}^n A_i \ \biggr| &= \sum_{i=1}^n \ | A_i| \ - \sum_{1 \leq i \lt j \leq n} \ | A_i \cap A_j | +  \sum_{1 \leq i \lt j \lt k \leq n} \ | A_i \cap A_j \cap A_k|
	\\
	&- \dotso + (-1)^{n+1}|A_1 \cap \dotso \cap A_n| 
\end{align}
$$

**Example:** $n = 3$
By the formula above:

$$
\begin{align}
	\biggr| \ \bigcup_{i = 1}^3 A_i \ \biggr| &= |A| + |B| + |C| - |A \cap B| - |B \cap C| - |A \cap C| + |A \cap B \cap C|
\end{align}
$$

The first step adds up all the elements in each set. Then we remove the ones seen in two sets. However there is a possibility that if a element is present in all three sets it is removed 3 times. Thus we add the union of all sets to recover this lost element.  








<!-- 
## **Inductive** Proof of the Inclusion Exclusion Principle
**Base Case** for $n = 2$
Notice $\biggr| \ \bigcup_{i = 2}^n X_i \ \biggr| = \sum_{x \in X_1 \cup X_2} 1$

See that:
$$
\begin{align}
	|X_1| + |X_2| &= \sum_{x \in X_1} 1 + \sum_{x \in X_2} 1 \\ \\
				  ^*&= \sum_{x \in X_1 - X_2} + \sum_{x \in X_1 \cap X_2} + \sum_{x \in X_2 - X_1} + \sum_{x \in X_1 \cap X_2}
				  \\ \\
				  &= |X_1 \cup X_2| + |X_1 \cap X_2| 
\end{align}
$$
-->
