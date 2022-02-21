# Expected Value of Discrete Random Variables
Usually when discussing probability, we are not interested in individual numbers but descriptors. Something like an *average* or *median*. 

This note will be about
1. ***Expected Value***
2. ***Variance***

These terms **only** apply to random variables that are numerically distributed. 

## The Average Value
Suppose we are involved in a game where we have a die being rolled. Lets contain the value of the die in a var $X$. 
If $X$ is even we will lose \$$X$, if its odd we will win \$$X$. 

What is the average value of this $X$?. In other words this asks if the game is favorable for *the* player.

This game is simulated at $./\text{c6\_sim.py}$
Results
```python
    Trials      Gain
       100 -0.190000
      1000 -0.590000
     10000 -0.507400
    100000 -0.501500
```
We notice we are losing money. 

Lets then assume our trials $t \to \infty$. The number of trials is high. Then the frequency of each number $X$ will be $\frac{1}{6}$.

$$\mu = 1(\frac{1}{6})-2(\frac{1}{6})+3(\frac{1}{6})-4(\frac{1}{6})+5(\frac{1}{6})-6(\frac{1}{6})$$
$\implies \mu = .5$
Notice how $\mu$ agrees with the sim.

This is quite intuitive. The average value $\mu$ will be the sum of all possibilities with context (by this I mean whether its $\pm$) multiplied by their probabilities.    

## Expected Value
We often say Expected Value to refer to the *mean* or average. This is denoted by $E(X)$ or $\mu$ as shown above.

> **DEFINITION** of Expected Value
> Let $X$ be a numerically-valued discrete random variable with some sample space $\Omega$ with dist function $m(x)$. Then:
>$$E(X) = \sum_{x\in\Omega} xm(x)$$ 

> $E(X)$ only exists if the sum converges.

## Examples
### Example 1
> Let there be an experiment consist of tossing a fair coin three times. Let $X$ denote the number of heads that appear. The possible values for $X$ are $\{0, 1, 2, 3\}$. The corresponding probabilities are $1/8, 3/8, 3/8, \text{ and } 1/8$. 

$$E(X) = 0(\frac{1}{8}) + 1(\frac{3}{8}) + 2(\frac{3}{8}) + 3(\frac{1}{8}) = \frac{3}{2}$$

---
### Example 2
> Suppose that we toss a fair coin until a head comes up. Let $X$ represent these trials. Then $X = \mathbb{Z}^+$.
> $$X \sim \text{Geom}(.5)$$

See that $m(i) = \frac{1}{2^i}$
$$
\begin{align*}
	E(X) &= \sum_{i = 1}^{\infty} i\frac{1}{2^i} \\
		 &= \frac{1}{2^1} + \frac{2}{2^2} + \frac{3}{2^3} + \frac{4}{2^4} + \dotso
\end{align*}
$$
![[sum_c6.jpg]]
$$
\begin{align*}
	&= [\sum_{i = 1}^{\infty} \frac{1}{2^i}] + [\sum_{i = 2}^{\infty} \frac{1}{2^i}] + [\sum_{i = 3}^{\infty} \frac{1}{2^i}] + \dotso \\
	&= 1 + \frac{1}{2} + \frac{1}{2^2} + \dotso \\
	&= 2
\end{align*}
$$

Thus the mean number of flips required is only $2$. Seems reasonable.

#### Extension 
Suppose we flip until we get heads and when we do get heads we are paid $\$2^n$. 
> What is the average payment?

Let $Y$ be the amount that you can be paid, this will of course be powers of $2$
$$P(Y = 2^n) = \frac{1}{2^n}$$
$$E(Y) = \sum_{n=1}^{\infty} 2^n \frac{1}{2^n}$$
Since the sum diverges there does not exist an average value.

### Example 3
> Let $T$ represent the time for a first successful event in a Bernoulli trials process. Then the sample space $\Omega$ is $\mathbb{Z}^+$.

The distribution function is $m(j) = P(Y = j) = pq^{j-1}$ as shown in [[Geometric Distribution]].

