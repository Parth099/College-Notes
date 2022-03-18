# Election Example
## Background
Suppose we have a race where Candidate A(CA) is favored over   Candidate B(CB). Often times in the news that a proportion of people prefer CX to CY. This is only possible because only a subset of the population is sampled. 

Let $p$ be the real proportion of the people in favor of CA and let $q = 1- p$.

Then we choose a sample size $n$ from the population and represent each person with a random variable with $X_1, \dotso, X_n$ where $X_i = 1$ if person $i$ is in favor of CA and $X_i = 0$ if in favor of CB. 

$$\text{Let }S_n=\sum_{i = 1}^n X_i$$

Observe that  $S_n$ is HyperGeometric (see [[HyperGeometric Distribution]]).

Note that A HyperGeometric distribution is approximately Binomial. 

Then an estimate can be created with 
$$
\overline{p} = \frac{S_n}{n} = A_n
$$

<!-- to be finished when i get a better understanding -->