# Semaphores

> How can we use **Semaphores** instead of locks and condition variables.

## What is a `semaphore`?
A semaphore is a object with an integer we can manipulate with two routines:
1. `sem_wait()`
2. `sem_post()`

The initial value of the semaphore determines its behavior. 

**Sample Initialization**
```c
#include <semaphore.h>

sem_t s;
sem_init(&s, 0, 1); //initial value set to one (3rd arg)
//arg 2: val=0 means 's' will be shared over ALL threads
```

**Routines**:
```c
int sem_wait(sem_t *s){
	decrement value of s by 1
	if s < 0 -> wait()
}

int sem_post(sem_t *s){
	increment the value of s by 1
	if any thread is waiting -> wake ONE up
}
```

## Binary Semaphore

> This is when the semaphore is initialized to one. 

Notice a binary semaphore is just a lock.

```c
sem_t s;
sem_init(&s, 0, 1); 

sem_wait(&s);
//critical code
sem_post(&s);
```

Suppose a $T_0$ has the lock, this means that $s=0$ . If $T_1$ tries to enter the critical section via `sem_wait()` it will decrement $s$ to $s=-1$ . This will force $T_1$ to go back to sleep. When $T_0$ is done it will increment $s\to s=0$ allow $T_1$ to wake up and return from its `sem_wait()`. When $T_1$ is done it will `sem_post` and restore the value of $s\to s=1$ .

## Semaphores For Ordering

> Semaphores are also useful to order events in a concurrent program.

An example of an event to wait on is a list becoming empty. 

Here is a parent waiting for a child to be done:

```c
sem_t s;

void* child(void* arg){
	printf("child\n");
	sem_post(&s); //wake up parent
	return NULL;
}

int main(int argc, char** argv){
	sem_init(&s, 0, 0); //init s = 0
	printf("Parent START");
	
	pthread_t c;
	pthread_create(&c, NULL, child, NULL);
	sem_wait(&s); //sleep 
	
	printf("Parent END");
	return 0;
}
```

```c
"Parent START"
"child"
"Parent END"
```

Notice if we want things to wait on the semaphore it is required to be $0$ . This is quite similar to the condition variable pattern.

**IMPORTANT**: It does **not** matter which program runs first. 

If the child runs first it will increment $s$ to 1 and the parent will not `wait` on the semaphore. However, if the parent runs it will be put on the waiter queue which the child will help release. 

The initial value of the semaphore should be the number of resources you are able to give away **immediately** after initialization.

## The Producer/Consumer (Bounded Buffer) Problem (*again*)

Here are the get and set functions pertaining to the buffer.
```c
int buffer[MAX];  
int fill = 0;  
int use = 0;  
 
void put(int value) {  
	buffer[fill] = value;    // Line F1  
	fill = (fill + 1) % MAX; // Line F2  
}  
 
int get() {  
	int tmp = buffer[use];   // Line G1  
	use = (use + 1) % MAX;   // Line G2  
	return tmp;  
}
```

It is clear without any guards this will break itself. Thus, we only allow a buffer to be written to if it is **NOT** full and a buffer can only be consumed when it has at min 1 value. 

### Solution 1
```c
sem_t empty, full;

void* producer(void* arg){
	int i;
	for(i = 0; i < loops; i++){
		sem_wait(&empty);
		put(i);
		sem_post(&full);
	}
}

void* consumer(void* arg){
	int tmp = 0;
	while(tmp != -1){
		sem_wait(full);
		tmp = get();
		sem_post(&empty);
		printf("%d\n", tmp);
	}
}

int main(int argc, char* arg[]){
	//...
	sem_init(&empty, 0, MAX);
	sem_init(&full, 0, 0);
	//...
}
```

Consider $\text{MAX} = 1$ ,

If the consumer runs first it will wait on full as it will be decremented to $-1$ .
Now the producer has to run. It will wait on empty which will be decremented to $0$ but it will still run. It will "post up" allowing the consumer to run. 

Here one of two things can occur. If producer loops around, it will be waiting on empty ($\text{empty}=-1$).  Them the consumer will run and increment empty. The other possibility is producer being preempted and consumer running. This will **also increment** $\text{empty}$ which will allow producer to run. 

Notice that when $\text{MAX}=1$ , this solution works. 

Consider now $\text{MAX}=10$ and multiple consumers and producers. If we have two producers, a case may arise when they both fill the same buffer spot at the same time[^1].

