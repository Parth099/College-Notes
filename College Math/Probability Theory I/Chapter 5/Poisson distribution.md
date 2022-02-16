# Poisson distribution
Cont. from [[3 types of Distributions]]
## Theory - Checkout Line Example
> **Background**
> Lets say you are a cashier.
> It is 4:30 om and your shift ends in 30 mins.
> The policy is to close the checkout line 15 mins before your shift ends so you can leave on time. 

> **Info**
> By looking at cams on each weekday, data recorded indicates that usually 10 people enter the line between 4:30 and 4:45 on average.

> **Questions**
> 1. What is the probability that exactly 7 people show up
> 2. What is the probability that over 10 people show up

Notice that the range for customers showing up is $k$ for $k \in [0, \infty]$, but $k=10$ is *most* likely.
![[pisson_dist_ex_a.png]]

See that this looks like a Binomial Distribution. This is because they are related but they are not the same.

## Poisson Dist. Definition
The PD focuses on the number of discreet events or occurrences over a specified interval. This can be time, length, area, etc. 
$$\lambda = \frac{\# \text{ occurrences}}{\text{interval}}$$

For our example above $\lambda = 10$.
This is because we have 10 customers coming  in on average over this time period (15 mins).
## Usage \& Poisson Characteristics
1. Counts Discreet Outcomes $(x = 0, 1, 2, \dotso)$
2. The number of theoretical occurrences is $0\leq x \lt \infty$
3. Describes **rare** events
4. Each event is **independent** of other events
5. The expected number of occurrences $\lambda$  is assumed to be constant over the experiment

## Formula
$$P(x) = \frac{\lambda^x e^{-\lambda}}{x!}$$
Derivation in [[3 types of Distributions]].
$x$ here is our \# Occurrence of Interest. Recall $x\in\mathbb{Z}^++\{0\}$ 

## Answers to Questions in P1
> Q1 
> $$P(7) = \frac{10^7e^{-10}}{7!} \approx 0.09 $$
> Thus, the probability that $7$ people come into our checkout line is $9\%$.  

> Q2
> Recognize that new need a CDF now.
> Also know that 
> $$1 - P(\text{customers}\leq 10) = P(\text{over 10})$$ 

$$
\begin{align}
	1 - \sum_{n = 0}^{10}P(X = n) &= P(\text{over 10})\\
	&= .417
\end{align}
$$
### Ex.1
A typesetter makes on average 1 mistake every 1000 words. He is to type 100 words a page. Let $S_{100}$ be the number of mistakes one a single page. The exact distribution of $S_{100}$ can be found with a series of 100 Bernoulli trials with $p = 0.001$, thus the rate $\lambda$ is: 
$$\lambda = ({100}p) = 0.1$$

While the exact probability of $S_{100} = j = b(100, 1/1000, j)$ the Poisson approximation is $$\frac{e^{-.1}(.1)^j}{j!}$$

### Ex.2
We look over the question of bombs hitting the south of London over the 2nd world war. 

Assume there is a $10\times 10$ block system. How likely is it that a block you live in does not get hit if the entire area has been hit with 400 bombs.  

Assume each block has a $1/100$ chance of being bombed. Since there is $400$ bombs, we can regard the number of hits as the successes in a BTP with $n=400$ and $p = 1/100$.  

$$\lambda = 400(\frac{1}{100}) = 4$$

$$\to p(j) = \frac{e^{-4}4^j}{j!}$$
Then, the number of squares that receive $j$ hits is $100\cdot p(j)$
![[PD_1.png]]

### Ex.3
Suppose a fix amount of blood $W$ has 40 white blood cells. Then, $X$ can be the random variable that gives the number of white blood cells in a random sample of size $W$ of blood. We can see that $X$ is binomially distributed with each white blood cell in the body representing a trial. Each cell is a trial with 2 states: stay in the body or leave it. Leaving the body is a success. This way we see that 
$$p = \frac{W}{\text{Total Blood in body}}$$

Say for the average human, 40 is the average. Thus $40=np$. We can now think if $X$ being Poisson distributed, with rate $\lambda = 40$

%%
Optional reading: 
## Hypergeometric Distribution
%%