#include <bits/stdc++.h>
using namespace std;
// T.C = O(V+E)
void dfs(int node, int &parent, int &timer, vector<int> &distance, vector<int> &low, vector<bool> &visited, vector<int> &ap, unordered_map<int, list<int>> adjList)
{
    visited[node] = true;
    distance[node] = low[node] = timer++;
    int child = 0;
    for (auto neighbour : adjList[node])
    {
        if (neighbour == parent)
            continue;
        if (!visited[neighbour])
        {
            dfs(neighbour, node, timer, distance, low, visited, ap, adjList);
            // while returning
            low[node] = min(low[node], low[neighbour]);
            // check AP or not
            if (low[neighbour] >= distance[node] && parent != -1)
            {
                ap[node] = 1;
            }
            child++;
        }
        else
        {
            // if there is a back Edge present
            low[node] = min(low[node], distance[neighbour]);
        }
    }
    // for the parent node
    if (parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}
int main()
{
    int n = 5;
    int v = 5;
    int e = 6;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(4, 0));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    // intialling the variable
    int timer = 0;
    vector<int> distance(n);
    vector<int> low(n);
    int parent = -1;
    vector<bool> visited(n);
    vector<int> ap(n, 0); // for articulation point

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, timer, distance, low, visited, ap, adjList);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (ap[i] != 0)
        {
            cout << "Articulation Points are " << i << " " << endl;
        }
    }
}