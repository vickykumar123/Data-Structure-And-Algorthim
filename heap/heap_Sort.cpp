#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    if (leftIndex <= n && arr[leftIndex] < arr[largest]) // = because 1 based indexing
    {
        largest = leftIndex;
    }
    if (rightIndex <= n && arr[rightIndex] < arr[largest]) // = because 1 based indexing

    {
        largest = rightIndex;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, n, size);
    }
}
int main()
{
    int arr[6] = {-1, 90, 69, 55, 59, 10};
    heapSort(arr, 5);
    for (int i = 1; i <= 5; i++)
    {
        cout << arr[i] << " ";
    }
}