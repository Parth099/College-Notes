# Domain Driven Design (DDD)
For: [[CIS4360]]
## What is DDD
Domain Driven Design is an software development approach for complex needs that connects the implementation of the software to business needs.

Its premise:
+ Place the project's primary focus on the core domain and the domain logic
+ Base designs on a model
+ initiate creative collaboration between technical and domain experts to **iteratively** solve the problem

This **methodology** helps projects get deployed when the domain is complicated.

## Aggregates
An aggregate in DDD is a representation of a real domain concept. This can be something like `Order`, `Invoice`, or etc. These aggregates usually have a life-cycle around them and this means they contain **state**. In DDD, we wish to treat aggregates as their own entity. 

When thinking about aggregate & microservices, a *single* MS will handle the life-cycle and data storage of many aggregates. If we want to manipulate data of these aggregates we need to call for a change directly (API) or have the aggregates respond to changes in their state directly. Additionally, an aggregate does not always have to respond to change. It can also reject changes.

### Additional Clarification
> Aggregate is a pattern in Domain-Driven Design. A DDD aggregate is a cluster of domain objects that can be treated as a single unit. - [Martin Fowler](https://martinfowler.com/bliki/DDD_Aggregate.html)

The example given in the above was an `order` entity and its `line-items`. These may be useful to package together. 

Aggregates are the basic element of data storage, you request to load or save aggregates. 

The Transactional line is drawn at aggregate boundaries. **No** transaction should cross aggregate boundaries. 

## Bounded Context
A Bounded Context represents a *larger* organizational boundary. Within this *boundary* explicit responsibilities need to be carried out.

When building models it gets progressively harder to build a single unified model as different sets of people call the same things with a different context. A "book" can mean different things to different departments, for one it may mean dimensions and weight(shipping) or it can mean price and discounts (sales).
### Example
Imagine a warehouse business. Here are some sample activities going on here:
+ shipping items
+ handling returns
+ keeping inventory
+ payroll
+ paying for shipments
+ ...

Bounded Context exist to *hide* implementation detail. A bounded context only contains the aggregates it needs for that business domain. The other domains have no *business* knowing about the life-cycle of these aggregates.

> **Summary**
> The aggregates is a self-contained state-ful machine focused on one *sole* business concept while a bounded context is a associated aggregates. Bounded Context represents a set of closed associated aggregates which are *not* needed anywhere else. 


### Definitions
> Core Domain: Area of the business that sets that business apart from others. 