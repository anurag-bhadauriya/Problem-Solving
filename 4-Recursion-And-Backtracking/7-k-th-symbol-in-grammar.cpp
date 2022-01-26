// https://leetcode.com/problems/k-th-symbol-in-grammar

#include <iostream>
#include <vector>
using namespace std;

int kthGrammar(int n, int k);

int main()
{
    cout << "Hello World!";
    return 0;
}

// Find the kth element of the parent element
int kthGrammar(int n, int k)
{
    if (n == 1 && k == 1)
        return 0;
    int parentElementIdx = (k % 2 == 1) ? (k + 1) / 2 : (k / 2);
    int parentElem = kthGrammar(n - 1, parentElementIdx);

    if (parentElem % 2 == 1)
    {
        return ((k % 2 == 1) ? 1 : 0);
    }
    else
    {
        return ((k % 2 == 1) ? 0 : 1);
    }
}