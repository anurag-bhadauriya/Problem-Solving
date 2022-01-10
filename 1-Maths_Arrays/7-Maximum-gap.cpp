// https://leetcode.com/problems/maximum-gap/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxDif=0;
        sort(nums.begin(), nums.end());
        for(int i =0;i <nums.size()-1; i++){
            maxDif = max(maxDif, nums[i+1]-nums[i]);
        }
        return maxDif;
    }
};