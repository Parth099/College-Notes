# Process API

This note will discuss the process creation API in UNIX systems. Moreover it will discuss what interfaces an OS should provide for easy-to-use efficient process control. 

## `fork()` syscall
`fork()` creates a new process. 

Look at `./snippets/fork_syscall.c`

When this program is called it prints its PID, which is used to identify unique processes. Then it calls `fork`. An almost exact copy of the calling process is made. The only difference is the PID and the state the child is in. The child starts off as if it was the one that made the call to `fork`. The name `fork` is a really good descriptor. 

At this point we have two of the same *processes* running. However they are not 
**deterministic**. If we assume a single CPU, then either the parent or child may run. Thus the order of the prints may be different. 

`fork()` - return values:

| Value   | Meaning                     |
| ------- | --------------------------- |
| $\lt 0$ | `fork` failed               |
| $= 0$   | This is the child process   | 
| $\gt 0$ | PID of of the child process |

The child **does not** address the same memory space as the parent. 

## `wait()` syscall
Sometimes it may be useful for a parent to wait for its childen's execution. This is where `wait()/waitpid()` comes in. Often times adding a `wait()` to the code makes it deterministic. 

**`wait` signature**:
```c
pid_t wait(int* status)
```

The argument `status` will write the exit status of the child to a variable provided while also returning the PID of the child that was reaped (killed).

## `exec()` syscall
This is like `fork()` but runs a **different** program as a process. 

**`exit()` signature**
```c
int execvp (const char *file, char *const argv[]);
```

We can use *fork* to create a child that calls another program with `execvp` and then *wait* its finish. 

`exec` needs the path the program is located and its command line args. What it does is that it will load the code and static data from that program onto the **current** stack, overwriting its parent code segment. The heap and stack along with other parts are reinitialized. Then the new program is ran with the `argv` provided. `exec` transforms the current program to the program specified.  After the call to `exec` it is like the current **never** existed.

> Note there exists other exec flavors. 

## Why do we do it this way?
The combination of `fork` and `exec` is built the way it is to make the shell, a **user program**, very powerful. When you run a program from the shell it will `fork` and `exec` the program and `wait` for it to finish which allows us to do chaining like this:

```unix
$my-shell: myProg.c arg1 arg2 > output.xml
```

The way this redirection works is by the shell closing the stdin and opening `output` to redirect the output from `myProg`.

**Class Questions:** Can you explain file descriptors and how they are used to pipe commands

//page 7 / 15