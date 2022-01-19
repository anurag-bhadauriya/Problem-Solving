// https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/

class Solution {
public:
    int preimageSizeFZF(int k) {
        if(k==0)return 5;
        
        long long l=0;
        long long r=INT_MAX;
        while(l<r)
        {
            long long m=l+(r-l)/2;
            
            long long temp=5;
            long long count=m;
            while(temp<=m)
            {
                count+=(m/temp);
                temp*=5;
            }
            if(count>k)r=m;
            else if (count<k) l=m+1;
            else return 5;
        }
        return 0;
    }

};