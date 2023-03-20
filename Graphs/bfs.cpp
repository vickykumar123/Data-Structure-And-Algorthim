#include <bits/stdc++.h>
using namespace std;
// if u want answer in sorted order use set in place of list and replace push_back with insert
void adjencency(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
void bfs(unordered_map<int, list<int>> &adjList, vector<int> &ans, unordered_map<int, bool> &visited, int node)
{
    queue<int> q;
    q.push(node);

    visited[node] = 1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        // traversing the neighbour
        for (auto i : adjList[front])
        {
            if (visited[i] != 1)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    adjencency(adjList, edges);
    for (int i = 0; i < vertex; i++)
    { // using forLoop because graphs will be disconnected
        if (visited[i] != true)
        {
            bfs(adjList, ans, visited, i);
        }
    }
    return ans;
}