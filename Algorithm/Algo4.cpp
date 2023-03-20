#include <iostream>
using namespace std;

int ceilFloor(int arr[], int size, int x)
{
    int s = 0;
    int end = size - 1;
    int floor = -1, ceil = -1;
    while (s <= end)
    {
        int mid = (s + end) / 2;
        if (arr[mid] < x)
        {
            while (s <= end)
            {
                if ((arr[mid] < x) and (floor != arr[mid]))
                {
                    floor = arr[mid];
                    // s = mid + 1;
                }
                else if ((arr[mid] > x) and (floor != arr[mid]))
                {
                    ceil = arr[mid];
                    break;
                }
                s = mid + 1;
                mid = (s + end) / 2;
            }
            // s = mid + 1;
        }
        else
            end = mid - 1;
    }
    return floor, ceil;
}

int main()
{
    int arr[8] = {5, 5, 5, 6, 6, 6, 8, 9};
    int x = 7;
    cout << ceilFloor(arr, 8, x);
}