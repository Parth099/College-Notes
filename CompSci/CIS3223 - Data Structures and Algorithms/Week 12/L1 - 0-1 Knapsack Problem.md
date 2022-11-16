# The Classic 0-1 Knapsack Problem
In a robbery, there are $n$ items that a thief can take. The $i\text{-th}$ item is worth $v_i$ dollars and weighs $w_i$ pounds. The thief’s knapsack can only carry $W$ pounds, which items should the thief take?

tldr:

$$
\text{Maximize}
\sum_{i=1}^{n}x_iv_i \text{ for } x_i\in\{0, 1\} \text{ and } \sum_{i=1}^{n}x_iv_i \leq W
$$

## Naive Recursive Problem
For each entry we can select to either pick it up or leave it. This runs in $O(2^n)$ time. 

```python
# recursive solution
def knapsack_r(Weights, Value, Weight_limit):

    #need to ask ourselves if we are going to place the item or not
    def helper(index, curr_weight, curr_value):
        if curr_weight > Weight_limit:
            return float("-inf")
        
        # reached end of array
        if N == index:
            return curr_value

        not_add = helper(index + 1, curr_weight, curr_value) 
        add = helper(index + 1, curr_weight + Weights[index], curr_value + Value[index])

        return max(add, not_add)
    
    N = len(Weights)
    cache = []
    return max(helper(0, 0, 0), 0) #max(..., 0) handles the case where max weight is smaller than each item


W = [1, 3, 4, 5]
V = [1, 4, 5, 7]
Weight_limit = 7

carry_max = knapsack_r(W, V, Weight_limit)
print(f'max weight: {carry_max}') # 9
```

## Dynamic Programming - Tabular
> This is what the lecture was about

Data:

$$
\begin{align}
v &= [1,\ 2,\ 5,\ 6] \\
w &= [2,\ 3,\ 4,\ 5] \\
\\
W &= 8 \text{ (capacity)}
\end{align}
$$

Construct a table that is $(N+1)\times(W+1)$ where $N$ is the number if items we have.

<table>
<thead>
  <tr>
    <th></th>
	<th>0</th>
    <th>1</th>
    <th>2</th>
    <th>3</th>
    <th>4</th>
    <th>5</th>
    <th>6</th>
    <th>7</th>
    <th>8</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td style="font-weight:900;">0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
	  <td>0</td>
  </tr>
  <tr>
    <th>1</th>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
	<td>0</td>
  </tr>
  <tr>
    <th>2</th>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
	<td>0</td>
  </tr>
  <tr>
    <th>3</th>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
	<td>0</td>
  </tr>
  <tr>
    <th>4</th>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
  </tr>
</tbody>
</table>

We start at weight zero and increase the weight, we do the same with the items.

Trivially, the first row is all $0$ since 0 objects will have 0 value. By the same logic the first column will also be zero since 0 weight implies we cannot carry anything. 

Lets fill the rest of the rows. The first object requires $W \geq 2$ and this means we can only place the first object *if* $W \geq 0$ .

<table>
<thead>
  <tr>
    <th></th>
	<th>0</th>
    <th>1</th>
    <th>2</th>
    <th>3</th>
    <th>4</th>
    <th>5</th>
    <th>6</th>
    <th>7</th>
    <th>8</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td style="font-weight:900;">0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
	  <td>0</td>
  </tr>
  <tr>
    <th>1</th>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
	<td>1</td>
  </tr>
  <tr>
    <th>2</th>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
	<td>0</td>
  </tr>
  <tr>
    <th>3</th>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
	<td>0</td>
  </tr>
  <tr>
    <th>4</th>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
  </tr>
</tbody>
</table>

The first object can be carried in any knapsack where $W\geq 2$ as shown on the table. 

When we consider the second object we also consider the first object. 

When the $W=2$ we can only place the first object. However when $W=3$ we can place the second object. Now if $W\geq5$ we can place both. 

