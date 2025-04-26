# 0-1 Knapsack Problem

## Overview

The 0-1 Knapsack Problem is a classic optimization problem in computer science and operations research. The problem is defined as follows:
Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible. Each item can either be included in the knapsack or excluded from it (hence "0-1"). Also there are 2 versions of the problem, bounded and unbounded. In the bounded version, each item can be included only once, while in the unbounded version, an item can be included multiple times.

- Time complexity: $O(nW)$, where $n$ is the number of items and $W$ is the maximum weight capacity of the knapsack.
- Space complexity: $O(nW)$ for the dynamic programming approach, but can be optimized to $O(W)$ using a 1D array.

## How It Works

1. Define the problem: You have a set of items, each with a weight and a value, and a maximum weight capacity for the knapsack.
2. Create a 2D array `dp` where `dp[i][w]` represents the maximum value that can be obtained with the first `i` items and a weight limit of `w`.
3. Initialize the first row and column of the `dp` array to 0, as no items or weight means no value.
4. Iterate through each item and each weight limit, updating the `dp` array based on whether to include the current item or not.
5. The final answer will be in `dp[n][W]`, where `n` is the number of items and `W` is the maximum weight capacity.
6. Optionally, backtrack through the `dp` array to find which items were included in the optimal solution.

## Pseudocode
```plaintext
function knapsack(weights, values, W):
    n = length(weights)
    dp = array of size (n+1) x (W+1) initialized to 0

    for i from 1 to n:
        for w from 1 to W:
            if weights[i-1] <= w:
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]] + values[i-1])
            else:
                dp[i][w] = dp[i-1][w]

    return dp[n][W]
```

## Example Implementations

- [0-1 Knapsack in C++](./knapsack.cpp)