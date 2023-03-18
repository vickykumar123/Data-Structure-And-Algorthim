#include <bits/stdc++.h>
using namespace std;

int peak_element(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return arr[start];
}
int main()
{
    int arr[5] = {1, 10, 5, 2};
    cout << peak_element(arr, 5);
}