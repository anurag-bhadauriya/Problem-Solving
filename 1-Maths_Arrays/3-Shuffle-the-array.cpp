// https://leetcode.com/problems/shuffle-the-array/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for(int i=0; i< n; i++){
            res.insert( res.end(), nums[i]);
            res.insert( res.end(), nums[n+i]);
        }
        return res;
    }
};