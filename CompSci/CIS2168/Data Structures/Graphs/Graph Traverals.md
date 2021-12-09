# Graph Traversals

This [[Graph]] will be taken as our Sample Graph. 
![[GraphTrav.png]]
## Breath-First-Search
In BFS we start at a given node $S$ and then we BFS all those Adj to $S$. BFS visits all nodes with Shortest path $k$ before any node of path length $k+1$.

### Algorithm
Unlike the [[3 Basic Tree Traversals]], Graphs have no *start* node. We must at random choose one. We utilize a [[Queue]] here.


```
Initialize a Queue Q.
We start at an arbitrary node S.
Add S to Q
while Q is not Empty:
	u = Q.poll()
	for each v in adj(u):
		if v is NOT visited or identified:
			Q.offer(v)
			MARK v as identified
	MARK u as visited 	
```

A BFS of the Graph above with $S$ = *0*:
$$
[0, 1, 3, 2, 4, 6, 7, 8, 9, 5]
$$
Its just one possibility. 

Note that identification can be done via a HashMap, or an Array if the entries are integers. 

# Depth-First-Search
In DFS, the traversal goes all the way down a path and then backs up to reach new nodes. 

In DFS each node is in one of states:
1. Visited
2. Not visited

We can a [[Stack]] here. The Stack allows us to *back up* if no new nodes can be visited from the current node. 

## Algorithm
```python
def DFS(G, v):
    label v as discovered**
    for all v to w in G.adj(v):
        if vertex w is not labeled as discovered then
            recursively call DFS(G, w)
			
From: Wikipedia
```
Note that if the graph nodes are integer based, the discovery list** can be a `boolean` array. 
### Analysis:
We start by marking the *init* node as visited and then call DFS on its **direct** neighbors. Notice that the call returns once all nodes from an initial call were already visited. 

![[DFS.png]]

Lets call DFS on this graph with *innit* node as 0.
0 calls Node 1, Node 1 calls 3, 3 calls 4. Now the call handling returns to the frame where $v = 0$. Its last option is to call on node 2. Node 2 calls 5 which calls 6. This ends the DFS. 

A visit order: 
$$[0, 1, 3, 4, 2, 5, 6]$$