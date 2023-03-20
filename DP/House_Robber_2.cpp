#include <bits/stdc++.h>
using namespace std;
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police
*/
int solveSpace(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    for (int i = 1; i < n; i++)
    {
        int inculde = prev2 + nums[i];
        int exculde = prev1;
        int ans = max(inculde, exculde);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> first, second;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            first.push_back(nums[i]); // because if we inculde first then we will not inculde the last index;
        if (i != 0)
            second.push_back(nums[i]); // because it is circle so first index  and last index are neighbour
    }

    return max(solveSpace(first), solveSpace(second));
}
int main()
{
}