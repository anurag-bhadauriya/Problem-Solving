// https://leetcode.com/problems/maximum-ice-cream-bars/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int len = costs.size();
        sort(costs.begin(), costs.end());
        int count =0;
        for(int i=0; i<len; i++){
            if(costs[i] > coins) break;
            count++;
            coins -= costs[i];
        }
        return count;
    }
};