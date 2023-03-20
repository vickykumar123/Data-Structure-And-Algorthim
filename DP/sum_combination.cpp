#include <bits/stdc++.h>
using namespace std;

/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
*/
int solveMem(vector<int> &num, int tar, vector<int> &dp)
{

    if (tar == 0)
        return 1; // means one combination is possible
    if (tar < 0)
        return 0;
    if (dp[tar] != -1)
        return dp[tar];
    int sum = 0;
    for (int i = 0; i < num.size(); i++)
    {
        sum += solveMem(num, tar - num[i], dp);
    }
    dp[tar] = sum;
    return dp[tar];
}

int solveTab(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= tar; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0)
                dp[i] += dp[i - num[j]];
        }
    }

    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{

    // vector<int> dp(tar+1,-1);
    // return solveMem(num,tar,dp);
    return solveTab(num, tar);
}