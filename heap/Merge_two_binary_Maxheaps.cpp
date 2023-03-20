#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest, n);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> merge;
    for (auto i : a)
    {
        merge.push_back(i);
    }
    for (auto j : b)
    {
        merge.push_back(j);
    }
    int size = merge.size();
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(merge, i, size);
    }

    return merge;
}
int main()
{
}