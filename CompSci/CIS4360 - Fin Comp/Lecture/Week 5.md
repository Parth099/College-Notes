# Week 5
## Technical Analysis

> Price determined by supply and demand only

+ Market participants focused on short-term dynamics only, Market participants are watching support and resistance levels

Trades will use technical indicators to design their trading strategy for entry, exit, and cut losses.  *Investors* do not usually use technical indicators. 

P/E Ratio: if your earnings are $\$2$ and you sell your company stock for $\$30$ your $PE$ is $15$ .

## Indicators 

![tech_indicator](../../img/tech_indicator.png)

### Moving Averages

Goal: Smooth out fluctuations to identify trends

Types:

#### Simple Moving Averages (SMA)

+ Average from the like $N$-period closing prices
+ Common periods: 9, 20, 50, ...

$$
SMA = \frac{A_1 + \dotso + A_n}{n}
$$

#### Exponential Moving Averages

+ Gives more weight to recent prices
+ Can signal reversal[^1] than SMA but can also give false signals
+ Common periods: 12 or 26 day

$$
EMA_k = A_k * \biggr(\frac{2}{1+n}\biggr) + EMA_{k-1} * \biggr(1-\frac{2}{1+n}\biggr)
$$

#### Using MAs

Use two MAs:
+ Faster Shorter window: 20-period MA
+ Slower longer window: 100-period MA

You should:
+ BUY: Golden Cross - Short Term rises above long term 
+ SELL: Death Cross - short term drops below long term
	+ Past Trends have shown the  stock will drop even more.  

> These are irrespective of positions. 


### MACD - Moving Average Convergence/Divergence indicator

See [Macroption - MACD](https://www.macroption.com/macd)

```text
MACD = Shorter EMA Line - Longer EMA Line

Signal Line = EMA of MACD
```

A Signal Line is a moving average line yet named differently to avoid confusion with price-based averages. 

![MACD](../../img/MACD.png)

### RSI - Relative Strength Index

One of the Oscillators: value is between $[0, 100]$

$$
RS = \frac{\text{Average Gain}}{\text{Average Loss}}
$$

+ $\text{Average Gain}$ - average of all up moves within $N$ periods
+ $\text{Average Loss}$ - see above


> If the period is `days` the $\text{Average Gain}$ is simple the number of days it closed at a net positive. 

You can even weigh the nodes:

$$
\text{Average Gain} = \frac{1}{14} \cdot \text{Current Gain} + \frac{3}{14} \cdot \text{Previous Average Gain}
$$

$$
RSI = 
\begin{cases}
\text{overbought} & RSI > 70 \\
\text{neutral} & 30 \lt RSI \lt 70\\
\text{underbought} & RSI < 30 \\
\end{cases}
$$

### VWAP - Volume Weight Average Price

> Can be used as support and resistance

Notice when a broker asks to sell a huge chunk of stock they cannot sell high amount of shares at once. When market closes the trader will be judged if he did well (sold above VWAP or bought below VWAP). 

VWAP can be used as support[^2] and resistance[^3] line. 

$$
VWAP = \frac{\sum{\text{Price}*\text{Volume}}}{\sum{\text{Volume}}}
$$

### Bollinger Band

They are plotted above and below the SMA of the price based in standard dev. It is used to measure volatility.

If the band tightens we can assume it will have a sharp movement soon. Prices tend to bounce around the band. 

![BB](https://www.fidelity.com/bin-public/600_Fidelity_Com_English/images/migration/article/content_12-lc/BB1_602x345.png)

### More Indicators

+ ATR: Average true range: measures a stock's volatility
	+ Formula: $\max(H-L, H - \text{Prev Day Close}, \text{Prev Day Close} - L)$ 
+ ADX: Average Directional Index


[^1]: Signal Reversal: ?
[^2]: Support: Magic min line (stock should not drop below)
[^3]: Resistance: Magic max line (if stock hits this is likely to come back down)