// prefix_sum matrix

class NumMatrix {
    vector<vector<int>> prefix_sum;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row =matrix.size(), col =matrix[0].size();
        
        /* Row wise additions */
        for(int i=0; i<row; i++){
            int sum =0;
            vector<int> temp;
            for(int j=0; j<col; j++){
                sum +=matrix[i][j];
                temp.push_back(sum);
            }
            prefix_sum.push_back(temp);
        }
        
        
        /* Column wise additions */
        for(int i=0; i<col; i++){
            int sum =0;
            for(int j=0; j<row; j++){
                sum += prefix_sum[j][i];
                prefix_sum[j][i] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefix_sum[row2][col2];
        if(row1 !=0) sum -=prefix_sum[row1-1][col2];
        if(col1 !=0) sum -=prefix_sum[row2][col1-1];
        if(row1 !=0 && col1 !=0) sum +=prefix_sum[row1-1][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */