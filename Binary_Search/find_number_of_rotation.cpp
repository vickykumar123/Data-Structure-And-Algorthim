#include <bits/stdc++.h>
using namespace std;
bool isSorted(vector<int> &nums, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return false;
        }
    }

    return true;
}
int findMin(vector<int> &nums)
{
    if (isSorted(nums, nums.size()))
    {
        return nums[0];
    }
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] > nums[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return nums[end];
}
int main()
{
}