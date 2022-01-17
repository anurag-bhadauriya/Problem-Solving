// https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int dvnd = abs(dividend);
        long long int dvsr = abs(divisor);
        long long int res=0;
        
        if(dvnd == 0 || dvnd < dvsr){
            res =0;
        } 
        else if (dvsr == 1){
            res =dvnd;
        }else{
            long long int i=0, tempDvsr = dvsr, tempDvnd =dvnd;
            while(tempDvsr <= tempDvnd){
                if(tempDvsr == tempDvnd){
                    res++; break;
                } else {
                    tempDvsr = tempDvsr << 1; i++;;
                    if(tempDvsr == tempDvnd){
                        res +=pow(2,i); break;
                    }
                    else if(tempDvsr > tempDvnd){
                        tempDvsr = tempDvsr >> 1; i--;
                        res += pow(2,i);
                        tempDvnd -= tempDvsr;
                        tempDvsr = dvsr;
                        i=0;
                    }
                }
                cout << "dvsr: " << tempDvsr << ", Dividend: " << tempDvnd << ", Res: " << res << endl;
            }
        }
        if(dividend < 0) res *= -1;
        if(divisor < 0) res *= -1;
        if(res > INT_MAX ) res = INT_MAX;
        return res;
    }
};