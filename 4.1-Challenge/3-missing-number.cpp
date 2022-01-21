// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int res =0;
        for(int i=0; i<len; i++){
            if( nums[i] != i){
                res =i;
                return res;
            }
        }
        return len;
    }
};