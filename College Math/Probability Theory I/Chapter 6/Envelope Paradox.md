# The Two Envelope Problem
[Link - YouTube](https://www.youtube.com/watch?v=_NGPncypY68)
## Preface
> Suppose you are given 2 **identical** envelopes $A$ and $B$ that **both** contain money. However the money in $A$ is 10 times that of $B$. Since it is not revealed which envelope is $A$, you are told to pick one of them and keep they money. 
> Now you pick and before you open you are given a chance to switch envelopes
> > Is that a beneficial?

This question seems to have no meaning since the situation is *symmetrical*. Both chances are equal.

## Alteration
Suppose now they allowed you to open the envelope and see the money inside. 
Suppose you open an envelope and it contains $\$40$. This means the other envelope has either \$400 or \$4.

Now on *average* the other envelope (not picked) has 
$$
	\frac{400 + 4}{2} = 202 \gt \$40
$$
So switching may have some value. 

In general if your envelope has $x$, the other envelope has $5.05x$. Which means you should always switching. 
> Hence it seems you should always switch regardless of if the let you see the contents of the envelope.

But, this is problematic.  Since both envelopes have the same chance of having the $10x$ money. 

Since we do not know the possible amounts of money (domain) or the chances of them showing up (distribution) this problem is too vague to even simulate or work out.

## Stricter Version of the Problem
The possible amounts of money will be powers of 10 in the smaller envelope:
$$10^0, 10^1, 10^2, \dotso$$

This will create pairs like

| Smaller  | Larger   |
| -------- | -------- |
| 1        | 10       |
| 10       | 100      |
| 100      | 1000     |
| $\vdots$ | $\vdots$ | 

The probability of each of them showing up is the first pair will be $1/2$, then $1/4$ and so on. The pattern is 
$$\frac{1}{2^{\text{pair \#}}}$$

Since the probability **does** sum to $1$.  

The probability of picking one of two envelopes is $1/2$
This means that suppose the pair of money amounts is $10$ and $100$. You will have a $\frac{1}{4}$ chance of getting this pair and then $\frac{1}{8}$ chance of any one of the envelopes.

![[money_table.png]]
This allows us to see the probability of any event.

Suppose the event is picking $\$10$. The chances of this is a sum. The 10 can be the smaller or larger of the 2. 
$$P(\$10) = \frac{1}{4} + \frac{1}{8} = \frac{3}{8}$$

So we ask again
> Should you switch given you can see the money?

## Answering the Question 
Lets analyze if we should switch.
Suppose you see \$1 
Then we should, since we can only go higher (\$10).
We switch because the **profit** her is positive.

Suppose you see \$10
Then we are in one of two cases here
1. We are in the pair (1, 10) 
2. We are in the pair (10, 100)

Now the conditional probability **given we see a 10** of the cases is 
1. $P(\$1|\$10) = \frac{1/4}{1/4+1/8} = 2/3$
2. $P(\$100|\$10) = \frac{1/8}{1/4+1/8} = 1/3$

Then, **given** you saw \$10. 
$$E(\text{other envelope}) = 1(\frac{2}{3})+100\frac{1}{3} = \frac{102}{3} = \$34$$

The profit from switching is $24$, and this we should switch

Suppose you see \$100
The two cases again are
1. pair : $(10, 100)$
2. pair: $(100, 1000)$

Then our conditional probabilities are
1. $P(\$10|\$100) = \frac{1/8}{1/8+1/16} = 2/3$
2. $P(\$1000|\$100) = \frac{1/16}{1/8+1/16} = 1/3$

Given the same conditionals we can see that our expected value now is: 
$$10(\frac{2}{3}) + 1000(\frac{1}{3}) = 1020/3 = 340$$
Again we are better out switching. 

But then this implies that we should switch **everytime**.
Thus, we do not need to see whats in the envelope and just switch everytime. 

Again, this is an issue because if both envelopes have the same probabilities then why would we be switching. Also this casts a new issue. If I was going to pick $B$ and know I will just switch to $A$ should I just pick $A$ but then have to switch to $B$.

### A bigger issue $\dotso$
> Suppose we pick a envelope and then they open the other one and show you whats inside. 

Suppose they show you the other one is $\$1$.
Then yours is surly \$10 and you should not switch. 

What if they show you $\$10$ in the other one.
By the logic above we note that **your** envelope has on average $\$34$ dollars, thus you should **not** switch. 

Since we always don't switch, we do not need to observe. We simply just need to **not** switch.

This contradicts our last analysis. 
What to do now?

## Resolving this 'Paradox'
Let $X$ = the amount in the envelope picked.
Let $Y$ = Profit from switching.

See that $Y$ can be negative. 

Recall our previous calculations.
$$E(Y | X = 1) = 9$$
Given that $X = 1$, the other envelope was 10. Thus $Y = 9$

What if $X = 10$
$$
E(Y | X = 10) = 24
$$
Look above for why its $24$

In general,  $E(Y | X = x)$ is $2.4x$

Now each conditional expected value is positive. This means we should always switch after seeing what we observed.
$$\forall x, E(Y | X = x) \gt 0$$

The next jump we made before was
> Well if anytime we observe we switch why even observer
> **Just Switch** always. 

We cannot make this jump anymore since this asks for $E(Y)$ being always positive. 

We also need to ask:
$$\forall x, E(Y | X = x) \gt 0 \implies E(Y) \gt 0$$

## Investigating $E(Y)$
To prove we need to just switch blindly we need to show the profit $\gt 0$

Lets look at the [[Conditional Expectation]] for $Y$
$$E(Y) = \sum_{k = 0}^{\infty}E(Y | X = 10^k)P(X = 10^k)$$

We have already shown that each factor here is positive and thus $E(Y)$ is positive.

This may now seem that we **must** switch all the time and sadly the paradox still exists.
Moreover we can repeat the proof with $X =$ amount in other envelope and get $E(Y) \lt 0$ meaning we should **never** switch.

### How it gets worse
> Recall $Y=$ profit from switching

Lets attain $E(Y)$ via the natural definition of expectation.
$$E(Y) = \sum_{}yP(Y = y)$$
![[money_table.png]]
$$
\begin{align}
	P(Y = 9) &= \frac{1}{4} \\
	P(Y = -9) &= \frac{1}{4} \\
	\\
	P(Y = 90) &= \frac{1}{8} \\
	P(Y = -90) &= \frac{1}{8} \\
	\\
	& \vdots
\end{align}
$$

$P(Y = 9) = \frac{1}{4}$ because its a $1/2$ chance we get the pair $(1, 10)$ and then another $1/2$ we get $10$. This logic extends to **all** pairs. 

Anyways. 
$$E(Y) = 9\frac{1}{4} + (-9)\frac{1}{4} + 90\frac{1}{8} + (-90)\frac{1}{8} + \dotso = 0$$

Now we have shown that all the possibilities for $E(Y)$ exist:
+ $E(X) > 0$
+ $E(X) = 0$
+ $E(X) < 0$

This is impossible. 

## Taking a closer look into $\infty$ sums
> **Theorem**
> Given a alternating series $\sum a_n$.
> If the sum of all positive $a_n \to \infty$ and the sum of all negative terms $a_n \to \infty$.
> We **cannot** rearrange any terms without changing the sum output.

See that this is what we did above. 
Notice each profit is in the form $10^{n+1} - 10^n = 9\times10^n$ and each loss is in the form $(-9)\times10^n$

Our Positive sum was 
$$\sum_{n = 0}^{\infty}\frac{1}{2^n}9\times10^n$$
which **did** diverge to $+\infty$
Using the same idea the negative sum **also** diverged to $-\infty$

Reordering these terms made our conclusion **invalid**. 

The expected value for random variables like this are **not defined**

## Conclusion
$E(Y)$ did not ever exist due to the issue above and thus using the Law of Total Expectation was invalid. How sad.

## Results
Lets review all our 'strategies'. 
1. Not Switching
	+	Profit = 0, since we don't lose or gain here

2. Switching
	+	Profit is *random*
	+	$E(\text{profit})$ does **not** exist

## Consolation
Can we find a strategies that allows us to define a concrete criterion under both strategies?

Yes we can. 
> Something like
> not losing the chance at $x$ dollars.
> This is like picking $100$ when $1000$ is available or switching to $100$ when you were at $1000$ 
> $$P(\text{losing} > x)$$

Consider a reasonable $x = 500$
### Strategy: No-Switch
> $$P(\text{losing} > 500)$$

We can only lose $500$ after pair $(100, 1000)$
This has a chance $1 - \frac{1}{2} - \frac{1}{4}$.
I just removed the non-fitting pairs.

And we must also pick the smaller pair:
$$\frac{1}{2}(1 - \frac{1}{2} - \frac{1}{4}) = 1/8$$
### Strategy: Switch
Similarly, we can only lose $500$ after pair $(100, 1000)$.
But this time we must switch from the higher number to the lower number in the pair.

$$\frac{1}{2}(1 - \frac{1}{2} - \frac{1}{4}) = 1/8$$

We note that both strategies result in the same probability, "as they should"

