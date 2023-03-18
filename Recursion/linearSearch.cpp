#include <iostream>
using namespace std;

bool linearSearch(int *arr, int size, int key)
{
    if (size == 0)
        return false;
    if (arr[0] == key)
        return true;
    else
    {
        bool remaining = linearSearch(arr + 1, size - 1, key);
        return remaining;
    }
}

int main()
{
    int arr[5] = {5, 3, 1, 7, 9};
    int k = 10;
    int ans = linearSearch(arr, 5, k);
    if (ans)
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
}