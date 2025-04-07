# The Skyline Problem

## Overview

The Skyline Problem involves determining the outline of a set of buildings in a city skyline. Each building is represented by a triplet (left, right, height), where `left` and `right` are the x-coordinates of the left and right edges of the building, and `height` is its height. The goal is to find the points that form the outline of the skyline when viewed from a distance.

- Time complexity: $O(n \log n)$
- Space complexity: $O(n)$

## How It Works

1. Divide the buildings into two halves.
2. Recursively compute the skyline for each half.
3. Merge the two skylines similar to merge sort.

## Pseudocode
```plaintext
skyline(buildings)
    if buildings is empty
        return []

    mid = len(buildings) // 2
    left_skyline = skyline(buildings[:mid])
    right_skyline = skyline(buildings[mid:])

    return merge(left_skyline, right_skyline)
merge(left, right)
    result = []
    h1 = h2 = 0
    i = j = 0

    while i < len(left) and j < len(right)
        if left[i][0] < right[j][0]
            x = left[i][0]
            h1 = left[i][1]
            i += 1
        else
            x = right[j][0]
            h2 = right[j][1]
            j += 1

        max_height = max(h1, h2)
        if not result or result[-1][1] != max_height
            result.append((x, max_height))

    while i < len(left)
        result.append(left[i])
        i += 1

    while j < len(right)
        result.append(right[j])
        j += 1

    return result
```

## Example Implementations

- [Skyline Problem in C++](./skyline.cpp)