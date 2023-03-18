/*
Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
*/
#include <bits/stdc++.h>
using namespace std;
int pivot(vector<int> &nums, int size)
{
    int start = 0, end = size - 1;
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
    return start;
}
int binary_search(vector<int> &nums, int s, int e, int key)
{
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] == key)
        {
            return mid;
        }
        else if (key > nums[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}
int search(vector<int> &nums, int target)
{
    int sizes = nums.size();
    int pivot_ele = pivot(nums, nums.size());
    if (target >= nums[pivot_ele] && target <= nums[sizes - 1])
    {
        return binary_search(nums, pivot_ele, sizes - 1, target);
    }
    else
    {
        return binary_search(nums, 0, pivot_ele - 1, target);
    }
}
int main()
{
}