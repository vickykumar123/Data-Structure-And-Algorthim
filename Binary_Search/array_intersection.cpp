#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[3] = {2, 4, 4};
    int arr2[5] = {1, 4, 4, 5, 9};
    int n = 3, m = 5, i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}