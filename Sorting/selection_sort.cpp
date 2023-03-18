#include <bits/stdc++.h>
using namespace std;
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int midIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[midIndex])
            {
                midIndex = j;
            }
        }
        swap(arr[i], arr[midIndex]);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[5] = {10, 3, 1, 10, 9};
    selection_sort(arr, 5);

    printArray(arr, 5);
}