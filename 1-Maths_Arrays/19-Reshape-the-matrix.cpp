// https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n =mat[0].size();
        if( m*n != r*c) return mat;
        
        vector<vector<int>> res;
        res.push_back({});
        int k=0, l=0;
        
        for(int i=0; i< m; i++){
            for(int j=0; j< n; j++){
                if( l == c){
                    l =0;
                    k++; res.push_back({});
                }
                res[k].push_back(mat[i][j]);
                l++;
            }
        }
        
        return res;
    }
};