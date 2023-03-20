#include <bits/stdc++.h>
using namespace std;
/*
Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
*/
// using top-Down T.C = o(n) s.c = o(n)+o(n)
int solve(vector<int> &cost, int n, vector<int> &dp)
{
    if (n == 0)
        return cost[0];
    if (n == 1)
        return cost[1];
    // step 3
    if (dp[n] != -1)
        return dp[n];
    // step2
    dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    return dp[n];
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    // step 1
    vector<int> dp(n + 1, -1);
    int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    return ans;
}

// Using Bottom-Up (Better Solution) T.C = o(n) s.c = o(n)
int solve(vector<int> &cost, int n)
{
    vector<int> dp(n + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[n - 1], dp[n - 2]);
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    return solve(cost, n);
}

// space Optimization T.C = o(n) s.c = o(1) (Best solution)
int solve(vector<int> &cost, int n)
{
    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    return solve(cost, n);
}