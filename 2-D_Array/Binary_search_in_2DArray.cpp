#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0, end = (row * col) - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int midElement = matrix[mid / col][mid % col];
        if (midElement == target)
        {
            return 1;
        }
        else if (midElement > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return 0;
}
int main()
{
}