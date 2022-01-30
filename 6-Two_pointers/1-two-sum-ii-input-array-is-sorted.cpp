// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> result;

    int i = 0, j = numbers.size() - 1;
    while (i < j)
    {
        if (numbers[i] + numbers[j] < target)
        {
            i++;
        }
        else if (numbers[i] + numbers[j] > target)
        {
            j--;
        }
        else
        {
            result.push_back(i + 1);
            result.push_back(j + 1);
            break;
        }
    }
    return result;
}

int main()
{
    return 0;
}