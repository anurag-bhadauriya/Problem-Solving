// https://leetcode.com/problems/total-hamming-distance/


// Based on mathematical approach
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int totalDist =0;
        int len = nums.size();
        // Fixing the number of bits to be 32 & counting the 1's & 0's at each bit
        for(int i=0; i<32; i++){
            int setCount =0;
            for( int j=0; j<len; j++){
                if((nums[j] & (1 << i))) setCount++;
            }
            totalDist += setCount*( len-setCount);
        }
        return totalDist;
    }
};


// BRUTE FORCE SOLUTION
/*
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sum =0;
        for(int i=0; i<nums.size()-1 ; i++){
            for(int j=i+1; j<nums.size(); j++){
                sum += hammingDistance(nums[i], nums[j]);
            }
        }
        return sum;
    }
    
    int hammingDistance(int a, int b){
        int c = a ^ b;
        int dist =0;
        while(c > 0){
            if( c & 1 == 1){
                dist++;
            }
            c >> 1;
        }
        return dist;
    }
};
*/