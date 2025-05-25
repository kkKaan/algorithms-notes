#include <climits>
#include <iostream>
#include <vector>

using namespace std;

long rod_cutting_rec(vector<int> prices, long n)
{
    if (!n)
        return 0;

    long m = LLONG_MIN;
    for (int i = 0; i < n; ++i)
    {
        m = max(m, prices[i] + rod_cutting_rec(prices, n - i - 1));
    }
    return m;
}

long rod_cutting_mem(vector<int> prices, long n, vector<int>& mem)
{
    if (mem[n - 1] >= 0)
        return mem[n - 1];   // prices are bigger than 0
    else if (!n)
        return 0;

    long m = LLONG_MIN;
    for (int i = 0; i < n; ++i)
    {
        m = max(m, prices[i] + rod_cutting_mem(prices, n - i - 1, mem));
    }

    mem[n - 1] = m;
    return mem[n - 1];
}

long rod_cutting_dp(vector<int> prices, long n, vector<int>& dp)
{
    dp[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        int m = INT_MIN;
        for (int j = 0; j < i; ++j)
        {
            m = max(m, prices[j] + dp[i - j - 1]);
        }
        dp[i] = m;
    }
    return dp[n];
}

int main()
{
    long n = 8;
    vector<int> prices = { 1, 5, 8, 9, 10, 17, 17, 20 };
    vector<int> mem = { -1, -1, -1, -1, -1, -1, -1, -1 };
    vector<int> dp(n + 1, -1);
    cout << "Maximum obtainable value is (recursive) " << rod_cutting_rec(prices, n) << endl;
    cout << "Maximum obtainable value is (memoization) " << rod_cutting_mem(prices, n, mem) << endl;
    cout << "Maximum obtainable value is (tabulation) " << rod_cutting_dp(prices, n, dp) << endl;

    return 0;
}