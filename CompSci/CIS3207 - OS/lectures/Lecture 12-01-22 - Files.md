# Lecture 12 01 22 - Files
> Final OS Lecture

## Memory-Mapped Files
> Map file contents into the program's address space. 

+ The idea is that the file pages are part of the process. This way a process can use regular pointers to address the file. 
	+ When a process address parts of the file that are not in memory they are brought in (page fault). 
+ Changes are made to this file in memory and later its written to the file in disk
	+ Treats memory as a write-back cache for disk
		+ Modified blocks are copied back to the disk later

All of the file based book keeping is done by the OS.

Files open before `fork()` will be shared between processes. 