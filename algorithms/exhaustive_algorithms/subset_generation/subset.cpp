#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subset_gen_iter(vector<int>& vec)
{
    vector<vector<int>> res;
    res.push_back({});

    for (auto curr : vec)
    {
        int n = res.size();
        for (int i = n - 1; i >= 0; --i)
        {
            vector<int> temp = res[i];
            temp.push_back(curr);
            res.push_back(temp);
        }
    }
    return res;
}

void backtrack(int startIndex, vector<int>& curr, vector<int>& vec, vector<vector<int>>& res)
{
    res.push_back(curr);
    int n = vec.size();
    for (int i = startIndex; i < n; ++i)
    {
        curr.push_back(vec[i]);
        backtrack(i + 1, curr, vec, res);
        curr.pop_back();
    }
}

vector<vector<int>> subset_gen(vector<int>& vec)
{
    vector<vector<int>> res;
    vector<int> curr;
    backtrack(0, curr, vec, res);
    return res;
}

int main()
{
    vector<int> vec = { 1, 2, 3 };
    vector<vector<int>> subsetsIter = subset_gen_iter(vec);
    vector<vector<int>> subsetsBacktrack = subset_gen(vec);

    for (auto vec : subsetsBacktrack)
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
