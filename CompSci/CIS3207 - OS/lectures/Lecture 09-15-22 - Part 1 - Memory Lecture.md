# Lecture 09 15 22

## Quiz Issues
1. Can a process be blocked on multiple events?
	+ The answer is **no**. The process is no longer running (*blocked*) from the *first* blocking event. It **cannot** have create more blocking events during this time. 
2. The PCB is created when the program loaded into memory, **not** when the program starts running. 
3. Waiting vs Ready
	+ Ready: *Waiting* for the CPU
	+ Waiting/Blocked: *Waiting* for an event to complete. 

 # Lecture
 ## Efficiency & Performance

> Hardware Issues that a Modern OS Relies On for Efficiency & Performance.

We have already talked about virtual memory and virtual addressing (Logical vs Physical Memory). 

As a process executes, the virtual addresses it operates with **must** be mapped to physical (real) addresses. This process is trivial if the physical addresses are mapped contiguously. If it is fragmented it will take a little bit longer with a different process.

This translation is the job of the **MMU**: *Memory Management Unit*.
![mmu.png](/img/mmu.png)

## Von Neumann Architecture
The primary computer memory that stores programs as they execute is “RAM” (implemented as DRAM - *volatile*)

- data and instructions are both stored as binary digits in memory
- data and instructions are both stored in primary memory
- instructions are fetched from memory one at a time and in order
- processor decodes and executes each instruction before fetching next
- cycle of fetching and executing continues until there are no more instructions left. 

## IO Activities

> Recall how we did not want to be *busy-waiting*

### Memory Mapped IO (MMIO)
Before it was programmed IO. Machine instructions to control devices (device registers, polling, ...).

MMIO: Treating Device registers as locations in the machine's address space. This removes the need for specific device machine instructions.

![MMIO](/img/MMIO.png)

The address space is not the same as memory, it is all the addressable space by the machine. For example, the disk portion is the address space for the disk which is not part of the machine. 

### Direct Memory Access
- devices can directly communicate without the use of programmed instructions to move the data

![DMA](/img/DMA.png)

CPU tells the disk to transfer some $X$ bytes to another disk. It will simply tell the disk to do it and leave after that. The disk will **complete** the task while communicating with each other. In this instance the CPU can go work on another tasks while the disks can do data transfer. 

'Bus-stealing' effects: Notice in the image above that while the disks are using the BUS the CPU cannot fetch from it. This is why caches are so important on the CPU itself, no bus is required to CPU fetch from caches.   


Continued: [[Lecture 09-15-22 - Part 2 - Intro to Scheduling]]