// https://leetcode.com/problems/gray-code/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> grayCode(int n)
{
    vector<int> code;

    if (n == 1)
        code = {0, 1};
    else
    {
        vector<int> prev_code = grayCode(n - 1);

        for (int i = 0; i < prev_code.size(); i++)
            code.push_back(prev_code[i]);

        for (int i = prev_code.size() - 1; i >= 0; i--)
            code.push_back(pow(2, n - 1) + prev_code[i]);
    }

    return code;
}

int main()
{
    vector<int> res = grayCode(1);
    return 0;
}