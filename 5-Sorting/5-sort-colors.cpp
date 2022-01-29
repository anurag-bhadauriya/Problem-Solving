// https://leetcode.com/problems/sort-colors

#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums)
{
    // Can be done using count sort in O(n) time and const space

    // Create count array
    vector<int> countArray(3, 0);

    // Fill count array using nums
    for (int i = 0; i < nums.size(); i++)
    {
        switch (nums[i])
        {
        case 0:
            countArray[0]++;
            break;
        case 1:
            countArray[1]++;
            break;
        case 2:
            countArray[2]++;
            break;
        default:
            break;
        }
    }

    // Update nums array using count array
    int cIdx = 0, k = 0;
    while (cIdx < 3)
    {
        int elemCount = countArray[cIdx];
        while (elemCount != 0)
        {
            nums[k] = cIdx;
            k++;
            elemCount--;
        }
        cIdx++;
    }
}

int main()
{
    vector<int> nums{2, 0, 2, 1, 1, 0};
    sortColors(nums); // Output: [0,0,1,1,2,2]
    return 0;
}