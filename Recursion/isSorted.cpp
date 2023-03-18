#include <bits/stdc++.h>
using namespace std;
bool isSorted(int *arr, int size)
{
    if (size == 0 || size == 1)
        return true;
    if (arr[0] > arr[1])
        return false;
    else
    {
        bool remaining = isSorted(arr + 1, size - 1);
        return remaining;
    }
}

int main()
{
    int arr[5] = {2, 3, 10, 5, 8};
    int size = 5;
    bool ans = isSorted(arr, size);
    if (ans)
    {
        cout << "Array is Sorted";
    }
    else
    {
        cout << "Array is not Sorted";
    }
    return 0;
}