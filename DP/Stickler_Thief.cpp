#include <bits/stdc++.h>
using namespace std;
int solveTab(int *&arr, int n)
{
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int include = dp[i - 2] + arr[i];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n - 1]; // n-1 because last index
}
int FindMaxSum(int arr[], int n)
{
    return solveTab(arr, n);
}
int main()
{
}