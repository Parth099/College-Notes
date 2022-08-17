# PS1 - Central Limit Theorem
## 1
Let $S_{100}$ be the number of heads that turn up in 100 tosses of a fair coin.

> Note $\pm\frac{1}{2}$ correction not applied here

Know that
$$
\begin{align}
	\mu &= 50 \\
	\sigma^2 &= 25 \\
\end{align}
$$

### a)
Find $P(S_{100} \leq 45)$

Then, 
$$
\begin{align}
	P(S_{100} \leq 45) &\approx P\biggr(S_{100}^{*} \leq \frac{45-50}{5}\biggr)\\
	&= P(S_{100}^{*} \leq -1)\\
	&= 0.5 - \text{NA}(0, 1) \\ \\
	&= 0.1587
\end{align}
$$

### b)
Find $P(45 \lt S_{100} \lt 55)$

$$
\begin{align}
	&P\biggr(\frac{45 - 50}{5}\lt S_{100}^* \lt \frac{55-50}{5}\biggr)  
	\\
	&= P(-1 \lt S_{100}^* \lt 1) \\
	&= 2\text{NA}(0, 1) \\
	&= 2\cdot .3413 \\ 
	&= .6826
\end{align}
$$

### c)
Find $P(S_{100} \lt 63)$
$$
63^* = \frac{63 - 50}{5} = 2.6
$$

$$
\begin{align}
	&= P(S_{100}^* \lt 2.6) \\
	&= \int_{-\infty}^{2.6} \phi(x)\:dx \\
	&= 0.5 + \text{NA}(2.6) \\
	&= 0.5 + 0.4953 \\
	&= .9953
\end{align}
$$
## 2
Let $S_{200}$ be the number of heads that turn up in 200 tosses of a fair coin.

Know that
$$
\begin{align}
	\mu &= 100 \\
	\sigma^2 &= 50 \\
\end{align}
$$

Find $P(S_{200} = 100)$

$$
\begin{align}
	P(S_{200} = 100) &= \frac{1}{\sqrt{50}}\phi\biggr(\frac{100 - 100}{\sqrt{50}}\biggr) \\ \\
	
	\phi(0) &= \frac{1}{\sqrt{2\pi}}e^{-0^2/2} = \frac{1}{\sqrt{2\pi}} \\ \\ 
	
	P(S_{200} = 100) &= \frac{1}{\sqrt{50}}\frac{1}{\sqrt{2\pi}} = \boxed{0.0564}
\end{align}
$$

## 3
![[c9_1p3.png]]
Realize this is a Bernoulli Trials Process
### P(June Passing)
For June to pass we require that she gets $\geq 30$ questions correct.

See that 
$$
\begin{align}
	\mu &= np = {48}\times{\frac{3}{4}} &= 36 \\
	\sigma &= \sqrt{npq} = \sqrt{48\times\frac{3}{4}\frac{1}{4}} = \sqrt{\frac{16 * 3 * 3}{16}} &= 3
\end{align}
$$

Then,
$$
\text{Let }J_n = \sum_{i = 1}^{48} J_i
$$
where $J_i$ is an indicator for each test question
$$
J_n^* = \frac{J_n - np}{\sqrt{npq}} = \frac{J_n - 36}{3}
$$

Notice that 
$$
J_{\geq 30}^* = \int_{a}^{b} \phi(x)\:dx
$$
We must get values for $a$ since $b$ is an endpoint we do not need it.
$$
\begin{align}
	a &= \frac{30 - \frac{1}{2} - 36}{3} = −2.16\overline 6 \\
\end{align}
$$

Thus $x_{30} = −2.16\overline 6$
Now we can confront the NA table.
$$
\begin{align}
	NA(-2.16) &= NA(2.16) \approx NA(2.2) \approx .4861
\end{align}
$$

Since NA($2.2$) is $.4861$ 
$$0.5 + .4861 = .9861$$

We add the $.5$ because:

![[vis_aid.png]]

Same process for April yields: 

$$
\begin{align}
	\mu = np = 24 \\
	\sigma = \sqrt{48\frac{1}{2}\frac{1}{2}} = \sqrt{12}
\end{align}
$$
$$
a = \frac{30 - \frac{1}{2} - 24}{\sqrt{12}} \approx 1.6
$$

Thus $P(X\geq30) = 0.5 - \text{NA}(0, 1.6) \approx 0.0548$

Both are close to the real [Binomial CDF](https://stattrek.com/online-calculator/binomial.aspx)
## 5
A rookie is brought to a baseball club on the assumption that he will have a .300 batting average. (Batting average is the ratio of the number of hits to the number of times at bat.) In the first year, he comes to bat 300 times and his batting average is .267. Assume that his at bats can be considered Bernoulli trials with probability .3 for success. Could such a low average be considered just bad luck or should he be sent back to the minor leagues? Comment on the assumption of Bernoulli trials in this situation.

**Setup**

Since the batting average is $.267$ he has hit the ball approximately 80 times in this *new* league.

Thus we need to find 
$$
P(S_{300}^{*} = x_{80}^{*}) \text{ with } p(\text{success}) = 0.3
$$

**Expectation and Deviation**
$$
\begin{align}
	E(X) &= np = 90 \\
	D(X) &= \sqrt{npq} = \sqrt{100(0.21)} \approx 4.58
\end{align}
$$

Here is the probability that someone with a batting avg of 0.3 would hit 80 or less.

$$
P(S_{300}^* \lt x_{80}^*) = \int_{-\infty}^{x_{80}^{*}}\phi\left(x\right)dx
$$

Now, 
$$
x_{80}^* = \frac{90-100-\frac{1}{2}}{D(X)} = −2.29
$$

Then, 
$$
P(S_{300}^* \lt x_{80}^*) \approx 0.5 - \text{NA}(2.3) \approx 0.107
$$

Seems like the batter isn't very good.


## 10
![[c9_1p10.png]]
$$
\text{Let }S_n = \sum_{i = 1}^{10000}X_i \text{ for } X_i = 
	\begin{cases}
		1 & \text{ if } &x = 3
		\\
		0 & \text{ otherwise }
	\end{cases}
$$

Observe for $n = 10000$
$$
\begin{align}
	E(X_i) &= p =\frac{1}{10}\\
	V(X_i) &= p - p^2 = \frac{9}{100} \\
	
	\\
	
	E(S_n) &= 1000 \\
	V(S_n) &= 900 \\
	D(S_n) &= 30 \\
\end{align}
$$

Now 
$$
\begin{align}
	P(S_n \leq 931) &\approx P(S^*_n \leq -2.3) \\
					&= 0.5 - \text{NA}(0, 2.3) \\
					&\approx 0.5 - .4893 \\
					&\approx \mathbf{.0107}
\end{align}
$$