#include <bits/stdc++.h>
using namespace std;
void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int leftArray = mid - s + 1;
    int rightArray = e - mid;

    int *first = new int[leftArray];
    int *second = new int[rightArray];

    int mainArray = s;
    for (int i = 0; i < leftArray; i++)
    {
        first[i] = arr[mainArray++];
    }
    mainArray = mid + 1;
    for (int i = 0; i < rightArray; i++)
    {
        second[i] = arr[mainArray++];
    }

    // merge Sort concept
    int index1 = 0;
    int index2 = 0;
    mainArray = s;
    while (index1 < leftArray && index2 < rightArray)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArray++] = first[index1++];
        }
        else
        {
            arr[mainArray++] = second[index2++];
        }
    }
    while (index1 < leftArray)
    {
        arr[mainArray++] = first[index1++];
    }
    while (index2 < rightArray)
    {
        arr[mainArray++] = second[index2++];
    }
    delete[] first;
    delete[] second;
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
    int arr[5] = {2, 1, 3, 5, 4};
    mergeSort(arr, 0, 5);
    for (int i = 0; i < 5; i++)
    {

        cout << arr[i] << " ";
    }
}