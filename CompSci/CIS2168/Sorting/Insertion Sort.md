[[Sorting]]

# Insertion Sort
Insertion Sort is one of the O($n^2$) sorting algorithms that will be discussed here.

## Description: 
Insertion Sort starts at index $\#1$ and ends at $n$, the length of the array.

If $i$ is the current level of iteration then the **array** starting from $0$ to $i$ is **sorted** only with respect with the elements seen. The rest of the array is in any state, usually unsorted. 

If we are examining  an element $e$ we need to find the correct place to insert. So to do this we keep looking back to find a place to insert it. If the element behind it is greater than it, they are swapped. This occurs until an array boundary like $0$ is hit or $e$ is larger than the element behind it.

Ex:
![[InsertionSortIMG1.png.png]]

## Code

```java
private static <T> void swap(T[] Table, int i, int j){  
    T temp = Table[i];  
	 Table[i] = Table[j];  
	 Table[j] = temp;  
}  
  
public static <T extends Comparable> void InsertionSort(T[] table){  
    for(int pos = 1; pos < table.length; pos++){  
 		int BKcounter = pos;  
 		while(BKcounter > 0){ //avoids table[-1] call  
 			if(table[BKcounter - 1].compareTo(table[BKcounter]) > 0){  
                swap(table, BKcounter-1, BKcounter);  //the sorting part
 			}  
            else{  
                break; 
 			}  
            BKcounter--;  
 		}  
    }  
}
```
