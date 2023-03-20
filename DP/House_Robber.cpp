#include <bits/stdc++.h>
using namespace std;
/*
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/
int solveTab(vector<int> &nums)
{
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
int rob(vector<int> &nums)
{
    return solveTab(nums);
}
int main()
{
}