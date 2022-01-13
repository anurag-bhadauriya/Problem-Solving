// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int row=mat.size(), col=mat[0].size();
        
        vector<vector<int>> res=mat;
        for( int k=1; k<=4; k++) {
            for(int i =0; i<row; i++){
                for(int j=0; j< col; j++){
                    res[j][col-i-1] = mat[i][j];
                }
            }
        
            if( target == res ) return true;
            else mat =res;
        }
        
        
        return false;
    }
};