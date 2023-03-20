#include <bits/stdc++.h>
using namespace std;
/*
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
*/

// n = days.size()
int solveRec(int n, vector<int> &days, vector<int> &cost, int index)
{
    if (index >= n)
        return 0;

    // for 1-day pass
    int oneDay = cost[0] + solveRec(n, days, cost, index + 1);

    // for 7-day pass
    int i;
    for (i = 0; i < n && days[i] < days[index] + 7; i++)
        ;

    int sevenDay = cost[1] + solveRec(n, days, cost, i);

    // for 30-day pass
    for (i = 0; i < n && days[i] < days[index] + 30; i++)
        ;

    int thirtyDay = cost[2] + solveRec(n, days, cost, i);

    return min(oneDay, min(sevenDay, thirtyDay));
}
// n = days.size()
int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    // for 1-day pass
    int oneDay = cost[0] + solveMem(n, days, cost, index + 1, dp);

    // for 7-day pass
    int i;
    for (i = 0; i < n && days[i] < days[index] + 7; i++)
        ;

    int sevenDay = cost[1] + solveMem(n, days, cost, i, dp);

    // for 30-day pass
    for (i = 0; i < n && days[i] < days[index] + 30; i++)
        ;

    int thirtyDay = cost[2] + solveMem(n, days, cost, i, dp);

    dp[index] = min(oneDay, min(sevenDay, thirtyDay));
    return dp[index];
}

int solveTab(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);
    // bottom up approach
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        // for 1-day pass
        int oneDay = cost[0] + dp[k + 1];

        // for 7-day pass
        int i;
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;

        int sevenDay = cost[1] + dp[i];

        // for 30-day pass
        for (i = k; i < n && days[i] < days[k] + 30; i++)
            ;

        int thirtyDay = cost[2] + dp[i];

        dp[k] = min(oneDay, min(sevenDay, thirtyDay));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n + 1, -1);
    // return solveRec(n,days,cost,0);
    // return solveMem(n,days,cost,0,dp);
    return solveTab(n, days, cost);
}
int main()
{
}