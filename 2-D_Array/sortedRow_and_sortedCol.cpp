#include <bits/stdc++.h>
using namespace std;

bool findElement(vector<vector<int>> arr, int target)
{
    int n = arr.size();
    int m = arr[0].size();

    int row = 0;
    int col = m - 1;
    while (row < n && col >= 0)
    {
        int element = arr[row][col];
        if (arr[row][col] == target)
        {
            return true;
        }
        else if (arr[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return 0;
}
int main()
{
    vector<vector<int>> vect{
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24}};
    if (findElement(vect, 5))
    {
        cout << "Element found ";
    }
    else
    {
        cout << "Element not found";
    }
    return 0;
}