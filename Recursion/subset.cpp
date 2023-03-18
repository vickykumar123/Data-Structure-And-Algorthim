/*
Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
*/
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }
    // exculding
    solve(nums, output, index + 1, ans);
    int ele = nums[index];
    output.push_back(ele);
    solve(nums, output, index + 1, ans);
}
vector<vector<int>> subset(vector<int> nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}
int main()
{
}