# The Graph
The Graph is one of the more complex [[Data Structure]]. A Graph consists of a set of Edges and Vertices both of which are **finite**.
$$G = (E, V)$$
The Set of Vertices is just a set of nodes that the edges can span a connection from.

The Set of Edges is a set of connections from an element from $V$ to another element in $V$. The 2 elements can be the same. 
$$E \subset V \times V$$
$V \times V$ is the Cartesian product.

Notice [[Trees]] are just a minimally connected Graph. Trees are just a subset of Graphs. 

## Directness
The set $E$ can be directed or not. If it is then the connection $(a, b) \in E$ describes a connection from Vertex A to Vertex and not back. If its not directed then $(a, b)$ shows a connection from A to B and B to A.

Example of a Graph and its Isomorphism
![[Graph1.png]]

## Vocab
1. Path: Sequence of Vertices that describe a traversals from 
Node X to Node Y.   
2. *Simple* Path: A path without repeated edges or vertices.
3. Cycle: A path with the same Start and End node.

