# Paging

Recall the challenge with segmentation from [[OSTEP 16 - Segmentation]] which dealt with fragmentation. This is natural, dividing up space into blocks of a different size will eventually become fragmented. Paging deals with this by creating blocks that are **fixed size**.

We divide the logical address space into equal sized chunks called **pages**. The physical space is also divided into equal sized blocks which are called **page frames**[^1]. 

Each **page frame** maps to *one* **page**.

## Overview
![paging_overview_1](/img/paging_overview_1.png)

Consider this $64$ KB process on a system with $16$ KB pages. 

![paging_overview_2](/img/paging_overview_2.png)

This image shows the above process on a system with $128$ KB memory. 

### Pros of Paging
1. No Need to worry about which directions the stack and heap grow
2. If the OS needs to place a large process into memory there is no need to look for contiguous segments to place it in. Notice in the image above pages were placed out of order *and* since all pages are of the same size we do not need to look for appropriately sized spots. 

## Address Translation
There is a *per-process* data structure known as a page table to perform address translations. It simply tells us what physical page frame a virtual page maps to:

Example ***page-table*** based on the images above to illustrate this:
$$
\begin{align}
\text{Virtual Page 0} &\to \text{Physical Frame 3} \\
\text{Virtual Page 1} &\to \text{Physical Frame 7} \\
\text{Virtual Page 2} &\to \text{Physical Frame 5} \\
\text{Virtual Page 3} &\to \text{Physical Frame 2} \\
\end{align}
$$

When a context switch is performed this data must be changed. 

> We can think of a page table as a *one-to-one* mapping of pages to frames where each page **must** have a frame mapping yet a frame need not map back to a page (not *onto*).

### Example
Consider a $64$ B process address space with $16$ B sized system pages. 

Since the address space is $64$ B it will have 6 bits long address.

Suppose we get an instruction to perform some action at some **virtual** address. To find the actual location in memory we need to find its page frame and offset[^2]. Since the process is *virtualized* with memory it assumes its address begin at zero and are contiguous. Therefore we can take the first few bits as the page bits and the last bits as the page offset bits. Since we are on a system with 4 pages[^3] the first two bits need to be the page frame bits. 

$$
\underbrace{\boxed{V_5}\boxed{V_4}}_{\text{VPN}}\overbrace{\boxed{V_3}\boxed{V_2}\boxed{V_1}\boxed{V_0}}^{\text{offset}}
$$

**VPN** - Virtual Page number
**PFN** - Physical Frame number[^4]

It should be evident that $\text{VPN}\neq\text{PFN}$ all the time. 

Anyways, now that we have our VPN and OFFSET we can find the physical address:

![paging_overview_3](/img/paging_overview_3.png)

The mysterious gray "Address Translation" is just using the page table located in the memory somewhere[^5]. 

## Storing Page Tables
In a lecture we were told that page tables can get very large. Here is why:

Consider a $32$ bit address space where page sizes are $4$ KB. 

> In a 32-bit system the total available virtual address space is $2^{32}$ **BYTES**. Instead of address each bit most modern systems address *bytes*. 

In this scheme, there will be a $20$ bit VPN[^6] and $12$ bits OFFSET. A 20 bit VPN means there are $2^{20}\approx10^6$ pages the OS has to keep track of **for each process**[^7]. If we assume each page table resides in main memory and holds nothing else of value but the frame number mapping we can assume that each entry is $4$ bytes since it holds a $32$ bit address. Since each process holds a million of these, that is $4$ MB per process for **each** process running. This adds up on any modern system running 1000s of processes. 

## Information in a Page Table and PTEs (Page Table Entries)

> The page table is a data structure that maps virtual address to physical ones

The simplest page data structure is a linear page table which is just an *array*. This the the abstraction for the page table we will use until subsequent readings. 

### Parts of a PTE - Page Table Entry
A **valid** bit is used to *remember* if a process is *allowed* to access a page[^8]. Virtualized, a process will have empty space between the stack and the heap. In reality this space doesn't really exist however, when the address to this 'empty' space is translated, it points to a page that is not valid since the stack nor the heap have been extended their allocated page(s). In other words the process's page table has not marked this space is valid since we have not needed it yet. 

The valid bit is **crucial** when the address space is sparse simply by marking **all** unused pages are invalid. 


Much like [[OSTEP 16 - Segmentation]] **Protection bits** allot each page RWX[^9] permissions. 

+ **Present bit** - The `isSwapped` bit. 
+ **Reference bit** - track whether a page has been accessed

## Is Paging too Slow?
Consider translating some address $X$

The system must extract out the VPN and OFFSET, use the VPN to find the PFN using the page-table-base register. The page-table-base register keeps track of where all the page tables are per process. After it is found we add the PFN and the OFFSET to obtain the location in physical memory. 

This is likely to slow down the program by a factor or two or more due to the two memory access per one access

> It seems paging takes up too much memory **and** is slow.




[^1]: Great Terminology!
[^2]: Page frame locations are memory pointers to the *start* of a frame. The offset tells us how far to travel down. 
[^3]: 64 divide by 16
[^4]: AKA: **PPN** - Physical Page number
[^5]: For now we will assume it is contiguous
[^6]: $2^{32}$ addressable bytes with each page being 4096 bytes -> $2^{20}$ pages
[^7]: This was a bit confusing for me but we are only using this naive approach to show how to improve paging later. Each process has a full sized page table. Thanks TA Alex! Also notice each process needs a translation where the key (VPN) is non unique. For example Process A may map page 0 to frame 2 whereas a Process B may map page 0 to frame 6. Since the keys are non-unique we require a page table per process. 
[^8]: We will ignore the *loading* of a page for now. Assume all pages are loaded onto memory when the process is ready
[^9]: Read, Write, Execute