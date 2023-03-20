#include <bits/stdc++.h>
using namespace std;

// T.C = o(n*m)
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> distance(n + 1, 1e9);
    distance[src] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (distance[u] != 1e9 && ((distance[u] + wt) < distance[v]))
            {
                distance[v] = distance[u] + wt;
            }
        }
    }
    // check for cycle
    int flag = 0;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (distance[u] != 1e9 && ((distance[u] + wt) < distance[v]))
        {
            flag = 1;
        }
    }
    if (flag == 0)
        return distance[dest];
    return -1;
}
int main()
{
}