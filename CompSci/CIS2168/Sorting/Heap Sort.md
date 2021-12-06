[[Sorting]]

# Heap Sort

## Description
Heap Sort is based on the Heap *Data-Structure*, specifically the **Max** heap. 
A naive approach to this problem would be to first load all array elements into a Min/Max heap and then remove off the top of the heap. Depending on the insert direction into the new $output$ array. This can order the array in either descending or ascending. 

Heap Sort consists of 2 parts: 
1. Build Heap 
2. Shrink Heap

### Build Heap
The **first** step is the build the heap. The word transform here is better since we are modifying the input array. They way this is done is at first we consider the first element. The heap property is fulfilled up-to index $1$, not including thus far. Now we consider index $1$. If this element is greater than the parent element then it is exchanged until the heap property is fulfilled. 

#### Array Child/Parent Calculations 
In an array-based heap each index represents the $i^{\text{th}}$ node in a tree which is tree that is reversed in level order*. 

$$
\text{parent}_i = \frac{\text{child - 1}}{2}
$$
$$
\text{child}_L = \text{parent}_i * 2
$$
$$
\text{child}_R = \text{parent}_i * 2 + 1
$$

The $-1$ for parent calculation exists to make sure integer div produces the correct index for parent.   

Level order traversal is named in a named in a manner that exposes its description.  

#### Build Heap Code
```java
public static <T extends Comparable<T>> void heapify(T[] table){  
    int n = 1; //since by definition a single element heap is a heap  
 	while(n < table.length) {  
        int child = n;  
 		int parent = (child - 1) / 2;  
 		while(parent >= 0 && table[parent].compareTo(table[child]) < 0){  
            swap(table, child, parent);  
 			child = parent;  
 			parent = (child - 1) / 2;  
 		}  
        n++;  
 	}
}
```
##### Code Comments
Notice in $\text{heapify}()$ elements will only need to be moved up and never down and thus we only need to get parent's index.

### Shrink Heap
The Shrink heap is where the heap from **build heap** is turned into a sorted array.
The first step is to take the first element from the built heap and swap it with the element in the back. Now array$[n-1, n]$ is sorted where $n$ is the size of the array. 

The array$[0, n-1]$ needs to be reheaped and the swapping can happen again. So the element at array$[n-1]$ is swapped with array$[0]$ and the heap reformatted, the element is floated down to its correct position. 

These 2 processes occur until the array is full sorted.

#### Shrink Code

```java
public static <T extends Comparable<T>> void shrinkHeap(T[] table){  
    int n = table.length;  
 	while(n > 0){  
		n--;  
		swap(table, 0, n); //pushes largest element to the backend pos  
		int parent = 0;  
		while(true){  
			int left = parent * 2 + 1;  
			if(left >= n){  
					break;  
			}  
			int right = left + 1;  
			int maxChild = left;  
			if(right < n && table[right].compareTo(table[left]) > 0){  
				maxChild = right;  
			}  
			if(table[parent].compareTo(table[maxChild]) < 0){  
				swap(table, parent, maxChild);  
				parent = maxChild;  
			}  
			else{  
				break; //heap is restored  
			}  
		}  
    }  
}
```

##### Code Analysis
The shrink-Heap shrinks a heap by moving the highest element $[0]$ to the back of the array $[n - k]$. Now the process is simple, after the swap from the back the heap property is not fulfilled. So we need to float the top back down since the rest is a heap$^{\alpha}$. This element is floated down in the internal *while* loop. Its children index are calculated and sees if a swap is necessary. If swapping is need the loop goes on, else the control is passed back to the main while loop which swaps from the back which starts the cycle again. 

The cycle occurs until the heap is of size one at which point the array **will** be sorted.



---
**${\alpha}$**: This matters since only one element is out of heap order, once this element is in order this will be a heap again from index *0* to *n - k* where *k* is iteration count starting at 0. 