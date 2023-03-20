#include <bits/stdc++.h>
using namespace std;
// arr : given array
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int r, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++) // pushes only k element
    {
        pq.push(arr[i]);
    }

    for (int i = k; i <= r; i++) // pushes from k ele to last element
    {
        if (arr[i] < pq.top()) // top element is greater then remove
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top(); // now only k element left in heap the top element is the answer`
}
int main()
{
}