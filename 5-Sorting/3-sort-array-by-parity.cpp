// https://leetcode.com/problems/sort-array-by-parity/

#include <iostream>
#include <vector>
using namespace std;

void swapElement(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
vector<int> sortArrayByParity(vector<int> &nums)
{
    int idx;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 != 0)
        {
            idx = i;
            break;
        }
    }

    for (int i = idx + 1; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        {
            swapElement(nums, i, idx);
            idx++;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums{3, 1, 2, 4};
    sortArrayByParity(nums); // Output: [2,4,3,1]
    return 0;
}