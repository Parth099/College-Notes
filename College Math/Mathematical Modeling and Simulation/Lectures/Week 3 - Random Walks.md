# Random Walks
+ Stochastic process that describes a path that consists of a succession of random steps on some mathematical space such as $\mathbb{Z}$ or $\mathbb{R}^2$

## 1D Random Walk on $\mathbb{Z}$
Consider starting at some point $0$ and having a fifty-fifty chance of moving forward or backward on the number line.


| Step | Description                                |
| ---- | ------------------------------------------ |
| 0    | The particle can only be at position zero. |
| 1    | $50\%$ chance at -1 or 1                   |
| 2    | $25\%$ at -2 or 2 and a $50\%$ chance at 0 |
| 3    | $12.5 \%$ at $\pm 3$, $37.5 \%$ at $\pm 1$ | 

This can also be made into a decision tree. The depth of the tree would be the step count $n$. 

Questions proposed to be solved by a model:
1. Expected value after $n$ steps
2. How many steps does a object travel over $n$ steps. 