| Week |
| ---- |
| 4    |

# Simulated Annealing

> Simulated annealing (SA) is a probabilistic technique for approximating the global optimum of a given function. -[wikipedia](https://en.wikipedia.org/wiki/Simulated_annealing)

The way this works is that the system starts out in some system $s$ and considers the neighbors of $s$ . However it also has some chance $p$ of moving to another state $s^*$ to find the "answer" there. This is repeated until conditions are met or the iteration has gone on for too long.  That chance $p$ is determined by the "temperature" function which changes over time[^1]. The temperature acts as a control parameter that determines the probability of accepting a new state. The temperature is typically decreased according to a schedule[^2]. When the temperature is high, the 'Simulated annealing' is more lenient to switching to other states. 

Lets take finding the minimum of a function $f(x)$ on $I$ as a example. When the temperature is high it will jump around the interval. This is because we might get stuck near a local min and the fact that the point can jump around during high temperatures can help reduce this error. 

The simulation has a acceptance function that helps it determine if a solution is "good enough".

Simulated annealing is directly related to [[Week 3 - Random Walks]].

[^1]: The literal function doesnt change only the outputs it gives. 
[^2]: linear or exponential schedule