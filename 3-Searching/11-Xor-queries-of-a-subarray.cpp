// https://leetcode.com/problems/xor-queries-of-a-subarray/

//Subset sum concept can be used
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // Update arr where each elem contains its xor with all previous elements
        for(int i=1; i<arr.size(); i++){
            arr[i] = arr[i] ^ arr[i-1];
        }
        // Iterate in queries array
        vector<int> result;
        for(int i=0; i<queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int xor_within_range;
            if(start !=0){
                xor_within_range = arr[end] ^ arr[start-1];
            }
            else xor_within_range = arr[end];
            result.push_back(xor_within_range);
        }
        return result;
    }
};