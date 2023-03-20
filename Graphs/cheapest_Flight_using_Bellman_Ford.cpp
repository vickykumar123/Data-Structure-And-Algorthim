#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> &flight, int src, int dst, int k)
{
    // Bellman Ford
    vector<int> dis(n, 1e9);
    dis[src] = 0;

    for (int i = 0; i <= k; i++)
    {
        vector<int> temp = dis;

        for (auto j : flight)
        {
            temp[j[1]] = min(temp[j[1]], dis[j[0]] + j[2]);
        }
        dis = temp;
    }

    if (dis[dst] != 1e9)
    {
        return dis[dst];
    }
    return -1;
}
int main()
{
}