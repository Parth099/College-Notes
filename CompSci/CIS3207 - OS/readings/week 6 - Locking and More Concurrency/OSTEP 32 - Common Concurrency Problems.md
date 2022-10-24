# Common Concurrency Problems
## What Types Of Bugs Exist?
This question is too general and will be answered **quantitatively**.

A study[^1] analyzed popular applications and broke down the most popular bugs. We classify the into two categories. 

1. Non-Deadlock bugs
2. Deadlock Bugs

## **Non**-Deadlock Bugs

These bugs are the **most popular**. They **usually** arise from atomicity violation bugs and order violation bugs.

### Atomicity violation

***Definition***: "The desired serializability among multiple memory accesses is violated (i.e. a code region is intended to be atomic, but the atomicity is not enforced during execution)".

What this really says is that critical sections that are meant to be atomic are not. 

Example from OSTEP:
```c
//Thread 1:
if(thd->proc_info) {
	fputs(thd->proc_info, ...);
}

//Thread 2:
thd->proc_info = NULL;
```

The issue is that the `if` statement and the correspond write operation can be interrupted and when it is resumed, the value of `thd->proc_info` could be changed to `NULL`.

**Solution**: Use locks to make the critical section atomic. 

### Order-Violation

***Definition***: ""

Example from OSTEP:
```c
//Thread 1:
void init(){
	//create thread to run method below called mMain
	mThread = create_thread(mMain, ...);
}


//thread 2
void mMain(){
	struct thread_state* mState = mThread->state
}

//assume the main() launches these two threads
```

The issue here is that we assume $T_1$ will **always** run before $T_2$ .

We can fix this with either **condition variable/Mutex combo** *or* a **Semaphore** initialized to **0**.

## Deadlock Bugs
Deadlock bugs require a deeper understand of the software you write. 

The primary question here is:

> How should we build systems to prevent, avoid, or at least detect and recover from deadlock? Is this a real problem in systems today?

Deadlocks usually occur due to complex dependencies between components (think of the OS).

There is also the standard encapsulation[^2] design principle many developers go for.

Consider this method in java that adds the content of one list into another list.

To ensure the methods are thread-safe locks are acquired.

```java
Vector v1, v2;

//populate v1 and v2

//thread 1 ->
v1.AddAll(v2);

//thread 2 ->
v2.AddAll(v1);
```

This presents a clear deadlock which depends on how threads pick up the locks. However the developer will never know how this happened since the implementation for `AddAll` is hidden. 

### Conditions for Deadlock
There are four conditions for a deadlock to occur. 

1. Mutual Exclusion
	+ Threads claim exclusive control of the resources the need
2. Hold and wait
	+ Threads with mutex hold the resources instead of letting them go
3. No Preemption
	+ Resources that threads hold **cannot** be forcibly removed
4. Circular wait
	+ A thread $T_i$ is hold a resource that $T_j$ needs and $T_j$ holds something $T_i$ needs. This the case with two threads but it can happen for $n\geq2$ threads.

#### Prevention
##### Preventing Circular wait
There needs to be a **total ordering** in terms of lock acquisition. 
Suppose we have $2$ locks $L_1$ and $L_2$ . To avoid circular wait you need to acquire locks in the same order each time. This means we would need to acquire $L_1, L_2$ in order per thread. 

###### Partial Ordering
If there are too many locks and not all threads need them just ensure a ordering such as $L_k$ before $L_l$ before $\dotso$ .

###### Ordering TIP
We can always enforce an ordering based on the memory address of the locks. We can acquire locks based on the lowest address to the highest or the ordering. 

```c
if (m1 > m2) { // grab in high-to-low address order  
	pthread_mutex_lock(m1);  
	pthread_mutex_lock(m2);  
} 
else {  
	pthread_mutex_lock(m2);  
	pthread_mutex_lock(m1);  
}  
// Code assumes that m1 != m2 (not the same lock)
```

##### Hold-and-wait
```c
pthread_mutex_lock(prevention); // begin acquisition  
pthread_mutex_lock(L1);  
pthread_mutex_lock(L2);  
//CS  
pthread_mutex_unlock(prevention); // end
```

The `prevention` is sort of a mutex of mutexes. It will let the thread grab all the resources as soon as it has grabbed `lock:prevention` .

This approach works against code modularity as when calling a function we are required to know which locks are required to be held. This idea also decrease concurrency as we prep by acquiring locks before they are needed rather then *when* they are needed. 

##### No Preemption
In situations where we need two locks and we can unsure if we will cause we can use a `trylock` routine.

```c
//thread view

//loop the following to acquire L1 and L2
pthread_lock_mutex(&L1);
if (pthread_lock_trylock(&L2) != 0){
	pthread_unlock_mutex(&L1); //give the lock back
}
```

The `trylock` routine will lock if possible else return and report a failure to acquire the lock. 

Sadly this is susceptible to a **livelock** if two threads are running the above code at the same time. You can solve this by adding a random `sleep(X)` to give one of them time to acquire both locks. However that does not work when is involved and when more locks are involved. 

For example if after getting $L_1$ we `malloc` some memory and copy something to it we would need to free it if we **cannot** obtain $L_2$ .

##### Mutual Exclusion

> The final prevention technique would be to avoid the need for mutual exclusion at all.

We can build data structures with hardware instruction that allow us to discard locks. 

Recall the **atomic instruction** compare and swap. 
```c
int CompareAndSwap(int *address, int expected, int new) {  
	if (*address == expected) {  
		*address = new;  
		return 1; // success  
	}  
	return 0; // failure to update
}
```

We can employ compare and swap to increment a variable. 

```c
void AtomicIncrement(int *value, int amount){
	int old;
	do{
		old = *value;
	} while(CompareAndSwap(value, old, old + amount) == 0);
}
```

### Deadlock Avoidance via Scheduling
Sometimes avoidance is easier than prevention but requires great knowledge about the threads and the locks they will require.

Suppose we have 2 Locks and 4 Threads. 

We know what threads will acquire which locks:
```txt
Y = YES
N = NO
T = Thread
L = Lock

    T1    T2    T3    T4
L1  Y     Y     N     N
L2	Y     Y     Y     N
```

A smart scheduler will see that if it never schedules $T_1$ and $T_2$ at the same on the same CPU it will never deadlock. Notice $T_3$ only grabs one lock so we can put it on with any thread since once its done the other thread can acquire $L_2$ . 

### Detect and Recover
If a dead lock is very rare, ignore it. Also, many systems have a deadlock detector which will check for resource cycles[^3].

[^1]: The study: https://dl.acm.org/doi/10.1145/1346281.1346323
[^2]: encapsulation is the idea of hiding implementation designs
[^3]: Builds a resource graph first