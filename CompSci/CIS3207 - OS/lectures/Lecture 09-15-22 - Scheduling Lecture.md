# Lecture 09-15-22 (Cont.)
Questions addresses: 
1. What are the different CPU Scheduling schemes?
2. What type of workload works well with each CPU Scheduler algorithm?

## Dynamics of Process Activity
This is what we have been talking about for a while. 
![Process_Dynamics](/img/Process_Dynamics.png)

### Suspended Process
Suspended Process - **does not** compete for CPU time but is in memory or in swapping. 

Swapping:
1. involves moving part or all of a process from main memory to disk
2. when no process in main memory are in `Ready` state the OS will swap the blocked processes out on to disk and into a suspended queue. Now the CPU **is not** being used. This is why we swap processes on to a disk to allow for more memory which can allow the CPU to run. 
 
![suspended_process](/img/suspended_process.png)

When the event occurs that will **un**block a suspended process, it will be swapped back on. 

![process_states](/img/process_states.png)

## Two Components for Process Scheduling
1. Dispatcher
	+ Add notes
2. Scheduler
	+ Process to determine which process gets CPU and when.

### Vocab
Workload - set of job descriptions (arrival time, run_time)
Job - View as current CPU burst of a process 
Metric - measurement of scheduling quality


### Metrics
1. Minimize Turnaround time
	+ Do not wait long for job to finish
2. Minimize response time
	+ Schedule interactive jobs promptly so users see output quickly
3. Minimize waiting time
	+ minimize waiting time in the *Ready*
4. Maximize throughput, resource utilization, CPU fairness
5. Minimize Overhead (EX: context switching, ...)