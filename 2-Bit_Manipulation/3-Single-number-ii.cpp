// https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result =0;
        
        // Iterating over each bit from right to left
        for(int i=0; i<32; i++){
            
            int k = 1 << i;
            int sum =0;
            // Iterating over each element of the array
            for(int j=0; j<nums.size(); j++){
                sum = sum + ( nums[j] & 1 );
                nums[j] = nums[j] >> 1;
            }
            
            if(sum%3 !=0 ){
                result = result | k;
            }
        }
        return result;
    }
};