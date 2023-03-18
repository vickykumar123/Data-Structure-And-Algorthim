/*
Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/
#include <bits/stdc++.h>
using namespace std;
int pivot(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] >= nums[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return end;
}
bool binary(vector<int> &nums, int s, int e, int target)
{
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] == target)
        {
            return 1;
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return 0;
}

bool search(vector<int> &nums, int target)
{
    int n = nums.size();
    int pivot_ele = pivot(nums);
    if (target >= nums[pivot_ele] && target <= nums[n - 1])
    {
        return binary(nums, pivot_ele, n - 1, target);
    }
    else
    {
        return binary(nums, 0, pivot_ele - 1, target);
    }
}

int main()
{
}