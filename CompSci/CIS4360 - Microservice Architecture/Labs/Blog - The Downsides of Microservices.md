# The Downsides of Microservices
For: [[CIS4360]]
## Technical and cultural
Since Microservices introduce a whole not design pattern(MSA) to the production pipe line there are a lot of issues on the management side. Team leaders must be open to changing how their team operates and solves problems. This extends to employees too, they too must be open to new technical design patterns.

This also opens up another issues. The MSA requires employees to be *very* proficient in both Agile development & DevOps. This is because the main premise of MSA is small increment deployments/changes. 

## Complexity 
Because MSA is difficult to implement it poses risks when implemented incorrectly. One of the more common cases is when MSA is internally implemented as a combination of Microservices & Macroservices. This leads to a degradation in the *agility* that MSA was supposed to provide. The Microservices & Macroservices reduce the benefits of MSA because they are likely tightly coupled & do more than one task. Since each subsystem is larger than its Microservice Implementation it will not perform as well. 

---
- Agile: An **iterative** Software development style with development cycles known as sprints
- DevOps: A set of practices to test, build & deploy code in *small* and *frequent* steps. See $CI$ (Continuous Integration) and $TDD$ 
	(Test-Driven-Development)
	
