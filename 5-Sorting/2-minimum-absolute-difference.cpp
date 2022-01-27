// https://leetcode.com/problems/minimum-absolute-difference/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinimumABsDiff(vector<int> &arr)
{
    int minDiff = arr[1] - arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if ((arr[i] - arr[i - 1]) < minDiff)
            minDiff = arr[i] - arr[i - 1];
    }
    return minDiff;
}

vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    vector<vector<int>> result;

    sort(arr.begin(), arr.end());
    int minDiff = findMinimumABsDiff(arr);

    for (int i = 1; i < arr.size(); i++)
    {
        if ((arr[i] - arr[i - 1]) == minDiff)
            result.push_back(vector<int>{arr[i - 1], arr[i]});
    }
    return result;
}

int main()
{
    vector<int> arr{3, 8, -10, 23, 19, -4, -14, 27};
    minimumAbsDifference(arr); // Output: [[-14,-10],[19,23],[23,27]]
    return 0;
}