Lets investigate $E(T)$ or how many trials on average until first success. 
$$
\begin{align}
	E(T) &= \sum_{n = 1}^\infty nP(T = 1) \\
		 &= \sum_{n = 1}^\infty npq^{n-1} \\
		 &= 1p + 2pq + 3pq^2 + \dotso \\
		 &= p(1 + 2q + 3q^2 + \dotso) \\
		 &= p(\frac{1}{(1-q)^2})\\
		 &= \frac{p}{p^2} \\
		 &= \frac{1}{p}
\end{align}
$$

#### Series Details
Recall the Geometric [[Series]]:
If $|x| \lt 1$, then
$$1+x^2+x^3+\dotso=\frac{1}{1-x}$$
Apply differentiation
$$1+2x+3x^2+4x^3+\dotso = \frac{1}{(1-x)^2}$$

#### Analysis
We see that the expected $\mu$ number of trials is $1/p$. This means a fair coin will take on average $\frac{1}{1/2}$ rolls to be heads Or $\frac{1}{1/6}$ for a die to roll a 1.  

## Interpretation of Expected Value
> "ideas of average value and expected value are very closely related."

However we **cannot** say they are the same. We know that for a finite experiment we are unable to predict the value as shown by the $\text{sim\_c6.py}$ experiment above. However, we **can** show that the average will approach $E(X)$ given a large amount of trials of the experiment.

## Expectation of a Function of a Random Variable
Related to [[Functions of Random Variables]]
Suppose $X$ is a discrete random variable with sample space $\Omega$ and $g(x)$ has domain $\Omega$. Then $g(X)$ is a real-valued random variable. 

One way to attain the expectation of $g(X)$ is to first determine the distribution function of $g(X)$ and then use the definition of  expectation. However there is a better way:

### Example 1
Suppose a coin is tossed 9 times and we get
$$H\ H\ H\ T\ T\ T\ T\ H\ T$$

> **Definition**: run 
> A run is a sequence of more than one consecutive identical outcomes, also known as a clump.
> Src: [Wolfram](https://mathworld.wolfram.com/Run.html)

See that in this example there exists 4 runs:
$$\{HHH, TTTT, H, T\}$$
> **Question**
> Find the expected number of runs in a coin flipped **3** times.

We can see that there are 2 random variables involved here:
1. $X$ - denoting the sequence of heads and tails.
2. $Y$ - denoting the runs in $X$

#### Table relating Discrete $X$ and $Y$
| **$X$** | **$Y$** |
| ------- | ------- |
| HHH     | 1       |
| HHT     | 2       |
| HTH     | 3       |
| THH     | 2       |
| THT     | 3       |
| TTH     | 2       |
| HTT     | 2       |
| TTT     | 1       |

#### Method $1$ for $E(Y)$
We note from the table values for $m(y)$
$$
\begin{align}
	m(1) &= \frac{1}{4}\\
	m(2) &= \frac{1}{2}\\
	m(3) &= \frac{1}{4}\\
\end{align}
$$

$$E(Y) = 1\frac{1}{4} + 2\frac{1}{2} + 3\frac{1}{4} = \boxed{2}$$
#### Method $2$ for $E(Y)$
Instead of counting $y$ itself we can also find $E(Y)$ via $X$.
We can multiply each value of $X$ value $x$ with its probability $P(X = x)$ and corresponding value of Y.

Note each outcome in $X$ has probability $1/8$
We see that 
$1(\frac{1}{8})+2(\frac{1}{8})+3(\frac{1}{8})+2(\frac{1}{8}) + 3(\frac{1}{8})+ 2(\frac{1}{8})+2(\frac{1}{8})+1(\frac{1}{8}) = 2$
This is the same distribution shown in the table above. 

From this we can learn that if $X, Y$ are two random
variables and $Y$ can be written as a function of $X$ then we use the distribution function of $X$ to compute $E(Y)$.

> **Theorem**
> If $X$ is a discrete random variable with sample space $\Omega$ and distribution function $m(x)$, and if $g:\Omega \to \mathbb{R}$
> $$E(g(X)) = \sum_{x\in{\Omega}}g(x)m(x)$$
> This assumes the sum is convergent.

%%## The Sum of Two Random Variables%%
