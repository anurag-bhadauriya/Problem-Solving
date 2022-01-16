// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    
    enum Move_Type { LEFT, RIGHT };
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        Move_Type m = LEFT;
        Move_Type r = RIGHT;
        res.push_back(findStartingIndex(nums, target, m));
        res.push_back(findStartingIndex(nums, target, r));
        return res;
    }
    
    int findStartingIndex(vector<int>& nums, int target, Move_Type move){
        int low=0;
        int high= nums.size()-1;
        int idx= -1;
        if(high >= low){
            while(low <= high){
                int mid= low + ((high-low)/2);
                if(nums[mid] == target){
                    idx = mid;
                    if(move == LEFT){
                        high = mid-1;
                    }
                    else{
                        low = mid+1;
                    }

                }
                else if(nums[mid] > target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
        return idx;
    }
    
};