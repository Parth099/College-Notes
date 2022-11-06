# Segmentation
So far we have been putting programs contiguously using base and limit registers. Notice that there is a free space between the heap and stack[^1].

![reloc_addr.png](/img/reloc_addr.png)

Notice this space takes up physical memory when we translate using registers. 

> How can we support a more efficient address space where the space between the heap and stack is large?

## Segmentation: Generalized Base/Bounds
We can use a base and bounds per logical segment[^2] of the address space. This will allow the OS to place the *code*, *stack*, and *heap* in different segments **independently**. 

![seg_reloc](/img/seg_reloc.png)

Inside the segment register:

![seg_regis](/img/seg_regis.png)

Notice this **does** have some security built in. 

Illegal memory access here are known as `SEGMENTATION_FAULTS`.

## Detecting Segment Reference
We saw the segment register but how does the OS know which segment to translate under?[^3]

### Common Approach
![common_app_seg](/img/common_app_seg.png)

This is a sample of we have three segments:
+ 00 - code
+ 01 - heap
+ 10 - stack

If our address space for a program space is 16KB we have 4KB segments. If we need a segment to be larger than 4KB, say the heap. This will become a problem.

### Implicit Approach
The hardware will implicitly find the segment based on the instruction formation. If the instruction is a code fetch use the code segment. If the address is based on the stack pointer we use the stack segment entry in the segment register. Otherwise it must be a heap segment we need the data from

## What about the Stack?
Recall that the stack grows upwards (backwards). A $2$ KB stack starting at $28$ KB will end at $26$ KB. The hardware needs to know which way the sections grow.

![grows_positive](/img/grows_positive.png)

Consider a virtual address comes in as: $11\ 1100\ 0000\ 0000$

The top 2 bits map to *stack* and the offset is $3$ KB.

To obtain offset we must subtract this number from the max segment size, this is $-1$ KB.

This is the number we add to the base to get to the correct location. 

**Why do we do this?**

![seg_reloc](/img/seg_reloc.png)
Look at this image and see the bottom of the stack is at $28$ KB. This means the segment that stack is on ranges from $24 \to 28$ KB. When we request an address of $15$ KB. It should be $1$ KB above the bottom of the stack much like how $15$ KB is one KB above $16$ KB.

If we remove the top two bits we see that the rest of addressing bits can address a $4$ KB space. **Recall** we are asking for $15$ KB. This means in the 4th $4$ KB segment, we are asking for $3$ KB. This means we must travel $3$ KB down from the start of the stack **segment**[^4]. *Or* we can travel up $4 - 3$ KB from the bottom (base). 

## Permissions
![perms_segment](/img/perms_segment.png)

As support for code-sharing grew developers added protection bits. Notice in the image above that if the code was read only, it could be **shared**. In addition to checking the bounds for a memory access the CPU now must also check for valid permission for any access. 

## Fine-grained vs. Coarse-grained Segmentation
The segmentation we have death with is Coarse-Grained. That was we take parts of a process (stack, heap, code) and those are the segments. These blocks are still kind of large. However there exists another option. 

For there to be smaller segments a **segment** table is require to be kept in memory. The idea at the time as that by having more segments it would allow for the address space to be more compact[^5] and utilize memory better. 

## OS Support for Segmentation
What we have learned in this chapter is that parts of a process are relocated in memory for increased saving[^6] (less fragmentation). This simple approach was achieved by using a *single* base/bound register.  

### Issues
**What should occur during a context switch?**
The CPU should switch in/out the base/limit registers.

**How should segments grow?**
Sometimes a call to `malloc` will require the heap segment to be extended. In this case a call to the OS will provide[^7] for more space and update the segment entry in the register along with its size. 

**How to deal with external fragmentation?**

![ext_frag_OSTEP.png](/img/ext_frag_OSTEP.png)

Suppose a process comes in and it requires a $20$ KB Segment. While there exists $24$ KB of free space, there is no contiguous block. 

> **The OS cannot fulfill this memory request.**

A solution, talked about in the book and in class, is to compact this space by moving all the blocks over. The result of this 'clean up' is on the right. 

However to do this the OS must preempt the current process and start moving over the fragments. This is very **expensive**. Moreover there is another issue. If we compact all of the fragments into one part of the memory as shown in that figure on the right, it will make it very hard serve requests to make a segment larger as it will have to be moved out of that *compact* block. 

Maybe a simpler approach is to keep track of all the free spaces. Algorithms like best-fit keep track of large blocks of memory and when a request is sent it will return the block of memory closest to the request size. 

[^1]: Internal Fragmentation
[^2]: A segment is just a contiguous portion of the address space of a particular length
[^3]: How does it know to translate under code, stack or heap?
[^4]: NOT THE STACK!
[^5]: less external fragmentation
[^6]: This was due to not having to initialize the empty space between the heap and the stack. 
[^7]: A call to add space could be rejected by the OS

