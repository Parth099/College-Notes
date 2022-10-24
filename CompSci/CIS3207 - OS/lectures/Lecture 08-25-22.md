# 08 25 22
The **OS** is an extended machine.
- no longer do devs need to fully understand machine architecture
- provides efficient high level functions

## The OS as a Resource Manager
The OS has the following responsibility.
- ensure good performance
	- low response times
	- safe communication between tasks

### Program Behavior
A program alternates between two states. 
1. IO (Input/Output)
2. COMPUTING

During an IO phase of a program the CPU is idle. This is an area of improvement. Parallelization can improve the overall performance of all the apps. The OS strives to keep all of its resources utilized by **overlapping independent operations when possible**. 

### Multi-Programming
#### Sequential
Technique that keeps saved programs in memory and switches between them. This style of programming runs a program from start to finish before starting a new one. 

#### MultiProgramming
This allows programs to run **on the CPU** when other programs are doing IO based tasks. This allows for two or more tasks to exist at the same time by switching to a *ready* task when the current task is going to be doing IO related tasks. 

#### TimeSHARE
Given tasks A and B, tasks are alternated WRT time. Each task gets a block of time and then it gets switched off when their time is up. If a task is not ready to be switched into the CPU context it does not have to. The next task in the *queue* can be started. 

### Policy vs. Mechanism
A mechanism provides how we do something while a policy determines *when* to commit an action. An example of a policy is choosing when to switch off a task in the timeshare while the switching is the mechanism. 

> Switching process in the CPU is known as context switching

### Fundamental Abstractions of an OS
A program is static. It sits on the drive until we start the program. A process is a *running* program. 

#### Virtualizing the CPU
Each programming that runs gets its own process. 

How does a CPU switch context? How is it able to *resume* a process from before? Lets explore CPU state.

The state of a CPU is defined by the values in its registers. Now with virtualization each process *gets* a CPU (virtual). Now the state of a CPU that needs to be resumed is stored in the PCB (Process Control block) which is located in main memory. Each process has its own PCB data structure(s) in memory. 

##### Process States
![process_states_1](/img/process_states_1.png)

Note the PCB is not updated until the process is done its time in the CPU. 

The OS has `syscalls` that allow us to control process ourselves. These process allow for CRUD ops on the process with more control options like `priority leveling`. Each process is identified with a PID (process ID), PIDs allow the OS to attach resources to processes. 