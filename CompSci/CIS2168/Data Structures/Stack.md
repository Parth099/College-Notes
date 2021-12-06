

# The Stack
The Stack is a [[Data Structure]] created to optimize one ended Add/Remove operations.

You can imagine this is a stack of books. You an either add a book on top or remove a book off the top. These 2 operations are the core of *Stack* DSA

## Methods

| Method                  | Description                                                |
| ----------------------- | ---------------------------------------------------------- |
| **boolean** *isEmpty()* | returns if stack is empty or not                           |
| **E** *peek()*          | returns the object at the top of the stack without removal |
| **E** *pop()*           | returns the object at the top while also **removing** it   |
| **E** *push(E obj)*     | adds the obj on top of the stack                                                           |

## Implementation

The implementation for the stack doesn't take much imagination. One option is a abstraction layer on the `ArrayList` class. The best option to optimize add/remove times is actually a custom `LinkedList`. If a pointer to the tail is kept the addition/deletion is *trivial*.

In a `LinkedList` implementation, both `push()` and `pop()` will be $O(1)$. While an `ArrayList` would have to reset the internal array when a size cap is reached.  