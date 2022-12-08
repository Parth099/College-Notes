# Lecture 09-08-22
## Pre-Class Questions
A memory cell is just a series of bits. How can a CPU know if it is fetching the address or a data value. The answer is it does not, it assumes based on the context of the running program. The instruction does determine what the CPU will fetch, it uses the context of the instruction. The instruction tells the CPU what the next fetch will be, data or OP Code. 

# Lecture
Continuation from [[Lecture 09-06-22 - Interrupts Cont.]] with information about PSW and Priority Servicing. 

## Interrupt Priority Simplification
The OS controls Interrupt Servicing Priority at programmable levels in the CPU. 
- Software and CPU interrupts are requested at the **highest** priority
- Each device is assigned a **Fixed** priority for requesting interrupt servicing.

Interrupts are acknowledged by priority level relative to the CPU. The CPU has a floating number to determine which level to service; **synchronous** interrupts are serviced *first*. 

If Multiple Devices at the same Priority Level Request Service, the Device Closest to the CPU is Serviced. ("Daisy Chaining" from Lecture 09-06-22)

## Kernel vs. User Mode
- Places limits on accessible memory for non-kernel code.
	- Prevents user code from overwriting the kernel
- The timer allows the kernel to regain control of the CPU from *runaway* programs. 

### Mode Switch

> Below are examples for when the OS shifts from one mode to another. 

#### Kernel Mode to User Mode
+ Start New Process/Thread
	+ Jump to first instruction on program/thread 
+ `RTT/RTI`
	+ Resume suspended process
+ Context switch
	+ run a different process which is not the same as the one that was paused (Resume some other process)

#### User Mode to Kernel Mode
+ interrupt from a user process (or outside the CPU like a device depending on priority)
	+ Asynchronous - leads to device ISR
	+ Synchronous

### Privileged instructions
These can be anything that could interfere with the kernel's function and management.

Examples:

+ Change PSW register state
+ Access memory outside allocated bounds 
	+ See [[Lecture 10-20-22 - Intro to Memory Address Translation]] for a talk about bounds in memory
+ Send IO commands
+ Jump directly to kernel without a secure method

If a user executes a privileged instruction without kernel mode it will trigger an interrupt which will *deal* with he offending process. The offending Process is usually killed. 

## Process API
### Creation
Ways to create a new process:
1. Build a new empty process
2. Copy an existing process and edit relevant parts

#### Creation Method 1
+ Steps performed by the OS to create a new process
	+ Allocate Memory
		+ Load code, data into memory, create stack/heap
	+ create and initialize PCB
		+ so it can be switched on when CPU becomes available
	+ Put process state as ready

| Pros           | Cons                                                                  |
| -------------- | --------------------------------------------------------------------- |
| No Wasted work | Difficult to setup correctly and express all possible process args\*. |

\* -  *Windows* has 10 arguments for creating new process

#### Creation Method 2
Clone an existing process. 
+ `fork()` - clones the calling process
+ `exec(FILE)` - overwrites process code with the argument code

##### syscall - `fork()`
- Stop current process and save its state
- Make copy of all of its data (code, data, PCB)
- Add this new PCB to `ready` list

The `fork()` returns in the child **and** the parent however the values are different to distinguish parent and child. The child starts from wherever the `fork` was called.  

![fork](/img/fork.png)

The red blocks is the data from the **original** program while the blue represents the `fork`ed code. The blue arrow under fork represents the allocation of memory/resources for this new (`fork`ed) process

![fork_exe](/img/fork_exe.png)

When fork is invoked the child is a **exact** copy of the parent. Initially, all pages are shared between parent and child. This is done by copying the parent's page tables. The page tables are arrays of pointers to memory the process has to *deal* with. 

The memory is set to read-ONLY. If a parent or child needs to write to it, a copy of only that region of memory will be recopied so the they can modify it. Since we know that processes have regions of memory that only contain code we know that that section **will never** be written to, it allows the parent process and child process to share code if needed. This concept is called *copy on write*. Only what is needed to be written to needs to be copied. 



The Kernel makes COW (copy-on-write) read-only and page faults when a child or parent tries to write to it. The ISR for the page fault will duplicate this page and update page tables to the contents could be modified. 

##### syscall - `exec()`
- Executed after child starts, Replace current data and code segments with those in specified file

| Pros                                                                                                                         | Cons                                                                                                                                     |
| ---------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| Flexible, clean, simple; parent’s environment available. This means the child can access thinks like the parent's open files | Wasteful to copy a parent's code and then overwrite. All of this happens after the address space is allocated for this new child process |

