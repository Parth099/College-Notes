# Process API

This note will discuss the process creation API in UNIX systems. Moreover it will discuss what interfaces an OS should provide for easy-to-use efficient process control. 

## `fork()` syscall
`fork()` creates a new process. 

Look at `./snippets/fork_syscall.c`

When this program is called it prints its PID, which is used to identify unique processes. Then it calls `fork`. An almost exact copy of the calling process is made. The only difference is the PID and the state the child is in. The child starts off as if it was the one that made the call to `fork`. The name `fork` is a really good descriptor. 

At this point we have two of the same *processes* running. However they are not 
**deterministic**. If we assume a single CPU, then either the parent or child may run. Thus the order of the prints may be different. 

## `wait()` syscall






