#include <bits/stdc++.h>
using namespace std;
int main()
{
}
int maximumFrequency(vector<int> &arr, int n)
{
    map<int, int> m;
    int maxFreq = 0;
    int maxAns = 0;
    for (int i = 0; i < n; i++)
    {
        int ele = arr[i];
        m[ele]++;
        maxFreq = max(maxFreq, m[ele]);
    }
    for (int i = 0; i < n; i++)
    {
        int ele = arr[i];
        if (maxFreq == m[ele])
        {
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}