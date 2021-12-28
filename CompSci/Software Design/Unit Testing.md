# What
Unit-testing is defined in its name: it is a system of testing a isolated unit in system.

Unit: Smallest piece of code that is part of a system. Usually, this is a Function or Method.

Units are always isolated. You cannot test units that reply on other *external* systems.

# Why?
In TDD (Test Driven Development) an engineer writes *tests* before any production code. This sets up a contract which the code must pass in order to be pushed, a sort of living documentation. Moreover, this helps a developer keep track of what cases exist to a function. 

Because Unit Tests test 'units' of code, the addition of code does not change the outcome of pre-written tests. Additionally, with tests a bug can be traced back to its origin if unit tests exist. 

# Disadvantages
It is impossible to write tests for all scenarios, and thus 100% coverage is impossible. 

Writing good tests takes time, this adds up over the summation of the program. 