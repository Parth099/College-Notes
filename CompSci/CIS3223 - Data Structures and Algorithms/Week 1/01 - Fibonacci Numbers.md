# Fibonacci Numbers

## Rabbits Example
Suppose pairs rabbits never die and always produce a pair male and female babies  each iteration.

Initially their is one pair of rabbits.
During the 2nd month they start to mate. 
Then, the next month there exists a baby pair and the original pair.
Then the babies grow up so the pair total is 2. However the original pair has a pair of babies.

We notice the number of rabbits at each level is 
$$R_n = A_n + B_n$$
Where $A_n$ are the number of rabbits currently alive and $B_n$ is the number of babies alive. 

Notice the number of adults alive depends on the number of babies last round and the adults alive last round. This means that $A_n = R_{n-1}$. 

We notice that $A_{n-1}$ baby pairs are alive currently. This is because each adult from the last iteration makes a pair of babies. Using the relation we developed above we notice that 
$$R_n = R_{n-1} + R_{n-2}$$

## Golden Ratio
We define the golden ratio $\phi$ as:
$$\lim_{n \to \infty} \frac{f_n}{f_{n-1}} \approx 1.618034$$