// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(weights.begin(), weights.end()); // Max element of array
        int high;
        accumulate(weights.begin(), weights.end(), high) ; // Sum of all elements of array
        int result = -1;
        
        while( low <= high){
            int mid = low + ((high - low)/2);
            if( checkShipWithMaxWeight(weights, days, mid) ){
                result = mid;
                high = mid-1; // Left move
            }
            else{
                low = mid+1; // Right move
            } 
        }
        return result;
    }
    
    // Checks if shipping is possible with max_weight within certain days
    bool checkShipWithMaxWeight(vector<int>& weights, int days, int max_weight){
        int weight_per_day =0, days_count =1;
        
        for(int i=0; i< weights.size(); i++){
            if( (weight_per_day + weights[i]) > max_weight){
                days_count++;
                weight_per_day = weights[i];
            }
            else{
                weight_per_day += weights[i];
            }
            if(days_count > days) return false;
        }
        return true;
    }
};