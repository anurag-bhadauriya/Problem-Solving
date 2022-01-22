// https://leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generateString(string &str, int openCount, int closeCount);
vector<string> generateParenthesis(int n);

int main()
{
    cout << "Hello World!";
    return 0;
}

vector<string> result;

vector<string> generateParenthesis(int n)
{
    string str = "";
    generateString(str, n, n);
    return result;
}

void generateString(string &str, int openCount, int closeCount)
{
    // Base Condition
    if (openCount == 0 && closeCount == 0)
    {
        result.push_back(str);
        return;
    }

    // Condition to fill open parentheses
    if (openCount > 0)
    {
        str.push_back('(');
        generateString(str, openCount - 1, closeCount);
        str.pop_back();
    }

    // Condition to fill close parentheses
    if (closeCount > 0 && (openCount < closeCount))
    {
        str.push_back(')');
        generateString(str, openCount, closeCount - 1);
        str.pop_back();
    }
}
