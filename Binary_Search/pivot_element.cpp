#include <bits/stdc++.h>
using namespace std;

int pivot_element(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] >= arr[0])
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
int main()
{
    int arr[5] = {7, 8, 9, 1, 2};
    cout << "Pivot Element is at Index " << pivot_element(arr, 5);
}