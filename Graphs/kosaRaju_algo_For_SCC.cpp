#include <bits/stdc++.h>
using namespace std;

// T.C o(v+e) S.c = o(n^2)
void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    for (auto nbr : adjList[node])
    {
        if (!visited[nbr])
        {
            dfs(nbr, visited, s, adjList);
        }
    }
    s.push(node);
}
void revDFS(int top, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &transpose)
{
    visited[top] = true;
    for (auto nbr : transpose[top])
    {
        if (!visited[nbr])
            revDFS(nbr, visited, transpose);
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }
    // topo sort
    stack<int> s;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, s, adjList);
        }
    }

    // Transpose the graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
        for (auto nbr : adjList[i])
        {
            transpose[nbr].push_back(i);
        }
    }
    // print the count of Strongly connected compponent
    int count = 0;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (!visited[top])
        {
            count++;
            revDFS(top, visited, transpose);
        }
    }
    return count;
}