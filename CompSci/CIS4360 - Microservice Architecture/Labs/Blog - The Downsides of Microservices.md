# The Downsides of Microservices
For: [[CIS4360]]

## Technical and cultural
Since Microservices introduce a whole lot of design patterns(MSA) to the production pipeline there are a lot of issues on the management side. Team leaders must be open to changing how their team operates and solves problems. This extends to employees too, they too must be open to new technical design patterns.

This also opens up other issues. The MSA requires employees to be *very* proficient in both Agile development & DevOps. This is because the main premise of MSA is small increment deployments/changes. MSA also needs the creation of new roles to support the MSA dev cycles.

## Complexity 
Because MSA is difficult to implement it poses risks when implemented incorrectly. One of the more common cases is when MSA is internally implemented as a combination of Microservices & Macroservices. This leads to a degradation in the *agility* that MSA was supposed to provide. The Microservices & Macroservices reduce the benefits of MSA because they are likely tightly coupled & do more than one task. Since each subsystem is larger than its Microservice Implementation it will not perform as well. 

Tracing bugs can also become a new nightmare. Since there exist many (100s or 1000s+) microservices in a single system one can presume that bug tracing can be a lot harder. For one we first need to establish where the bug is coming from. For microservices that rely on other services, we need to find the afflicted one *first*. Version control is also harder.

## Latency
We first note that 2 microservices must communicate in a predetermined way. This can be via a RESTful API or simple HTTP methods. This added layer of distance (metaphorically speaking) between one microservices and the service it needs creates latency between what we need and who needs to call to get it. This type of latency will **not** exist in monolithic systems as all functionalities *are* present to all entities in the system. There exists a greater latency when we account for all the different databases that need to be contacted per microservice.

## Conclusion 
In addition to these issues, we also note that it is more beneficial for small-medium companies to remain monolithic than convert to a Microservice Architecture. This is because of the overhead caused by the disruption of an MS development cycle. Moreover, the benefits of MS will not be recognized by a smaller business since it doesn't need to scale and deploy quickly like a *larger* enterprise. 

### A Microservice Alternative: **Mini**service
A Miniservice is the middle-ground between Microservices and Macroservices. 

A Miniservice is a microservice with the loose rules of MSA. The individual components are larger and can implement more than one function. Since the program is still very much divided it still retains some of the benefits of microservices like fast*er* deployment & scalability.   

---
- **Agile**: An *iterative* Software development style with development cycles known as sprints
- **DevOps**: A set of practices to test, build & deploy code in *small* and *frequent* steps. See $CI$ (Continuous Integration) and $TDD$ (Test-Driven-Development)
- **RESTful API**: API that follows the REST protocol. A REST API is at it core *stateless*.