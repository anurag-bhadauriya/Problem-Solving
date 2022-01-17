// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0, end = matrix.size()-1;
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        while(start <= end){
            int mid = (start + end)/2;
            // If target lies in the mid
            if( target >= matrix[mid][0] && target <= matrix[mid][colSize-1] ){
                return binarySearch(matrix, target, mid);
            }
            // If target lies on left side of mid
            else if( target < matrix[mid][0] ){
                end = mid -1;
            }
            // If target lies on right side of mid
            else if( target > matrix[mid][colSize-1] ){
                start = mid+1;
            }
        }
        return false;
    }
    
    bool binarySearch(vector<vector<int>>& matrix, int target, int idx){
        int start =0, end = matrix[idx].size()-1;
        while(start <= end){
            int mid = (start + end)/2;
            if(matrix[idx][mid] == target){
                return true;
            }
            else if( target < matrix[idx][mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return false;
    }
};