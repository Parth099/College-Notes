# Week 9
## Option/Equity Trading

### Equity Trading

**Strategies**

```text
Intraday Trading
No overnight exposure, Close all the trades gain or loss

Swing Trading
Typically hold from a few days to a few weeks

Position Trading
Holds from a month to one or two years

Long-Term Conviction Trades
Investing, hold for at least a year
```

Trading strategies have two main views:
1. Momentum strategies: what goes up will continue to go up; use the trend
2. Mean Reversion: What goes up will come down later

### Option Trading
#### Covered Call
You own shares of $X$ and you sell 1 $X$ OTM call.

Max Profit: `prem + (strike - spot)`
Max Loss: `spot - prem`

Recall `strike` is the price you set, that is the price the stock has to hit for the counterparty to start `winning` .

#### Naked Put
Sell 1 $X$ Put

Max Profit: Premium
Max Loss: `strike - prem`

You would do this to buy a stock at a lower price.

Suppose $X$ closed at $\$150$ on expiry day yet your strike price was $\$160$ . Then you would lose $\$10 * 100$ but gain the premium. 

#### Bull Call Spread and Bear Call Spread

> For Bear its `'sell'` instead of `'buy'`

Buy 1 $X$ call
Sell 1 $X$ call at higher strike