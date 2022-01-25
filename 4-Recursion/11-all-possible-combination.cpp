// https://leetcode.com/problems/combinations/

#include <iostream>
#include <vector>
using namespace std;

void generateCombination(vector<vector<int>> &result, vector<int> &comb, int start, int n, int k)
{
    // Base condition
    if (k == 0)
    {
        result.push_back(comb);
        return;
    }

    // Create combination
    for (int i = start; i <= n; i++)
    {
        comb.push_back(i);
        generateCombination(result, comb, i + 1, n, k - 1);
        comb.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> result;
    vector<int> comb;
    generateCombination(result, comb, 1, n, k);
    return result;
}

int main()
{
    vector<vector<int>> res;
    combine(4, 2); // Returns : [[2,4],[3,4],[2,3],[1,2],[1,3],[1,4],]
    combine(1, 1); // Returns : [[1]]
    cout << "Hello World!";
    return 0;
}
