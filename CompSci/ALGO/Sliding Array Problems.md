# Sliding Array Problems

[[LeetCode]]

## Max Contiguous Sum

Let arr  = $[-2,1,-3,4,-1,2,1,-5,4]$
What is the max consecutive sum(contiguous) in the array?
Here its simply $sum([4, -1, 2, 1]) = 6$ 

## Brute Force

You can take every **single** subarray and find its sum. For $arr$ you would take every array with -2, than -1 and so on.

```python
def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxSubArr = nums[0]
        
        for x in range(0, len(nums)):
            curr = 0
            for y in range(x, len(nums)):
                curr += nums[y]
                maxSubArr = max(maxSubArr, curr)
                
        return maxSubArr

```

This is sadly $O(n^2)$



## Kadane's Algorithm - Maximum Sum Subarray

The idea here is that we loop over each element and ask:
$$\text{What is the max subArray upto this point?}$$

At each point(index) we have **2** options:
1. Start a new Sub Array Sum at that point
2. Add the next element onto the sum

```python
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        gobMax = nums[0];
        localMax = nums[0];
        for x in range(1, len(nums)):
            localMax = max(localMax+nums[x], nums[x])
            gobMax = max(gobMax, localMax)
            
        return gobMax
```

### Analysis of Kadane's Algorithm 
One loop $\to O(n)$

Every loop we notice the change in $localMax$. We see that it see if its a good idea to start a new SubArray or not. 

$gobMax$ is self-explanatory.  

---
## Max Contiguous Product

EX-1 from https://leetcode.com/problems/maximum-product-subarray/submissions/

**Input:** nums = [2,3,-2,4]
**Output:** 6
**Explanation:** [2,3] has the largest product 6.

This can be solved with an extension of Kadane's Algorithm. 

```python
def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_prod, min_prod, ans = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            x = max(nums[i], max_prod*nums[i], min_prod*nums[i])
            y = min(nums[i], max_prod*nums[i], min_prod*nums[i])            
            max_prod, min_prod = x, y
            ans = max(max_prod, ans)
        return ans
```
### Analysis

First thing we notice is that there are Temp vars x, y. There exist because both $max$ and $min$ depend on each other and so they cannot be altered when they are both being decided.  

Now the reason why we keep a min is for this reason. Imagine a sequence like: $$[\dotso P, Q, R \dotso], P > 0,  \ \ \ Q, R < 0$$

We would miss the max since $Q \times R > 0$ but max skips over negative numbers.

We can imagine the running of this Algorithm as such:
To find the max we have 3 options when encountering a **new** number in the array:

1. This number creates a new max by it self 
2. This number can be added to the moving product_max to create a new local max
3. This number can be added to the moving product_min to create a new local min 

The moving min can become the max very fast if it is already *very small* $p < 0$ and and the next index is a neg number making $p > 0$
 
