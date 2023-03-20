#include <bits/stdc++.h>
using namespace std;

int solveRec(int n, int arr[], int currIndex, int prevIndex)
{
    if (currIndex == n)
        return 0;

    int include = 0;
    if (prevIndex == -1 || arr[currIndex] > arr[prevIndex]) // include only if lastIndex is smaller than upcoming Index
        include = 1 + solveRec(n, arr, currIndex + 1, currIndex);
    int exclude = 0 + solveRec(n, arr, currIndex + 1, prevIndex);

    return max(include, exclude);
}

int solveMem(int n, int arr[], int currIndex, int prevIndex, vector<vector<int>> &dp)
{
    if (currIndex == n)
        return 0;

    if (dp[currIndex][prevIndex + 1] != -1)
        return dp[currIndex][prevIndex + 1];

    int include = 0;
    if (prevIndex == -1 || arr[currIndex] > arr[prevIndex])
        include = 1 + solveMem(n, arr, currIndex + 1, currIndex, dp);
    int exclude = 0 + solveMem(n, arr, currIndex + 1, prevIndex, dp);

    return dp[currIndex][prevIndex + 1] = max(include, exclude);
}

int solveTab(int n, int arr[])
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int currIndex = n - 1; currIndex >= 0; currIndex--)
    {
        for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--)
        {
            int include = 0;
            if (prevIndex == -1 || arr[currIndex] > arr[prevIndex])
                include = 1 + dp[currIndex + 1][currIndex + 1];
            int exclude = 0 + dp[currIndex + 1][prevIndex + 1];

            dp[currIndex][prevIndex + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

int solveSpace(int n, int arr[])
{
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for (int currIndex = n - 1; currIndex >= 0; currIndex--)
    {
        for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--)
        {
            int include = 0;
            if (prevIndex == -1 || arr[currIndex] > arr[prevIndex])
                include = 1 + next[currIndex + 1];
            int exclude = 0 + next[prevIndex + 1];

            curr[prevIndex + 1] = max(include, exclude);
        }
        next = curr;
    }
    return next[0];
}

// using Binary Search
int solveOptimal(int n, int a[])
{
    if (n == 0)
        return 0;

    vector<int> ans;
    ans.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] > ans.back())
            ans.push_back(a[i]);
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }
    return ans.size();
}
int longestSubsequence(int n, int a[])
{

    //   return solveRec(n,a,0,-1);

    // vector<vector<int>> dp(n,vector<int>(n+1,-1));
    // return solveMem(n,a,0,-1,dp);

    // return solveTab(n,a);
    return solveSpace(n, a);
}
