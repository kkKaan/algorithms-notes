# Greedy Coin Change

## Overview

This is a method to find the minimum number of coins needed to make change for a given amount. The greedy algorithm works by selecting the largest coin denomination that is less than or equal to the remaining amount. This process is repeated until the remaining amount is zero.

However, the greedy algorithm does not always produce the optimal solution. For example, if the coin denominations are 1, 3, and 4, the greedy algorithm will produce 4 coins for the amount 6 (4 + 1 + 1), while the optimal solution is 2 coins (3 + 3). Plus, may not find a solution at all for some inputs.

- Time complexity: $O(n)$
- Space complexity: $O(1)$

## How It Works

1. Sort the coin denominations in ascending order.
2. Initialize a variable `count` to 0.
3. While the remaining amount is greater than 0:
    1. Find the largest coin denomination that is less than or equal to the remaining amount.
    2. Subtract the coin denomination from the remaining amount.
    3. Increment `count` by 1.
4. Return `count`.

## Pseudocode
```plaintext
procedure greedyCoinChange(coins: array of integers, amount: integer)
    sort coins in ascending order
    count = 0
    while amount > 0 do
        for i from length(coins) - 1 to 0 do
            if coins[i] <= amount then
                amount -= coins[i]
                count += 1
                break
            end if
        end for
    end while
    return count
end procedure
```

## Example Implementations

- [Greedy Coin Change in C](./greedy_coin_change.c)