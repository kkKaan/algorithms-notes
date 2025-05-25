#include <iostream>
#include <vector>

using namespace std;

bool partition(vector<int> set)
{
    long sum = 0;
    for (auto i : set)
    {
        sum += i;
    }

    if (sum % 2)
    {
        return false;
    }

    int div = sum / 2;
    int n = set.size();

    vector<vector<bool>> dp(n + 1, (vector<bool>(div + 1, false)));

    for (int j = 0; j <= n; ++j)
    {
        dp[j][0] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= div; ++j)
        {
            if (set[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // To check which elements are actually used
    // for (int i = n; i > 0;)
    // {
    //     for (int j = div; j > 0;)
    //     {
    //         if (dp[i][j] != dp[i - 1][j])
    //         {
    //             cout << i << ' ';
    //             j -= set[i - 1];
    //             --i;
    //         }
    //         else
    //             --i;
    //     }
    //     cout << endl;
    // }

    return dp[n][div];
}

int main()
{
    vector<int> set = { 3, 1, 1, 2, 2, 1 };

    cout << "Is it possible to have 2 subsets of equal sum: " << partition(set) << endl;

    return 0;
}