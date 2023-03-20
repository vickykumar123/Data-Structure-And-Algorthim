#include <bits/stdc++.h>
using namespace std;
bool isSafe(int x, int y, vector<vector<int>> &arr, int n,
            vector<vector<bool>> &visited)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] != 1) && arr[x][y] == 1)
    {
        return true;
    }
    else
        return false;
}
void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans,
           vector<vector<bool>> &visited, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    // Down
    if (isSafe(x + 1, y, arr, n, visited))
    {
        solve(x + 1, y, arr, n, ans, visited, path + 'D');
    }
    // Left
    if (isSafe(x, y - 1, arr, n, visited))
    {
        solve(x, y - 1, arr, n, ans, visited, path + 'L');
    }
    // right
    if (isSafe(x, y + 1, arr, n, visited))
    {
        solve(x, y + 1, arr, n, ans, visited, path + 'R');
    }
    // Up
    if (isSafe(x - 1, y, arr, n, visited))
    {
        solve(x - 1, y, arr, n, ans, visited, path + 'U');
    }
    // backTracking
    visited[x][y] = 0;
}
vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    string path = "";
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    if (arr[0][0] == 0)
    {
        return ans;
    }
    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}
int main()
{
}