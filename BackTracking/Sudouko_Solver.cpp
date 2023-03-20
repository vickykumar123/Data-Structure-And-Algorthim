#include <bits/stdc++.h>
using namespace std;
bool isVaild(int row, int col, vector<vector<int>> &board, int val)
{
    for (int i = 0; i < board.size(); i++)
    {
        // row check for val
        if (board[row][i] == val)
            return false;
        // col check for val
        if (board[i][col] == val)
            return false;
        // check for 3*3 matrix
        int rowCheck = 3 * (row / 3) + i / 3;
        int colCheck = 3 * (col / 3) + i % 3;
        if (board[rowCheck][colCheck] == val)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> &board)
{
    int rowSize = board.size(), colSize = board[0].size();
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isVaild(row, col, board, val))
                    {
                        board[row][col] = val;
                        bool solvedSudoku = solve(board);
                        if (solvedSudoku)
                            return true;
                        else
                        {
                            // backTracking the solution
                            board[row][col] = 0;
                        }
                    }
                }
                // below false is because u didnt got any 0 or empty space
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}
int main()
{
}