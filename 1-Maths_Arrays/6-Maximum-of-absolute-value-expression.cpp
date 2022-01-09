// https://leetcode.com/problems/maximum-of-absolute-value-expression/

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int> sumArr;
        vector<int> diffArr;
        
        for(int i=0;i<arr1.size(); i++){
            sumArr.push_back(arr1[i]+arr2[i]);
            diffArr.push_back(arr1[i]-arr2[i]);
        }
        
        return max( getAbsValue(sumArr), getAbsValue(diffArr));
        
    }
    
    int getAbsValue(vector<int>& arr){
        int maxA = INT_MIN, maxB = INT_MIN;
        int minA = INT_MAX, minB = INT_MAX;
        
        for(int i=0; i<arr.size(); i++){
            int elemA= arr[i]+i;
            int elemB= arr[i]-i;
            
            maxA = max(maxA, elemA);
            maxB = max(maxB, elemB);
            minA = min(minA, elemA);
            minB = min(minB, elemB);
        }
        
        return max((maxA-minA), (maxB-minB));
    }
    
};