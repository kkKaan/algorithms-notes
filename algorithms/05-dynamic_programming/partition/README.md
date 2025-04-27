# Partition Problem

## Overview

The Partition Problem is a classic problem in computer science and combinatorial optimization. It involves determining whether a given set of integers can be partitioned into two subsets such that the sum of the elements in both subsets is equal.
This problem is NP-complete, meaning that there is no known polynomial-time solution for all cases. However, it can be solved using dynamic programming techniques.

- Time complexity: $O(n \cdot W)$, where $n$ is the number of elements in the set and $W$ is the target sum (half of the total sum of the set).
- Space complexity: $O(n \cdot W)$ for the DP table, but can be optimized to $ O(W)$ using a 1D array.

## How It Works

1. Calculate the total sum of the elements in the set.
2. If the total sum is odd, return false, as it cannot be partitioned into two equal subsets.
3. Initialize a DP table where `dp[i][j]` will be true if a subset with sum `j` can be formed using the first `i` elements.
4. Iterate through the elements and fill the DP table:
   - If the current element is less than or equal to the current sum `j`, check if either including or excluding the element can form the sum.
   - If the current element is greater than `j`, carry forward the previous value.
5. The answer will be in `dp[n][W]`, where `n` is the number of elements and `W` is half of the total sum.
6. If `dp[n][W]` is true, the set can be partitioned into two subsets with equal sum; otherwise, it cannot.

## Pseudocode
```plaintext
function canPartition(nums):
    totalSum = sum(nums)
    if totalSum % 2 != 0:
        return false

    target = totalSum / 2
    n = length(nums)
    
    dp = array of size (n+1) x (target+1)
    
    for i from 0 to n:
        dp[i][0] = true  // A sum of 0 can always be formed with an empty subset
    
    for i from 1 to n:
        for j from 1 to target:
            if nums[i-1] <= j:
                dp[i][j] = dp[i-1][j] or dp[i-1][j - nums[i-1]]
            else:
                dp[i][j] = dp[i-1][j]
    
    return dp[n][target]
```

## Example Implementations

- [Partition Problem in C++](./partition.cpp)