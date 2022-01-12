// https://leetcode.com/problems/transpose-matrix/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row =matrix.size(), col =matrix[0].size();
        
        vector<vector<int>> res;
        
        for(int i =0; i<col; i++) res.push_back({});
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                res[j].push_back(matrix[i][j]);
            }
        }
        return res;
    }
};