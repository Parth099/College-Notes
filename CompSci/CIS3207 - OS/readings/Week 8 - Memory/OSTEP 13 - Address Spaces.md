# Address Spaces
## Multiprogramming and Time Sharing

One method of time sharing was to let one process run for a short period of time but let it have all the available memory. After its quantum expires it is put on the disk[^1].

It is easier to give them a chunk of memory and keep that memory attached to that process[^2]. While this opens up security issues with Process $P$ reading the memory of Process $Q,$ it will be solved later. 

![/img/address_space_basic.png](/img/address_space_basic.png)

## The Address Space
See that each part (code, stack/heap...) of a program has to live in memory somewhere meaning they are in the address space. We must also worry about dynamic memory with `malloc` calls. 

Consider the below $16KB$ address space below. 

![address_space_internal.png](/img/address_space_internal.png)

The heap and stack are placed this way because each needs to grow. When threads come in this model is no longer intact. 

Outside of this abstraction, the this process's address space **does not** start at $0KB$ , it is at some arbitrary physical address. The process sees a **virtual address** however this *virtual address* is translated into a physical address by the OS with the help of some hardware.  

## Goals for VM

> VM  - virtual memory

1. **Invisible**: Running program is not aware that its memory is virtual
2. **Efficiency**: Translations should be fast
3. **Protection**: Ensure one process cannot read/write the memory of some other process.[^3] 




[^1]: Should be evident why this is an issue. 
[^2]: Assuming it does not get swapped out. 
[^3]: Ensure no process can access anything outside of its address space. 