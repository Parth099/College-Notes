# Docker Containers
For: [[CIS4360]]
When someone switches to MSA there are usually 1000s of services to host, deploy and manage. This is where containers come in.
## What is Docker?
Docker is a open source technology that aims to solve deployment and scalability issues by separating applications from the infrastructure dependencies. What happens here is that we package an application with all of its dependencies like 
> directory structure, metadata, processes space, sets of ports, ...

This packaged Application **will** run on any machine/environment with the same behavior. 

## Virtual Machines (VMs)
A VM is a *self-contained* system that has its own Operating System(Guest OS). A VM will contain an application and its environment. A VMs can help a company utilize their hardware better as they will not have to make physical servers for their individual services. 

### HyperVisor
A host machine (*physical*) can host more than one VM on its hardware. To get this working we need to install a layer called the **HyperVisor** on top of the Host OS. It acts a as proxy for the hardware, it gives the individual VMs that they are running on  their own *dedicated* hardware.  

![[VM_deeper_look.png]]
Cite: (Parminder Singh Kocher)

### Props of a VM
- Efficiency
- Flexibility in resource allocation
- Backup and recovery. The state of a VMs is contained in a *single* file. This is easy to store and move. Some softwares like VMware support the *live* migration of VMs.
- OS Freedom

However a VM isn't always the right answer. Since an VM contains an OS this eats a lot of storage space. This can be hard to move. 

The layering with the HyperVisor(HV) also causes issues. We note that the Guest OS has to talk to the HV which has to talk to the OS which has to talk to the hardware. It can be seen that this can be inefficient. 

> **Note**:
> HyperVisor Type 1: Installed on the Hardware. Can communicate *directly* to the hardware
> 
> HyperVisor Type 2: Software based. Must talk to the guest OS. 


## Containers
> Containers also provide a virtual environment that packages the application processes, metadata, and file system—everything that is required by an application to run. (Parminder Singh Kocher)

But unlike VMs containers **do not** require their own OS. Instead they are just wrappers around a UNIX process that talks directly to the kernel to request and use resources.
> *What is a kernel*:
> The kernel is the most important part of the operating system. It is the primary interface between the hardware and the processes of a computer.
> A kernel has **complete** control over the system & hardware.

![[container-visual_1.png]]
First thing we note is that containers provide **total** isolation, no *App* knows about the existence of the other one. However, all the *Apps* run on the same hardware \& Kernel. 

This is because containers utilize the resource isolation feature of the Linux kernel. Since we do not require an OS we can run more apps in a container than we would be able to in a VM. A Linux based container is know as a LXC: Linux containers. 

## Docker
Containers have existed for a while but they have gained their popularity thanks to `Docker`. Docker is an open source software that made several changes to LXCs to make them more portable \& flexible. These new features allowed for easy creation, shipping, and copying of containers.

### Difference between Docker and Linux Containers
+ Within an LXC you can have multiple processes where are Docker containers are restricted to only **one** process. If a program has $n$ processes you must also have $n$ containers in docker. Due to this restriction you can micromanage: manage at a granular level. 

+ Docker Containers are **stateless**. 

+ Docker containers **are** more *portable*. 

## Docker Architecture \& Components
Docker uses the client–server architecture whereby the client interactions with the Docker Daemon which provides the Docker services.

### Docker Server or Daemon
Runs on the *host* machine and manages all containers.

### Docker Container
Is a standalone virtual system that contains running services, and all their subfiles \& dependencies.

### Docker Client
A UI or CLI to talk to the Docker Daemon.

### Docker Images
Read only template files of a Docker *container*. These files can be part of a Version Control System. There exists layers to these docker files. Suppose you ship an Image Update. This update simply goes to the top layer of the image. This implies we can deploy any layer we need making deployment faster. 

### Docker Registry
> repository for sharing and storing Docker container images.

A popular option is `DockerHub` like github. 

### Dockerfile
Simple text file where we specify all the commands to build Docker Images. We can use it to install dependencies, set up environment vars, working directories, and etc.

### Docker Machine
Used to host from local machine. 

### Docker Swarm
Swarm is capable of a clustering action where a pool of docker nodes act as one larger docker host. 

### Docker Compose
Usually each app has many components and by extension is running on many containers. The Docker Compose tool allows you to define these components and run them. 

This will be extended later much like the other empty explanations.

## Example
Suppose you have a `wordpress` site with three parts:
1. Web Server with `wordpress` apps
2. Some form of Database likely relational
3. Storage to store 1 \& 2

### VM Version
If you attempt a VM approach we can have these three parts in 1 or more VMs. Now you will have to install the software(i.e SQL or `Wordpress`) on each OS. 

### Docker Version
Note that we need a container for each separate process. 
#### A
We need a Data Container. We can get any Linux image off the registry and run it. This is because we want a file structure and storage to store our data.
#### B \& C
We need a Database Container. We can simply install an image for this service.We do the same for the `wordpress`. 

## IBM Explanation of Containers and Docker.
### Example
Suppose we created a `Node.js` application and want to push to production. 

Taking a look at VMs (and as stated above) we note that a VM-based process has a Hypervisor and a HOST OS. This *already* consumes some resources. Then to push our `Node` app we need to put it in `Linux VM`. This can be shown to be *bloated* as we have the app itself and the Hypervisor/OS(multiple). Scaling this app we would need to copy the Guest OS and libs every time for out `App`. 

New we can examine a Docker based implementation. We first need the Dockerfile(manifest) to create the container Image with all of its required files.  
$$\text{Manifest} \to \text{Image} \to \text{Container}$$

So we have a `HOST OS` and a `RUNTIME Engine`(container controller). And **then** we have the app itself which can be scaled faster since its lighter. Then suppose we want to add in an another dependency. Like having your `Node.js` app call an `Python` API. In a container system we can deploy the python app and then update the rest of our containers to call it. 

In a container based stack when resources aren't shared they are available to other process that need it \[the processes that need it\]. 
From: [Link](https://www.youtube.com/watch?v=0qotVMX-J5s)

## Definitions:
>  **Client Server Architecture**
>  is a computing model in which the server hosts, delivers and manages most of the resources and services to be consumed by the client.

> **Daemon**
> is a program that runs in the background and does some useful system function. It usually starts when you boot the machine or when you log in. You do *not* launch daemons yourself. 