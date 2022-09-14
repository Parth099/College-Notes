# Lecture 09-13-22
## `wait()` syscall

Recall at the end of the fork we have two ongoing processes that are **identical**:
1. parent
2. child

Here is where the programs are forked:
```c
int pid = fork(); 
```

In the child process, `pid=0` while the parent `pid` is equal to the **child's PID**. We can use this to branch logic based on parent and child. 

Recall our issue of what is printing in what order. We saw that forked calls are *non deterministic*.

The `wait` call pauses the parent **until** the child finishes.

```c
int wc = wait(NULL);
//more code ..
```
The `NULL` refers to the first child and the value inside of `wc` is the exit status of the child. After the child finishes, `//mode code` is run. We can also wait on based on `pid` with:
```c
pid_t wait(pid_t pid);
```

## Termination
A process can perform voluntary termination with `exit(status)`. Then the exit value is passed with wait: `wait(&status)`. 

**Zombie Process**:
PCB exists in OS but the process is not executing. This is used for the parent to read the child's exit status. 

Once the parent reads status, zombie entries removed from the OS, this is called reaping the child. 

If we do not read the status, 
- Memory leak: Zombie will continue to exist
- These are found by reaper processes
	- When a parent terminates, `init` adopts all zombies and reaps them. This is done for clean up. 

## Process API
+ Create
	+ `fork`
	+ Load program into memory (maybe be performed lazily)
	+ Then the runtime stack is allocated
		+ stack is used for local variables, function param, return addresses
		+ initialize stack with args: `argv, argc`
	+ Allocate Heap
		+ used for dynamically allocated data
		+ Ex: `malloc`, `free`
	+ IO Setup
		+ Each process by default has three open file descriptors
		+ stdio, stdout, error
	+ **START** the program via an entry point like `main`
		+ transfers control of the program to the CPU
+ Destroy
	+ `kill`
+ Wait
	+ `wait`
	+ `waitpid`
+ Miscellaneous Control 
	+ `pause()`

![fork_syscall_diag](/img/fork_syscall_diag.png)

## `exec()` syscall
![exec_syscall_diag](/img/exec_syscall_diag.png)

There are many versions of the `exec` function. Each has its own variation and purpose. 

If we fork and exec we notice that the PCB is already set up by the parent which implies the file that were opened by the parent apply to the new code that is running. 

We can apply `wait()` on a `exec()` child (see slides for 9/13/22) and the parent will **wait** for the `exec`ed program to finish. 

## Using `exec`
1. Use one source ode that includes the code for each process

```c
int main(...){
	//code above
	int pid = fork();
	if(pid == 0){
		child1();
	}
	else{
		int pid1 = fork();
		if(pid1 == 0){
			child2()
		}
	}
	//code below
}
```

2. Writing code for children in separate files: Multi-process Program

```c
int main(){
	//code above
	
	int pid = fork();
	if(pid == 0){
		exec(child1);
	}
	else{
		int pid1 = fork();
		if(pid1 == 0){
			exec(child2);
		}
	}
	
	//code below
}
```

## How the shell works
+ In a basic OS, the `init` process is created after the hardware is initialized
+ the `init` process spawns a shell such as a bash
	+ this is done because the OS wants to make its operations available to the user.
+ shell reads a command, forks a child and execs the command executable. It will wait for it to finish and then it will read the next command

## CPU Switching
![CPU_switching_diag](/img/CPU_switching_diag.png)

## Virtual Address Space
MMU - Memory mamanegment unit
