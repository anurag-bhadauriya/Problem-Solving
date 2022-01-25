// https://leetcode.com/problems/power-of-three/submissions/

#include <iostream>
#include <vector>
using namespace std;

bool isPowerOfThree(int n)
{
    if (n == 1)
        return true;
    if (n == 0 || n % 3 != 0)
        return false;
    return isPowerOfThree(n / 3);
}

int main()
{
    cout << isPowerOfThree(27);
    return 0;
}