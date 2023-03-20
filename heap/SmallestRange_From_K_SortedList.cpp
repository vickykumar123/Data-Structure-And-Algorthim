#include <bits/stdc++.h>
using namespace std;
/*
Sample Input 1 :
2
3 2
2 4 5
5 6 7
2 3
1 1
9 12
4 9
Sample Output 1 :
1
9
Explanation For Sample Input 1 :
Test case 1 :
The given list are [2, 4, 5], [5, 6, 7]. The range [5, 5] will include 5 which is present in both the list and hence the length of this range is 1. This is the only possible range having the minimum length.

Test case 2 :
The given list are [1, 1], [9, 12], [4, 9]. The range [1, 9] will include 1 which is present in the first list, and 9 which include in both the second and third list  The length of the range is 9 (9 - 1 + 1 = 9).

*/
class node
{
public:
    int data;
    int row;
    int col;
    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    int maxi = INT_MIN, mini = INT_MAX;
    priority_queue<node *, vector<node *>, compare> minHeap;
    for (int i = 0; i < k; i++)
    {
        // only first element of k array
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        node *newNode = new node(a[i][0], i, 0);
        minHeap.push(newNode);
    }
    int start = mini, end = maxi;
    while (!minHeap.empty())
    {
        // fetches minimum element
        node *temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;
        // compare the smallest range
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }
        int nextElementCol = temp->col + 1;
        // if next element exist or not
        if (nextElementCol < n)
        {
            maxi = max(maxi, a[temp->row][nextElementCol]);
            node *nextNode = new node(a[temp->row][nextElementCol], temp->row, nextElementCol);
            minHeap.push(nextNode);
        }
        else
        {
            break;
        }
    }
    return (end - start + 1);
}