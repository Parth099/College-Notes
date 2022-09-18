# [Introduction](https://pages.cs.wisc.edu/~remzi/OSTEP/intro.pdf)

When a program runs it is instructions very fast (million/s). A processor will:
+ Fetch
+ Decode
+ Execute

instructions.

The body of software that allows us to run program(s) which makes the system easy to use is called the OS. It ensures that the system operates correctly and efficiently in an easy to use manner. 

The way this is done is via virtualization. This is when a physical resource is transformed into a more general and easy to use **virtual** version of it self. 

To allow users to control the OS it proves an API in the form of system calls. This is often said to be a standard library for applications that want to control hardware pieces like memory and CPUs. Now virtualization allows many apps to run at the same time where they share the resources managed by the CPU. The apps will concurrently access resources like disks or memory making resource shared.  

## Virtualizing The CPU
This is when the OS takes one CPU and makes it *look* like we have infinite CPUs giving us the ability to run many programs at once.

Since we have many programs running at the same time what happens if two programs want to run at the same time? This is answered by OS policies which is covered later. 

## Virtualizing Memory
Memory is just an array of bytes. Memory is used to keep program information in state like data structures. Moreover each instruction that is required for the program is also in memory. 

Much like the CPU the memory is also virtualized. If we run two C programs at the same time they may say they are using pointers to the same address in memory. In fact each process has its own virtual address space. This space is mapped to physical space. In the process's POV it has the entire memory to it self.  

## Concurrency
This is a set of issues that arise when we run multiple threads at the same time. Moreover notice that the OS even suffers from Concurrency issues as it must handle many resources at once. 

## Persistence
Recall from 2107 DRAM (Dynamic RAM, [[6.02 Storage Technologies]]). It is a volatile memory. This is why if we want data to persist we need a different technology like HDDs and SSD. The OS will also manage the File System (FS). However, disk space is **not** virtualized as programs may share data. 

Writing to a drive is a very intricate process and a costly one. Therefore the OS will batch commands like this in hopes of getting a bunch of them in at the same time. File writing is done via the standard library the OS provides.
