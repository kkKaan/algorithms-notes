# Interval Partitioning (Greedy Solution)

## Overview

Interval Partitioning problem is to find the minimum number of resources needed to schedule a set of tasks. Each task has a start time and an end time, and the resources can only be used by one task at a time. The goal is to minimize the number of resources needed to schedule all tasks.

There are several wrong approaches to solving this problem, such as earliest finish time first, shortest task first, and fewest conflicts first. However, greedy algorithm can solve this problem optimally, using a priority queue to keep track of the resources that are currently in use.

- Time complexity: $O(n \log n)$ (both sorting and scheduling)
- Space complexity: $O(n)$

## How It Works

1. Sort the tasks by their start time.
2. Initialize a priority queue to keep track of the resources that are currently in use.
3. For each task, check if there is a resource available.
4. If there is a resource available, assign the task to the resource.
5. If there is no resource available, assign a new resource to the task.
6. Repeat steps 3-5 until all tasks are scheduled.


## Pseudocode
```plaintext
sort intervals by start time
d = 0
for 1 to n do 
    if lecture i is compatible with room k then
        schedule lecture i in room k
    else
        allocate a new room for lecture i
        schedule lecture i in the new room
        d = d + 1
    end if
```

## Example Implementations

- [Interval Partitioning in C](./interval_partitioning.c)