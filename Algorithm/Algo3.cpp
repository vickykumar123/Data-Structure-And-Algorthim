/*Given a sorted array arr[] of size N without duplicates, and given a value x. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. Find the index of K(0-based indexing).

Example 1:

Input:
N = 7, x = 0
arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less
than 0 is found. So output
is "-1".
Example 2:

Input:
N = 7, x = 5
arr[] = {1,2,8,10,11,12,19}
Output: 1
Explanation: Largest Number less than 5 is
2 (i.e K = 2), whose index is 1(0-based
indexing).*/

#include <iostream>
using namespace std;

int lessThan(int v[], int size, int x)
{
    int s = 0;
    int end = size - 1;
    int ans = -1;
    while (s <= end)
    {
        int mid = (s + end) / 2;
        if (v[mid] < x) // x= 16 v[mid]=10
        {
            ans = mid;
            s = mid + 1;
        }
        else if (v[mid] > x)
            end = mid - 1;
    }
    return ans;
}

int main()
{
    int v[8] = {1, 2, 8, 9, 10, 11, 12, 19};
    int x = 16;
    int ans = lessThan(v, 8, x);
    if (ans == -1)
        cout << "-1";
    else
        cout << "less than " << ans;
}