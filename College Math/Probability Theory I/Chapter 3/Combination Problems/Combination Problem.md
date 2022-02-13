For: [[Probability Theory 1]]
# P1
![[p20_32.png]]
## P1A
The first part of the question is 
> How many ways can we pick 6 cards that are of type: Heart
> Answer is : $\binom{13}{6}$

We will pick 6 items from a set of 13 items.
> How many ways can we pick 6 cards from the deck?
> Answer is : $\binom{52}{6}$

$$\text{Answer: }\frac{\binom{13}{6}}{\binom{52}{6}} \approx 0.000084289$$

## P1B
3 Aces: $\binom{4}{3}$
2 Kings: $\binom{4}{2}$
1 Queen : $\binom{4}{1}$

Ways to pick all 3 items from a deck
$$\frac{\binom{4}{3}*\binom{4}{2}*\binom{4}{1}}{\binom{52}{6}}$$

## P1C
We first want $3$ cards of a suit. There are $\binom{4}{1}$ suits to choose from and then $\binom{13}{3}$ ways to pick 3 cards from there. we need to do this again but now there are $\binom{3}{1}$ suits left.
$$\binom{4}{1}\binom{3}{1}\binom{13}{2}^{2}$$
is the number of ways we can do this. Notice that we can condense the steps further. $\binom{4}{2}$ is the number of ways we can pick 2 suits.

Answer:
$$\frac{\binom{4}{2}\binom{13}{3}^2}{\binom{52}{6}}$$

