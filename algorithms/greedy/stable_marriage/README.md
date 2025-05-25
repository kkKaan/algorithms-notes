# Stable Marriage Problem

## Overview

Stable Marriage is a classic problem in combinatorial mathematics and computer science. The problem is to find a stable matching between two sets of elements given a set of preferences for each element. Stable solution, in this context, means that there are no two elements that prefer each other over their current partners. Naive algorithm is $O(n!)$, where you try every permutation of the elements. Gale-Shapley algorithm is a more efficient solution that runs in $O(n^2)$ time.

- Time complexity: $O(n^2)$
- Space complexity: $O(n)$

## How It Works

1. Initialize all elements to be free and unengaged.
2. While there
3. For each free element, propose to the most preferred element that has not rejected the proposal.
4. If the proposed element is free, they become engaged.
5. If the proposed element is already engaged, they compare their current partner with the proposing element.
6. If the proposed element prefers the proposing element, they break up with their current partner and become engaged with the proposing element.
7. If the proposed element prefers their current partner, they reject the proposal.
8. Repeat steps 3-7 until all elements are engaged.

## Pseudocode
```plaintext
procedure stableMarriage(A: array of array of integers, B: array of array of integers)
    n = length(A)
    engaged = array of n elements
    free = array of n elements
    for i from 0 to n - 1 do
        free[i] = true
    end for
    while there is a free element do
        for i from 0 to n - 1 do
            if free[i] then
                for j from 0 to n - 1 do
                    k = A[i][j]
                    if engaged[k] = -1 then
                        engaged[k] = i
                        free[i] = false
                        break
                    else
                        l = engaged[k]
                        if B[k][i] < B[k][l] then
                            engaged[k] = i
                            free[i] = false
                            free[l] = true
                            break
                        end if
                    end if
                end for
            end if
        end for
    end while
    return engaged
end procedure
```

## Example Implementations

- [Gale-Shapley Algorithm in C](./gale_shapley.c)