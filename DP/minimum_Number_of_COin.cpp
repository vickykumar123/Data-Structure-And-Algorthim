#include <bits/stdc++.h>
using namespace std;

/*
Sample Input 1 :
2
3 7
1 2 3
1 0
1
Sample Output 1 :
 3
 0
Explanation For Sample Output 1:
For the first test case,
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.
*/
// This solution takes t.C = O(2^n) which is exponential
// Not a best solution

// Here x = sum of amount we need in example 7 , nums = array of coins present
int solveRec(vector<int> &num, int x)
{
    // Base case
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;
    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveRec(num, x - num[i]);
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans); // 1 because we are also adding current node
    }
    return mini;
}

// This is good solution but some test case may faile. This solve is also not working with memorization
// T.C = O(x*n) x = amount, n = no. of coins s.c = O(x);
int solveMem(vector<int> &num, int x, vector<int> &dp)
{
    // Base case
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;
    if (dp[x] != -1)
        return dp[x];
    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveRec(num, x - num[i]);
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans); // 1 because we are also adding current node
    }
    dp[x] = mini;
    return dp[x];
}

// Best solution using tabulation
int solveTab(vector<int> &num, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    { // for every xth coin
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - num[j]]); // 1 because root count
        }
    }
    if (dp[x] == INT_MAX)
        return -1;
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    // int ans = solveRec(num, x);
    // if (ans == INT_MAX)
    //     return -1;
    // return ans;

    // vector<int> dp(x + 1, -1);
    // int ans = solveMem(num, x, dp);
    // if (ans == INT_MAX)
    //     return -1;
    // return ans;

    return solveTab(num, x);
}