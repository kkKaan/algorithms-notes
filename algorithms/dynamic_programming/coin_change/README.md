# Coin Change Problem

## Overview

The Coin Change Problem is a classic problem in dynamic programming. The goal is to determine the minimum number of coins needed to make a certain amount of money, given a set of coin denominations.

- Time complexity: $ O(n \cdot m)$, where $n$ is the amount and $m$ is the number of coin denominations.
- Space complexity: $ O(n)$, where $n$ is the amount.

## How It Works

1. Define a function that takes the amount and the list of coin denominations as input.
2. Create a list `dp` of size `amount + 1` initialized to infinity, except for `dp[0]`, which is set to 0.
3. Iterate through each coin denomination.
4. For each coin, iterate through the amounts from the coin value to the target amount.
5. Update the `dp` list to store the minimum number of coins needed for each amount.
6. Return `dp[amount]` if it's not infinity; otherwise, return -1 (indicating that it's not possible to make that amount with the given coins).

## Pseudocode
```plaintext
function coinChange(coins, amount):
    dp = array of size (amount + 1) initialized to infinity
    dp[0] = 0

    for x from coin to amount:
        for coin in coins:
            if x >= coin:
                dp[x] = min(dp[x], dp[x - coin] + 1)

    return dp[amount] if dp[amount] != infinity else -1
```

## Example Implementations

- [Coin Change in C++](./coin_change.cpp)