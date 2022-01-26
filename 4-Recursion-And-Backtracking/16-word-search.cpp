// https://leetcode.com/problems/word-search/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool travereAndFind(int row, int col, int idx, vector<vector<char>> &board, vector<vector<int>> &visited, string &word)
{
    // Base Condition
    if (word.length() == idx)
    {
        return true;
    }

    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || visited[row][col] == 1 || board[row][col] != word[idx])
    {
        return false;
    }

    // Backtrack after visiting all paths
    visited[row][col] = 1;
    bool res = (travereAndFind(row + 1, col, idx + 1, board, visited, word) ||
                travereAndFind(row - 1, col, idx + 1, board, visited, word) ||
                travereAndFind(row, col - 1, idx + 1, board, visited, word) ||
                travereAndFind(row, col + 1, idx + 1, board, visited, word));
    visited[row][col] = 0;

    return res;
}

bool exist(vector<vector<char>> &board, string word)
{
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols, 0));

    // Loops to check the first matching character of word in matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == word[0])
            {
                if (travereAndFind(i, j, 0, board, visited, word))
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    // Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    // Output: true

    // Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
    // Output: true

    // Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
    // Output: false
    return 0;
}