# Containers Lecture
## Virtualization
Virtualization is all about making the hardware virtual. We are pretending its there using containers.

There are four parts of running a server. 
+ 1 - Application Code
+ 2 - Dependencies
+ 3 - Operating System
+ 4 - Hardware

A bare metal server (physical) contains all four. However, a Virtual Machine only has the first three since it does **not** contain hardware.

## Containers
A container has only the first two. It does **not** have an operating system. A single container hosts *a* microservice. Note that a container has the Dependencies included. This means that it has all the necessary executable, binary codes, libraries, and configuration files.
### Container Scaling
Since the container is more lightweight we can scale a container's microservice just by creating a another instance of a container. A container is also portable due to the fact it does not contain an OS which can take up lots of storage. 

Containers are:
 - Shareable
 - Reusable - 
 - Versioning
 - Isolated - A container cannot see what other things are going on outside the current container. 
 - Immutable

## Why Containers
Suppose your app crashes but it seemed to work fine on your machine. You then check logs and rollback. Then finally fix the primary problem. 

## Docker 
At the high level we have the Docker CLI and Docker Daemon. These two have **control** over all the containers running. The lowest level is the actual containers, however *all* containers have a Container Supervisor which can issue commands like
```
start|stop|pause|...
```

## Building Containers
We first have to make a container image. This image contains all the dependencies. The image is made up of versions. Once we ship an image we can pick a version to run at *runtime*. You will be able to specify in the version what the program can control like images, config files, ... . 

> More information is located at [[]]
> This is a file on VM & Containers