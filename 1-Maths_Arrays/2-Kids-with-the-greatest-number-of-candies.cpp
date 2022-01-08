// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = findMax(candies);
        vector<bool> result;
        for(int i=0; i<candies.size(); i++){
            if((candies[i] + extraCandies) >= max){
                result.insert(result.end(), true);
            }
            else{
                result.insert(result.end(), false);
            }
        }
        return result;
    }
    
    int findMax(vector<int>& candies){
        int max = candies[0];
        for(int i=1; i<candies.size(); i++){
            if(candies[i] > max){
                max = candies[i];
            }
        }
        return max;
    }
};