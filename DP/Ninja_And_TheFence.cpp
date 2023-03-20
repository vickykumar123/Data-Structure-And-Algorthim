#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive fences have the same colors. Since the answer can be large return it modulo 10^9 + 7.

Example 1:

Input:
N=3,  K=2
Output: 6
Explanation:
We have following possible combinations:
*/
int solveRec(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return (k % MOD + (k * (k - 1) % MOD)) % MOD;

    int sameColor = (solveRec(n - 2, k) % MOD * (k - 1) % MOD) % MOD;
    int diffColor = (solveRec(n - 1, k) % MOD * (k - 1) % MOD) % MOD;
    int ans = sameColor + diffColor;
    return ans;
}

int solveMem(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;
    if (n == 2)
        return (k % MOD + (k * (k - 1) % MOD)) % MOD;
    if (dp[n] != -1)
        return dp[n];
    int sameColor = (solveMem(n - 2, k, dp) * 1LL % MOD * (k - 1) % MOD) % MOD; // 1ll because range issue
    int diffColor = (solveMem(n - 1, k, dp) * 1LL % MOD * (k - 1) % MOD) % MOD; // 1ll because range issue
    dp[n] = (sameColor + diffColor) % MOD;
    return dp[n];
}

int solveTab(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = (k % MOD + (k * (k - 1) % MOD)) % MOD;
    for (int i = 3; i <= n; i++)
    {
        int sameColor = (dp[i - 2] * 1LL % MOD * (k - 1) % MOD) % MOD; // 1LL because range issue
        int diffColor = (dp[i - 1] * 1LL % MOD * (k - 1) % MOD) % MOD; // 1LL because range issue
        dp[i] = (sameColor + diffColor) % MOD;
    }
    return dp[n];
}

int solveSpace(int n, int k)
{
    int prev2 = (k % MOD + (k * (k - 1) % MOD)) % MOD;
    int prev1 = k;
    for (int i = 3; i <= n; i++)
    {
        int sameColor = (prev2 * 1LL % MOD * (k - 1) % MOD) % MOD;
        int diffColor = (prev1 * 1LL % MOD * (k - 1) % MOD) % MOD;
        int ans = (sameColor + diffColor) % MOD;

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int numberOfWays(int n, int k)
{
    // vector<int> dp(n+1,-1);
    // return solveTab(n,k);
    return solveSpace(n, k);
}
