# Closest Pair of Points

## Overview

Given a set of points in the plane, find the closest pair of points.

- Time complexity: $O(n \log n \log n)$
- Space complexity: $O(n)$

## How It Works

1. Sort the points according to their x-coordinates.
2. Divide the set of points into two equal-sized subsets by a vertical line.
3. Solve the problem recursively in the two subsets.
4. Check if there is a pair of points, one in each subset, that are closer than the smallest distance found in the recursive calls.
5. Combine the results.

## Pseudocode
```plaintext
closest_pair(points)
    sort points by x-coordinate
    return closest_pair_recursive(points)

closest_pair_recursive(points)
    if |points| <= 3
        return brute_force(points)
    
    mid = |points| / 2
    left = points[0:mid]
    right = points[mid:]
    
    left_closest = closest_pair_recursive(left)
    right_closest = closest_pair_recursive(right)
    
    closest = min(left_closest, right_closest)
    
    mid_x = points[mid].x
    strip = []
    for point in points
        if |point.x - mid_x| < closest
            strip.append(point)
    
    return min(closest, strip_closest(strip))
```

## Example Implementations

- [Closest Pair of Points in C++](./closest_pair.cpp)