// https://leetcode.com/problems/next-permutation/

class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int n = nums.size()-1;
        if(n > 0){
            
            // Step 1: Find the index where elements is lesser than its next index ie a[n] < a[n+1]
            int idx =-1;
            for(int i =n-1; i>=0; i--){
                if( nums[i] < nums[i+1] ) {
                    idx = i;
                    break;
                }
            }
            
            // Return the sorted array if next permutation does not exists
            if(idx ==-1){
                sort(nums.begin(), nums.end());
                return nums;
            }
            
            // Step 2: Find the index where element 
            int idx2 =0;
            for(int i=n; i>idx ; i--){
                if( nums[i] > nums[idx] ){
                    idx2 = i;
                    break;
                }
            }
            
            // Step 3: Swap element at idx & idx2
            int temp = nums[idx];
            nums[idx] = nums[idx2];
            nums[idx2] = temp;
            
            // Step 4: Sort the array between idx+1 to n
            sort(nums.begin()+idx+1, nums.end());
        }
        return nums;
    }
};