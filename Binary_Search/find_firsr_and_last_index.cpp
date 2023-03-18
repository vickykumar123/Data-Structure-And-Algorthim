#include <bits/stdc++.h>
using namespace std;
int leftOccurance(int arr[], int size, int key)
{
    int left = 0, right = size - 1, ans = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (key == arr[mid])
        {
            ans = mid;
            right = mid - 1;
        }
        else if (arr[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

int RightOccurance(int arr[], int size, int key)
{
    int left = 0, right = size - 1, ans = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (key == arr[mid])
        {
            ans = mid;
            left = mid + 1;
        }
        else if (arr[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int arr[6] = {5, 7, 7, 8, 8, 10}, size = 6, key = 7;
    cout << leftOccurance(arr, size, key) << " ";
    cout << RightOccurance(arr, size, key) << endl;
    int total_count = (RightOccurance(arr, size, key) - leftOccurance(arr, size, key)) + 1;
    cout << "Total Number of Occurance " << key << " are " << total_count;
}