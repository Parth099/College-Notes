# Domain-Oriented Microservice Architecture \[DOMA\]
> The point of my presentation would be to **clearly** explain why we **need** DOMA and what does it bring to the table along with how it works. 

Main Article : [Uber - Engineering](https://eng.uber.com/microservice-architecture/)

I chose this option because I want to expose myself to more design principles and it gives us a glimpse of how a larger company operates WRT software.  

## The problem with *regular* MSA
Uber has recently taken up Microservices however, it was faced the same problems many large microservice adopters have: **complexity**. As the number grows (to `2,200` in this case) Microservices get hard to manage. 
### Why is this a problem?
+ More nodes => More security threats
+ More Services to test
	+ This extends to Fault tolerance, Microservice coordination, and more. 
+ Latency (communication and coordination)
+ Debugging: Uber states that they had to investigate **50 services** over **12 teams** to find the root cause of a bug. 
+ Collaboration is hard when service calls are nested deeply.

## DOMA
> Doma is only **novel** in the way that it is a **new** way to employ *established* design principles. (for larger-sized orgs.)
## Doma Vocabulary
1. Domain
	+	Usually we focus a Microservice on a service we want. DOMA will focus on a **domain** or a set of related services. 
	+	From DDD, a domain is a business area. We build software **based** on the *rules* of a business area and not the other way around. (src: [martinFowler](https://martinfowler.com/bliki/DomainDrivenDesign.html))

2. Layer - Design
	+	These are collections of domains. The layer of a domain is determined by its dependencies. 
	+	According to [DZone](https://dzone.com/articles/layered-architecture-code-smells-medium), layering creates a separation of concerns.
	+	This architecture only exposes layers that are neighbors to each other.
		+	If we look at this closely we can see that one of our issues is getting solved right here. Since only layer neighbors can communicate, we can debug *faster*.

3. Gateways
	+	A gateway is a clear point of entry into a collection. This can also serve as an entry into a design layer (\#2)

4. extension architecture
	+	The number one rule is that **no** domain should be **coupled** with another domain. However, this is hard. Since developers on Team A will often require custom support (code) from Team B we should provide **extension architecture** to support their needs.
	+	This was hard for me to understand when I saw it. A comment from [ycombinator](https://news.ycombinator.com/item?id=23937005) helped me understand this: 
		+	Instead of injecting custom code (maybe validation) into a microservice, we can *extend it*. 


## The Uber Implementation
> This is what I would want to go into in detail on the paper so I will not do so here.

### Domains
Uber gives **no** guidance on how to split domains. Their advice is to think about the role of **each** collection. 

### Layer Design
The answer here is what service should be able to call what other service. Their Layer Design is built with specific services at the top and more broad services at the top. This means that an outage of **broad** services is a **major** outage. This makes logical sense too since **more** services will depend on *broader* services. 

### Gateways
As we defined we want an **exclusive** entry into a *collection*.

### Extensions
We want all of our custom features to work without having to alter already working microservice code. We **must** extend this service. 
 
 There are two types of Extensions at Uber:
 1. Logical
 2. Data

## Benefits
Since Uber has adopted extension architecture, the development time for new features. (reduction of operational and developmental complexity and thus an increase in maintainability)

