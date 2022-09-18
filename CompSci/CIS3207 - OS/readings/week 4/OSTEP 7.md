# Scheduling

> How should we develop a basic framework for thinking about scheduling policies? What are the key assumptions? What metrics are important? 

Recall `non-preemptive` vs `preemptive`:
- preemptive OSs are **willing** to take the CPU away from processes. 

## Workloads
The **workload** is the assumption collective of the running processes running. Here are the *unrealistic* assumptions we will make about each processes AKA **jobs**:
1. Each Job runs for the same time and arrives at the same time
2. Once started each job runs to completion 
3. All jobs are CPU based (no IO)
4. runtime of each job is known\*

\* - IMO the most unrealistic assumption we make

## Metric - Turnaround
We need to measure different scheduling polices and we need metrics to do so. We will use turnaround time:
$$
T_{\text{turnaround}} = T_{\text{completion}} - T_{\text{arrival}}
$$

Recall that we assumed all jobs arrive at the same time:
$$
\implies T_{\text{turnaround}} = T_{\text{completion}}
$$

Notice that $T_{\text{turnaround}}$ is performance based. Another metric is **fairness**. Fairness and performance are often conflicted as we may optimize performance by not letting a few jobs run which decreases fairness. 

## Metric - Response Time
$$
T_{\text{response}} = T_{\text{firstrun}} - T_{\text{arrival}}
$$

Notice that $T_{\text{firstrun}}$ is not the same as $T_{\text{arrival}}$ from the turnaround metric. 

## Policies
### FIFO
This is the most basic *queue* based algorithm which is easy to implement. $T_{\text{turnaround}}$ is also easy to check. Suppose jobs $A, B, C$ arrive in that order and each takes $10$ seconds to complete. The turnaround time respectively is $10, 20, 30$ seconds with the average being $20$ sec. 

If we assume that all jobs **do not** have the same runtime, *FIFO* fails. Think about what happens to the **average turnaround** if `runtime(A) = 100 sec`. The average runtime goes to $110$ seconds since the turnarounds are $100, 110, 120$ respectively.  

### SJF - Shortest Job First
By the title we can see how this solves the issue from FIFO. It will bring the average turnaround from the $110$ seconds above down to $50$ sec. 

Lets drop the fact that all jobs arrive at the same time. This opens to another issue: What if long jobs like A arrive first?

### STCF - Shortest Time-to-Completion First
One can infer by the name what this policy will do. 

We can run $A$ if it is the first to come but we can **preempt** the job if $B, C$ arrive. 

Suppose each job gets 10 seconds of CPU time. 
- A arrives at $t = 0$
- B arrives at $t = 10$
- C arrives at $t = 20$

We can compute the average turnaround metric as follows:

$$
T_\text{avg} = \frac{\underbrace{(120-0)}_{A} + \overbrace{(20-10)}^{B} + 
\underbrace{(30-10)}_{C}}{3} = \mathbf{50}
$$

### RR - Round Robin
This scheduling algorithm answers to the response time metric. Notice that for an algorithm like SJF, if a process that takes a lot longer than other jobs arrives first the other jobs will have a terrible response time.

RR runs jobs for slices of time (AKA *scheduling quantum*). The time slice is a multiple of the length of the timer interrupt.  

#### Comparison with SJF - Response TIme
Lets say $A, B, C$ arrive sequentially and each wants runs for $5$ seconds. SJF will run each fully before switching:
$$
T_\text{SJF}^\text{resp} = \frac{(0 - 0) + (5 - 0) + (10 - 0)}{3} = 5
$$

However if used time slices of $1$ sec:
$$
T_\text{RR}^\text{resp} = \frac{(0 - 0) + (1 - 0) + (2 - 0)}{3} = \mathbf{1}
$$

Notice the smaller the slice is the faster (response metric) RR will be. However it cannot be too short as then the time to switch context will dominate. The cost of a context-switch must be **amortized**.

#### Turnaround
![Turnaround_RR](/img/Turnaround_RR.png)

$$
T_\text{RR}^\text{tr\_arnd} = \frac{(13 - 0) + (14 - 0) + (15 - 0)}{3} = \mathbf{14} \ \text{:(}
$$

Even though it is not good at turnaround, it is **fair**.

### Results
Notice we have two classes of schedulers:
- Turnaround Focused: SJF and STCF
- Response time: RR

## Incorporating I/O
Suppose we have jobs $A$ and $B$ which both need $50$ ms of CPU time. However $A$ needs IO for 10ms every 10ms.

### SJTC
We see that $A$ is made up of 5 $10$ ms sub-jobs and another 5 sub-jobs for IO. 

![IncorporatingIO](/img/IncorporatingIO.png)

We can treat each sub job of A as an actual **independent** job. When SJTC chooses a job to run it will pick A. Once that is completed B can run. However once A is finished we will submit the next sub-job of A which will preempt B. 

## No more *omniscient* Scheduler
Realistically, the scheduler will not know the runtime for each process. Perhaps we can incorporate some of the ideas from RR. That will be the topic of the next chapter: `multi-level feedback queue`.