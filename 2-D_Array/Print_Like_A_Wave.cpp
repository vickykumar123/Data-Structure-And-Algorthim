/*
print the 2-D array in
1 2
3 4

output = {1,3,4,2}
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int col = 0; col < mCols; col++)
    {
        if (col % 2 != 0)
        {
            for (int row = nRows - 1; row >= 0; row--) // Print odd from Bottom to Top..
            {
                ans.push_back(arr[row][col]);
            }
        }
        else
        {
            for (int row = 0; row < nRows; row++) // Print even from Top to Bottom..
            {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}