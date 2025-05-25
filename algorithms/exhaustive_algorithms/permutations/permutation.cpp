#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int> nums, vector<int>& curr, vector<vector<int>>& res, int goalSize)
{
    int n = nums.size();
    if (curr.size() == goalSize)
        res.push_back(curr);
    else
    {
        for (int i = 0; i < n; ++i)
        {
            curr.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            backtrack(nums, curr, res, goalSize);
            nums.insert(nums.begin() + i, curr[curr.size() - 1]);
            curr.pop_back();
        }
    }
}

vector<vector<int>> permutation(vector<int> nums)
{
    vector<vector<int>> res;
    vector<int> curr;
    backtrack(nums, curr, res, nums.size());
    return res;
}

int main()
{
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> res = permutation(nums);

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