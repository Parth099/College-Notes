# Threads

The following API is made available via:

```c
#include <pthread.h>
```

Creation is covered in [[OSTEP - 26 Concurrency]] and the parameter names are quite accurate on what that parameter requires. 

## Completion
To wait for a thread to complete use:

```c
int pthread_join(pthread_t thread, void **value_ptr);
```

`thread` is the thread pointer captured from the creation call. `value_ptr` serves to capture the return value of the thread pointed by `thread`. It needs to be a pointer to a pointer since the `pthread_join` routine will need to change it. 

### Example - Sending arguments and receiving return values

```c
/*
	this code is from 
	Operating Systems: Three Easy Pieces
	Figure 27.2
*/
typedef struct { int a; int b; } myarg_t;  
typedef struct { int x; int y; } myret_t;  
 
void *mythread(void *arg) {  
	myret_t *rvals = Malloc(sizeof(myret_t));  
	rvals->x = 1;  
	rvals->y = 2;  
	return (void *) rvals;  
}  
  
int main(int argc, char *argv[]) {  
	pthread_t p;  
	myret_t *rvals;  
	myarg_t args = { 10, 20 };  
	Pthread_create(&p, NULL, mythread, &args);  
	Pthread_join(p, (void **) &rvals);  
	printf("returned %d %d\n", rvals->x, rvals->y);  
	free(rvals);  
	return 0;  
}
```

 This examples shows how to return *multiple* values from a thread. However, there is an important detail hidden here about returning values from threads. 

You **cannot** return a value that is stored on the thread's call stack. 

## Locks 
+ Provide mutual exclusion to critical sections.

Most operations can be down with these two:
```c
int pthread_mutex_lock(pthread_mutex_t *mutex);  
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```

### Sample (Broken) Code

Here is what your code with these would look like:
```c
pthread_mutex_t lock; //creation of lock
// uncritical code ...

pthread_mutex_lock(&lock);
// BEGIN Critical Routine
	
// ENDED Critical Routine
pthread_mutex_unlock(&lock);
	
// uncritical code ...
```

The way this works that if no other thread is locking the `lock` variable **currently**, the access is granted to enter the critical section. **If** another thread **is holding** the lock, the call **will not return** until the lock is released. 

The reason why this is broken is because the `lock` needs to be initialized. 

Method 1:
```c
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
```

Method 2:
```c
int rc = pthread_mutex_init(&lock, NULL);  
assert(rc == 0); // always check success!
```

> Locks should be destroyed when not needed with  `pthread mutex destroy()`

## Condition Variables
- Used for signaling
	- This is when we need to inform one thread of an event
	- Example: Allow a thread to continue only after another thread is finished

Programs that want to interact in this way need a lock and a conditional var. 

Here are the two main routines associated with conditional variables. 
```c
int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);  
int pthread_cond_signal(pthread_cond_t *cond);
```

Much like *mutex* we have two ways to initialize the condition variables.   

Consider the code:

In main:
```c
//ALL of these are global
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;  
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
ready = 0;

//launch threads
```

Thread $1:$ 
```c
Pthread_mutex_lock(&lock);  
while (ready == 2)  
	Pthread_cond_wait(&cond, &lock);  
Pthread_mutex_unlock(&lock);
```

Thread $2:$
```c
Pthread_mutex_lock(&lock);  
ready += 1;  
Pthread_cond_signal(&cond);  
Pthread_mutex_unlock(&lock);
```

Here is what happens here.

When thread 1 starts it will lock and check if the variable it needs is meets the sufficient condition (`ready == 0`) to move forward with the code. Since it is not it will be put to sleep via `pthread_cond_wait` and the lock will be released[^1]. 

When we step back into thread 2 and set ready to be 1 we signal the other thread **that the value of ready has changed**. The signaling is not to make thread 1 move forward but to ask thread 1 to check its conditions. This will occur until thread 2 sets `ready` to 2. 



[^1]: This is why it needs access to the mutex. Imagine if it did not, it would wait for a condition to change where the variable could never change since it would **always** be locked. The `wait()` function unlocks the mutex and then waits. When a signal is received, it will return from the wait after acquiring the lock *again*.  