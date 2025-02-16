# Bubble Sort

## Overview

Bubble Sort is a simple, comparison-based algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. 

- Time complexity: `O(n^2)`
- Space complexity: `O(1)`
- Stable: Yes
- In-place: Yes
- Best performance: `O(n)` (when the list is already sorted)
- Worst performance: `O(n^2)` (when the list is sorted in reverse order)

## How It Works

1. Iterate through the list from start to finish.
2. Compare each pair of adjacent elements.
3. Swap the elements if they are in the wrong order.
4. Repeat the process until no swaps are needed on a full pass through the list.

## Pseudocode
```plaintext
procedure bubbleSort(A: array of items)
    n = length(A)
    for i from 0 to n - 1 do
        swapped = false
        for j from 0 to n - i - 2 do
            if A[j] > A[j + 1] then
                swap(A[j], A[j + 1])
                swapped = true
            end if
        end for
        if not swapped then
            break
        end if
    end for
end procedure
```

## Example Implementations

- [Python](./bubble_sort.py)