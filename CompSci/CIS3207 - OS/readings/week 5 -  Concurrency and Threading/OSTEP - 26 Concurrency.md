# Introduction to Concurrency 
A **multi-threaded** program has multiple points of execution. This means that it has many PCs[^1] running at the same time. Each point of execution is like its own process **but** shares the total address space and by extension its variables. 

The state of a **thread** is similar to a process:
+ PC
+ Private Registers 

Similar to a process and a PCB, there exists a TCB (*Thread Control block*) to control thread context-switches. Unlike a process however, the address space does not need to be changed.

Threads also change how the stack of the program is laid out. **There is a stack per thread** to maintain its internal routines. Each thread needs its **own** stack to allocate its own variables, when allocated they will be placed in the **thread-local** stack. 

![mt_stack](/img/mt_stack.png)

## Why use Threads over Processes?
1. Parallelization of the same process
2. Avoid blocking program progress due to slow I/O. While one thread may the blocked on IO, another thread can be switched on. 

The fact that threads **share** an address space and process **do not**, make (1) and (2) easier to accomplish with threads. 

## Thread Creation
Much like processes it is impossible to predict *when* a thread will be ran. 

Creation:
```c
int pthread_create(pthread_t *thread, 
                   const pthread_attr_t *attr,
                   void *(*start_routine)(void*), 
                   void *arg);
```

Waiting to finish:
```c
int pthread_join(pthread_t thread, void **retval);
```

## Shared Data
The synopsis here is that threads can change global (or shared) variables in an unpredictable manner (comes up anytime threads do).

Suppose we had a program that updated a counter `2e7` times via threads where each thread shares the counter yet only performs `1e7` of the additions. When this is run the counter is not at `2e7` due to race conditions and how/where threads can be preempted. The solution here is atomic operations that cannot be interrupted. Assuming we are on a uni-processor, a single atomic operation for adding a number **and** saving it to memory could solve this issue. 

This solution might seem great for now but we cannot invent *singular*-instructions for each operation. 

## Waiting
While accessing shared data is one form of interaction there is also another: waiting for thread $X$ to finish its own to start off thread $Y$ . This is another problem that needs to be solved.



[^1]: Program Counter