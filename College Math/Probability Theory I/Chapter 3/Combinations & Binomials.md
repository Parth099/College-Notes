# Combinations
>The number of distinct subsets with $j$ elements that can be chose from a set with $n$ elements is denoted by
>$${\binom{n}{j}} = \frac{n!}{(n-j)!j!}$$

## Formula Analysis
Recognize the $$\frac{n!}{(n-j)!}$$ is the same from [[Permutations]]. The added $j!$ is from that fact that a *list* of length $j$ can be ordered in $j!$ ways. Thus we divide out the $j!$ to represent that order does matter. 
$$\text{This means } \{a, b, c\} \text{ is the same as }\{c, a, b\}.$$

## Pascal's Triangle & A Recurrence Relation

See that $^{\alpha}$
$$\binom{n}{0}=\binom{n}{n}=1$$

### Theorem
For $j, n \in\mathbb{Z}$ and $j \lt n$.
$$\binom{n}{j}=\binom{n-1}{j}+\binom{n-1}{j-1}$$

### Explanation
This is ***sadly*** a combinatoric proof. 😢

The end result is $\binom{n}{j}$ or picking a subset of $j$ length from a set of length $n$. We will call this set $U$. $|U| = n$ 
($U$ is the main set)

Consider an arbitrary element $u \in U$. 
Suppose this element $u$ is in our set. The amount of sets that satisfy this is: $$\binom{n-1}{j-1}$$ There are $n-1$ elements and $j-1$ positions to consider.

Suppose $u$ is not in outset. The amount of sets that satisfy this is $$\binom{n-1}{j}$$
$n-1$ elements for $j$ positions 

Since this problem applies the addition principle of counting, we add together the two Binomial Coefficients.

This Recurrence Relation is enough to construct Pascal's triangle. 

Suppose we wanted $\binom{10}{5}$
$$\binom{10}{5} = \binom{9}{4} + \binom{9}{5}$$
This allows us to use numbers from a previous line of Pascal's triangle to construct the next one.

### Important Identity
$$
\begin{align*}
	\binom{n}{j} &= \binom{n}{n-j}\\
	\frac{n!}{j!(n-j)!} &= \frac{n!}{(n-j)!(n-[n-j])!} \\
	&= \frac{n!}{(n-j)!j!}
\end{align*}
$$

## Bernoulli Trials: Binomial Coefficients
A *Bernoulli trials process* is a sequence of $n$ experiments such that.
1. Each experiment has **two** concrete possible outcomes.
2. Each experiment and subsequent experiment is **independent**. Each experiment has a success chance of $p$ and failure of $q$. $$q=1-p$$


![[BTcubic.png]]$$\text{Fig A - Sample Bernoulli Trial}$$

### Examples of a Bernoulli Trial Process
1. Tossing a coin $10$ times
2.  A Gambler making a sequence of \$1 bets on black at a roulette table. $$P(\text{BLACK})=\frac{18}{38}$$*Note*: A win means +\$1  and a loss is -\$1
3.  A poll that gets people opinion (agree/disagree) on statement. 

### Analysis of a BTP
We can analyze a BTP by choosing our sample space as a ***binary tree*** and assigning various probabilities to each edge, this is laid out in $\text{FIG A}$.    

Let $X$ be a random variable that represents the outcome of this experiment. $X$ has to be an **ordered** triple tuple of $S|F$. Let $X_i$ represent the outcome of the $i$th trial with a distribution function $m_i$. An outcome of the entire experiment is a desired path from the root to *a* leaf. 

Notice that for any $\omega_i$ the probability of it occurring (denoted by $m_i$) is the product of probabilities on its path. This indeed shows that each event is independent.

## Binomial Probabilities