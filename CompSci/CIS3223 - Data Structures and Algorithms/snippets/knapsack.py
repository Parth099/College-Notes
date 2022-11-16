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


V = [1, 2, 5, 6]
W = [2, 3, 4, 5]
Weight_limit = 8

carry_max = knapsack_dp(W, V, Weight_limit)
print(f'max weight: {carry_max}') # 9