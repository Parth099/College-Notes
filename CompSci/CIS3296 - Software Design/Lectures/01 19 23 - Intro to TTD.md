# Lecture January 19th 2023

## TDD - Test Driven Development
Tests are written **before** code is written to create a layout for implementing functionality and preparing test cases.  

Code is written to **pass tests** and it is **refactored** to do so. 

## Testing

#quiz

1. Construction Test		
	+ Occurs **during implementation**. 
	+ Faults are discovered while programming
2. Unit Test
	+ Started when code construction is complete
	+ Used to verify correctness
	+ Detailed examination of the operations of *each* function or module
3. Integration Test
	+ Started after unit tests
	+ The goal of 'Integration Tests' is to *test* the composition of tested modules.
		+ Modules can be built by different teams.  
4. Validation Test
	+ Torture tests or stress tests
5. Qualification Test
	+ Test of *legal* completeness (have all requirements met)
6. Regression Test
	+ Summary level test to show that an existing and tested system works after a change in the environment

## Unit Testing
> A code snippet written to test a piece of code

Unit tests are used to check if code meets design requirements and if it produces that *correct output*. (Helps highlight logic/algo failures).

Manual Testing requires a tester to play the role of the end user. This is:
+ Less Efficient
+ not structured
+ not repeatable
+ not comprehensive

Usually a team external to the current team that built the product is used for testing. 

## TDD - Test Driven Development Cont.

> Tests are developed before code is written

Steps: 
+ Write Test Driver and test runner
+ Attempt to run and compile
	+ revise code until this succeeds
+ Add code to implement functionality
+ Continue TDD process until module is finished

> Red $\to$ Green $\to$ Refactor

Note: It may not be to test a unit on every possible scenario it may need to handle. 

### TDD Rhythm for the Lab
1. Add a test
2. Run all tests to see failures
3. Make small changes to make test(s) pass
4. Refactor
5. Run tests again after refactoring (regression)

> Refactoring is the process of changing a software system in such a way that does not alter its behavior yet improves code structure. 

## Good Unit Testing
+ Fully Automated (test suites)
+ Can be run in any order
+ Runs in memory
+ Returns consistent results
+ Readable, Maintainable, Trustworthy