#include <bits/stdc++.h>
using namespace std;

// Not a best solution T.C=exponential
int solveRec(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    int fromX = solveRec(n - x, x, y, z) + 1;
    int fromY = solveRec(n - y, x, y, z) + 1;
    int fromZ = solveRec(n - z, x, y, z) + 1;

    int ans = max(fromX, max(fromY, fromZ));
    return ans;
}

// Good solution
int solveMem(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;

    if (dp[n] != -1)
        return dp[n];
    int fromX = solveMem(n - x, x, y, z, dp) + 1;
    int fromY = solveMem(n - y, x, y, z, dp) + 1;
    int fromZ = solveMem(n - z, x, y, z, dp) + 1;

    dp[n] = max(fromX, max(fromY, fromZ));
    return dp[n];
}

// Best Solution

int solveTab(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x]);
        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y]);
        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z]);
    }
    return dp[n];
}
int cutSegments(int n, int x, int y, int z)
{
    int ans = solveRec(n, x, y, z);
    if (ans < 0)
        return 0;
    else
        return ans;
}
