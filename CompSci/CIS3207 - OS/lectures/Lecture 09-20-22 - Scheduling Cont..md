# Lecture 09-20-22 - Scheduling Cont.

The end of [[Lecture 09-15-22 - Scheduling Lecture]] talked about relevant scheduling metrics. 

Metric specifics are located in the [[OSTEP 7]] reading. Any notes here are an **extension** to the notes in there. 

## MLFQ - Multi-level Feedback Queue

This is the evolution of the scheduler when we remove the last assumption: "the runtime of each job is known". 

**Goal**: General-purpose scheduling

Most support two job types with distinct metrics:
1. interactive (*response time*)
2. batch (*turnaround time*)

### Approach - Multiple Levels of RR Queues
Each level has a **scheduling priority** which may differ the time slice or process quantum. The next job will be picked up from the **highest** non-empty queue. Processes arriving at a higher level priority than the current priority can preempt lower priority processes. 

![MLFQ_visual](/img/MLFQ_visual.png)


Rule 3: A new process is entered at the highest priority level
Rule 4: f job uses whole time slice, demote process (longer time slices at lower priorities)

Rule 4 Graphic:
![MLFQ-poor](/img/MLFQ-poor.png)

**Why do higher levels have lower slices?**
Notice we require a interactive job to have a high response time. Since we wait for IO the slices are smaller and less waiting going on. As processes block before Quantum expiration, we consider raising it's priority.

If it keeps going past its quantum we can increase it for its next run. This allows them to "find there level" where they willingly give up the CPU. 

If we have too may interactive jobs[^1], jobs in the lower queues are **unlikely** to run. This is known as starvation. The solution is to periodically boost jobs that aren't being scheduled. All modern OSs do this, it is called *boosting*. 

[^1]: Interactive Jobs to not use their total time quantum and thus are never demoted. 