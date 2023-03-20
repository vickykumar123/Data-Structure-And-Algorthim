#include <bits/stdc++.h>
using namespace std;
void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int left = mid - s + 1;
    int right = e - mid;

    int *first = new int[left];
    int *second = new int[right];

    int midArray = s;
    for (int i = 0; i < left; i++)
    {
        first[i] = arr[midArray++];
    }
    midArray = mid + 1;
    for (int i = 0; i < right; i++)
    {
        second[i] = arr[midArray++];
    }

    int index1 = 0;
    int index2 = 0;
    midArray = s;

    while (index1 < left && index2 < right)
    {
        if (first[index1] < second[index2])
        {
            arr[midArray++] = first[index1++];
        }
        else
        {
            arr[midArray++] = second[index2++];
        }
    }
    while (index1 < left)
    {
        arr[midArray++] = first[index1++];
    }
    while (index2 < right)
    {
        arr[midArray++] = second[index2++];
    }
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}
int main()
{
    int arr[5] = {5, 7, 1, 8, 2};
    mergeSort(arr, 0, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}