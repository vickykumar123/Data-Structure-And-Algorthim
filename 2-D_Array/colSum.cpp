#include <bits/stdc++.h>
using namespace std;
void printColSum(int arr[][4], int row, int col)
{
    for (col = 0; col < 4; col++)
    {
        int sum = 0;
        for (row = 0; row < 3; row++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
}
int main()
{
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {10, 34, 29, 11}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Sum of col ->" << endl;
    printColSum(arr, 3, 4);
}