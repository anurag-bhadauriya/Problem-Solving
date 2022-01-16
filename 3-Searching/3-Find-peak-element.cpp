// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0; 
        int high = nums.size()-1;
        
        // In case of one elements
        if(high == 0){
            return 0;
        } 
        // In case of two elements
        else if(high == 1){
            if( nums[0] > nums[1]){
                return 0;
            }
            else {
                return 1;
            }
        }
        // In case of more than two elements
        else{
            while( low <= high){
                int mid = (low + high)/2;
                if(mid != 0 && mid != nums.size()-1 ){
                    if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                        return mid;
                    }
                    else if(nums[mid] < nums[mid-1]){
                        //Left move
                        high = mid-1;
                    }
                    else if(nums[mid] < nums[mid+1]){
                        //Right move
                        low = mid+1;
                    }
                }
                else{
                    if(mid ==0 ){
                        if(nums[mid] > nums[mid+1]){
                            return mid;
                        }
                        else{
                            return mid+1;
                        }
                    }
                    else if(mid == nums.size()-1) {
                        if(nums[mid] > nums[mid-1]){
                            return mid;
                        }
                        else{
                            return mid-1;
                        }
                    }
                }
                
            }
            return -1;
        }
    }
};