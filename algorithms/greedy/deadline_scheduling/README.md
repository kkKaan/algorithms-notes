# Deadline Scheduling (Greedy Solution)

## Overview

Deadline Scheduling is a classic problem to schedule tasks with deadlines and processing times. The goal is to minimize the lateness of the tasks. There are several failing approaches to solving this problem, including shortest processing time first and smallest remaining time to deadline first. The optimal solution is a simple greedy one, which sorts the tasks by deadline and schedules them in order.

- Time complexity: $O(n \log n)$ (sorting $O(n \log n)$, scheduling $O(n)$)
- Space complexity: $O(n)$

## How It Works

1. Sort the tasks by deadline.
2. Schedule the tasks in order.

## Pseudocode
```plaintext
procedure deadlineScheduling(tasks: array of Task)
    n = length(tasks)
    sort(tasks) by deadline
    current_time = 0
    latency = 0
    for i from 0 to n - 1 do
        current_time += tasks[i].processing_time
        latency += max(0, current_time - tasks[i].deadline)
    end for
end procedure
```

## Example Implementations

- [Deadline Scheduling in C](./deadline_scheduling.c)