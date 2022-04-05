# Bayes Probabilities
For: [[Probability Theory 1]]

Continuation of [[Discrete Conditional Probability]]

Recall the Last example from that note about the Bag and Balls.

See that in the example we used a tree in which we picked the bag first and then the ball. The reverse is: 
![[reversetree.png]]

Such an *inverse probability* is called an Bayes probability. 
From the normal tree or basic logic we note that 
$$P(\text{Black Ball}) = \frac{9}{20}$$

Now if wanted we wanted to assign a probability to the topmost branch we only need
$$\frac{9}{20}\cdot x = \frac{1}{5}$$
$x = \frac{4}{9}$ which agrees which our data. 

This tree *does* display all the *inverse* probabilities.

## *Famous* Monty Hall problem
Suppose you are on a gameshow where you have to pick between three doors. One door has a ***new car*** while the other 2 have goats. 

You pick door $\#1$ initially. The host then open door $\#3$ and reveals a goat. Is it a good idea to shift your door to $\#2 ?$

**Note**: Host *always* picks a goat door and the car's location is random

Marilyn vos Savant gave the solution to switch since it would jump your winning probability to $2/3$. This became a point of controversy since some agreed and some didn't. 

We can ask a simpler question to help solve the problem. 
What is the chance of winning the car if the contestant does **not** switch his answer. The clear answer is $\frac{1}{3}$ since the car is being one of three doors. 

Now we examine the swap doors strategy.
The stages are:
1. The car is placed being a door
2. Contestant picks a door
3. Host opens *goat* door

We then make a tree out of this:
![[montyhall.png]]

Now lets go back to the problem
> Contestant has picked door $1$ and the host opened door $3$

We note the car cannot be behind door $\#3$

Only 2 paths are now possible

###### Path 1: Placement of the Car is in Door 1
If we follow the path this has a probability of $1/18$

###### Path 2: Placement of the Car is in Door 2
If we follow the path this has a probability of $1/9$

Hence Door 2 is by far the better choice. 