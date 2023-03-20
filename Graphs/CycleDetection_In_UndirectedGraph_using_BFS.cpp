#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int src, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> visited)
{
    queue<int> q;
    unordered_map<int, int> parent;
    parent[src] = -1;
    q.push(src);
    visited[src] = 1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto i : adjList[front])
        {
            if (visited[i] == true && i != parent[front])
            {
                return true;
            }
            else if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclic(i, adjList, visited);
            if (ans)
                return "Yes";
        }
    }
    return "No";
}