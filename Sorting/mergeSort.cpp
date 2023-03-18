#include <bits/stdc++.h>
using namespace std;
void mergeSort(int arr1[], int n, int arr2[], int m, int arr3[])
{ // n= size of arr1, m= size of arr2
    int i = 0, j = 0, k = 0;
    while (i <= n && j <= m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
            // k++;
            // i++;
        }
        else
        {
            arr3[k++] = arr2[j++];
            // k++;
            // j++;
        }
    }
    while (i < n)
    {
        arr3[k++] = arr1[i++];
        // k++;
        // i++;
    }
    while (j < m)
    {
        arr3[k++] = arr2[j++];
        // k++;
        // j++;
    }
}

// or//
/*
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Here, nums1 =1st array, nums2 = 2nd array...
        for(int i = 0 ; i < n ; i++)
            nums1[i + m] = nums2[i];
            // Sort the 1st array...
            sort(nums1.begin() , nums1.end());
        // Print the required result...
        return;
    }
*/
int main()
{
    int arr1[6] = {1, 5, 7, 10, 13, 16};
    int arr2[4] = {2, 3, 6, 11};
    int arr3[11] = {0};
    mergeSort(arr1, 6, arr2, 3, arr3);
    for (int i = 0; i < 10; i++)
    {
        cout << arr3[i] << " ";
    }
    return 0;
}