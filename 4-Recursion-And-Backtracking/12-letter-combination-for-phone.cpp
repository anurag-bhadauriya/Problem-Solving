// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<char, string> digitMap{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

void generateString(string &digits, vector<string> &result, string &str, int idx)
{
    if (idx == digits.length())
    {
        if (str.length())
            result.push_back(str);
        return;
    }

    for (int i = 0; i < digitMap[digits[idx]].length(); i++)
    {
        str.push_back(digitMap[digits[idx]][i]);
        generateString(digits, result, str, idx + 1);
        str.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> result;
    string str;

    generateString(digits, result, str, 0);
    return result;
}

int main()
{
    letterCombinations("23"); // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    letterCombinations("");   // Output: []
    letterCombinations("2");  // Output: ["a","b","c"]
    return 0;
}
