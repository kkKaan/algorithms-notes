# Permutations

## Overview

Permutations are arrangements of all or part of a set of objects. The order of arrangement is significant, and each arrangement is unique. This algorithm generates all possible permutations of a given list of elements.

- Time complexity: $ O(n!) $
- Space complexity: $ O(n) $ (for recursion stack)

## How It Works (Iterative Approach)

1. Start with an empty list to hold the current permutation.
2. Recursively build permutations by adding one element at a time.
3. When the current permutation reaches the length of the original list, it is added to the result list.
4. Backtrack by removing the last added element and trying the next available element.
5. Repeat until all permutations are generated.

## Pseudocode
```plaintext
function generate_permutations(elements):
    result = []
    current_permutation = []

    function backtrack(start):
        if start == length(elements):
            result.append(current_permutation.copy())
            return
        
        for i from start to length(elements) - 1:
            swap(elements[start], elements[i])  # Swap to fix the current element
            current_permutation.append(elements[start])
            backtrack(start + 1)  # Recur for the next element
            current_permutation.pop()  # Remove the last added element
            swap(elements[start], elements[i])  # Swap back to restore order

    backtrack(0)
    return result
```

## Example Implementations

- [Permutations in C++](./permutations.cpp) 