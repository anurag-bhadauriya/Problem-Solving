// https://www.geeksforgeeks.org/counting-inversions/
// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/

#include <iostream>
#include <vector>
using namespace std;

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long grp = 1, p1, p2;
    long long int ans = 0;
    while (grp < N)
    {
        p1 = 0, p2 = grp;
        while (p2 < N)
        {
            //merge(p1,p2,n);
            long long temp[(p2 - p1) * 2] = {0}, t_i = 0;
            long long i = p1, j = p2;
            while (i < p2 && j < (p2 + grp) && j < N)
            {
                if (arr[i] <= arr[j])
                    temp[t_i++] = arr[i++];
                else if (arr[i] > arr[j])
                    temp[t_i++] = arr[j++], ans += (p2 - i);
            }
            while (i < p2)
                temp[t_i++] = arr[i++];
            while (j < (p2 + grp) && j < N)
                temp[t_i++] = arr[j++];
            long long cnt = t_i;
            t_i = p1, i = 0;
            while (i < cnt)
                arr[t_i++] = temp[i++];
            p1 = p2 + grp, p2 = p1 + grp;
        }
        grp *= 2;
    }
    return ans;
}

int main()
{
    return 0;
}
