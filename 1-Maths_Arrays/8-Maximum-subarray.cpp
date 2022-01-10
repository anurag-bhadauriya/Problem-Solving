// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum =INT_MIN;
        int max_end_here =0;
        
        // Using Kadane's algorithm
        for(int i=0; i<nums.size(); i++){
            max_end_here += nums[i];
            max_sum = max(max_sum, max_end_here);
            if(max_end_here < 0){
                max_end_here =0;
            }
        }
        return max_sum;
    }
};