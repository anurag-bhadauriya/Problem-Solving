// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        
        // Create a left max array
        vector<int> left_max;
        int leftMax = 0;
        for(int i=0; i<height.size(); i++){
            left_max.push_back(leftMax);
            leftMax = max(leftMax, height[i]);
        }
        
        // Create a right max array
        vector<int> right_max;
        int rightMax = 0;
        for(int i=(height.size()-1) ; i>=0 ; i--){
            right_max.insert(right_max.begin(), rightMax);
            rightMax = max(rightMax, height[i]);
        }
        
        // Calculate water height for each building
        int result=0;
        for(int i=0 ; i<height.size(); i++){
            int temp = min(left_max[i], right_max[i]) - height[i];
            if( temp >= 0){
                result = result+temp;
            }
        }
        
        return result;
        
    }
};