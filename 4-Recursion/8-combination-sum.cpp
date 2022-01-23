// https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <vector>
using namespace std;

void findCombination(vector<int> &candidates, vector<int> &combination, int target, vector<vector<int>> &combinations_list, int start)
{
    // Base Condition
    if (target == 0)
    {
        combinations_list.push_back(combination);
        return;
    }

    if (target < 0)
        return;

    for (int i = start; i < candidates.size(); i++)
    {
        // Selecting condition
        if (candidates[i] <= target)
        {
            combination.push_back(candidates[i]);
            findCombination(candidates, combination, target - candidates[i], combinations_list, i);
            combination.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> combinations_list;
    vector<int> combination;
    findCombination(candidates, combination, target, combinations_list, 0);
    return combinations_list;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    combinationSum(candidates, target);
    return 0;
}
