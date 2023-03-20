#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int size)
{
    int s = 0, end = size - 1;

    while (s <= end)
    {
        int mid = (s + end) / 2;

        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        // mid = (s + end) / 2; // for updating the mid
    }
    return -1;
}
int main()
{
    int arr[7] = {8, 10, 12, 14, 16, 18, 20};
    int key = 20;
    int ans = binarySearch(arr, key, 7);
    if (ans == -1)
    {
        cout << "Element not found ";
    }
    else
    {
        cout << "Element found in " << ans;
    }
    return 0;
}