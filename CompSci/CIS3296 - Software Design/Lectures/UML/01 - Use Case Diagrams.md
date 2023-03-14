# Use Case Diagrams

![use_case_diagrams.png](../../img/use_case_diagrams.png)

## Preface
+ Rectangles are classes or instances
+ Ovals are functions or use cases
+ Instance of a class are denoted via underline


## Use of the Use Case Diagram
+ Specify the context of a system
+ Capture the requirements
+ Generate Test Cases
+ Developed by *domain experts*

## The Diagram
### Use Cases
Consists of:
+ Unique Name
+ Participating actors
+ Flow of Events, Entry/Exit conditions
+ Special requirements

### Example

![use_case_ex_1](../../img/use_case_ex_1.png)

![use_case_ex2](../../img/use_case_ex2.png)

---

### Relationships
#### `<<extends>>`[^1]

The `<<extends>>` relationship represent exceptional cases. They are **factored out** of the main case for clarity. 

![use_case_extends](../../img/use_case_extends.png)

> Watch the direction of the relationship. It should read "A" extends "B" in the direction of the arrow. 

#### `<<includes>>`[^1]

The `<<includes>>` relationship represents behavior that is factored out of the use case because it can be reused. 

![use_case_includes](../../img/use_case_includes.png)

> Watch the direction of the relationship. It should "A" includes "B" in the direction of the arrow. 

[^1]: Think about interfaces and `@override`