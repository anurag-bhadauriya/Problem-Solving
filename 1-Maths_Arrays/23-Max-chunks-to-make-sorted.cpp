// https://leetcode.com/problems/max-chunks-to-make-sorted/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunksCount =0;
        int maxScope =0;
        
        for(int i=0; i<arr.size(); i++){
            maxScope = max(arr[i], maxScope);
            if( maxScope == i) chunksCount++;
        }
        return chunksCount;
    }
};