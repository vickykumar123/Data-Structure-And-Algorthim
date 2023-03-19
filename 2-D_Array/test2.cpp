#include <bits/stdc++.h>
using namespace std;
int main()
{
    // vector<vector<int>> vect{
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9},
    //     {7, 8, 9}};
    // cout << vect.size() << endl;
    // cout << vect[0].size();
    int n = 100;
    for (int i = 2; i < n; i++)
    {
        for (int j = 2 * i; j < n; j = j + i)
        {
            cout << j << " ";
        }
    }
}
