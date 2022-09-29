# Lecture 09-27-22 - Concurrency Cont.
## What do `threads` share ⁉
### DOES SHARE:
1. **PID**
2. Address Space
	+ Code
	+ Most data (heap)
3. Open File Descriptors
4. Signals and Signal handlers
5. Current Working Directory
6. UID/GID

### Each thread has its own:
1. T*hread* ID (TID)
2. Sets of registers + PC + SP
3. Stack for local vars and return addresses
4. Signal Mask

## OS Support for Threads
1. User Level Threads
2. Kernel Level Threads
3. Hybrid of (1) and (2)

### User Level Thread
+ Threads can be implemented completely within a user application
+ A *thread library* provides thread CURD operations.
+ Kernel is not aware of threading
+ Process is treated as single threaded for scheduling
+ Thread level context switch is provided by the library

![ULT](/img/ULT.png)

Notice in (b) the process is blocked. This is because a thread cannot it self commit IO tasks. It does IO tasks by using a library. Therefore the kernel sets the process's state to blocked when one of its threads calls for IO.  

After the IO is done, **B** shifts back to complete and thus is *ready* to run on the CPU. The states of the threads are the same. 

***Note***: A thread *running* does not mean it is executing. Also, a thread is not blocked from an IO request but the parent process will. 

### Kernel Level Thread
+ Threads are implemented within the OS Kernel
+ Kernel provides CRUD for threads
+ Thread Switching is done by Kernel too

Notice the overhead with Kernel `TRAP`s. You do not need to switch to kernel mode. 


## Combined Approach
The kernel supports a small number of KLTs.
Each app can implement any number of ULTs which are mapped to KLTs. 

![hybrid_KLT_ULT](/img/hybrid_KLT_ULT.png)

## Pros/Cons
### Pros - ULT
1. no switching overhead 
2. OS agnostic
3. Customize scheduling

### Cons - ULT
1. IO call from *any* thread will block process and block all threads
2. With **pure ULT** there is **no** real multiprocessing

### Pros - KLT
1. Schedule many threads from same process
2. If one thread is blocked in a process we can schedule another thread from same process
3. kernel routines can be MT

### Cons - KLT
1. Time to CRUD threads due to kernel mode and management
