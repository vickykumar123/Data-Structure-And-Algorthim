#include <bits/stdc++.h>
using namespace std;
void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                temp.push_back(j + 1); // this prints where the queens are in column
            }
            // if u want to push the output in format of board use
            // temp.push_back(board[i][j])
        }
    }
    ans.push_back(temp);
}
bool isSafe(int col, int row, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;
    // checking row;
    while (y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
    }
    // checking for upper diagonal
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }
    // checking for lower diagonal
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
        x++;
    }
    return true;
}
void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(col, row, board, n))
        {
            board[row][col] = 1;
            solve(col + 1, board, ans, n); // use chatGPT with example... to understand the recursion....
            // backTracking
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, board, ans, n);
    sort(ans.begin(), ans.end()); // ans in sorted order if u want
    return ans;
}