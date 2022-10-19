# Condition Variables
+ Used for when a thread needs to check in a condition before executing instructions

Here is one method of doing this with **flags**:
```c
#include <stdio.h>
#include <pthread.h>

volatile int done = 0;

void* child(void* arg){
	printf("im child");
	done = 1;
	return NULL;
}

int main(int argc, char *argv[]){
	printf("im parent: starting");
	
	pthread_t c;
	pthread_create(&c, NULL, child, NULL);
	
	while(done == 0); //busy wait
	
	printf("im parent: ending")
		
}
```

Spin waits are wasting time here[^1].

## Definition and Routines

> A condition variable is an explicit queue that threads can put themselves on when some state of condition is not at a desired value. [OSTEP30](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-cv.pdf)

When the state of a condition changes a wakeup call is triggered to see if anyone's code can now proceed. 

### Declaration:
```c
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;
```

### Usage
Suppose we are waiting for done to change in value from 0. We can initiate a wait like this:

```c
//need a $while and not an $if
while (done == 0){
	Pthread_cond_wait(&c, &m)
}
```

If we do ever change `done` we can issue a change via[^2]:

```c
Pthread_cond_signal(&c);
```

***Why `wait()` needs a mutex parameter***
If we assume no mutex parameter it has no way of accessing the variable correctly due to it being volatile. Also, if we wait we want to **release** the lock to be used by other threads to do their work. The `wait()` will **atomically** unlock the mutex **and** put thread to sleep if called. 

***Why do we need `done` and why cant we jusy signal?***
If T2 waits on a condition from T1 and T1 signals while T2 is asleep it will be lost since T2 is not waiting on it (T1 ran first). Then when T2 runs it will *wait* forever.

## Producer/Consumer (Bounded Buffer) Problem
> This problem is presented in chapter $30.2$

Conditions:
1. 1+ Producers
2. 1+ Consumers
3. **1** **SHARED** Buffer

### Solution Attempt 1 - Single Producer/Consumer
```c
int loops;
cond_t cond;
mutex_t mutex;

void* producer(void* arg){
	int i;
	for(i = 0; i < loops; i++){
		if (count == 1){
			//buffer of size 1 is full
			Pthread_cond_wait(&cond, &mutex);
		}
		put(i);
		pthread_cond_signal(&cond);  
		pthread_mutex_unlock(&mutex);
	}
}

void *consumer(void *arg) {  
	int i;  
	for (i = 0; i < loops; i++) {  
		pthread_mutex_lock(&mutex); 

		if (count == 0) 
			pthread_cond_wait(&cond, &mutex);   

		int tmp = get();
		pthread_cond_signal(&cond);   
		pthread_mutex_unlock(&mutex); 
		printf("%d\n", tmp);  
	}  
}

```

With 1 producer and consumer the code works here. If we have more than 1 ... .

Firstly the *if* is a problem. 
Consider two consumers C1 and C2 with one producer P.

Suppose C1 runs:
1. gets the lock
2. checks if the buffer has any data to process
3. it has none $\implies$ time to sleep
	+ **Important**: It is placed on the queue to collect data once available. 

Then P runs:
1. Gets the lock
2. Produces
3. puts onto buffer via `put()`
	+	Signals that the buffer has been filled, C1 is put on ready state. 
4.	drops the lock

If now C2 runs[^3] and processes the new buffer value C1 will have an issue trying to also consume. 

#### Mesa semantics
Notice that while C1 was on ready but did not run the state of the program changed due to C2. Signaling a thread is a *hint* that the state has changed yet there is **no guarantee** that the state when the woken thread runs will **still** be desired. This is known as *Mesa semantics*.

Hoare semantics are the opposite. While harder to build they ensure any thread that is woken up is **ready** to run immediately. 

This is why we use `while` over `if` when checking the condition of a condition variable. While this is a general rule of thumb, this program still has an issue even when `if` $\to$ `while`.

#### The Issue
Suppose this is the state now:

| Thread | State |
| ------ | ----- |
| C1     | Sleep |
| C2     | Sleep |
| P      | Awake |

P will put data onto the buffer and go to sleep while signaling which will wake up C1 or C2, say C1. C1 will consume the new buffer value via `get()`. Since there are no more values to consume, it will signal and go to sleep. Who should wake up?

Both C2 and P are sleeping on the same `cond_t cond`. Suppose C2 wakes up. It will check the buffer is empty and sleep on the condition. Now everyone is asleep. 

We now learn that only opposite types should be able to wake each other up. 

### The Single Buffer Producer/Consumer Solution
We need to use two condition variables that are meant to signal producers and consumers separately. 

Here is how we can solve the issue:
```c
mutex_t mutex;
cond_t empty, fill;

void* producer(void* arg){
	int i;
	for(i = 0; i < loops; i++){
		pthread_mutex_lock(mutex);
		while(count == MAX) { pthread_cond_wait(&empty, &mutex); }
		
		put(i);
		pthread_cond_signal(&fill); //wake up A consumer from queue
		pthead_mutex_unlock(&mutex);
	}
}

void* consumer(void* arg){
	int i;
	for(i = 0; i < loops; i++){
		pthread_mutex_lock(mutex);
		while(count == 0) { pthread_cond_wait(&fill, &mutex); }
		
		int item = get();
		pthread_cond_signal(&empty); //wake up A producer from queue
		pthead_mutex_unlock(&mutex);
	}
}
```

Spurious wakeups - When a signal causes two threads to wake up.

## Extra: Covering Condition
Consider a multithreaded library that allocates and frees memory. 

Say that currently 0 bytes are free. T2 wants 100 bytes, T3 wants 10 and T4 just freed 20 bytes. We don't know the correct thread to wake up when T4 calls `free` since two threads both want memory. Well we know the correct thread is T3 but the scheduler may not wake up this thread.  The solution is when `free` is called, use `pthread_cond_broadcast()` over `pthread_cond_signal()` to wake up everyone.[^4]

[^1]: [[OSTEP 28 - Locks]]
[^2]: After changes be sure you unlock the variable to allow access for other threads.
[^3]: C2 can run because we have no idea what the scheduler will schedule.
[^4]: This is quite wasteful but required since we might wake up threads that do not meet the condition criterion.