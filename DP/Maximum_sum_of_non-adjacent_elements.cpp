#include <bits/stdc++.h>
using namespace std;
// Using Recursion and memorization
int solveRec(vector<int> &nums, int n, vector<int> &dp)
{
    // Base case
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];
    if (dp[n] != -1)
        return dp[n];
    int include = solveRec(nums, n - 2, dp) + nums[n];
    int exclude = solveRec(nums, n - 1, dp) + 0;
    dp[n] = max(include, exclude);
    return dp[n];
}

// using tabulation method
int solveTab(vector<int> &nums)
{
    // Base case
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int include = dp[i - 2] + nums[i];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n - 1]; // n-1 beause last index
}

// Space Optimization best solution
int solveSpace(vector<int> &nums)
{
    // Base case
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    for (int i = 1; i < n; i++)
    {
        int include = prev2 + nums[i];
        int exclude = prev1 + 0;

        int ans = max(include, exclude);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // int n = nums.size();
    // vector<int> dp(n + 1, -1);
    // int ans = solveRec(nums, n - 1, dp); // n-1 because we are going from right to left
    // return ans;
    return solveTab(nums);
}
int main()
{
}