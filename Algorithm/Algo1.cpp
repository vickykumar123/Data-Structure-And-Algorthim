#include <iostream>
using namespace std;

int linearSearch(int arr[], int key, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)

            return i;
    }
    return -1;
}
int main()
{
    int arr[7] = {8, 10, 12, 14, 16, 18, 20};
    int key = 18;
    int ans = linearSearch(arr, key, 7);
    if (ans == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Element found in index " << ans;
    }
}