# Advanced Paging
The previous chapter showed show page tables are too large that will be focus of this chapter. 

Recall how a linear page table in a 32 bit address space with $4$ KB table entries had $2^{32} / 2^{12} \approx 10^6$ pages. With a 250 active processes that would have cost us 1 GB in memory alone[^1].

The question here is how to make smaller pages.

## Trivial: Larger Page Sizes

If instead we used 16KB pages we could reduce the page table to $1$ MB[^2] per process. However this solution is not good due to the internal fragmentation - pages will be left unfilled. 

## Segment and Paging Hybrid
> See [[OSTEP 16 - Segmentation]] for Segmentation Information. 
 
 
Consider a 16 KB address space with 1 KB pages.

![hyb_seg_page](/img/hyb_seg_page.png)

Note this table does not need an VPN because the table is sequential. See how the code in virtual page 0 maps to Page frame 10. 

However notice even for a tiny space the valid bit is most 0s for process with a smaller heap and stack[^3].

**The hybrid approach** suggest a page table **per** logical segment[^4].

Recall in the segmentation chapter we had base/bound registers that told us the start/end of a segment. However now the base register for a process will point the start of the segment page table while the bound will point to the end of the end of the segment page table. 

### 32-bit address space Example

**Address Space**: 32 bit with 4 KB pages and 4 segments

![32bits_seg_page](/img/32bits_seg_page.png)

When a process is running each base/bounds register contains the start/end address for their respective segment. These registers are changed per context switch.

**The savings**:
The critical part of this hybrid is the **bounds register per segment**. If a segment like the code segment only has allocated pages 0, 1, and 2, then the code segment table will only have 3 entries with the bounds register set to $3$. 

Segmentation contains its issues however. For one the page tables are not of a fixed length anymore meaning finding free space for them is not easy. 

## Multi-level Page Tables

> Modern systems employ this approach

1. Chop up the page table into page-sized units. 
	+ If an entire region of PTEs for a page-sized page is invalid do not allocate memory for it
2. New Structure: Page Directory
	+ Tells you where a page of the page table is in memory
	+ Tells you if a page of a page table contains no valid entries

![MLPT](/img/MLPT.png)

> **PTBR** - Page Table Base register

> **PDBR** - Page Directory Base Register 

Notice how the Linear Table wastes space by having NULL rows where a process is not using *that* frame.

**Advantages**:

The MLPT is more sparse since it only allocates space for the page table relative tho the space you need. It is easy to add pages to the directory as the OS can just grab **any** available frame to put the frame into. 

**Disadvantage** - Space-Time Trade Off:

Given a TLB miss we will have to incur more memory accesses. Lastly, the MLPT is a lot more complex to implement. 

### Example
Lets consider a $16$ KB address space with $64$ byte pages. This is 256 frames in physical memory. 

An address in this system is 14 bits long where $8$ bits are reserved for the VPN. 

Notice a linear PT could have 256 entries even if 3 or 4 pages are in use. 

Consider this setup for a process:
```c
VPN 0   - CODE
VPN 1   - CODE
//...
VPN 4   - HEAP
VPN 5   - HEAP
//...
VPN 254 - STACK
VPN 255 - STACK
```

The rest of the pages are *invalid*. 

Lets build the Multi-Level PT assuming each PTE is 4 bytes. This leads to $\frac{64 \text{KB PAGE SIZE}}{4\text{KB per PTE}} = 16$ different sections. At this point the $256 \times 4$ KB table is now divided into 16 $64$ byte chunks[^5].

All we need to do now is use the VPN to index the PD (Page Directory).

![PD_from_VPN](/img/PD_from_VPN.png)

Given that we have 16 $64$ byte chunks the top 4 bits can act as index for the PD. 

```c
//PDE - Page Directory Entry
PDEAddr = PageDirBase + (PDIndex * sizeof(PDE)) 
```

If the `PDE` at `PDEAddr` is marked invalid, we know there was an illegal access. 

![PDF_from_VPN_MLPT](/img/PDF_from_VPN_MLPT.png)

From the PDE we have the page address that contains the page address we need. 

So the PD's PDE gave is the page of the page table that contains the page we want to get to. We can move down PTI (Page Table Index) units to get the relevant PTE. From the PTE we can combine that frame address and our OFFSET to obtain the physical address. 

#### Code
```c
//PDE - Page Directory Entry
PDEAddr = PageDirBase + (PDIndex * sizeof(PDE)) 
PTEAddr = (PDE.PFN << SHIFT) + (PTIndex * sizeof(PTE))
PhysAddr = (PTE.PFN << SHIFT) + offset
```

The SHIFT is due to the fact that the PFN is a **page** number. For example if the page number is $100$ we cannot use that as the address of the page. It is really $100\times\text{Page Size}$ , and since Page Size is a power of two we can bit shift left. 

### Example Cont. 
![trans_MLPT](/img/trans_MLPT.png)

> While not shown in the image, there are 16 PDEs. There are not numbered. Notice the first PDE contains the code and stack while the last PDE contains the Heap.

Notice that instead of allocating **16** page table pages (256 entries) we only needed 3. 

## **MULTI-MULTI-LEVEL** Paging and the TLB
There exists a deeper nesting such as a three-level paging however the concept is the same. 

The TLB works the same here. If it has the entry it is used if not it is found via a trap and loaded onto the TLB. Given an address of `<p1, p2, OFFSET>` it will map upper level bits `p1, p2 -> PFN`.

## Inverted Page Tables
In this scheme we keep **ONE PAGE TABLE** representative of all the process on memory. 

Mapping:

$$
\biggr(\text{PID, VPN}\biggr) \to \boxed{\text{ PFN} }
$$

The length of this table is the number of frames possible. 

The downside to an IPT is the access time as each entry has to be checked to find a valid `PID, VPN` pair. A hash function can solve this issue. 


[^1]: See [[OSTEP 18 - Paging]] to see why
[^2]: This size does not count for any extra bits in the PTE. 
[^3]: Very Wasteful
[^4]: Code, Stack, Heap 
[^5]: Each page holds $16$ PTEs