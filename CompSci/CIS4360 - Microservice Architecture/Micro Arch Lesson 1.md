BackLink: [[CIS4360]]

# What are Microservices 
See that in a Monolithic application all the business logic appears in one piece. There many be many files but only one entry executable/deliverable. There are several faults to this.

See [War File](https://en.wikipedia.org/wiki/WAR_(file_format))

> Microservices is an architectural design for building a distributed application using containers. They get their name because each function of the application operates as an independent service. -[Src](https://avinetworks.com/glossary/microservice/)

The Microservice Architecture treats each function of an application as an independent service when can be altered by it self without affecting the entire network of Microservices. They are self-contained.

# Why Might you choose Microservices?
A singular failure will not cause a fatal crash for the entire system. An example in class was the Netflix User preference Microservice. If this service goes down Netflix users will not be effected by this issue. However, in a monolithic application, this would cause an outage for Netflix. Isolation of services can is proved to be beneficial. 

## Challenges with Monolithic Software
- Difficult to scale
- Long Software scale: Build/Test/Release
- "Module X is failing" Who did it?

# Microservice Architecture
A collection of small autonomous services. Each service is loosely coupled and contains an API which represents a single business activity. 

In a Microservice Architecture, each internal Microservice does not share the same data store.

# Containers
Containers are isolated but share OS and appropriate resources.

%%
# Monitoring
A Microservice Architecture can have thousands of individual services. ---
%%