### Solving the Race condition - 1
We can always add a mutex to allow only one thread into the CS[^2] at the same time.
Lets add a `sem_wait(&mutex)` before each block of CS. 

```c
sem_t empty, full, mutex;

void* producer(void* arg){
	int i;
	for(i = 0; i < loops; i++){
		sem_wait(&mutex);
		sem_wait(&empty);
		put(i);
		sem_post(&full);
		sem_post(&mutex);
	}
}

void* consumer(void* arg){
	int tmp = 0;
	while(tmp != -1){
		sem_wait(&mutex);		
		sem_wait(full);
		tmp = get();
		sem_post(&empty);
		sem_post(&mutex);
		printf("%d\n", tmp);
	}
}

```

This code produces a dead lock

Consider a producer $P$ and consumer $C$ .

If $C$ runs first it will acquire the lock and then be put in a waiting queue after calling `sem_wait(full)`. Now The producer will run but it **can never** acquire the lock. This means it can never add a value onto the buffer and increase `full`. Thus the consumer waits forever on `sem_wait(full)` and the producer waits forever on `sem_wait(mutex)`.

To solve the issue we just need to flip the order of signaling `empty` & `full` with mutex:

Producer Example:

```c
void* producer(void* arg){
	int i;
	for(i = 0; i < loops; i++){
		sem_wait(&empty);
		sem_wait(&mutex);
		put(i);
		sem_post(&mutex);		
		sem_post(&full);
	}
}
```

This way the lock does not **lock** the signals. 

## The Dining Philosophers Problem (DPP)

Setup:
+ 5 Philosophers
+ Next to them is a chopstick
+ 1 bowl of rice
+ Each Philosopher needs 2 chopsticks to eat rice
+ Each Philosopher has two states: *thinking*, *hungry*

![Dining_Philosopher_OSTEP](/img/Dining_Philosopher_OSTEP.png)

This is a synchronization problem since they complete for the chopsticks. 

Here is what each philosopher wants to do:
```python
while 1:
	think()
	get_BOTH_chopstick() #get forks()
	eat_rice()
	put_down_chopsticks() #put forks()
```

The challenge is to write functions:
+ `put_forks()`
+ `get_forks()`
such that no philosopher staves. 

### Solution 1
Suppose we have a `sem_t forks[5]`. Where `forks[i]=1` for all $i$ .

We can these functions
```c

int left (int p){ return p; }
int right(int p){ return p + 1 % 5; }

void get_forks(int p){
	sem_wait(&forks[left(p) ]);
	sem_wait(&forks[right(p)]);
}

void put_forks(int p){
	sem_post(&forks[left(p) ]);
	sem_post(&forks[right(p)]);
}
```

This causes a deadlock. Supposes everyone grabs a left fork. 

We need to ensure they get forks in a different order. This is discussed in [[Lecture 10-18-22 - Concurrency]]

## Thread Throttling - Admission Control
This helps us stop too many threads from doing the same thing. 

Suppose we have $N$ threads doing the same thing. Say one of the procedures is `malloc(M)` for a large $M$ .

We should ensure that not too many threads are in the same region here or else ...

To perform admission control we can `sem_init(&semaphore, 0, X)` where $X$ is the number of threads we want to be admissible in this region.

The we can have code like this:

```c
sem_wait(&semaphore); //block if thread_count in region > X
// memory-intensive region
// malloc(M)
// .. .. ..
// free(M)
sem_post(&semaphore); //wake up sleepers and allow them to enter region
```

## How To Implement Semaphores

OSTEP calls their implementation Zemaphores.

State Struct:
```c
typedef struct __Zem_t {  
	int value;  
	pthread_cond_t cond;  
	pthread_mutex_t lock;  
} Zem_t;
```

```c
void Zem_init(Zem_t *s, int value){
	s->value = value;
	Cond_init(&s -> cond);
	Mutex_init(&s -> lock);
} 

void Zem_wait(Zem_t *s) {  
	Mutex_lock(&s->lock);  
	while (s->value <= 0)  
		Cond_wait(&s->cond, &s->lock);  
	s->value--;  
	Mutex_unlock(&s->lock);  
}  
  
void Zem_post(Zem_t *s) {  
	Mutex_lock(&s->lock);  
	s->value++;  
	Cond_signal(&s->cond);  
	Mutex_unlock(&s->lock);  
}
```

[^1]: Race condition
[^2]: Critical Section