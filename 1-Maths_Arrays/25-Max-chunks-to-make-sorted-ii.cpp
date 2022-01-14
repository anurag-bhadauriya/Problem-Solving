// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

/*
    Achieved using the chaining technique. 
    1. Create array containing max from left.
    2. Create array containing min from right.
    3. Iterate over the original array & increase the chunks counter.
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int len = arr.size();
        vector<int> left_max(len+1, INT_MIN);
        vector<int> right_min(len+1, INT_MAX);
        
        left_max[0] = arr[0];
        for(int i=1; i<len; i++)
            left_max[i] =max(left_max[i-1], arr[i]);
        
        for(int i=0; i<left_max.size(); i++)
            cout << left_max[i] << " ";
        cout << endl;
        
        right_min[len-1] =arr[len-1];
        for(int i=len-2; i>=0; i--)
            right_min[i] = min(right_min[i+1], arr[i]);
        
        for(int i=0; i<right_min.size(); i++)
            cout << right_min[i] << " ";
        cout << endl;
        
        int chunkCount =0;
        for(int i=0; i<len; i++){
            if( left_max[i] <= right_min[i+1] ) chunkCount++;
        }
        
        return chunkCount;
    }
};