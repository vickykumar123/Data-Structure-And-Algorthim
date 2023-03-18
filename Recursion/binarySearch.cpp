#include <bits/stdc++.h>
using namespace std;
bool binarySearch(int *arr, int start, int end, int key)
{

    if (start > end)
        return false;
    else
    {
        int mid = (start + end) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            return binarySearch(arr, start, mid - 1, key);
        else
        {
            return binarySearch(arr, mid + 1, end, key);
        }
    }
}

int main()
{
    int arr[5] = {1, 4, 10, 19, 20};
    int k = 20;
    int ans = binarySearch(arr, 0, 5, k);
    if (ans)
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
}