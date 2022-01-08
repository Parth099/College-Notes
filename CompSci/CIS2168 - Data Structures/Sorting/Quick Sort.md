# Quick Sort
[[Sorting]]

Quick sort is another recursive algorithm for sorting in $O(n\log{n})$ time. It has two subprocesses.

1. Find a **pivot** and Partition WRT that **pivot** 
2. QuickSort to the left and right side of that **pivot**

For now the pivot can be thought of as just a *special* entry in the array.

## Partition WRT a selected Pivot
For this class we will not use the median of threes method of selecting a pivot but instead we will simple use the rightmost entry as our pivot. Coding when the pivot is the last entry is easier, but not by much.

$$\text{Pivot} = \text{array}[n - 1]$$
$n$ is the length of the array. 

Let ***P*** be our pivot. Note that this is the actual number and not the index.

So we select a pivot which we now know as the last entry in the array and put it in a position where all the elements that are smaller than ***P*** are to the left of it, and the larger to the right. We can see that now no matter how the sorting proceeds ***P*** is in the correct spot.

The Partition is created with swaps. One pointer starts from the left and one from the right. When left pointer reaches a value larger than ***P*** and the right sees one larger than ***P***, the two values are swapped. In the end of this procedure ***P*** is swapped with the right pointer, because larger elements will reside to the right anyways.

### Code
```java
private static <T extends Comparable<T>> int partition(T[] table, int L, int R) {  
    T Pivot = table[R];  
	int up = L; //to be swapped forward  
	int down = R; //to be swapped backward  
  
 	while(up < down){ //once they cross swaps are useless  
 		while((up < down) && (table[up].compareTo(Pivot) < 0)){  
            up++;  
 		}  
        while((down > -1) && (table[down].compareTo(Pivot) >= 0)){  
            down--;  
 		}  
        if(up < down){  
            swap(table, up, down);  
 		}  
    }  
    swap(table, up, R);  
	return up; 
}
```

#### Code Analysis 
The block:
```java
while((up < down) && (table[up].compareTo(Pivot) < 0)){  
	up++;  
} 
```
finds the first element to float/swap up. It passes over elements that are on the right *side* and finds the first out of place element. The 2nd block does the same thing but for elements that need to floated down.

## QuickSorting Left and Right

```java
public static <T extends Comparable<T>> void quickSort(T[] table, int L, int R){  
    if(L < R){  
		int P = partition(table, L, R);  
		quickSort(table, L, P - 1);  
		quickSort(table, P+1, R);  
	}
}
```

Puts ***P*** in the right place and sorts to the left and right of it. 
