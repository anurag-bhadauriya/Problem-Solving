// https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        findPermute(nums, 0);
        return ans;
    }
    
    void findPermute(vector<int>& nums, int i){
        if( i==nums.size() ){
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> s; // To keep track of duplicate elements
        for(int k=i; k<nums.size(); k++){
            if( s.find(nums[k]) != s.end()) continue; // If the elements is already fixed & permutated then no need to swap/permutate
            s.insert(nums[k]);
            swap(nums[i], nums[k]);
            findPermute(nums, i+1);
            swap(nums[i], nums[k]);
        }
    }
};