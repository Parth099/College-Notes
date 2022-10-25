# Mechanism: Limited Direct Execution
> How to efficiently virtualize the CPU **with** control.

This will be done with the combination of software and hardware.

## Limited Direct Execution (LDE)
#  Direct Execution
To run a process it a is loaded into memory, entered into the queue, and then ran directly on the CPU. 

![direct_exe](/img/direct_exe.png)

Image above shows the steps in Direct Execution. 

This protocol presents a serious problem. How can we ensure the program does not do anything we do not want it to do. Moreover, how can we use Direct Execution with time sharing. 

> Without limits the OS would just be a library to interface with the hardware. 

### Restricted Operations
A process must be able to make operations like IO without it having **complete** control over the system. 

To do this we introduce modes. One mode, the `user mode`, is when the processor runs in restrictive mode. In this mode we cannot issue IO otherwise the processor would raise an exception. The other mode is `kernel mode`, it has no restrictions, this is the mode the OS runs on. 

If a user process wants to commit restricted operations it will need to make a system call. These are exposed calls to allow a process to do things like IO.  

### `trap` instruction
To execute a system call, a program must execute a special `trap` instruction. This instruction jumps into the kernel and changes the privilege mode to kernel mode. Once in the kernel the *system* can commit any operation it needs to. When finished, the OS calls a `return-from-trap` instruction which returns the processor to user modes and hands back control to the original process. 

The hardware needs to be careful when executing a `trap`. It needs to make sure that the context of the caller program is saved so when the process is returned it can resume. On `x86`, the processor will push the PC, flags and some other registers on a per-process `kernel` stack; the `return-from-trap` will pop off these values to resume tasks. 

**How does the OS know what to execute while in `trap`**?

The kernel does this by setting up a `trap-table` at boot time. During boot, the machine is in kernel mode. Thus, it is free to make any calls it needs to configure the machine for use. It sets up code to run when certain events occur such as hardware interrupts (keyboard, disk) or when a process makes a system call. Note modifying trap tables is a `kernel mode` operation. 

The OS informs the hardware about the location of these trap handlers. Once informed the hardware will 'remember' where they are and thus what code to jump to when a interrupt is made.  

To specify the exact system call, a system-call number is assigned to each system call. The user code is then required to place the system call number onto the stack or in a register to call it. The user code asks for a service from the OS using a number instead of asking to jump code. 

## Switching between Processes
When a program is running, see that the OS is not running. If the OS is not running, how can it stop this process and handle the process switch? 

> How can the OS regain control of the CPU after handing it off to a process to run?

### Cooperative Approach: Waiting for system calls
In this process the OS assumes the any program will *behave* and give the control of the CPU back to the OS all on its own. Eventually it will need to make a system call and when a `trap` instruction is hit the OS will regain control. In systems like this there exists a `yield` instruction to pass control back. Also, if a program makes an illegal operation (div by 0 or access a illegal memory location), a trap will be generated and the OS will wake up. 

### Non-Cooperative Approach: The OS Takes Control
Notice the **Cooperative Approach** is prone to takeover. The Non-Cooperative Approach makes it so the OS will take back the processor after a certain event (timeout). A timer interrupt solves this issue, when it times out the pre-configured interrupt handler for a timeout is called which switches the control back to the CPU. 

> The OS kills all offending processes (process making illegal operations)

Note this time can be paused for a privileged operation. 

The hardware has some responsibility when an interrupt occurs, it has the job of saving some state of the program so that a interrupt can be handled and the program can resume.

It is important to know that a preemptive scheduling algorithm makes a scheduling decision to choose a process for the CPU whenever a new process arrives in the Ready queue. This is because a new process may have higher priority than the currently running process and thus could preempt the current process.


### Saving and restoring context
Assume that the OS has gained control it now must decide which process to run now. This decision is made by the schedule. If a **different** process needs to run a **context-switch** needs to made, it is low level code. The CPU context is restored on to the CPU (maybe from the kernel stack). However before the state is restored the context from the previous process is saved. Thus, when the `return-from-trap` instruction is executed the correct chosen process can run. 

**Saving Context**:
To save context the OS will execute low level assembly code to save the general purpose registers, PC, and the kernel stack pointer of the running process.  

## Concurrency
> What happens when while handling a interrupt another one is made?

One of the options here is to disable interrupts while we handle them. However this can lead to lost interrupts. We will see later how locking systems can help with concurrent access and multiprocessing. 


## Supplemental Information
### System Call
![syscall](/img/syscall.png)

+ Process in **user-mode** executes a system call `S()` which requests a service from the OS. 
+ Execution transfers to the library function `S()`
+ `S` sets up parameters for the service and executes the supervisor call instruction (`TRAP`). 
+ Execution is **transferred** to the kernel function which executes in kernel mode. 
+ The kernel function completes the requested service and then the execution returns to `S`, the system call. 
+ `S` finishes the request and returns to the application which executes the next execution. 