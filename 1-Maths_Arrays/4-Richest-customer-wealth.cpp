// https://leetcode.com/problems/richest-customer-wealth/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth =0;
        for(int i=0; i<accounts.size(); i++){
            
            //Compute the total wealth of customer
            int totalWealth =0;
            for(int j=0; j<accounts[i].size(); j++){
                totalWealth += accounts[i][j];
            }
            //Set maximum wealth
            if(totalWealth > maxWealth){
                maxWealth = totalWealth;
            }
        }
        return maxWealth;
    }
};