#include <bits/stdc++.h>
using namespace std;
int solve(int *arr, int n, int k)
{
    deque<int> maxi(n);
    deque<int> mini(n);
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.front()] <= arr[i])
            maxi.pop_back();
        while (!mini.empty() && arr[mini.front()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;
    for (int i = k; i < n; i++)
    {
        int max = arr[maxi.front()], min = arr[mini.front()];
        ans += max + min;
        // removal
        while (!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        while (!mini.empty() && i - mini.front() >= k)
            mini.pop_front();
        // addition

        while (!maxi.empty() && arr[maxi.front()] <= arr[i])
            maxi.pop_back();
        while (!mini.empty() && arr[mini.front()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    ans += arr[maxi.front()] + arr[mini.front()];
    return ans;
}
int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    cout << solve(arr, 7, 4);
}