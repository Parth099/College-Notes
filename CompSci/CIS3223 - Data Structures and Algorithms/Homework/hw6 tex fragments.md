# Hw6
## 1.a

Consider the **base case** of a single node (*the root*) with no edges. This is trivially a tree. 
+ $|V|=1$ (1 node)
+ $|E|=0$ (no edges)

Since $|E| = |V|-1 = 1-1=0$ the base case with $|V|=1$ is satisfied. 

Consider a tree with two nodes. Since one edge is required to connect two nodes, $|E|=1,\ |V|=2$ and again the property $|E| = |V| -1=2-1=1$ is satisfied. 

**Inductive Step**: Consider a tree with $k$ nodes. Then $|V|=k$ and $|E|=k-1$ .

Then to get to $|V|=k+1$ we must add to an node. Since trees are fully connected this node must be adjoined to the *graph*. Thus at least $1$ edge has to be added to the tree. However if more than one edge is added this will create a cycle since each of the nodes connected can visit each other. Therefore $\mathbf{1}$ edge has to be added. Thus $|E|+1= k-1+1=k$ .

Using Principle of Mathematical Induction a tree with $|V|$ nodes requires $|E|-1$ edges. 

$$
\implies \boxed{ |E| = |V|-1 }
$$

## 1.b
Let suppose there are $k$ trees in the forest.

If $k$ is zero then there are zero edges and nodes and the property still holds since $|V|-|E|=0$

As shown in **(1.a)** a tree with $n$ nodes has $n-1$ edges. Therefore each tree has one more vertex than edge.

Then for each tree $i:$
- $|V_i|$ - number of vertices in tree $i$
- $|E_i|$ - number of edges in tree $i$ 

$$
\implies |V_i| - |E_i| = 1
$$

Since there exist no connections between trees we can add up this quantity

$$
\begin{align}
\sum_{i=1}^k |V_i| - |E_i| = \sum_{i=1}^k 1 = k
\end{align}
$$

However, 

$$
\begin{align}
\sum_{i=1}^k |V_i| - |E_i| = \sum_{i=1}^k |V_i| - \sum_{i=1}^k |E_i| = |V| - |E|
\end{align}
$$

Since the sums are equivalent, $\boxed{|V| - |E|=k}$ 