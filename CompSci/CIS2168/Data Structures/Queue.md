# The Queue
The Queue is a [[Data Structure]] which follows the first in first out policy (FIFO) unlike the [[Stack]]. The `Queue` has the same operations as `Stack` but they occur in different places. A `Queue` deletes from the front and adds to the back where as the `Stack` would delete and add in the back. 

## Methods
![[QueueMethods.png]]
In short, `Offer` is the addition to the back & `poll` is the removal from the front. 

## Implementation 
Much like the [[Stack]], the Queue is better designed as a `LinkedList`, double or single. However there does exist an `Array` option.

### The Circular Array
The internal array will keep track of the Queue's elements with 2 index trackers: `int front` & `int rear`. While Size and Capacity will keep track of size limitations. 

When initialized:
$$
\begin{align}
\text{front} &= 0 \\
\text{rear} &= - 1
\end{align}
$$
**rear** starts at *-1* since if it started at *0* the rear would point to 1 when the first element is added but that element would be at index *0*

As we add elements `rear`, gets operated on like: 
$$\text{rear} = ( \text{rear} + 1) \ \% \text{ capacity}$$
and we increment size.

Here is a full `ArrayQueue`:

![[CirQueue1.png]]

Recall in an Queue, a remove operation is done to the head and thus when removal is called front is incremented by 1. Size is decremented by 1.

![[CirQueue2.png]]

Now if something were to be added it would overwrite index 0.

#### Reallocation 
What would occur if the array was full (size = capacity)? We need to move the elements to a new array with double the size. 

Here is the *procedure* to resize when the size is equal to the capacity of the array: 
1. Create a new array **double** the size
2. we need to loop from front to back which is exactly *size* elements. We can do this by doing $(\text{front}+k) \ \% \text{ size}$ while incrementing $k$ from 0 to size. 
$$\text{newArray}[k] = \text{oldArray}[(\text{front}+k) \ \% \text{ size}]$$
This will copy the elements in the correct order.
3. Fix up the new data about the array. 


## The Deque
The Deque is the culmination of a Stack & Queue. A Deque can Insert and Remove from any side.

Here is the Java Interface
![[Deque.png]]