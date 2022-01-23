// https://leetcode.com/problems/subsets/

#include <iostream>
#include <vector>
using namespace std;

void findSubsets(vector<int> &subsets, int idx, vector<int> &nums);
vector<vector<int>> subsets(vector<int> &nums);
vector<vector<int>> res; // Final array to store all the subsets

int main()
{
    cout << "Hello World!";
    return 0;
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> subsets;
    findSubsets(subsets, 0, nums);
    return res;
}

void findSubsets(vector<int> &subsets, int idx, vector<int> &nums)
{
    if (idx == nums.size())
    {
        res.push_back(subsets);
        return;
    }
    // Not including the idx index element in subset
    findSubsets(subsets, idx + 1, nums);
    // Include the idx index element in subset
    subsets.push_back(nums[idx]);
    findSubsets(subsets, idx + 1, nums);
    subsets.pop_back();
}
