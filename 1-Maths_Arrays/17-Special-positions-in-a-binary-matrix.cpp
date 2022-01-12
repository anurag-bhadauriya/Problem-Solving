// https://leetcode.com/problems/special-positions-in-a-binary-matrix/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rLen = mat.size(), cLen = mat[0].size();
        int count =0;
        for(int i=0; i<rLen; i++){
            int colIdx =-1;
            int sumRow =0;
            for(int j=0; j<cLen; j++){
                if(mat[i][j] ==1){
                    sumRow += 1; colIdx =j;
                }
            }
            
            if(sumRow == 1){
                int sumCol=0;
                for(int k=0; k<rLen ; k++){
                    if(mat[k][colIdx] ==1){
                        sumCol++;
                    }
                }
                
                if(sumCol ==1) count++;
            }
        }
        
        return count;
    }
};