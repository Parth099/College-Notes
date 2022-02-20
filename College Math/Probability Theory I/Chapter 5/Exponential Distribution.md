# Exponential Distribution
+ The time between the events in a Poisson Process

## Examples
| Poisson                                      | Exponential                          |
| -------------------------------------------- | ------------------------------------ |
| Number of cars passing a toll gate in 1 hour | Number of hours between car arrivals |
| Hipsters arriving into a bar per min         | mins between hipster arrivals        | 

| Poisson                          | Exponential               |
| -------------------------------- | ------------------------- |
| Events per single unit of time   | Time between events       |
| Discrete ($X = 0, 1, 2, \dotso$) | Continuous on an interval | 



## Requirements
1. Events must occur at a constant rate
2. Events must be independent of each other

$$\implies \text{ memoryless}$$

## An example
> **Problem**:
> On Average you complete $6$ homework problems per hour. 
> 1. What is the probability you complete less than 2 problems in 20 mins?
> 2. What is the probability you complete a homework problem in between 5 - 8 mins

### Work
See that $$\lambda = 6$$
#### #1
$$\frac{6 \text{ Problems}}{1 \text{ hour}} \to \frac{2 \text{ Problems}}{20 \text{ mins}}$$
$$\text{Hence, }\lambda = 2$$
Since we need up to 2 problems completed we need:

Let $X \sim \text{Poisson}(2)$, We need $P(X < 2)$
Since the Poisson is discrete, all we need is 
$$
\begin{align}
P(X < 2) &= P(X = 0) + P(X = 1) \\
&= e^{-2}\frac{2^0}{0!} + e^{-2}\frac{2^1}{1!}\\
&\approx .4 
\end{align}
$$
#### #2
$$\lambda = \frac{6 \text{ Problems}}{60 \text{ min}} = 0.1 \text{ prob/min}$$ 
$$
\begin{align}
P(5 \lt x \lt 8) &= P(x \lt 8) - P(x \lt 5)\\
 ^*&= (1 - e^{-0.1(8)}) - (1 - e^{-0.1(5)}) \\
 &\approx 0.1572
\end{align}
$$

\* - See the CDF for exponential in [[Important Densities]]