// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // Only one element
        if(nums.size() ==1){
            return nums[0];
        }
        // Multiple elements
        else{
            int low =1;
            int high = nums.size()-2;
            while(low <= high){
                int mid = (low+high)/2;
                if(mid%2 != 0 ){
                    if( nums[mid] == nums[mid+1]){
                        high = mid-1;
                    }
                    else if(nums[mid] == nums[mid-1]){
                        low = mid+1;
                    }
                    else {
                        return nums[mid];
                    }
                }
                else {
                    if( nums[mid] == nums[mid+1]){
                        low = mid+1;
                    }
                    else if(nums[mid] == nums[mid-1]){
                        high = mid-1;
                    }
                    else {
                        return nums[mid];
                    }
                }
            }
            
            if(low == nums.size()-1){
                return nums[low];
            }
            else if(high == 0){
                return nums[high];
            }
        }
        return -1;
    }
};