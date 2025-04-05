# Karatsuba's Algorithm

## Overview

Karatsuba's algorithm is a divide and conquer algorithm for multiplying large numbers. It reduces the multiplication of two n-digit numbers to at most three multiplications of n/2-digit numbers, which is more efficient than the traditional grade-school method.

- Time complexity: $O(n^{\log_2 3})$ (approximately $O(n^{1.585})$)
- Space complexity: $O(n)$

## How It Works

1. Split the numbers into two halves.
2. Recursively compute three products:
   - $z_0 = a_0 \times b_0$ (lower half)
   - $z_1 = (a_0 + a_1) \times (b_0 + b_1)$ (cross terms)
   - $z_2 = a_1 \times b_1$ (upper half)
3. Combine the results using the formula:
   $$ z = z_2 \times 10^{2m} + (z_1 - z_2 - z_0) \times 10^m + z_0 $$
   where $m$ is the number of digits in the lower half.
4. Return the final result.

## Pseudocode
```plaintext
karatsuba(x, y)
    if x < 10 or y < 10
        return x * y

    m = max(length(x), length(y))
    m2 = m / 2

    a = x / 10^m2
    b = x % 10^m2
    c = y / 10^m2
    d = y % 10^m2

    z0 = karatsuba(b, d)
    z1 = karatsuba((a + b), (c + d))
    z2 = karatsuba(a, c)

    return (z2 * 10^(2 * m2)) + ((z1 - z2 - z0) * 10^m2) + z0
```

## Example Implementations

- [Karatsuba's Algorithm in C++](./karatsuba.cpp)