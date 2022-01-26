// https://leetcode.com/problems/add-digits
// https://www.hackerrank.com/challenges/recursive-digit-sum

#include <iostream>
using namespace std;

int main()
{
    cout << "Recursive digits sum: " << addDigits(38);
    return 0;
}

int addDigits(int num)
{
    int sum = find_sum(num);
    if (sum < 10)
        return sum;
    else
        return addDigits(sum);
}

int find_sum(int num)
{
    if (num < 10)
        return num;
    else
        return ((num % 10) + find_sum(num / 10));
}