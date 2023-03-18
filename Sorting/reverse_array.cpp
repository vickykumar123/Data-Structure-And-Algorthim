/*Not the sorting problem*/
/*
>> Sample Input 1:
2
6 3
1 2 3 4 5 6
5 2
10 9 8 7 6
>> Sample Output 1:
1 2 3 4 6 5
10 9 8 6 7
*/
#include <bits/stdc++.h>
using namespace std;
void reverse(int arr[], int start, int end, int n)
{
    int s = start, e = end;
    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    reverse(arr, 2, 4, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}