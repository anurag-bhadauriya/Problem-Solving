https://leetcode.com/problems/magnetic-force-between-two-balls/

class Solution {
public:
    // Acheived using binary search
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int low = 1, len = position.size();
        int high = position[len-1] - position[0];
        int result = 0;
        
        while(low <= high){
            int mid = (low+high)/2;
            if( checkBucketPossibility(position, m, mid) ){
                result =mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return result;
    }
    
    // Checks if it is possible fill m balls in array having minimum distance of minDist
    bool checkBucketPossibility(vector<int>& position, int m, int minDist){
        // Consider the first element is already contins one ball
        int noOfElems =1;
        int lastIncludedIndex =0;
        
        for(int i=1; i <position.size(); i++){
            if( (position[i] - position[lastIncludedIndex]) >= minDist){
                lastIncludedIndex = i;
                noOfElems++ ;
            }
            if(noOfElems == m) return true;
        }
        return false;
    }
};