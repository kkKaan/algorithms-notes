#include <climits>
#include <iostream>
#include <vector>

using namespace std;

long coin_change_rec(vector<int> coins, int sum, int currIndex)
{
    int n = coins.size();
    if (sum == 0)
        return 0;
    else if (n <= currIndex || sum < 0)
        return INT_MAX;

    long skip = coin_change_rec(coins, sum, currIndex + 1);

    long take = INT_MAX;

    if (coins[currIndex] <= sum)
    {
        long curr = coin_change_rec(coins, sum - coins[currIndex], currIndex);
        if (curr != INT_MAX)
            take = curr + 1;
    }

    return min(take, skip);
}

long coin_change_memo(vector<int>& coins, int sum, int currIndex, vector<vector<long>>& memo)
{
    int n = coins.size();
    if (!sum)
        return 0;
    else if (currIndex >= n || sum < 0)
        return INT_MAX;

    if (memo[currIndex][sum] != -1)
        return memo[currIndex][sum];

    long skip = coin_change_memo(coins, sum, currIndex + 1, memo);

    long take = INT_MAX;

    if (coins[currIndex] <= sum)
    {
        long curr = coin_change_memo(coins, sum - coins[currIndex], currIndex, memo);
        if (curr != INT_MAX)
            take = curr + 1;
    }

    memo[currIndex][sum] = min(skip, take);
    return memo[currIndex][sum];
}

long coin_change_dp(vector<int>& coins, int sum)
{
    vector<long> dp(sum + 1, INT_MAX);
    dp[0] = 0;

    int n = coins.size();
    for (int i = 1; i <= sum; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[sum];
}

int main()
{
    vector<int> coins = { 1, 2, 5 };
    int sum = 11;

    cout << "Min num of coins recursive: " << coin_change_rec(coins, sum, 0) << endl;

    vector<vector<long>> memo(coins.size(), vector<long>(sum + 1, -1));

    cout << "Min num of coins memoization: " << coin_change_memo(coins, sum, 0, memo) << endl;

    cout << "Min num of coins dp: " << coin_change_dp(coins, sum) << endl;

    return 0;
}