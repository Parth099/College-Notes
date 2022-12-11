# Strongly Connected Components

> When we have to make a decision about what node to pick next (or initially) choose alphabetically

## Definition
Strongly Connected Components are sets of nodes in a graph such that in a component each node can access any other node. 

## Algorithm
1. Perform DFS with Pre and Post Numbers
2. Reorder the vertices by descending post numbers. Let this ordering be $V_1$
3. Perform DFS on $G^R = (V_1,\ E^R)$
	+ $G^R$ is the reverse graph
	+ Each time there are no more node accessible restart the DFS process from unused nodes in the ordering $V_1$ .

