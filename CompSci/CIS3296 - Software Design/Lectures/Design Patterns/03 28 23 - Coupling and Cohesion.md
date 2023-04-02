## Coupling and Cohesion
### Coupling
+ Coupling refers to the degree of interdependence between software components.
	+ When two components are highly coupled, changes made to one component will have a significant impact on the other.

> Components vary in granularity: classes, packages, functions, ...

#### Direct Dependencies
Direct Dependencies are explicit dependencies such are import statements are required parameters. 

#### Indirect Dependencies
Dependencies that you cannot spot by looking at the code.

Examples
1. Constants defined by other classes including shared variable
2. Replying on OS constants like system registries or env vars
3. Relying on file formats
4. Relying on an order of instantiation
5. Assuming a database schema
6. Replying on open ports and specific ports/IP addresses.  

### Law of Demeter
> Do not collaborate with indirect objects

In a method you should only invoke methods on:
1. `this` or an attribute of `this` including something inside a collection of `this`
2. a parameter of the method
3. an object created inside the method

Example:
If class `A` needs to collaborate with `D`, `A` should not need to interact with `D` via some classes `B` or `C`.

$$
A.D \gt A.B.C.D
$$

> `>` represents 'better'

If there is a lot of object chaining, `A.B.C.D`, usually this is not good. 


### Cohesion
+ Cohesion, on the other hand, refers to the degree to which the elements within a single software component are related to each other.
	+ High cohesion means that the elements are strongly related and work together towards a common goal, while low cohesion indicates that the elements are loosely related and may not work together effectively.



##  Maintainability and Flexibility
+ Maintainability refers to the ease with which software can be modified or updated over time without introducing errors or causing unintended consequences.
	+ The `open-closed` principle states that components should be open for extension yet closed for modification. 
+ Qualities of Maintainability
	+ Analyzablity - bug finding and readability 
	+ Changeability 
	+ Stability - changes to code do not lead to large number of bugs
	+ Testability 
	+ Flexibility - ability to be extended rather than directly modified

