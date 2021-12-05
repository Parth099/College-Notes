# Sliding Array Problems

## Max Contiguous Sum

Let arr  = <img src="https://render.githubusercontent.com/render/math?math=%5B-2%2C1%2C-3%2C4%2C-1%2C2%2C1%2C-5%2C4%5D">
What is the max consecutive sum(contiguous) in the array?
Here its simply <img src="https://render.githubusercontent.com/render/math?math=sum%28%5B4%2C%20-1%2C%202%2C%201%5D%29%20%3D%206"> 

## Brute Force

You can take every **single** subarray and find its sum. For <img src="https://render.githubusercontent.com/render/math?math=arr"> you would take every array with -2, than -1 and so on.

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

This is sadly <img src="https://render.githubusercontent.com/render/math?math=O%28n%5E2%29">



## Kadane's Algorithm - Maximum Sum Subarray

The idea here is that we loop over each element and ask:
<img src="https://render.githubusercontent.com/render/math?math=%5Ctext%7BWhat%20is%20the%20max%20subArray%20upto%20this%20point%3F%7D">

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
One loop <img src="https://render.githubusercontent.com/render/math?math=%5Cto%20O%28n%29">

Every loop we notice the change in <img src="https://render.githubusercontent.com/render/math?math=localMax">. We see that it see if its a good idea to start a new SubArray or not. 

<img src="https://render.githubusercontent.com/render/math?math=gobMax"> is self-explanatory.  

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

First thing we notice is that there are Temp vars x, y. There exist because both <img src="https://render.githubusercontent.com/render/math?math=max%24%20and%20%24min"> depend on each other and so they cannot be altered when they are both being decided.  

Now the reason why we keep a min is for this reason. Imagine a sequence like: <img src="https://render.githubusercontent.com/render/math?math=%5B%5Cdotso%20P%2C%20Q%2C%20R%20%5Cdotso%5D%2C%20P%20%3E%200%2C%20%20%5C%20%5C%20%5C%20Q%2C%20R%20%3C%200">

We would miss the max since <img src="https://render.githubusercontent.com/render/math?math=Q%20%5Ctimes%20R%20%3E%200"> but max skips over negative numbers.

We can imagine the running of this Algorithm as such:
To find the max we have 3 options when encountering a **new** number in the array:

1. This number creates a new max by it self 
2. This number can be added to the moving product_max to create a new local max
3. This number can be added to the moving product_min to create a new local min 

The moving min can become the max very fast if it is already *very small* <img src="https://render.githubusercontent.com/render/math?math=p%20%3C%200%24%20and%20and%20the%20next%20index%20is%20a%20neg%20number%20making%20%24p%20%3E%200">
 