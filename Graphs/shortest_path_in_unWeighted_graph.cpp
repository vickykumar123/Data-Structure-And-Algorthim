#include <bits/stdc++.h>
using namespace std;
// s= source, t =destination
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    // bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto neighbour : adjList[front])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    // print the path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);
    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
}