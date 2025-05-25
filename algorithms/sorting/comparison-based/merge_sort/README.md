# Merge Sort

## Overview

It is a stable divide-and-conquer sorting algorithm that divides the input array into two halves, recursively sorts the two halves, and then merges the sorted halves. 

- Time complexity: $O(n \log n)$
- Space complexity: $O(n)$
- Stable: Yes
- In-place: No
- Best performance: $O(n \log n)$
- Worst performance: $O(n \log n)$

## How It Works

1. Divide the input array into two halves.
2. Recursively sort the two halves.
3. Merge the sorted halves.

## Pseudocode
```plaintext
procedure mergeSort(A: array of integers)
    n = length(A)
    if n < 2 then
        return
    end if
    mid = n / 2
    left = array of mid elements
    right = array of (n - mid) elements
    for i from 0 to mid - 1 do
        left[i] = A[i]
    end for
    for i from mid to n - 1 do
        right[i - mid] = A[i]
    end for
    mergeSort(left)
    mergeSort(right)
    merge(A, left, right)
end procedure

procedure merge(A: array of integers, left: array of integers, right: array of integers)
    nL = length(left)
    nR = length(right)
    i = 0
    j = 0
    k = 0
    while i < nL and j < nR do
        if left[i] <= right[j] then
            A[k] = left[i]
            i = i + 1
        else
            A[k] = right[j]
            j = j + 1
        end if
        k = k + 1
    end while
    while i < nL do
        A[k] = left[i]
        i = i + 1
        k = k + 1
    end while
    while j < nR do
        A[k] = right[j]
        j = j + 1
        k = k + 1
    end while
end procedure
```

## Example Implementations

- [Merge Sort in C](./merge_sort.c)