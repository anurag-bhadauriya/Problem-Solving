// https://leetcode.com/problems/matrix-diagonal-sum/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int len =mat.size();
        int maxIdx = len-1;
        
        int sum =0;
        for(int i=0; i<=maxIdx; i++){
            sum += mat[i][i] + mat[maxIdx-i][i];
        }
        
        if(len%2 != 0) sum -= mat[len/2][len/2];
        
        return sum;
    }
};