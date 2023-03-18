/*
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5] = {10, 12, 14, 18, 19};
    int k = 5;
    int i = 0, j = 5;
    while (i < j)
    {
        int mid = (i + j) / 2;
        int unknown = arr[mid] - (mid + 1);
        if (unknown >= k)
        {
            j = mid;
        }
        else
        {
            i = mid + 1;
        }
    }
    cout << i + k;
}