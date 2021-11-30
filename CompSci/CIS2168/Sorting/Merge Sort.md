# Merge Sort

[[Sorting]]

Merge Sort is a recursive O($n\log{n}$) sorting algorithm made up of 2 parts:
1. Merge
2. Binary Split 


## Part 1: Merge

Marge is the more simple part to understand.
The merge procedure takes in 2 sorted *arrays* and outputs a new list which is fully sorted. 

### Merge Code

```java
private static <T extends Comparable<T>> void merge(T[] out,T[] left, T[] right) {

 int i = 0;  
 int j = 0;  
 int k = 0;  
 while(i < left.length && j < right.length){  
        if(left[i].compareTo(right[j]) < 0){  
            out[k++] = left[i++];  
 		}  
        else{  
            out[k++] = right[j++];  
 		}  
 }  
 while(i < left.length){  
 	out[k++] = left[i++];  
 }  
 while (j < right.length){  
	out[k++] = right[j++];  
 }  
}
```
*The extra while loops are for arrays that don't mix at the same rate*


## The recursive Split

The MergeSort Algo:

1. Split The array into Halves
2. Sort Left
3. Sort Right
4. **Merge** Left and Right

Now the Split only occurs when the $size$ of the array is over 1. Otherwise the trace ends and the $Merge()$ Calls begin to occur. 

### Split Code:
```java
private static <T extends Comparable<T>> void sort(T[] in){  
    if(in.length > 1){  
        int half = in.length / 2;  
		 T[] L = (T[])new Comparable[half];  
		 T[] R = (T[])new Comparable[in.length - half];  

		 for(int i = 0; i < half; i++){  
			L[i] = in[i];  
		 }  
		for(int j = 0; j < in.length - half; j++){  
			R[j] = in[half+j];  
		 }  
		sort(L);  
		sort(R);  
		merge(in, L, R);  
 	}  
}
```
We can also use in place of explicit for loops. 
```java
System.arraycopy(Object src, int srcPos, Object dest, int destPos, int length);
```

#### Code Analysis 
We notice the split of the $in: \text{List}[T]$ into 2 *subarrays*. Then the content of $in: \text{List}[T]$ is reflect in $L, R$

Then 
$$\text{sort}(L)\circlearrowleft$$
$$\text{sort}(R)\circlearrowleft$$
are called. We can assume for now that this effectively sorts the arrays $L$ and $R$.
Notice that $\text{merge}(in, L, R)$ uses $in$ as the output target. This means that the sorted marge is then sorted in the $in$ array. This means that $in$ which is the initial caller keeps the results of that level(recursive) of sort.


### Why its Linearithmic 
Firstly it takes $\log(n)$ calls to sort to break the subarray parts to Size: 0 or 1 to start calling $\text{merge}(\dotso)$. Then the split of the arrays and merge is always $O(n)$, and since $O(n)+O(n) \in O(n)$. The whole sort procedure is Linearithmic. 

$$\boxed{O(n\log{n})}$$
