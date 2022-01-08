# The Heap
The Heap is an 'ordered' [[Data Structure]] with only 1 rule. For now we will think of a Heap as one of the [[Trees]]. In this course there exists only the **Min**-Heap or the **Max**-heap. In this Note the focus will be on the **Min**-heap, the max is the same just with the word *min* replaced with *max*.


# The **Min**-Heap
## "Tree"-Idea
The rule of a Min-Heap is such that the root $R$ of the tree is the smallest its children, and the tree as a whole can be defined as a **Complete**-Tree [[Trees]]. This rule applies to its subtrees: $T_L, T_R$ as well.

*Note*: This will not create a [[Binary Search Tree]] 

An Example of a Min-heap:
![[MinHeap1.png]]

Notice that the smallest element is at the root position hence the name: ***Min***-Heap. Any consideration of a subtree $S$, its direct children are smaller.

## Insertion

Consider the heap: ![[MinHeapInsert1.png]]

Insertion into a Heap starts at the right-most position of the tree to ensure the **Complete** property. This element is then floated up to ensure the **Heap** property. If we insert *8* into the heap above it will start as the left child of 66. Since 8 is lesser than 66, they are swapped. Now 8 is the parent of 66. 8 is smaller than 29 and thus will be swapped. 
In the end we have: ![[MinHeapInsert2.png]]

## Removal

We can reduce this problem to a insertion problem. To ensure **Completeness** we replace the node we need to delete with the right-most node on the lowest-level. Now we just float by replacing it with the least element from below while its possible. 

## Implementation
The Heap can be implemented as a Tree as defined above but we can achieve better speeds with an `ArrayList`. All we need is an internal ArrayList and an size counter. 

Notice this heap from above: 
![[MinHeapInsert2.png]]
Can be represented as the array: 
$$
[6, 18, 8, 20, 28, 39, 29, 37, 26, 76, 32, 74, 89, 66]
$$
This is know as the **Level-Order** Traversal of a Tree.
We can make some observations here about Array to Tree index calculations: 
$$
\begin{align}
\text{parent}_i &= \frac{\text{child}_i - 1}{2} \\
\text{child}_L &= \text{parent}_i * 2 \\ 
\text{child}_R &= \text{parent}_i * 2 + 1 \\
\end{align}
$$

The subscript $i$ is shorthand for index.

With these index observations an Array-based Heap can be created easily since we only need to implement Add/Remove. 

### Runtime

| Action | **Heap** Performance |
| ------ | ------------------- |
| Add    | $O(\log{n})$        |
| Remove | $O(\log{n})$        |
| Find   | $O(n)$              |


