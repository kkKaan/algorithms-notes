# Maximum Sum Subarray Problem

## Overview

The problem seeks to find the contiguous subarray within a one-dimensional array of numbers that has the largest sum. There are several algorithms to solve this problem, but I am interested in the greedy one here. With naive approach, you can try every subarray, which is $O(n^2)$. The greedy algorithm (Kadane's algorithm) is more efficient with $O(n)$ time complexity.

- Time complexity: $O(n)$
- Space complexity: $O(1)$

## How It Works

1. Initialize two variables, `max_so_far` and `max_ending_here`, to the first element of the array.
2. Iterate through the array starting from the second element.
3. For each element, update `max_ending_here` to the maximum of the current element and the sum of the current element and `max_ending_here`.
4. Update `max_so_far` to the maximum of `max_so_far` and `max_ending_here`.
5. Return `max_so_far` as the maximum sum of a subarray.

## Pseudocode
```plaintext
procedure maxSubArraySum(A: array of integers)
    max_so_far = A[0]
    max_ending_here = A[0]
    for i from 1 to length(A) - 1 do
        max_ending_here = max(A[i], A[i] + max_ending_here)
        max_so_far = max(max_so_far, max_ending_here)
    end for
    return max_so_far
end procedure
```

## Example Implementations

- [Kadane's Algorithm in C](./kadane.c)