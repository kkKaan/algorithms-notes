#include <iostream>

int count_digits(long a)
{
    int count = 0;
    a = a < 0 ? -a : a;
    while (a)
    {
        a /= 10;
        ++count;
    }
    return count;
}

long pow(long num, int power)
{
    int ret = 1;
    for (int i = 0; i < power; ++i)
    {
        ret *= num;
    }
    return ret;
}

void split_at(long num, long& high, long& low, int m)
{
    int temp = pow(10, m);
    low = num % temp;
    high = num / temp;
}

long karatsuba(long a, long b)
{
    if (a < 10 || b < 10)
        return a * b;
    int dA = count_digits(a);
    int dB = count_digits(b);
    int m = dA > dB ? dA : dB;
    int m2 = m / 2;

    long high1 = 0, low1 = 0;
    split_at(a, high1, low1, m2);
    long high2 = 0, low2 = 0;
    split_at(b, high2, low2, m2);

    long z0 = karatsuba(low1, low2);
    long z1 = karatsuba(low1 + high1, low2 + high2);
    long z2 = karatsuba(high1, high2);

    return (z2 * pow(10, 2 * m2)) + ((z1 - z2 - z0) * pow(10, m2)) + z0;
}

int main()
{
    double a = 1234, b = 4567;
    std::cout << karatsuba(a, b) << std::endl;
}