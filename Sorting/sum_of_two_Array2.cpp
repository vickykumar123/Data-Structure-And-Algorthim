/*
array1 = 1 2 3 4
array2 = 6
For the first test case, the integer represented by the first array is 1234 and the second array is 6, so the sum is 1234 + 6 =  1240.

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < n; i++)
    {
        num1 = num1 * 10 + a[i];
    }
    for (int i = 0; i < m; i++)
    {
        num2 = num2 * 10 + b[i];
    }
    int temp = num1 + num2;
    vector<int> ans;
    while (temp > 0)
    {
        ans.push_back(temp % 10);
        temp /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}