#include <bits/stdc++.h>
using namespace std;

// Max heap
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    if (leftIndex < n && arr[leftIndex] > arr[largest])
    {
        largest = leftIndex;
    }
    if (rightIndex < n && arr[rightIndex] > arr[largest])
    {
        largest = rightIndex;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}