<table>
<thead>
  <tr>
    <th></th>
	<th>0</th>
    <th>1</th>
    <th>2</th>
    <th>3</th>
    <th>4</th>
    <th>5</th>
    <th>6</th>
    <th>7</th>
    <th>8</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td style="font-weight:900;">0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
	  <td>0</td>
  </tr>
  <tr>
    <th>1</th>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
	<td>1</td>
  </tr>
  <tr>
    <th>2</th>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>2</td>
    <td>2</td>
    <td>3</td>
    <td>3</td>
    <td>3</td>
	<td>3</td>
  </tr>
  <tr>
    <th>3</th>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
	<td>0</td>
  </tr>
  <tr>
    <th>4</th>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
  </tr>
</tbody>
</table>

With row 3 can can consider the first three objects. 
The third item has a value of 5 at weight 4 which is higher than the current value at 4 so we replace that. Moreover, item 1 and item 3 have value 6 at weight 6 and weight 7 if we consider item 2 and 3. We cannot consider all three since that violates the weight limit. 

<table>
<thead>
  <tr>
    <th></th>
	<th>0</th>
    <th>1</th>
    <th>2</th>
    <th>3</th>
    <th>4</th>
    <th>5</th>
    <th>6</th>
    <th>7</th>
    <th>8</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td style="font-weight:900;">0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
	  <td>0</td>
  </tr>
  <tr>
    <th>1</th>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
	<td>1</td>
  </tr>
  <tr>
    <th>2</th>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>2</td>
    <td>2</td>
    <td>3</td>
    <td>3</td>
    <td>3</td>
	<td>3</td>
  </tr>
  <tr>
    <th>3</th>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>2</td>
    <td>5</td>
    <td>5</td>
    <td>6</td>
    <td>7</td>
	<td>7</td>
  </tr>
  <tr>
    <th>4</th>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
  </tr>
</tbody>
</table>

A formula for this problem is:

$$
V[i, w] = \max\{
V[i-1, w],
V[i-1, w - w[i]] + P[i]
\}
$$

> Out of bound values are considered '0'

<table>
<thead>
  <tr>
    <th></th>
	<th>0</th>
    <th>1</th>
    <th>2</th>
    <th>3</th>
    <th>4</th>
    <th>5</th>
    <th>6</th>
    <th>7</th>
    <th>8</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td style="font-weight:900;">0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
	  <td>0</td>
  </tr>
  <tr>
    <th>1</th>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
	<td>1</td>
  </tr>
  <tr>
    <th>2</th>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>2</td>
    <td>2</td>
    <td>3</td>
    <td>3</td>
    <td>3</td>
	<td>3</td>
  </tr>
  <tr>
    <th>3</th>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>2</td>
    <td>5</td>
    <td>5</td>
    <td>6</td>
    <td>7</td>
	<td>7</td>
  </tr>
  <tr>
    <th>4</th>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>2</td>
    <td>5</td>
    <td>6</td>
    <td>6</td>
    <td>7</td>
    <td>8</td>
  </tr>
</tbody>
</table>

## Understanding the Formula

$$
V[i, w] = \max\{
V[i-1, w],
V[i-1, w - w[i]] + P[i]
\}
$$

The $V$ array is the 2d array that saves the sub-problem results. 

+ $V[i-1, w]$ this is the case where the current object is not selected to be in the knapsack
+ $V[i-1, w - w[i]] + P[i]$ is when the current object is selected

First realize that $V[i-1, :]$ has the solution for the selecting the first $i-1$ items. Then realize that we can either not select the current item or we can. But to select the current item we need to reserve it's space with is $w[i]$ .

Given that the previous row contains the best case results,  we can attempt to see what would happen if we added our current item with the items that already added. 

**DP Code**:
```python
def knapsack_dp(W, V, Weight_limit):
    # padding to make indexing easier with these we would need to -1 from each array ref in the loops
    W = [0] + W
    V = [0] + V

    #generate DP array
    N = len(W)
    dp = [[0 for _ in range(Weight_limit + 1)] for _ in range(N)]

    for obj in range(1, N):
        for w in range(1, Weight_limit + 1):
            idx = w - W[obj] #check if object can be included
            # idx < 0 and not idx <= 0 because if idx == 0 then item can be placed in the sack
            if idx < 0: #if not just copy the last max
                dp[obj][w] = dp[obj - 1][w]
            else: # if it can see whats bigger (include vs not include)
                dp[obj][w] = max(dp[obj - 1][w], dp[obj - 1][idx] + V[obj])

    return dp[-1][-1]
```

All code is included in the `../snippets` folder.