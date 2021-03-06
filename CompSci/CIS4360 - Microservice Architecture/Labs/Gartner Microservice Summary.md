# Summary
| Abbreviation | Extended                   |
| ------------ | -------------------------- |
| MS           | Microservice               |
| MSA          | Microservices Architecture | 

For [[CIS4360]]

## Initial Assumptions 
> Microservices enable unprecedented agility and scalability, but the architecture causes significant cultural disruption. Application leaders should understand this new design paradigm, its prerequisites and its disruptive impact before determining where and when to use it — if at all.

Article likely talks about the appropriate situations of MS. References "culturally disruptive" as a downside of MS. 

## MSA
**Microservice (MS)**: 
>tightly scoped, strongly encapsulated, loosely coupled, independently deployable and independently scalable application component

MSA is a architectural paradigm and model to building cloud-native apps. The *goal* of MSA is to enable dev teams to independently develop and scale individual components within an app.

Orgs that adopt MS do so to support their CD practice. 
CD or Continuous development is when updates are made incrementally instead of piece by piece. 

However, CD & monolithic code don't mix well as it gets hard to track bugs whereas MSA adds new feature as components which reduces the risks. 

The overarching principle of MSA is independence because we minimize dependencies between components. Moreover, new features can be developed without having to wait for a release date.

## Granularity
See that the term Microservice does not regard size, a pure component can be as large as it needs to be. 

> **Granularity:**  how small each component really is, not WRT size but its job.

Of Course not apps need to super Granular, we an relax MSA rules to allow for larger components but this decreases the benefits of Agile(See [[What is Agile]]) like scalability. 

Granularity is related to scoping as well. Tightly scoped Microservices are very *disposable*. By this I mean MS that have minor interactions with other MSs.  

### 3 Levels of Granularity by Gartner
1. MicroService: We know what this is 😎. A MS adheres to strict rules to support agility & scalability. It must be independently scalable & disposable. Implements a **individual** feature. If a MS has state, it has exclusive rights (CRUD) to its data store. It never has its API exposed for external use. This is fine-grained. 

2. MiniService: The MSA rules are loosed to avoid the disruptive aspects. 

A MiniService is like MS but its scope is larger and is a larger component. Moreover, it may implement more than one feature and may not have *exclusive* access to its data store. Oftentimes, the interdependencies here led to a harder time scaling up. This is coarse-grained

3. MacroService: Often traditionally an API, it is a monolithic application with an exposed API. Its scalability is not good. This is large-grained.

#### 3 service types Examples:
Lets suppose we wish to implement a checkout feature via an ideology.
- A MacroService would implement the checkout API as a part of the core functionality. 
- A MiniService would implement checkout separately outside of the core app
- A MicroService would breakdown checkout into smaller chunks and then implement each small component.  

We should not assume that because it seems like a Microservice it is. A MS can be an REST API (See [[What is a Rest API]]) or held in a container. The point is that just because it seems one way it doesn't have to be.  

## APIs & MS
The goal of Independence VIA MSA means you should never create dependencies via MS components.     
![[Pasted image 20220116223439.png]]

## Overall MSA Benefits & DrawBacks
### MSA Benefits
- Agility
	- facilitates a CD practice allowing for fast deployment
- Risk
	- Risk is lower in MSA since each deployment is small is loosely coupled.
- Distributed Development
- Technology flexibility
- Scalability
- Resiliency 
	- MSA design allows for self-healing apps that continue to work in the face of partial outages.

For some benefits of MS without some of the drawbacks a company an implement Miniservices.

### MSA Drawbacks
#### The Cost of MS Adoption
- Technical and cultural: people must be willing to change
- Agile and DevOps: Requires people with solid competency in agile and DevOps.
- Change in data governance 
- MSA requires new complex application infrastructure which will impact operational, networking & security models.

 #### Risks
 Because, MSA is complex its often implemented poorly resulting in poor performance. Sometimes, companies that say they are doing MSA are really just implementing MiniServices & MacroServices as many orgs are not ready to embrace the disruptions caused by MSA. This disruption is classified by need of more people with advanced architecture skills, new roles and organizational structures.
 
 MSA often requires the adoption of new application infrastructure like containers. 
 
Gartner Report goes on the regurgitate the preqs to adopting MSA mostly talking about how your dev teams should be prepared. 

## MS Alternatives
1. MiniServices

This seems to be the in between to MS & Monolithic apps. We can create larger components than MS but they are still easier to scale than Monolithic apps.

2. Low-Code Methods

This is like building an APP via a visual methods. 
 
 ## Gartner Recommendations
 Gartner tells readers to approach MSA with caution, this is because most organizations don’t have the *agility* to complete the conversion. Moreover, due to its recent emergence MSA is till immature and major tools for MSA creation are a few years away. 
 
 Gartner tells prospective converters to slowly turn their Monolithic application into Mini-Services and then micro services if really needed. They should not be afraid to mix architectures, there are no rules to which type of service can be used with which.  

 