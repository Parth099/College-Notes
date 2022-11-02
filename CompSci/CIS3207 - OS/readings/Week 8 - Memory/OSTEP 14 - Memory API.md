# Memory API

Chapter address:
1. How to allocate and manage memory
2. Mistakes to avoid

> Details about `malloc()`[^1], `free()` are not present here. 

> Both `malloc()` and `free()` are library calls not system calls. This is because the `malloc` library manages space within your virtual address space, but itself is built  on top of some system calls which call into the OS to ask for more memory or release some back to the system.


## Types Of Memory
### Stack
First is the stack or automatic memory which is allocated[^2] by the compiler. 

Stack memory use:
```c
void f(){
	int x = 3; //use of stack memory
	//...
}
```

After we return from `f()` the all the stack memory used by `f` is deallocated. If any information needs to persist after function ends it cannot live on the stack. 

### Heap
Unlike the stack allocations and deallocations both managed by **YOU**.

Heap memory use:
```c
void f() {  
	int *x = (int *) malloc(sizeof(int));  
	//...  
}
```

Note: The pointer variable `x` **does** live on the stack. 

Aside from `malloc`, the following functions are also useful. 
1. `calloc` - zeros out the memory region
2. `realloc` - reallocates the memory region to change its size and copies over old region. 

### Swap Space
We can use `mmap()` to allocate an anonymous memory region within a program. This memory is from the OS but can be managed like a stack or heap. This is not important now but will be explored later. 


## Why no memory is leaked once your process exits
Assume we write a program with a few `malloc` calls but no `free()` calls.

Notice that firstly memory is managed by the OS. This means that when the process ends it will clear the entire block of memory managed by the process. 

However for longer lived programs leaking memory can be fatal. For example suppose the OS leaked memory[^3] or a web server leaked memory per request.  



[^1]: In some cases the `malloc` call pads your allocation allow some room for errors. 
[^2]: allocations and deallocations both managed by compiler
[^3]: It would take over the entire address space