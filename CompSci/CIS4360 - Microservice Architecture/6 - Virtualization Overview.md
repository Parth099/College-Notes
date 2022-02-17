# Virtualization
For: [[CIS4360]]
## Multicomputer
A common example of a Multicomputer is where a company may have a web-server, an FTP server and an internal email service among other things. All of these run on different computers but on the **same** equipment rack connect by the **same** network line. The reason why servers run on separate machines is because no one can trust an OS to run without failure every day every year. By spitting services we can prevent system-wide outage given *an* outage.  This spitting also prevent malicious users from gaining access to everything given they have access to one service. 

This sounds great: fault tolerance and isolation. However, this method is very expensive and complex since there are many machines involved. The alternate solution can be to use VMs via a VMM(Virtual Machine Monitor)(a.k.a hypervisor). It creates the illusion that each OS has its own dedicated hardware. 

Regardless of Type 1 or Type 2 Hypervisor, virtualization allows a single computer to host multiple virtual machines. 

For Hypervisor, see [[5 - Docker Containers]].

This still retains the fault tolerance and isolation since failure in *a* VM will not end the entire system. However, now we *can* run multiple OSs on the same hardware at the same time. 

This is not to save VMM is completely safe. A server failure that runs the VMs is more catastrophic then the individual services one. In reality however, server outages are not due to faulty hardware but they occur due to poorly written code or configurations. 

In a VM setting the only thing running is the hypervisor. Which has a lot less code than an OS implying its increased stability. 

There are many benefits of VMs, I will not write about them here since there are **countless** resources that restate their benefits.  

## Requirements For Virtualization
It is an imperative that VMs act like the real deal. They must boot and have the ability to install any OS much like real hardware. This is the job of a hypervisor.

A good hypervisor(HV) scores well in: 
+ Safety - HV has full control over its the virtualized re-sources
+ Fidelity -  Behavior of apps on the HV should be the same as on bare-metal
+ Efficiency - Code running in the VM should not need intervention from the HV. 

## Instructions and their Terms
A safe way to execute the instructions is via an interpreter and perform whats needed per instruction. While many instructions will work fine most will not. For example the INC(increment) instruction will be fine to virtualize but an instruction like modifying the Page-Table many not be completed easily.    

- sensitive instructions: set of instructions that behave differently when executed in kernel mode than when executed in user mode
- privileged instructions - set of instructions that caused a trap(exception in a user process.) when used in user mode. 
## Type 1 and Type 2 Hypervisors
### Type 1
Low level hardware-based HV. A type 1 HV is the only thing that runs when active. 
> Technically, it is like an operating system, since it is the only program running in the most privileged mode. Its job is to support multiple copies of the actual hardware, called virtual machines, similar to the processes a normal operating system runs.

A type 2 HV is software-based. It relies on the host OS to allocate resources. Regardless of its software-based nature it still pretends to be a real computer. 

Both types of HVs must execute instructions in a safe manner. It should allow one of the OS to mess up their Page table (see Glossary) but not the table of others. 

![[hypervisor_a.png]]

A higher level overview for when a Hypervisor gets a sensitive instruction is that it rewrites the code for the instruction so as to emulate it and then emulates it since it cannot actually run the code.


## Glossary
+ Page Table - A [[Data Structure]] used by a virtual memory system in an OS to store the mapping between virtual addresses and physical addresses.
+ virtual addresses - set of virtual addresses an OS makes available to a process
+ physical addresses - :(
+ interrupts -  The interrupt is a signal emitted by hardware or software when a process or an event needs immediate attention.
+ CPU modes - place restrictions on the type and scope of operations that can be performed on the CPU
	+ Kernel Mode - the CPU may perform any operation allowed by its architecture; any instruction may be executed, any I/O operation initiated, any area of memory accessed
	+ User mode - More restrictive than Kernel

%%7.5%%