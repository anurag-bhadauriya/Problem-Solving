// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

/*
    Approach:
    Count the rows and columns that appear odd times;
*/
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> vect(m, vector<int>(n,0));
        int count = 0;
        for(int i=0; i<indices.size(); i++){
            int row = indices[i][0];
            for(int k=0;k<vect[row].size(); k++){
                ++vect[row][k];
            }
            
            int col = indices[i][1];
            for(int k=0;k<vect.size(); k++){
                ++vect[k][col];
            }
        }
        
        for(int i=0; i<vect.size(); i++){
            for(int j=0; j<vect[i].size(); j++){
                if(vect[i][j]%2==1)
                    count++;
            }
        }
        return count;
        
    }
};