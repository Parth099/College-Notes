Associated with: [[Unit Testing]]
# Pure Functions
Strictly following TDD concepts we can learn to write better code in terms of Pure Functions. When someone starts to learn to code, their functions are *tightly coupled*. This means that one function is filled with other functions like DOM calls. This type of code is hard to test.  

Testable functions are **isolated**, calling them does not depend on calls from other functions.

Definition of a Pure Function
- The function always returns the same result when the same *args* are passed in. The function does not require the external state of the system, it only depends on its parameters. 
- The function must not produce any side effects like requests.

## Side effects
This means anything in the function that changes the state of the external scope. This can mean changing a variable or calling another function.$^{\alpha}$

This also implies that a Pure Function **cannot** depend on external vars. 

The goal here isn't to make all functions pure. A callback for an event does need to be pure, but pure functions have their benefits. Those are the ability to change the function and test it easily.


$^{\alpha}$ Recursive pure functions are **still** pure