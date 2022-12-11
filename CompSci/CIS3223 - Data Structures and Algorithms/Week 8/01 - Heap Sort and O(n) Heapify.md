# Heap Sort (Max Heap)

Data Structure Notes on this: [[Heap]], [[Heap Sort]]

Consider the list of numbers:

$$
[3\ 7\ 11\ 5\ 4\ 13\ 16\ 12\ 29]
$$

## $O(n)$ Heapify
Place items in a binary tree. 

![heap_sort](../../../img/heap_sort_1.jpg)

By definition of a heap, any node with no children is a heap. 

Going from the last node to the first we get to a node eventually that is a parent of some other node, in this case that node is $\mathbf{5}$ .

The subheap rooted at $\mathbf{5}$ violates the definition of a heap and thus needs to be fixed. 

> 29 should be the root here. 

Notice that we can keep moving though nodes which are subheaps of height $1$ like how we did with $5$ until we get to node $7$ which is of height 2. 

By doing this process we have:
1. Started with leaf nodes that have a height of 0. They did not need to be fixed since by definition they are a valid heap. 
2. Next we moved on to the heaps of height $1$ and fixed those by floating the root downwards.
3. This process was repeated until we got to the root and floated it down as well.  

## Runtime Analysis
Notice that $\lceil n/2^{i+1} \rceil$ is the number of nodes at height $i$ given $n$ total nodes. 

**WHY?!**
It stems from the relation that each parent can have at most two children.  

Notice from the root, each level has at most the following number of nodes:

$$
1,\ 2,\ 4,\ 8,\ \dotso,\ 
$$

Also, 

$$
\sum_{i=0}^{n}{2^i} = 2^{n+1} - 1
$$

If we sum of the number of nodes from the first $n$ levels, we would get $2^{n+1} - 1$ . Now on the $n$-th level there were $2^n$ nodes, this means on the next level there were $2^{n+1}$ nodes which is larger one larger than the number of nodes above that level. 

What this means is that there are at most $n/2$ leaves on a binary tree. Which means $n/4$ subtrees of height 1.

The amount of work that needs to be done to *fix* a heap is directly proportional to height of the node. By summing over the work done in relation to all node heights we arrive at a $O(n)$ runtime for heapify.

## Example

![heap_sort](../../../img/heap_sort_1.jpg)

For the last 5 nodes there is no work to be done since they are already valid sub-heaps. 

The first change that needs to be made is swapping $5 \leftrightarrow 29$ as well as $11 \leftrightarrow 16$

![heap_sort](../../../img/heap_sort_2.jpg)

Next we consider all subheaps of height $2$ . There is only one, it is rooted at $\mathbf{7}$ .

![heap_sort](../../../img/heap_sort_3.jpg)


Finally the root is floated down. (the three) 
![heap_sort](../../../img/heap_sort_4.jpg)


## Heap Sort

Runtime: $O(n)\times \underbrace{O(\log{n})}_{\text{cost to float down root}}$

**Algorithm**:
```python
N = number of nodes
Arr = [0] * N

i = N

while i != 1:
	Arr[i] = remove_head_of_heap(H) # H is heap we built above
	i -= 1;
```

`remove_head_of_heap` is really just storing the value from the heap's head and replacing it with the right most leaf. This right most leaf is floated down. That is where the "cost float down root" comes from. 