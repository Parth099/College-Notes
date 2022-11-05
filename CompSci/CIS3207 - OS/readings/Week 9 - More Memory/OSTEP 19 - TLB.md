# Faster Translations with TLBs
Due to all the mapping information, paging is quite slow. 

To speed up translations hardware is needed. A translation-lookaside buffer (TLB) will be added to the MMU. To put it simply it is a cache of he most popular translations. Much like any other cache it has a hit/miss ratio and the cache is checked first before going to the actual page table. 

## TLB Basic Algorithm
```py
# Pusedocode

(VPN, OFFSET) = extract_virt_addr(address)

if VPN in TLB: #TLB HIT
	return TLB[VPN]
else: #TLB MISS
	(PFN, Protection_BITS) = get_PFN_info_from_VPN(VFN)
	TLB[VPN] = (PFV, Protection_BITS)
	return TLB[VPN] #important 
```

This 'code' assumes we are access valid bits all the time. All we really need to implement are some guard clauses to throw exceptions. 

Once the entry is in the TLB the TLB is called again but this time there will not be a miss. 

> The TLB is found near the processing core and is designed to be quite fast. Only when there is a miss a full access time is incurred. The point is to avoid any misses. 

## C Example: Accessing Array Indices
**Code**:
```c
int sum = 0;  
for (i = 0; i < 10; i++) {  
	sum += a[i];  
}
```

System Info:
1. Array starts at virtual address 100
2. 8 bit address space with 16 byte pages. (This means there are 16 frames)
3. For the sake of example, only memory access to the array will be analyzed

![arr_in_mem](/img/arr_in_mem.png)

When $a[0]$ is accessed there will be a miss. Therefore the CPU will need to access the page table and update the TLB. However since $a[1]$ is on the same page and the page is loaded on the the TLB this will be a *hit*. The same goes for $a[3]$ , since it is on a different page the TLB will need be updated but for $a[4], a[5], a[6]$ it is smooth sailing. 

We only incur a **miss** on indexes $0, 3, 7$ so we have a hit ratio of $70\%$ .[^1]

This TLB is great for improving performance due to spatial locality as elements requested are packed close together. The TLB also benefits from temporal locality where the same elements are frequently accessed. 

## TLB Misses
Who will handle a miss? The hardware or the OS?

Earlier the a **TLB Miss** was managed by the hardware which would find the relevant PTE and update the TLB. However more modern architectures have employed software based TLB Misses. This is done by allowing the TLB miss to trigger a interruption where the TRAP handler will update the TLB. After the RTI[^2], the process will access the memory which will be there. 

Usually a RTI will execute the next instruction which is not what we want here. The last instruction (which caused the TRAP) should be re-executed. We can employ a special RTI or save a different PC entry before executing the TRAP handler. 

Moreover, the OS needs to ensure an infinite chain of misses do not occur. 
1. Keep the TLB miss handlers in main memory
2. Initialize the TLB with fixed entries that point to the miss handler

With software-managed approach there is flexibility with how the page table is implemented.

## TLB Entries
> Preface: The TLB valid bit is not the same as a valid bit from the PTE. A TLB valid is for stating if the TLB has a valid entry for the VPN requested. On a boot or context-switch all entries are set to invalid. 

A typical TLB might have 32, 64 or 128 entries and be fully associative which is a fancy word for saying any translation can be anywhere. The hardware will search the cache for the relevant entry in parallel.

TLB Entry:

$$
\text{VPN}\ \biggr|\ \text{PFN} \ \biggr|\ \text{other bits}
$$

The other bits can include:
1. Valid bit
2. Protection Bits
3. Address Space ID (ASID)
4. Dirty bit

## TLB Issue: Context Switches
In the last chapter I talked about how the page table's keys are not unique per process: [[OSTEP 18 - Paging]]. The TLB suffers from this detail too. The translations of one process are **meaningless** to another. 

**Solutions**:
1. Flush TLB on new process (setting all valid bits to **0**) - evidently wasteful
2. Include ASID (PID)[^3] bit to mark which entries belong to which process 

ASIDs do allow for the sharing of pages as two entries can point to the same PFN with different ASIDs.

## Replacement Policies
As with any cache we must consider cache replacement with we need to enter a *new entry*. This will be done with a LRU[^4] methodology where we eject entries that have not been used for a while by assume they will not used again due to temporal locality. 

However if a program access random pages often it will exceed the number of entries in the TLB and incur losses. This is known as TLB coverage. 

[^1]: Notice how having a larger page may have improved the hit ratio.
[^2]: Return from Trap Instruction
[^3]: ASID not the same as PID
[^4]: Least-recently-used or LRU