# Lecture 11-29-22 - Page Fetching Cont.
## Fetch Policy
> The Fetch Policy determines when a page should be brought into main memory.

Two common strategies we have learned:
1. Demand Paging - [[Lecture 11-10-22 Demand Paging and Swapping]]
2. Prepaging - [[Lecture 11-17-22 Page Fetching and Replacement]]

### Demand Paging
Brings pages into memory when a reference to *that* page is made. Initially, there are many page faults when the process is started since there are no pages. Subsequently, the next references will likely be to pages that already exist and thus there is a lower chance of page faults. 

### Prepaging
This is when pages other than the one demanded by the page fault are loading in.  

> Prepaging is not to be confused with swapping a process where the entire resident set is moved out the main memory and brought back in when resumed. 

#### Why Prepaging

if pages of a process are stored contiguously in the secondary memory device it is more efficient to bring in a number of pages at once. Notice in a disk the arm has to *move to the location on the disk* and then read. The process of reading in many contiguously pages skips the seek time for the disk and thus is advantageous. 

#### Prepaging Disadvantage

The disadvantage of prepaging is shown when the extra pages are not referenced once loaded into main memory. 


## Resident Set Management
The OS must manage per process how many pages to bring/keep in main memory. 

### Preface
The smaller the amount of memory per process the more process can coexist in main memory. However this will lead to **more page faults**.  

Beyond a certain size the number of page allocation does not matter:
1. Too many frames: unused frames
2. Beyond a certain size the number page faults do not decreased 

### Resident Set Size Allocation Polices
#### Fixed Allocation
OS gives a process a **fixed** number of frames in main memory. When a fault occurs of the pages assigned to *that* process is replaced. 

#### Variable Allocation
The frames allocated to a process varies over its runtime. 

#### Replacement Scope
The scope of a **page replacement policy** can be:
1. Local - chooses only among the resident pages of the process that generated the page fault
2. Global - page replacement considers all unlocked pages 

Notice a *global* policy is more prone to page faults. 
+ If the OS gives a page to a process that some other process needs

**Note**: A Fixed Allocation cannot be global while Variable Allocation can be. 

#### Fixed Allocation w/ Local Scope
+ Decide ahead of time how many frames per process

If the allocation here is too small:
1. High Page Fault
2. Due to (1) increased process idle time
3. Due to (1) more time spent in swapping

If the allocation here is too large:
1. Wasted frames

#### Variable Allocation w/ Global Scope
Easy to implement as OS maintains a list of free frames. A free frame (if possible) is added to the resident set when a fault occurs.

If there are no free pages, the OS must choose a page to replace in memory.

> This works really well with Page Buffering (See [[Lecture 11-17-22 Page Fetching and Replacement]])

#### Variable Allocation w/ Local Scope

> Decision to increase or decrease a resident set size is based on the assessment of the likely future demands of active processes

+ When a process is loaded give it a certain number of page frames 
+ When a fault occurs select a page to replace among the resident set of the faulting process
+ Reevaluate periodically the allocation provided to a process to inc/decrement it for memory performance. 

### Working Set 

> Program needs a certain set of pages resident in memory to run efficiently. If this frame criterion is not met, a lot of page faults occur. 

The optimal working set of a process is the set of pages that will be needed in the immediate future and thus should be resident. 

#### Locality Of Reference Experiment
![Locality_of_Reference](../../img/Locality_of_Reference.png)

Given a small time window $\Delta t$ we notice that not a lot of frames are required for that interval of time even though the process access many pages over its run time. 

**Graph of Working Set Size**
![Working_Set_Size](../../img/Working_Set_Size.png)

The humps are generated from the process moving between working sets. 


**Relation Between Working Set Size and $k=\Delta t$**

![Working_Set_Size_relation_to_time](../../img/Working_Set_Size_relation_to_time.png)

### Working Set Strategy
> Variable Allocation, Local Scope

1. Monitor Working set size per process
2. Periodically remove from the working set of a process, pages that are no longer in the working set
3. A process may only execute if its working set is in main memory (working set = resident set)

![Working_Set_Strategy_graphic](../../img/Working_Set_Strategy_graphic.png)

### Working Set Model
+ Working Set Window 
	+ a fixed number of page references
+ $WSS_i$ - working set size of Process $P_i$ = total number of pages references in the most recent interval $\Delta$
	+ if $\Delta$ is too small it will not encompass entire locality
	+ if $\Delta$ is too big it it will encompass several localities

Lets define demand $D$ as 

$$
D = \sum_i \text{WSS}_i
$$

If $D > m$ for $m$ being the total number of free frames in the system, we need to suspend processes. 

$D > m$ causes **thrashing** where little work is being done due to too many IO transfers due to page faults. 

**Definition: Thrashing** - A state in which the system spends most of its time swapping process pieces rather than executing instructions. Thrashing will decrease the degree of Multiprogramming. 

### Working Set Implementation
However, it is hard to predict working set size before hand. We need to keep track when pages are referenced. 

### Working Set Algorithm
![Working_Set_Algorithm](../../img/Working_Set_Algorithm.png)