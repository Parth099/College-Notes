# Kruskal's Algorithm
1. Take all the edges are place them intro buckets WRT their weight $w$
	+ For example, all edges of $w = 1$ are put in the same bucket
2. Sort each bucket. 
	+ For example. $BE$ would come before $CD$
	+ This step is optional. It only exists to unify all graphs into one answer.
3. Create a `UnionByRank` data structure.
4. Starting from the bucket with the lowest weight attempt to add edges until a tree is created[^1]
	+ Only add an edge if it does not trigger a cycle. That is when $\pi(u) \neq \pi(v)$ when adding an edge $e$ that connects $u$ and $v$ . 
	+ The $\pi(e)$ function is from the  `UnionByRank` data structure. It determines connectivity between $u, v$ .
		+ $\pi(a) = \pi(b) \implies a, b \text{ connected}$

## Runtime

$$
O(|E|\log |E|)
$$

This is because the edges must be sorted. 

[^1]: You know to stop when you have added $|V|-1$ edges. 