#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &v, int start, int end)
{
    if (start + 1 == end)
        return 0;
    int ans = INT_MAX;
    for (int mid = start + 1; mid < end; mid++)
    {
        ans = min(ans, v[start] * v[mid] * v[end] + solveRec(v, start, mid) + solveRec(v, mid, end));
    }
    return ans;
}

int solveMem(vector<int> &v, int start, int end, vector<vector<int>> &dp)
{
    if (start + 1 == end)
        return 0;
    if (dp[start][end] != -1)
        return dp[start][end];
    int ans = INT_MAX;
    for (int mid = start + 1; mid < end; mid++)
    {
        ans = min(ans, v[start] * v[mid] * v[end] + solveMem(v, start, mid, dp) + solveMem(v, mid, end, dp));
    }
    dp[start][end] = ans;
    return dp[start][end];
}

int solveTab(vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                ans = min(ans, v[i] * v[k] * v[j] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n - 1];
}
int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    // return solveRec(values,0,n-1);
    // vector<vector<int>>dp(n,vector<int>(n,-1));
    // return solveMem(values,0,n-1,dp);
    return solveTab(values);
}
int main()
{
}