#include <bits/stdc++.h>
using namespace std;
/*
You are given N balls numbered from 1 to N and there are N baskets numbered from 1 to N in front of you, the ith basket is meant for the ith ball. Calculate the number of ways in which no ball goes into its respective basket.

Example 1:
Input: N = 2
Output: 1
Explanation: The balls are numbered 1 and 2.
Then there is only one way to dearrange them.
The (number-basket) pairs will be [(1-2),(2-1)].
*/
#define MOD 1000000007

// using Mem
long long int solveMem(int n, vector<long long int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1; // if only two element present we can only swap them.
    if (dp[n] != -1)
        return dp[n];
    dp[n] = ((n - 1) % MOD) * ((solveMem(n - 1, dp) % MOD) + (solveMem(n - 2, dp) % MOD)) % MOD;

    return dp[n];
}

// Using Tabulation
long long int solveTab(int n)
{
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;
        long long int sum = (first + second) % MOD;
        dp[i] = ((i - 1) % MOD) * sum;
    }
    return dp[n];
}

// Using Space
long long int solveSpace(int n)
{
    long long int prev2 = 0;
    long long int prev1 = 1;
    for (int i = 3; i <= n; i++)
    {
        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int sum = (first + second) % MOD;

        long long int ans = ((i - 1) * sum) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
long long int countDerangements(int n)
{
    // vector<long long int> dp(n+1,-1);
    return solveSpace(n);
}
int main()
{
}