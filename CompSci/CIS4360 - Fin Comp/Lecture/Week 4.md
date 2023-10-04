# Week 4

## Fundamental Principle in Pricing
- Step 1: Find current prevailing rate of interest 
	- Rate can differ depending on maturities
		- Longer maturities $\implies$ higher rate (usually)
	- It can even change during the loaning period 
- Step 2: Find discount factor for different times
	- $DF = (1+R)^{-N}$
	- $PV$ (present value) $=CF*DF$ where CF is cash flow
- Step 3. Sum up the Present Value of all the future cash flow

![cf_sum](../../img/cf_sum.png)

You will have some cash flow each month from this asset. Your pricing value is the sum of all of these cash flows converted to present value.

$$
\sum_i = PV(CF_i)
$$

Notice that each year's or months CF is not guaranteed (ex: loan defaults). 


## Value of money

In mortgage the level payments ensure the future cash flow is even. However, this is not true for all financial instruments. Our main goal is to value the money we will get in the future today.

In terms of a mortgage we want to compute

$$
\sum_{i}^N \text{Present\_Value}(\text{CashFlow}_i)
$$

Remember:

$$
\text{Present\_Value} = \text{Discount\_Factor} \cdot \text{Future\_Value}
$$

## Bonds

Bonds are a method that orgs used to borrow money where they give you more money when the loan period ends. 

If we have $n$ loan terms:
+ $CF_i$ is cash flow at $t_i$ which is the coupon payment at $t_i$
+ $CF_n$ is cash flow at $t_n$ and the principal paid at $t_n$

Where:
+ $\text{Discount\_Factor} = \frac{1}{(1+R)^N}$
+ $\text{Future\_Value} = {(1+R)^N}$