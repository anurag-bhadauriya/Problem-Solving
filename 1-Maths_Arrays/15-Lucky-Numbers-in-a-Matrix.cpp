// https://leetcode.com/problems/lucky-numbers-in-a-matrix/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        vector<int> res;
        
        for(int i=0; i<rowLen; i++){
            
            // Find index of minimum Element for ith row
            int minIdx = -1, minElem =INT_MAX;
            for(int j=0; j<matrix[i].size(); j++){
                if( minElem > matrix[i][j]) {
                    minElem = matrix[i][j]; minIdx =j;
                }
            }
            
            // Find index of the maximum element
            int maxIdx =-1, maxElem =0;
            for(int k =0; k<rowLen ; k++){
                if(maxElem < matrix[k][minIdx]){
                    maxElem = matrix[k][minIdx]; maxIdx =k;
                }
            }
            
            if( minElem == maxElem) res.push_back(minElem);
        }
        return res;
    }
};