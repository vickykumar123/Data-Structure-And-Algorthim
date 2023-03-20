#include <bits/stdc++.h>
using namespace std;
void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
            topoSort(neighbour, visited, s, adjList);
    }
    // by backTracking push the last element into the stack
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }
    unordered_map<int, bool> visited; // use vector<bool> visited(v); to save time exceeded limit
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoSort(i, visited, s, adjList);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        ans.push_back(top);
    }
    return ans;
}
int main()
{
}