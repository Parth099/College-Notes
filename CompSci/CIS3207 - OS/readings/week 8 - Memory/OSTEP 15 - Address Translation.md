# Address Translation
**Limited Direct Execution (LDE)** - Letting the program run on the hardware however at key points[^1] the OS will get involved to ensure smooth sailing.

Notice in this ideal the OS gets out of the way of the running process yet maintains control of its resources. We want to meet these same challenges in designing a virtual memory[^2]. 

> How can we build an efficient virtualization of memory? How do we provide the flexibility needed by applications? How do we maintain control over which memory locations an application can access, and thus ensure that application memory accesses are properly restricted? How do we do all of this efficiently? These are all questions the next few chapters will answer

## Hardware-Based Address Translation
In this scheme hardware changes a virtual address[^3] to a physical address[^4]. Each instruction will be *translated*. Moreover the OS must also manage memory (determine free and used space, allocate/deallocate, ...).

## Initial Assumptions
+ User's address space must be contiguously placed into memory. 
+ Address space for some process is not larger than the possible memory
+ Each address space is the same size

## Relocation
![reloc_addr.png](/img/reloc_addr.png)

The process however thinks it **owns** the 16KB and starts its address space at 0. 

The space it is wasting inside its address space is called internal fragmentation. 

### Dynamic (Hardware Based) Relocation

> AKA **base and bounds**

We will have two registers:
1. base register
2. limit register (*bounds* register)

This allows us to place a process anywhere in memory and give it the illusion that it has its own memory. When a program is loaded it gets a base address `base`. 

When an instruction is fetched, the translation is in the form:
```c
PHYSICAL_ADDR = VIRT_ADDR + base //iff VIRT_ADDR + base < LIMIT
```

If an instruction asks to fetch at byte 128 and has a base of $32KB$ we are really fetching at 32896. The limit register helps keep a *bound* on the accessible memory by the program. If a program access memory outside of its *limit*, a CPU exception[^5] is raised.  

These registers are one per chip, they are often called the Memory Management Unit (MMU).

***Hardware Support***:

Notice the instructions to modify the base/limit registers **must** be privileged[^6]. Moreover we need the CPU to be able to throw exception on a memory violation as well as an exception handler. 

## Operating System Issues for Base/Bound Address Translation

1. The OS must find an free slot to give to a process. This is obtained through the OS's free list data structure. 
2. The OS must also do the clean up when a process is terminated. 
3. The base and bound registers **must** be maintained upon a context switch. Thus, the registers must be saved in some PCB.
4. OS must provide ISRs[^7] for CPU memory violation exceptions
	+ The most likely policy is termination of offender program.

Relocation of process is quite easy *if they are paused*[^8]. The OS has to find a new free space and just update the registers. Due to the virtualization of memory in the process, it has no idea it has been moved. 


[^1]: System Calls, interrupts, timer ...
[^2]: This design gets complex soon 
[^3]: Used by the process
[^4]: The literal address on the memory
[^5]: More on exceptions: [[8.1 - Exceptions]]
[^6]: Only possible in only in kernel mode
[^7]: [[Lecture 09-06-22 - Interrupts Cont.]] about ISR and Interrupt Service Vectors
[^8]: Process cannot be blocked if you want to move it in memory. 