# Week 3

## Arbitrage Based Pricing

> A fundamental principle in Finance

**Arbitrage Opportunity**- Profit without risk (ex: Buy Low, Sell high if something is priced wrong)

Definition: simultaneous buy and sale of the same asset in different markets IOT to make profits from tiny differences. Often this has risky. 

If two portfolios or financial instruments have identical future payoff (or cashflow) in future, then they must have the same price. This is known as:
1. Law of one price
2. No Arbitrage Principle
3. Pricing by replicating

For any portfolio which consists of multiple or simple financial instrument:
+ If we can find or create a another portfolio s.t it can replicate the cash flow of the first one then it can be priced as the same as the first one.

## Mortgage Calculations

Level Payment Amount - Amt to money to be paid per money to pay off house in 30 years. 

We learned in week 3 how to find the level payment via Excel (Numerical). 

### Math

+ $B_i$ is Balance left at month $i$
+ $P$ Principle
+ $r$ rate of interest (**CAN BE ANANUALIZED, we assume monthly**)

$$
\begin{align}
B_{i+1} &= B_i - P \\\\
\text{Interest Payment} &= {B_i r} \\
P &= L - \text{Interest Payment} \\ \\ \\

B_{i+1} &= B_i(1+r) - L \\\\

B_1 &= B_0(1+r)-L \\
B_2 &= [B_0(1+r)-L](1+r)-L \\
B_3 &= [[B_0(1+r)-L](1+r)-L](1+r) - L \\
&= B_0(1+r)^3 - L[1+(1+r)+(1+r)^2] \\ \\
&= \vdots \\ \\
B_n &= B_0(1+r)^n - \underbrace{L\sum_{j=0}^{n-1}(1+r)^j}_{\text{Geometric sum}} \\
&= B_0(1+r)^n - L\biggr( \frac{(1+r)^n-1}{(1+r)-1} \biggr) 
\implies
\boxed{L = \frac{B_0 (1+r)^nr}{(1+r)^n-1}}
\end{align}
$$

> In table below $r$ is a Annual Interest Rate

| Month $i$ | Level Payment | Interest          | Principle           | Ending Balance |
| --------- | ------------- | ----------------- | ------------------- | -------------- |
| $1$       | $L$           | $B_0\frac{r}{12}$ | $L-B_0\frac{r}{12}$ | $B_1$          |
| $2$       | $L$           | $B_1\frac{r}{12}$ | $L-B_1\frac{r}{12}$ | $B_2$          |



## Equity Market Overview

> "How to value a company?"

### Valuing Companies

+ Demand and Supply
+ Types of Valuations
	1. Fundamental Analysis
		+ Do not time the market as market can be wrong in the short term
		+ Priced by fundamentals: the business (ex: Cost to make phone , cost to sell phone)
		+ Priced by Fundamental Events (news events by the company)
		+ Value of company is discovered via hard-work
		+ Pros
			+ Transparent - not dependent on magic
			+ Related to business
			+ Understandable
		+ Con
			+ Need Assumptions
			+ No direct translation on trading action
			+ Buy on rumors -> Sell on the news
	2. Technical Analysis
		+ Price determined by supply and demand
		+ Support and Resistance levels that market participants are watching carefully
		+ Pros
			+ Simple
			+ Easy to Compare
			+ Actionable
		+ Con
			+ Does not capture company behavior (No Causation)
			+ Support and resistance lines are just "magic"
			+ Cannot be changed without warning

Thousands of factors that effect the price at any point and so many investors with different trading strategies. As CS professionals it is our goal to understand this logic and calculation behind these theories and implement a toolbox for portfolio managers to make faster and more informed decisions.

## Supply Demand

The `bid-ask spread` is the difference between the bid and ask for a stock. A low spread implies a more liquid stock. 

If there are more buyers than sellers then the bid will increase which will rise the price.

The `price-action` is the live movement of the stock price. A live candlestick graph is an example of viewing the price-action. Using price-action to predict the price is Technical Analysis whereas Fundamental Analysis will take a deeper look into the company financial.

The `fair-value` the appropriate price for the shares of a company, based on its earnings and growth rate. We need company documents like income statements or balance sheets. If we cannot access these we can use other heuristics like PE rations, Price to Book, Price to revenue, Price to Free Cash flow[^1], ...

## Misc
### Certifications
1. CMT
2. CFA

[^1]: Things like this are often written as P/FCF