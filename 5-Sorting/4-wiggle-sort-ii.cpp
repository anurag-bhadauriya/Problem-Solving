// https://leetcode.com/problems/wiggle-sort-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void wiggleSort(vector<int> &nums)
{
    vector<int> temp(nums.begin(), nums.end());
    sort(temp.begin(), temp.end());
    int len = nums.size();
    int i = 1, j = len - 1;

    bool isRotated = false;
    while (i < len)
    {
        nums[i] = temp[j];
        if (!isRotated && (i + 2) >= len)
        {
            i = 0;
            isRotated = true;
        }
        else
            i += 2;
        j -= 1;
    }
}

int main()
{
    vector<int> nums{1, 5, 1, 1, 6, 4};
    wiggleSort(nums); // Output: [1,6,1,5,1,4]
    return 0;
}
