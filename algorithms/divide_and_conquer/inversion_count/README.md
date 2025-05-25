# Inversion Count

## Overview

Given an array of integers, count the number of inversions in the array. An inversion is a pair of indices (i, j) such that i < j and arr[i] > arr[j].
This problem can be solved using a modified merge sort algorithm. While merging two halves of the array, we can count how many elements from the right half are less than the elements from the left half. This gives us the number of inversions.

- Time complexity: $O(n \log n)$
- Space complexity: $O(n)$

## How It Works

1. Divide the array into two halves.
2. Recursively count the inversions in each half.
3. Count the inversions that cross the midpoint while merging the two halves.
4. Combine the counts from the two halves and the crossing inversions.
5. Return the total count of inversions.

## Pseudocode
```plaintext
FUNCTION InversionCount(arr, size)
    count = 0
    MergeSort(arr, 0, size - 1, count)
    RETURN count

FUNCTION MergeSort(arr, left, right, count)
    IF left < right
        mid = (left + right) / 2
        
        // Recursively sort and count inversions in left half
        MergeSort(arr, left, mid, count)
        
        // Recursively sort and count inversions in right half
        MergeSort(arr, mid + 1, right, count)
        
        // Count inversions across the divide while merging
        Merge(arr, left, mid, right, count)

FUNCTION Merge(arr, left, mid, right, count)
    // Create temporary arrays
    n1 = mid - left + 1
    n2 = right - mid
    
    leftArray[0...n1-1]
    rightArray[0...n2-1]
    
    // Copy data to temporary arrays
    FOR i = 0 TO n1-1
        leftArray[i] = arr[left + i]
    
    FOR i = 0 TO n2-1
        rightArray[i] = arr[mid + 1 + i]
    
    // Merge the two arrays while counting inversions
    i = 0    // Index for left array
    j = 0    // Index for right array
    k = left // Index for merged array
    
    WHILE i < n1 AND j < n2
        IF leftArray[i] <= rightArray[j]
            arr[k] = leftArray[i]
            i = i + 1
        ELSE
            // This is where we count inversions
            // All remaining elements in left array form inversions with rightArray[j]
            arr[k] = rightArray[j]
            count = count + (n1 - i)
            j = j + 1
        k = k + 1
    
    // Copy remaining elements from left array
    WHILE i < n1
        arr[k] = leftArray[i]
        i = i + 1
        k = k + 1
    
    // Copy remaining elements from right array
    WHILE j < n2
        arr[k] = rightArray[j]
        j = j + 1
        k = k + 1
```

## Example Implementations

- [Inversion Count in C++](./inversion_count.cpp)