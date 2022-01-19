From [[Parminder Singh Kocher - Microservices and Containers first edition (2018).pdf]]

| Abbreviation | Expansion       |
| ------------ | --------------- |
| MS           | Microservice(s) |

## What Are MicroService?
> A microservice is an independent, standalone capability designed as an executable or a process that communicates with other microservices via HTTP or REST.

A MS is unique in the sense that it is tested and scaled to meet with demand independent of other MS. This is because each MS only completes one function (does one thing).  

An Example is an order processing MS. This MS will do nothing but process orders. It will **not** handle things like notifications and billing but instead will call on other MS to do those tasks.

With this set of definitions we can say that a microservice-based application is simply a set of *independent* microservices that communicate via well-defined protocols to provide a singular functionality. 

### MicroService Calculator
#### Monolithic
Consider a **Monolithic** Calculator Web Application.

Each operation, $+, -, *, /, \dotso$ may be defined as functions that may call each other. 

![[mono_calc.png]]
Sample Monolithic Architecture

#### MicroService
While a MicroService Calculator maybe overkill its a good example. 
![[micro_calc.png]]
Sample MicroService Calculator.

Notice that each simple operation is a MS. This means that if Addition goes down the other 3 will **not** be effected. 

Notice that MS divides the App into smaller stand alone problems which can be developed faster and **independently**. Imagine we have to add in a *square* function to this calculator. We will simple call the **published** multiply API. MS can also be scaled on demand. 

An alternate idea is that of *helper microservices*. Say we have 3 groups of MS but an end-user can only call one of them. Groups 2 and 3 MS only serve to assist Group one MS.

For medium to small companies, a monolithic system may work. However for *large* applications, monolithic systems suffer from 
- Performance & Scalability Issues
- Long cycle of Testing
	- This testing includes upgrades & regression testing. Since the cycles are long, small bugfixes take very long.
- Potential downtime over upgrades
- No way to scale just the components you *need*. This one is important. 

Suppose we wished to decompose a monolithic app into a MS-based app. One problem we may run into is legacy code. If we wished to update to a newer language we would have to put in a **lot** of work. In a MS we can alter anything and as long as we run standard testing we can integrate it into the main system. 

### Modular Architecture
According to reports, enterprise software remains valid for 4-6 years before it falls into obsolescence and needs to be replaced. Now not everything does, this is where Modular Architecture comes in. Modular Architecture will allow companies to only update what they need.

### Other Benefits of MS
1. Simplicity - Since each MS has one job this creates an easy to track dependency graph and thus its less bug prone.
2. Scalability - We only need to create duplicates of required MS. For example, if the addition unit is being used a lot on the MS Calculator, we can simple add more Add units. 
3. Continuous delivery 
4. More Freedom
5. Fault Isolation & Bug Tracking - A fault in one MS may bring down the set of MS that use it but not the *entire* application.
6. Data segregation and decentralization - We no longer have a singular data-based. Each MS has its own Data store.
7. Choices - Since all MS are loosely coupled. We can make separate choices for all of them. One may run an relational database where another runs a NoSQL DB.

### Disadvantages of MS
1. Troubleshooting
	-	Since MS communicate with other MS via API/Inter-MS communications there are more points/chances for failure. 
	-	Sometimes its hard to think about where to even start.
	-	One the flip side Monolithic Apps have a trace to find a bug.
2. Latency 
	- API/Inter-MS communications make apps slower
3. Operational complexity
	- Since there is a lot of MIcroservices in one application there will be a lot of complexity with all the standard app protocols like deployment, monitoring, backups and etc. 
4. Version Control 