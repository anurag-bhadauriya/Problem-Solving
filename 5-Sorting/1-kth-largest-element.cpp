// https://leetcode.com/problems/kth-largest-element-in-an-array

#include <iostream>
#include <vector>
using namespace std;

// using Bubble Sort
void swapElems(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int findKthLargest(vector<int> &nums, int k)
{
    int len = nums.size();

    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j < len; j++)
        {
            if (nums[j - 1] > nums[j])
                swapElems(nums, j, j - 1);
        }
    }

    return nums[len - k];
}

int main()
{
    vector<int> nums{3, 2, 1, 5, 6, 4};
    findKthLargest(nums, 2); // Output: 5
    vector<int> nums2{3, 2, 3, 1, 2, 4, 5, 5, 6};
    findKthLargest(nums2, 4); // Output: 4
    return 0;
}

// Solution using Selection sort

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int len = nums.size();

//         for(int i=0; i<k;i++){
//             int max = nums[i], maxIdx =i;
//             for(int j=i; j<len; j++){
//                 if(max < nums[j]){
//                     max = nums[j]; maxIdx = j;
//                 }
//             }
//             swapElems(nums, maxIdx, i);
//         }

//         return nums[k-1];
//     }

//     void swapElems(vector<int>& arr, int i, int j){
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//     }
// };