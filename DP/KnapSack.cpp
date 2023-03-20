#include <bits/stdc++.h>
using namespace std;
int solveMem(vector<int> &weight, vector<int> &value, int index, int maxWeight, vector<vector<int>> &dp)
{
    // only one item to steal
    if (index == 0)
    {
        if (weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }
    if (dp[index][maxWeight] != -1)
        return dp[index][maxWeight];

    int include = 0;
    if (weight[index] <= maxWeight)
        include = value[index] + solveMem(weight, value, index - 1, maxWeight - weight[index], dp);

    int exclude = 0 + solveMem(weight, value, index - 1, maxWeight, dp);

    dp[index][maxWeight] = max(include, exclude);
    return dp[index][maxWeight];
}

int solveTab(vector<int> &weight, vector<int> &value, int index, int maxWeight)
{
    // only one item to steal
    vector<vector<int>> dp(index, vector<int>(maxWeight + 1, 0));
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for (int i = 1; i < index; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int include = 0;
            if (weight[i] <= j)
                include = value[i] + dp[i - 1][j - weight[i]];

            int exclude = 0 + dp[i - 1][j];

            dp[i][j] = max(include, exclude);
        }
    }
    return dp[index - 1][maxWeight];
}

int solveSpace(vector<int> &weight, vector<int> &value, int index, int maxWeight)
{
    // only one item to steal
    vector<int> prev(maxWeight + 1, 0);
    vector<int> curr(maxWeight + 1, 0);
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    for (int i = 1; i < index; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int include = 0;
            if (weight[i] <= j)
                include = value[i] + prev[j - weight[i]];

            int exclude = 0 + prev[j];

            curr[j] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{

    return solveSpace(weight, value, n, maxWeight);
}