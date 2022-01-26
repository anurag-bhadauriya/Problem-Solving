// https://leetcode.com/problems/n-queens/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Checks if the place we are putting the queen is valid or not
bool checkPlaceValidity(int col, int row, vector<string> &board, int n)
{
    int rowii = row;
    int colii = col;

    // Check for left upper diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    // Check for left lower diagonal
    row = rowii;
    col = colii;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    // Check for left side
    row = rowii;
    col = colii;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    return true;
}

// Find the Queen patterns on the board
void findPattern(int col, int n, vector<string> &board, vector<vector<string>> &soln)
{

    // Base Condition
    if (col == n)
    {
        soln.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (checkPlaceValidity(col, i, board, n))
        {
            board[i][col] = 'Q';
            findPattern(col + 1, n, board, soln);
            board[i][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> soln;
    vector<string> board(n);
    string str(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = str;

    findPattern(0, n, board, soln);
    return soln;
}

int main()
{
    solveNQueens(4); // Output:  [["..Q.","Q...","...Q",".Q.."],[".Q..","...Q","Q...","..Q."]]
    solveNQueens(1); // Output: [["Q"]]
    return 0;
}
