# Signals in C
A signal is a **software** generated interrupt that is sent to a process by the OS or a process to alert the process of some situation. 

We can change the default behavior of signal handlers to create an event based transfer of information between processes.

> A process is not allowed to replace or ignore the handler for the SIGKILL or SIGABRT.

Here is a signal number:

```c
#define SIGINT  2   /* Interrupt the process */
```

The OS keeps track of two integers where each bit corresponds to a signal type. One int is used to keep track of blocked signals while the other one is used to keep track of pending signals. 

The reason why we need pending bits is because when signals are sent the process can be not running, thus when it is running the relevant signals are sent. 

## Custom Handlers
A handler can have any name bit must conform to the following data types:

```c
void sig_handler(int sig);
```

Then we can use the `signal()` system call to set *this* function to handle signals. 

```c
void (*signal(int sig, void (*func)(int)))(int)
```

Notice we can also ignore signals:
```c
//SIG_IGN function that does nothing
signal(SIGINT,SIG_IGN);
```

## Sending Signals
The system call `kill()` to send a signal to a process:

```c
int kill(pid_t pid, int signal);
//pid    -> pid of the receiver
//signal -> signal type (number)
```

There are many values for signal depending on what you want to capture. For example with `SIGCHLD`, we can capture a child terminating[^1].

The `SIGUSR1` and `SIGUSR2` signals are set aside for you to use any way you want.

A process can send itself a signal via 
```c
int raise(int sig_num);
```

[^1]: A child will send a `SIGCHLD` to parent when they need terminate. 