#include <bits/stdc++.h>
using namespace std;
int pivot(vector<int> nums, int size)
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
int findPosition(vector<int> &arr, int n, int k)
{
    int pivot_ele = pivot(arr, n);
    if (k >= arr[pivot_ele] && k <= arr[n - 1])
    {
        return binary_search(arr, pivot_ele, n - 1, k);
    }
    else
    {
        return binary_search(arr, 0, pivot_ele - 1, k);
    }
}
int main()
{
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> arr2;
    for (int i = 0; i < 7; i++)
    {
        arr2.push_back(arr[i]);
    }
    vector<int> ans = findPosition(arr2, 7, 0);
    for (auto nums : arr2)
    {
        cout << ans;
    }
}
