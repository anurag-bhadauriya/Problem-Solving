// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> permute(vector<int>& nums) {
        findPermute(nums, 0);
        return ans;
    }
    
    void findPermute(vector<int>& nums, int i){
        if( i==nums.size() ){
            ans.push_back(nums);
            return;
        }
        for(int k=i; k<nums.size(); k++){
            swap(nums[i], nums[k]);
            findPermute(nums, i+1);
            swap(nums[i], nums[k]);
        }
    }
};