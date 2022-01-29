For [[CIS4360]]; Date: 1/27/2022

# Lecture 2 Notes
## Actions
The decision to migrate to MS is irreversible.  
Example of an irreversible action is Changing your public API since it requires a Global Buy-in. Since it requires a major investment & a shift in culture. 

A reversible action maybe something like picking a Open-Source lib and experimenting. The cost to delete this is very low $\implies$ reversible

## Design
See Waterfall Design.

## Fake Microservices
'Stateless' does not imply MS since many times state is still being pulled into a shared DB. 

## Bounded Design
Each service defines its own domain & data storage. For example, a payment microservice that is bound to a single data-base and has its own domain.

### Example
At Amazon `book` may have many contexts WRT Business Units.
From A Recommendation perspective, this will be a list of books often bought together with said `book`.
From a shipping perspective, this `book` will only have shipping data like
+ dim
+ weight
+ international restriction

From a Shopping Cart perspective, the data will be :
- price
- discount eligible / codes

Any Software System is a model of reality, it is **not** the reality itself. For example when we check our banking details it is not our real balance it is representation of reality. A Bank teller is a different model with different details from what is show for you. 

We split the model WRT Teams/departments

### Example
Imagine a Product on Amazon.
The sales team needs only:
+ Description
+ Product Images
+ Prices
+ Dimensions

Inventory May only need
+ Stock & Availability

Shipping Department may only need
 + Shipping Price WRT Regions
 + Options
 + Dimensions

These are Bounded Contexts, DDD pushes for efficient communication between people by focusing on the business domain. The Business domain allows us to define the boundaries of the Microservices. 