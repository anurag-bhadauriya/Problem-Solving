// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int tRow =0, tCol =col-1;
        while( tRow < row && tCol >= 0){
            if( matrix[tRow][tCol] == target) return true;
            else if( target > matrix[tRow][tCol]) tRow++;
            else tCol--;
        }
        return false;
    }
};

/* Binary search with complexity nlogn

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        if(target < matrix[0][0] || target > matrix[row-1][col-1]){
            return false;
        } else{
            for(int i=0; i <row; i++){
                if( target >= matrix[i][0] && target <= matrix[i][col-1]){
                    if( binarySearch(matrix[i], target) ) return true;
                }
            }
        }
        
        return false;
    }
    
    bool binarySearch(vector<int>& matrix, int target){
        int low = 0;
        int high = matrix.size()-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(target == matrix[mid]) return true;
            else if(target < matrix[mid]){
                high =mid-1; //Move left
            }
            else{
                low = mid-1; // Move right
            }
        }
        return false;
    }
};

*/

/* Brute Force
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool isTargetPresent = false;
        
        if(target < matrix[0][0] || target > matrix[row-1][col-1]){
            return false;
        }
        else{
            for(int i=0; i<row; i++){
                if(target >= matrix[i][0] && target <= matrix[i][col-1]){
                    for(int j=0; i<col; j++){
                        if( target == matrix[i][j]){
                            isTargetPresent = true; break;
                        }
                    }
                }
                if(isTargetPresent) break;
            }
        }
        return isTargetPresent;
    }
};
*/