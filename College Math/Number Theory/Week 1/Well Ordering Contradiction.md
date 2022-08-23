# Well Ordering Contradiction Proof

> Show that $\sqrt{3}$ is irrational

Let $S = \{k\sqrt{3} : k, k\sqrt{3} \in \mathbb{Z}_{\geq 1}\}$
Assume $S\neq\emptyset$. Given that $S\subseteq\mathbb{Z}_{\geq 1}$, $S$ has a minimum element (*well ordering principle*) $s$.

(!) we assume this because if it was rational there would exists another number s.t when multiplied $\sqrt{3}$ would result in an integer*

Then, $s = t\sqrt{3}$ for $t \in \mathbb{Z}^+$

Then, $s\sqrt{3} - s = s\sqrt{3} - t\sqrt{3} = [s-t]\sqrt{3}$

However, $s\sqrt{3} = t\sqrt{3}\sqrt{3} = 3t$
Notice that $3t - s = \sqrt{3}s - \sqrt{3}t = [s-t]\sqrt{3}$

See that $[s-t]\sqrt{3} \in \mathbb{Z}^+$ as $s - t = t\sqrt{3} - t = t(\sqrt{3} - 1) > 0$

However, $s\sqrt{3} - s = s(\sqrt{3} - 1) \lt s$ as $\sqrt{3} - 1 \lt 1$

This contradicts the fact that $s$ is the smallest element. 