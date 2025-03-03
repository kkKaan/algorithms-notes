# Interval Scheduling (Greedy Activity Selection)

## Overview

The problem is to find the maximum number of non-overlapping activities that can be scheduled in a given time frame. Each activity has a start time and an end time. The goal is to select the maximum number of activities that do not overlap with each other.

There are some heuristics that does not work, like selecting the activity with the earliest start time, or the activity with the shortest duration. The greedy algorithm works by selecting the activity that finishes first, regardless of the start time.

- Time complexity: $O(n \log n)$ (Sorting $O(n \log n)$, Greedy $O(n)$)
- Space complexity: $O(n)$ (Depending on your sorting algorithm)

## How It Works

1. Sort the activities by their finish time.
2. Select the first activity.
3. For each remaining activity, if the start time is greater than or equal to the finish time of the last selected activity, select the activity.
4. Repeat step 3 until all activities are processed.

## Pseudocode
```plaintext
procedure intervalScheduling(startTimes: array of integers, endTimes: array of integers, n: integer)
    endTimes
    count ← 0
    currentEndTime ← 0
    
    for i ← 0 to n-1 do
        if startTimes[i] >= currentEndTime then
            // Select this activity
            currentEndTime ← endTimes[i]
            count ← count + 1
        end if
    end for
    
    return count
end procedure
```

## Example Implementations

- [Interval Scheduling in C](./interval_scheduling.c)