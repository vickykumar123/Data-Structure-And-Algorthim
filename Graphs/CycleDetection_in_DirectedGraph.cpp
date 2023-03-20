#include <bits/stdc++.h>
using namespace std;
// using DFS
bool isCyclicDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    dfsVisited[node] = true;
    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour, visited, dfsVisited, adjList);
            if (cycleDetected)
                return true;
        }
        else if (dfsVisited[neighbour] == true && visited[neighbour] == true)
        {
            return true;
        }
    }
    // backTracking
    dfsVisited[node] = 0;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
    }
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 1; i <= n; i++)
    { // we not considering the 0 because it start directly from first node
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, visited, dfsVisited, adjList);
            if (ans)
                return true;
        }
    }
    return false;
}