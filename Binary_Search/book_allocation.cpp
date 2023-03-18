/*
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
*/
#include <bits/stdc++.h>
using namespace std;
bool isPossible(int arr[], int n, int m, int mid)
{
    int student = 1;
    int distri = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] + distri) <= mid)
        {
            distri += arr[i];
        }
        else
        {
            student++;
            if (student > m || arr[i] > mid)
            {
                return false;
            }
            distri = arr[i];
        }
    }
    return true;
}
int book_allocation(int arr[], int n, int m)
{ // m=size of distribution, n=size of array
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int start = 0, end = sum, ans = 0;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int arr[4] = {10, 20, 30, 40};
    cout << book_allocation(arr, 4, 2);
}