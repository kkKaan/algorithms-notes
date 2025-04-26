#include <iostream>
#include <vector>

using namespace std;

int knapsack_rec(vector<int>& weights, vector<int>& values, int wLimit, int currIndex)
{
    if (!wLimit || currIndex < 0)
        return 0;

    int t1 = 0, t2 = 0;

    t1 = knapsack_rec(weights, values, wLimit, currIndex - 1);

    if (wLimit - weights[currIndex] >= 0)
        t2 = knapsack_rec(weights, values, wLimit - weights[currIndex], currIndex - 1) + values[currIndex];

    return max(t1, t2);
}

int knapsack_mem(vector<int>& weights, vector<int>& values, int wLimit, int currIndex, vector<vector<int>>& mem)
{
    if (!wLimit || currIndex < 0)
        return 0;

    if (mem[currIndex][wLimit] != -1)
        return mem[currIndex][wLimit];

    int t1 = 0, t2 = 0;

    t1 = knapsack_mem(weights, values, wLimit, currIndex - 1, mem);

    if (wLimit - weights[currIndex] >= 0)
    {
        t2 = knapsack_mem(weights, values, wLimit - weights[currIndex], currIndex - 1, mem) + values[currIndex];
    }

    mem[currIndex][wLimit] = max(t1, t2);
    return mem[currIndex][wLimit];
}

int knapsack_dp(vector<int>& weights, vector<int>& values, int wLimit, int currIndex)
{
    int n = weights.size() + 1;
    int m = wLimit + 1;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int t1 = 0, t2 = 0;

    for (int i = 1; i <= currIndex + 1; ++i)
    {
        for (int j = 0; j <= wLimit; ++j)
        {
            t1 = dp[i - 1][j];

            if (j - weights[i - 1] >= 0)
                t2 = dp[i - 1][j - weights[i - 1]] + values[i - 1];

            dp[i][j] = max(t1, t2);
        }
    }
    return dp[n - 1][m - 1];
}

int unbounded_ks_dp(vector<int>& weights, vector<int>& values, int wLimit, int currIndex)
{
    int n = weights.size() + 1;
    int m = wLimit + 1;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int t1 = 0, t2 = 0;

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= wLimit; ++j)
        {
            t1 = dp[i - 1][j];

            if (j - weights[i - 1] >= 0)
                t2 = dp[i - 1][j - weights[i - 1]] + values[i - 1];

            dp[i][j] = max(t1, t2);
        }
    }
    return dp[n - 1][m - 1];
}

int main()
{
    vector<int> weights = { 1, 2, 3 };
    vector<int> values = { 10, 15, 40 };
    int capacity = 6;

    cout << "Max value with recursion: " << knapsack_rec(weights, values, capacity, 2) << endl;

    vector<vector<int>> mem(3, vector<int>(capacity + 1, -1));

    cout << "Max value with memoization: " << knapsack_mem(weights, values, capacity, 2, mem) << endl;

    cout << "Max value with tabulation: " << knapsack_dp(weights, values, capacity, 2) << endl;

    cout << "Max value with tabulation (unbounded knapsack): " << unbounded_ks_dp(weights, values, capacity, 2) << endl;
    return 0;
}