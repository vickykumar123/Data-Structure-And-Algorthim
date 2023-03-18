/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at
(3, 3) from (0, 0) by two paths - DRDDRR
and DDRDRR, when printed in sorted order
we get DDRDRR DRDDRR.
*/

#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve(vector<vector<int>> m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    // Down
    int x1 = x + 1;
    int y1 = y;
    if (isSafe(m, n, x1, y1, visited))
    {
        path.push_back('D');
        solve(m, n, ans, x1, y1, visited, path);
        path.pop_back();
    }
    // left
    x1 = x;
    y1 = y - 1;
    if (isSafe(m, n, x1, y1, visited))
    {
        path.push_back('L');
        solve(m, n, ans, x1, y1, visited, path);
        path.pop_back();
    }
    // Right
    x1 = x;
    y1 = y + 1;
    if (isSafe(m, n, x1, y1, visited))
    {
        path.push_back('R');
        solve(m, n, ans, x1, y1, visited, path);
        path.pop_back();
    }
    // Up
    x1 = x - 1;
    y1 = y;
    if (isSafe(m, n, x1, y1, visited))
    {
        path.push_back('U');
        solve(m, n, ans, x1, y1, visited, path);
        path.pop_back();
    }
    visited[x][y] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    int srcx = 0;
    int srcy = 0;

    if (m[0][0] == 0)
    {
        return ans;
    }
    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    string path = "";
    solve(m, n, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
}