# hw2
## q1
$$
\begin{align}
	\sum_{i=1}^n\frac{1}{i} &= \Theta\biggr(\int_1^n \frac{1}{x} \mathop{dx} \biggr) \\ \\
	&= \Theta\biggr(\ln{x}\biggr|_{n=1}^{n=x}\biggr) 
	\\ \\
	&= \Theta(\ln{n}) \stackrel{*}{=} \Theta(\log{n})
\end{align}
$$

\* - logs only differ by a constant $\forall (b_0, b_1 )\gt 1,\ \log_{b_0}{n} \in \Theta(log_{b_1}(n))$

## 2.c
**IMPORTANT:** $A^B \text{ mod } C = ( (A \text{ mod } C)^B ) \text{ mod } C$

$$
\begin{align}
	15^7 \text{ mod } 13 &= 2^7 \text{ mod } 13 \\ \\
	&= \biggr[ \biggr( 2^4 \text{ mod } 13  \biggr)\cdot \biggr( 2^3 \text{ mod } 13  \biggr) \biggr] \text{ mod } 13
	
	\\ \\
	
	&= \biggr[ \biggr( 16 \text{ mod } 13  \biggr)\cdot \biggr( 8 \text{ mod } 13  \biggr) \biggr] \text{ mod } 13
	
	\\ \\
	&= \biggr( 3 \cdot 8  \biggr) \text{ mod } 13
	\\\\
	&= \boxed{11}
\end{align}
$$

## 5 - E1.2
> Show that any binary integer is at most four times as long as the corresponding decimal integer. For very large numbers, what is the ratio of these two lengths, approximately?

Let $n$ be a number. 

The length of $n$ is in **binary** $\lceil \log_{2}(n+1)\rceil$

Then,
$$
\begin{align}
	\lceil \log_{2}(n+1)\rceil \stackrel{*}{=} \biggr\lceil \frac{\log_{10}(n+1)}{\log_{10}(2)} \biggr\rceil \leq \biggr\lceil\frac{1}{\log_{10}(2)}\biggr\rceil\lceil \log_{10}(n+1) \rceil \stackrel{**}{=} 4\lceil\log_{10}(n+1)\rceil
\end{align}
$$

Since $\lceil\log_{10}(n+1)\rceil$ represents the length of $n$ in decimal we can conclude that the length of a binary number is at most 4 times as long as its decimal format. 

\* - $\log$ Change of $\text{base}$
\*\* - See that $\frac{1}{\log_{10}(2)} = \log_{2}(10) \approx 3.3219\dotso$

### Large $n$

For $n$ the ratio of the $\log_{10}{n}$ and $\log_{2}{n}$ is represented by:

$$
\begin{align}
	\lim_{n\to\infty} \frac{\log_{2}{\ n}}{\log_{10}{n}} = \lim_{n\to\infty} \frac{\log_{2}{n}}{\frac{\log_{2}{\ n}}{\log_{2}{10}}} = \log_2{10} \approx 3.3219\dotso
\end{align}
$$

