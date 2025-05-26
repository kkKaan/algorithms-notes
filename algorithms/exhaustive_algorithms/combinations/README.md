# Combinations

## Overview

Combinations are a way to select items from a larger set where the order of selection does not matter. This is different from permutations, where the order does matter. Combinations are often used in scenarios such as lottery number selection, team formation, and more.

- Time complexity: $ O(n \choose k)$, where $n$ is the total number of items and $k$ is the number of items to choose.
- Space complexity: $  O(k)$ for storing each combination.

## How It Works (Iterative Approach)

1. Start with an empty combination.
2. Use a loop to iterate through the items in the set.
3. For each item, decide whether to include it in the current combination.
4. If the current combination reaches the desired size, store it.
5. Continue until all combinations of the desired size have been generated.

## Pseudocode
```plaintext
function generateCombinations(set, k):
    result = []
    currentCombination = []

    def backtrack(start):
        if len(currentCombination) == k:
            result.append(currentCombination.copy())
            return
        
        for i in range(start, len(set)):
            currentCombination.append(set[i])
            backtrack(i + 1)
            currentCombination.pop()

    backtrack(0)
    return result
```

## Example Implementations

-  [Combinations in C++](./combinations.cpp)