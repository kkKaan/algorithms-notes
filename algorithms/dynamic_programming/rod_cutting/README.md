# Rod Cutting

## Overview

The Rod Cutting problem is a classic optimization problem that can be solved using dynamic programming. The goal is to determine the maximum revenue obtainable by cutting up a rod and selling the pieces based on given prices for each length.

- Time complexity: $O(n^2)$, where $n$ is the length of the rod.
- Space complexity: $O(n)$, where $n$ is the length of the rod.

## How It Works

1. Define a function that takes the length of the rod and an array of prices.
2. Create an array `dp` to store the maximum revenue for each length from 0 to n.
3. Initialize `dp[0]` to 0, as the maximum revenue for a rod of length 0 is 0.
4. Iterate through each length `i` from 1 to n.
5. For each length `i`, iterate through all possible cuts `j` from 1 to `i`.
6. Calculate the maximum revenue by comparing the current maximum revenue with the revenue obtained by making a cut at length `j` and adding it to the maximum revenue of the remaining length `i - j`.
7. Store the maximum revenue in `dp[i]`.
8. Return `dp[n]`, which contains the maximum revenue for the rod of length n.

## Pseudocode
```plaintext
function rodCutting(prices, n):
    dp = array of size n+1
    dp[0] = 0

    for i from 1 to n:
        maxRevenue = -infinity
        for j from 1 to i:
            maxRevenue = max(maxRevenue, prices[j] + dp[i - j])
        dp[i] = maxRevenue

    return dp[n]
```

## Example Implementations

- [Rod Cutting in C++](./rod_cutting.cpp)