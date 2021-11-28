# Sliding Array Problems

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