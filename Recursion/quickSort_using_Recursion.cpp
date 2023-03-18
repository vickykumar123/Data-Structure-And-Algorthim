#include <bits/stdc++.h>
using namespace std;
int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int cnt = 0; // count of number which is less than pivot element
    for (int i = s + 1; i < e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= arr[pivotIndex])
        {
            i++;
        }
        while (arr[j] >= arr[pivotIndex])
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}
int main()
{
    int arr[5] = {4, 2, 5, 1, 3};
    quickSort(arr, 0, 5);
    for (int i = 0; i < 5; i++)
    {

        cout << arr[i] << " ";
    }
}