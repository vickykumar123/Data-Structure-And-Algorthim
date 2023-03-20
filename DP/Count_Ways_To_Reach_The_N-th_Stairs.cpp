#include <bits/stdc++.h>
using namespace std;
// long long mod = 1000000007; // given in the  question

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
*/
int solve(int nStairs, vector<int> &dp)
{
    if (nStairs == 0 || nStairs == 1)
        return 1;
    // step 3
    if (dp[nStairs] != -1)
        return dp[nStairs];
    // step 2
    // dp[nStairs] = (solve(nStairs - 1, dp) + solve(nStairs - 2, dp)) % mod; if given in otherwise no need to mod
    dp[nStairs] = (solve(nStairs - 1, dp) + solve(nStairs - 2, dp));
    return dp[nStairs];
}

int countDistinctWays(int nStairs)
{
    // step 1
    vector<int> dp(nStairs + 1, -1);
    return solve(nStairs, dp);
}
