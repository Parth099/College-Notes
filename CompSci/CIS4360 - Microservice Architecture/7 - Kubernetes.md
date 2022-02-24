# Intro to Kubernetes AKA K8S
From: [Youtube](https://www.youtube.com/watch?v=VnvRFRk_51k)
> **Definition**
> + open source orchestration tool
> + developed by google
> + helps manages containerize applications in varying environments (physical, VM, ...) 

## The Problem Kubernetes solves
The trend of moving to Microservices from monoliths led to the increased use of containers. Managing these containers can be very complex and downright impossible when there are thousands of containers

## What features do orchestration tools offer
+ High Availability or no downtime
+ Scalability (Better Performance)
+ Disaster Recovery - backup and restore

## Kubernetes Basic Architecture
Each *cluster* is made up of one *master* node and then several worker nodes.
![[kb_arch.png]]

Each worker has a **kubelet** a process running on that allows workers to talk to each other and also execute commands. 

Then, each worker has Docker containers running on them. The number and type varies per worker. The worker nodes are the ones that run the docker containers. 

### Info on Master Node
The master node contains important Kubernetes processes. 
One of them is the API Server which is the entry point or our K8S cluster. This means that all of the UIs, CLIs, and APIs will talk to this internal API Server.

There is also a controller manager, it keeps track of whats occurring in the cluster like required repairs or errors.

There exists Scheduler decides where to deploy containers based on the given load of existing worker nodes.

Lastly\*, there is an `etcd` `key-value` storage. It has the current status of the cluster. This is where the Disaster Recovery comes in.

There is also a Virtual network that over-arches the worker nodes that unifies them into a single machine which is the sum of all individual resources. A worker node has **more** resources than a master node, yet a master node is more important. This is why many corps use many masters per cluster. 

## Basic Concepts
### Pods
A pod is the smallest configurable unit in Kubernetes. Each worker has many pods and per pod there can be many containers. Usually we have one pod per application. Recall, the Virtual network from above. It assigns **each** pod its own *IP* address which allows each pod to be its own server and thus they can communicate with each other. 

In K8S we only work with pods **not** containers. 
Now pods are ephemeral, they don't last very long. Each time a pod dies the Virtual Network will create a new pod and will assign it a new IP address. This can cause a lot of headache. 

### Services
Services replace the IPs in pods. They stand in front of Pods and assure that when pods die and get replace services still stand and the other pods can retain communication with each other. 

Features
1. Permanent IP 
2. Load Balancing

## Configuration
Each config talks to the API server, the only entry point into the cluster. All config files must be in JSON or YAML.

\* - there exists a lot more services than this