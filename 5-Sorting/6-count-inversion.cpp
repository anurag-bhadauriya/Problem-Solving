// https://www.geeksforgeeks.org/counting-inversions/
// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/

#include <iostream>
#include <vector>
using namespace std;

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    return 0;
}
