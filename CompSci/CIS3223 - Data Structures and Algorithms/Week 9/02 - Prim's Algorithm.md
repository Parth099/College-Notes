# Prim's Algorithm

1. Pick a starting Node and create an empty heap $H$ (min-heap)
2. Add all edges to heap $H$
3. Select smallest edge $e$ from $H$ to travel to. If $e$ creates a cycle in the graph[^1], discard this edge and select a new one. 
	+ Heap removal cost: $O(\log{|V|})$
4. Repeat $(2), (3)$ until all nodes are added to the [[00 - Preface about Min Spanning Trees and Shortest Path Algos]]

## Runtime

Same reasons as [[02 - Dijkstra's Shortest Path Algorithm]]

$$
O\biggr(|E| \log{ |V| }\biggr) = O\biggr((|E|+|V|)\log{ |V| }\biggr)
$$

[^1]: It is easy to tell if an a new edge will trigger a cycle or not. If the edge does not introduce at least one new vertex it is connecting two existing edges it might be creating a cycle. It could be the case that separate networks are forming, in this case a deeper look is needed.   