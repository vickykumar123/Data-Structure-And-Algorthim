#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int num = stoi("33") * stoi("2");
    // cout << num << endl;
    // cout << to_string(num);
    int arr[7] = {10, 3, 14, 12, 50, 6, 1};
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < 7; i++)
    {
        minheap.push(arr[i]);
    }
    for (int i = 0; i < 7; i++)
    {
        cout << minheap.top() << " ";
        minheap.pop();
    }
}