/*
array1 = 1 2 3 4
array2 = 6
For the first test case, the integer represented by the first array is 1234 and the second array is 6, so the sum is 1234 + 6 =  1240.

*/

#include <bits/stdc++.h>
using namespace std;
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = n - 1;
    int j = m - 1;
    vector<int> v;
    int sum = 0;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        sum = a[i] + b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        v.push_back(sum);
        i--;
        j--;
    }
    while (i >= 0)
    {
        sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        v.push_back(sum);
        i--;
    }
    while (j >= 0)
    {
        sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        v.push_back(sum);
        j--;
    }
    while (carry != 0)
    {
        sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        v.push_back(sum);
    }
    reverse(v.begin(), v.end());
    return v;
}