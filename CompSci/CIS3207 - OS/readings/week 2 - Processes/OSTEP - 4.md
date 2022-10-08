# The Process

A process is a **running program**. When it is not running, it is *lifeless*. It just sits in the disk, taking up space. It is the OS that reads these bits and gives the program life. 

It is usually the case we want to run $\gt 1$ programs simultaneously. However, this is what the challenge is:

> How can we run many processes on **one CPU** ⁉️
> How to provide the illusion of many CPUs on a system with few or one CPU?

Running many processes is what it means to **virtualize** the CPU. One way to do it is with time sharing, defined in [[Lecture 08-25-22]]. The downside is that the slower the system is, the more processes exist. 

> 📖 **mechanism**: A mechanism is a low-level method that implements a needed piece of functionality. An example of a mechanism is the time-sharing mechanism; most modern OSs employ it. 

> 📖 **Policy**: A policy is a method of high-level intelligence. Policies are algorithms that help make decisions in the OS. An example of this is a scheduling policy. This policy allows the OS to choose what program to run at what time based on program history (who ran last?).

A mechanism is an answer to *how* an OS does something, while a policy is an answer to *when/which*. 

## Process State
To understand the process state, we must understand the machine state. 

> 📝 **Machine State**: What can this program read/write when running? What parts of the machine are essential during the execution of a program? 

One of these components is **memory**. The memory that a program can address is called its **address space**. Another component is the **registers**. The instructions held in the registers are also important to execution. Some programs may also access IO devices. 

Important Registers:
+ Program Counter
+ Stack Pointer - points to top/bottom of a stack 
	+ frame pointer - points to the current frame

## Process API

API functions used to control processes:
1. Create
2. Destroy
3. Wait - wait for the process to stop
4. Miscellaneous Control - suspend for a bit and continue later
5. Status

### Process Creation
Firstly, all the program code and static data is loaded into memory and address space. The OS will read the executable format file and place the bits into memory. 

There are two ways to load a program. 
+ Loading the entire program into memory 
+ Lazy Loading

Once the program is loaded, memory must be allocated for its runtime stack and heap. While the heap may start small, the OS will give it more memory (if possible) as more memory is requested. The OS will also set up IO, which has three open **file descriptors** open by default: 
1. stdin
2. stdout
3. error

Once the OS has completed all this setup, it can call `main`. Jumping to the main function is a mechanism. 

## Process States
A process is in any three states at once:
![process states](img/process_states_1.png)

+ Ready: The program is *ready* to run but is not started yet
+ Running
+ Blocked: The process requires an operation to be completed which makes it not ready to run until it is completed. An example of a blocking operation is IO.


![state_example](img/state_example.png)
Notice that many policies are in effect here. Who to run when each process is ready and deciding if making one process wait is a good idea.  

## Data Structures
Like any other software, the OS has many data structures to help it keep track of data. For example, some process list exists per process state (list of ready processes, list of blocked processes, ...). 

A register context will hold, for a stopped process, the contents of its registers. When a process is stopped, this context data is *saved* in memory. The process is restored by restoring this context (placing these contents back into the physical registers). This is known as *context-switching*. 

Recall **Process Control Block (PCB)** from [[Lecture 08-25-22]], which stores information about a process. 

> 📝 **Note**: more states exist than the three above. Some other ones are: `initial`, `final` (aka `zombie`). 