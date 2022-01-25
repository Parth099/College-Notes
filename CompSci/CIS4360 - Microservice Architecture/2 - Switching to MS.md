# Chapter 2
For [[CIS4360]]
## Signs you need an 'Upgrade'
By 'Upgrade' I mean the switch to MSA
- A difficult development process
- Large & Complex code base
- Some areas of the app require more scaling than others
- High cost of development, testing, and deployment
- Failure of one area of the app will crash the *entire* app

## Other requirements
### Culture Change
The mindset must shift from functional roles to those aligned with specific business areas. Now this means creating teams of testers, devs and business people to take lead in a microservices. Independence is a hallmark of MSA. Additionally this requires the hiring of new talent and training staff on new tech.  

### Operational Process
Now that we are shipping smaller services we must act in such a manner. The previous monolithic operations like development and testing will need to be broken down to support the concurrent development of MS.

## Learning Curve
There is a whole learning curve for MSA.
Here are the important learning points for MSA.

- Standalone Microservices - must learn to maintain **many** MS at the same with the same attention.
- Microservices Discovery - The more microservices exist the more complex the mesh becomes. This is also related to version control and choosing the ones you need to be active.
- Inter-MS Communication - Choosing and implementing Inter-MS Communication along with reducing latency is hard. 
- Testing a collection of microservices
- Security
- Management & Monitoring
	- With countless MS in place we must manage resources like CPU, Memory or I/O. This data generated off this monitoring can be used to improve the MS
- Error Handling - An Error is inevitable however, each MS must be designed to be able to operate with a partial service outage. (An outage of services unrelated to it)

All this to say that any organization planning to switch to MS must put forth many resources to make the switch.

## The Business Case
After reading this a possible thought is:
> Ok There seems to be a lot of hardships with Microservices. Why do them at all? 

Note the average life-space of a Software:
$$4-5\text{ Years}$$
This is low because:
- Changing need of customers
- Lack of Flexibility (hard to adjust/change architecture)
- Lack Scalability
- Outdated Tech
- Slowness due to above two reasons

When a software expires, a company starts to look at new technologies and then invest in a *new* next-gen solution.
This is known as the platform refresh cycle.

## Cost Comparison
### Monolithic Apps
#### Cost to Build: $M_{CTB}$
This is the standard for any Mono-app. This will be the sum cost of all the development cycles like design, development & testing.
#### Cost to Maintain: $M_{CTM}$
This is thing like bug-fixes and patches
#### Cost to update: $M_{CTU}$
Cost of adding new features and testing to do so (regression).
#### Cost to Scale: $M_{CTS}$
Cost to respond to change in traffic/user-base
#### Time to Market $M_{TTM}$
Time taken to put the app into production. 

### Comparison To MSA
Cost WRT MSA will be denoted by $S$

#### M$_{CTB} \lt$ S$_{CTB}$
Based on [[#Learning Curve]] we know that MSA isn't cheap due to training and new hires/roles.
#### M$_{CTM} \gt$ S$_{CTM}$ **|** M$_{CTU} \gt$ S$_{CTU}$ **|** M$_{CTS}$ $\gt$ S$_{CTS}$
Maintaining hardware or applying patches in MS will not cause downtimes like Mono-app will. 

Updating to a MS is easier since we only need to push updates to the services that need it rather than the entire app. 

We already know about the scaling ability of MSA. Instead of cloning a whole entire codebase like in the case of Monolithic apps we will only need to add a duplicate microservice with a load-balancer.

#### M$_{TTM} \gt$ S$_{TTM}$
Adding a new service in a MS is much faster than in a Monolithic app. 
For additional Information See: "DevOps"

![[costComparison.png]]