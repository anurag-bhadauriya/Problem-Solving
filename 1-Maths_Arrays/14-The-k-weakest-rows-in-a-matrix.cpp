// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        //Find the number of soldiers in all rows
        vector<pair<int,int>> rowSum;
        vector<int> res;
        for(int i=0; i<mat.size(); i++){
            int sum =0;
            for(int j=0; j<mat[i].size(); j++){
                sum += mat[i][j];
            }
            rowSum.push_back(make_pair(sum, i));
        }
        sort(rowSum.begin(), rowSum.end());
        for(int i=0; i<k; i++) res.push_back(rowSum[i].second);
        return res;
    }
};