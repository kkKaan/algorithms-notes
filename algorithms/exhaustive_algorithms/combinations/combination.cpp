#include <iostream>

using namespace std;

void backtrack(int start, vector<int>& comb, vector<vector<int>>& res, int n, int k)
{
    if (comb.size() == k)
        res.push_back(comb);
    else
    {
        for (int i = start; i <= n; ++i)
        {
            comb.push_back(i);
            backtrack(i + 1, comb, res, n, k);
            comb.pop_back();
        }
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> comb;

    backtrack(1, comb, res, n, k);
    return res;
}

int main()
{
    vector<vector<int>> res = combine(4, 2);

    for (auto vec : res)
    {
        cout << "{ ";
        for (auto num : vec)
        {
            cout << num << " ";
        }
        cout << '}' << endl;
    }

    return 0;
}