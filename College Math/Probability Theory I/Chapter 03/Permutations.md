# Permutations
For: [[Probability Theory 1]]

Solves problems that require the number of ways an event can unfold.

> **Multiplication Principle**
> 
> Suppose a task can be divided into $n$ stages. There are $a_1$ choices for how to carry about stage 1. $a_2$ for stage 2 and so on. The total number of possible arrangement of stage options is $a_1a_2\dotso a_n$

## Multiplication Principle Example
How many subsets for an Set $A$ exist? 
We can chose to discard or keep elements: 2 choices per element. 
**$$\boxed{2^{\lvert A \rvert}}$$**

## Famous Birthday Problem (Paradox?)
**Q**: How many people do we need to ensure the chance that 2 people having the same birthday is $\geq \frac{1}{2}$

Its tempting to say that the answer is 
$$\lceil\frac{365}{2}\rceil$$
but its actually **$23$**.

Assume there are 365 possible birthdays for each person. Number these people $1$ to $r$. Then choose a random sequence of $r$ birthdays. There are $365^r$ possibilities this sequence can come out. Now we must find the number sequences that contain no duplicate birthdays.

Consider $r = 2$
The first person has $365$ days to have their birthday on while person 2 has $364$ days. 

Thus
$$p_r = \frac{365*364*\cdots*(365 - r + 1)}{365^r}$$
See that this actually calculates the ways no duplicates occur.
This the real probability of 2 people having the same birthday is really:
$$p_B(r) = 1 - p_r$$
where $r$ stands for the number of people you wish to examine. 

Note the $+1$ comes from the fact that there are $r$ integers in $[1, r]$. (Try $r = 2$ or $3$).

## Permutations 
Let $A$ be **finite** set. A *permutation* of $A$ is a one-to-one mapping of A onto itself 


$$\begin{align*}
\text{Let }A &= \{a, b, c\} \\
\text{Let }\sigma &= 
\begin{pmatrix}  
	a & b & c\\  
	b & c & a  
	\end{pmatrix}
\end{align*}
$$
$\sigma$ is a *permutation* of $A$.
It represents the fact that
- a is mapped to b
- b is mapped to c
- c is mapped to a

```python
>>> list(permutations([1, 2, 3]))
[(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)] 
```

> Definition: 
> 
> The total number of permutations of a set $A$ with $n$ elements is $n!$
> 
> The total number of permutations of a set $A$ with $n$ where $k$ elements are taken at a time is 
> $$\frac{n!}{(n-k)!}$$

> **Division Principle**
> 
> If $n$ things can be divided in to $d$ groups of size $k$ then $d=\frac{n}{k}$

## Division Example
How many ways can word $BOOKKEEPER$ be rearranged
$$= \frac{10!}{2!2!3!}$$
10 total letters. Then we divide out the number of times the word stays the same.

For example there are 6($3!$) ways we can swap around the $E$s and the word stays the same.

## Stirling's Approximation
> Stirling’s Formula
> $$n! \approx n^ne^{-n}\sqrt{2\pi n}$$

Note that 
$$\lim_{n\to\infty}\frac{n!}{n^ne^{-n}\sqrt{2\pi n}} = 1 \implies \text{ asymptotically equal}$$

