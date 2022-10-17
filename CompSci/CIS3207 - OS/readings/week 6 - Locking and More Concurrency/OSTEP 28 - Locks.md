# Locks
> Basic of locks are known from lecture notes.

A lock or mutex is variable and thus can have internal data structures to maintain key information like which thread is the owner[^1] or the threads in the queue to acquire the lock. 

It is important to know that locks **do not** give a programmer any control in terms of scheduling, locks on ensure that no two threads are in the same critical section.

```c
lock_t mutex;

lock(mutex);
//critical code
unlock(mutex);
```

## `pthread` Locks

The `pthread` library provides mutual exclusion lock functionality between threads.

```c
//INITIALIZER (same as from prev chapter)
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;  
 
Pthread_mutex_lock(&lock); // wrapper; exits on failure  
//critical code
Pthread_mutex_unlock(&lock)
```

***Locking Strategies***:
- coarse-grained - one big lock
- fine-grained - many small locks (increased concurrency)

## Building Locks
Implementing locks will require OS **and** hardware support. 

## Evaluating Locks
1. Mutual Exclusion - How well does it provide mutual exclusion?
2. Fairness - Does each threading trying to acquire a lock get a fair chance?
3. Performance - How large are the time overheads?
	+ One thread overhead vs many threads overhead
	+ One CPU vs Multi-CPU 

## Lock Strategies
### Controlling Interrupts
One of the earlier attempts to build a lock was to disable interrupts. 
```c
void lock(){
	DisableInterrupts();
}

void unlock(){
	EnableInterrupts();
}
```

Technically the code in the CS[^2] will not be interrupted however this opens up so many new issues. For example we have to *trust* any threaded program is not malicious and we lose interrupts while locked. Also, this method **does not** work on systems where $\gt 1$ processors are present. 

### Flag Based Locks
The idea here is that we use a boolean variable to tell if a lock is locked. 

Here is basic code for this idea:
```c
typedef struct __lock_t { int flag; } lock_t;

//on init lock is free 
void init(lock_t *mutex) {  
	// 0 -> lock is available, 1 -> held  
	mutex->flag = 0;  
}

void lock(lock_t *L){
	//1 means lock, so if locked just sit inside while loop
	while(L->flag == 1);
	
	//(A)
	
	//if managed to exit while loop now take the lock!
	L->flag = 1;
}

//trivial
void unlock(lock_t *L){
	L->flag = 0;
}
```

Here are a few reasons why this **will not** work:
1. Any thread that wants the lock will **spin wait**[^3]
2. Does not provide mutex. 
	+ Imagine a thread being interrupted at point $(A).$ We know the status of the lock is $0$ so the next thread sets the lock to $1$. When the old thread is ready to run it resumes at $(A)$ and sets the lock to $1$ and runs its code. Now two thread own the lock. :(

### Test-And-Set - Spin Lock
This builds on hardware support for locks in the form of a atomic instruction[^4]. 

Here is a test and set instruction (atomic exchange) in ***C*** since I dont know assembly:

```c
int Test_and_set(int *old_ptr, int new){
	int old = *old_ptr; //store old value
	*old_ptr = new; //load new value into old
	return old; 
}
```

Here is how `Test_and_set` can help with locking. 

```c
typedef struct __lock_t{
	int flag;
} lock_t;

void init(lock_t* L){
	L->flag = 0;
}

void lock(lock_t* L){
	//spin wait
	while(Test_and_set(&L->flag, 1) == 1);
}

void unlock(lock_t *L){
	L->flag = 0;
}
```

See that in one **uninterruptible** action the lock value will be updated and returned. Thus, we can capture the lock without being interrupted. 

If no thread holds the lock it returns $0$ which, on the next cycle will be set to one by a another waiting thread. 

### Evaluating Spin Locks
1. correctness ✅
2. Fairness ❌ 
	+ Not each thread is **guaranteed** to be put on 
3. Performance 	❌
	+ Two words: Spin Lock[^5]

### Compare-And-Swap - Spin Lock
This is another hardware primitive.

The idea here is to compare the value at an address and if its equal to the expected value, update it and return the old value:

```c
int Compare_and_swap(int *ptr, int expected, int new){
	int old_val = *ptr;
	if(old_val == expected){
		*ptr = new;
	}
	return old_val;
}

void lock(lock_t* L){
	while(Compare_and_swap(&L->flag, 0, 1);
}
```

This is the same as `Test_and_set` but with a different atomic operation. 

### Spinning and `yield()`
Each of the hardware primitives utilizes spin locks which waste CPU time. 

We can yield the CPU if the current thread on CPU is a thread that needs critical section access yet will not get it since the lock is held by another CPU. 

```c
void lock(lock_t* L){
	//spin wait
	while(Test_and_set(&L->flag, 1) == 1){
		yield(); //give up the CPU
	}
}
```

A call to `yield()` will move a thread from a **running** state to **ready**. Yielding is still in terms of CPU context switching overheads. Consider 100 threads trying to acquire a lock while one of them has it. When the one that has it is preempted, the 99 will be switched on[^6] but they will just yield since they cant really run. 

### Addressing Fairness - Using Queues
Our previous implementations leave everything up to the scheduler as the scheduler may put on a thread that will just spin. 

We will use two syscalls here:
1. `park()` - put a thread to sleep
2. `unpark(T_ID)` - wake up thread based on its ID

Each thread that wanted the lock is put on a queue and woken up based on availability **and** not woken up before hand.  This idea is more complicated but is not covered in this class.

#### Priority Inversion
Consider the following threads using **spin-locks**:

1. T1 - Low Priority
	+ Given its **low priority** T2 will always run over T1
2. T2 - High Priority

If T2 is ever blocked (maybe IO related) T1 will run. If T1 obtains the lock and some time later T2 is unlocked the system will freeze. Since T1 will be descheduled now that T2 is done, T2 will never be able to obtain the lock. 

To solve this a "knowing OS" can boost lower priority thread to overcome this *inversion*.



[^1]: A thread is known as the **owner** of a lock *if* is holds the lock currently. 
[^2]: Critical Section
[^3]: Busy Waiting, bad for performance metric
[^4]: During 
[^5]: Spinning on a multi-processor system is not so bad if the number of threads is less then or equal to the number of processors. 
[^6]: 