#include <bits/stdc++.h>
using namespace std;

// same as Bridge in Graph
void dfs(int node, int parent, vector<int> &distance, vector<int> &hop, int &timer, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<vector<int>> &result)
{
    visited[node] = true;
    distance[node] = hop[node] = timer++;
    for (auto neighbour : adjList[node])
    {
        if (neighbour == parent)
            continue;
        if (!visited[neighbour])
        {
            dfs(neighbour, node, distance, hop, timer, adjList, visited, result);
            // while returning or backTracking
            hop[node] = min(hop[node], hop[neighbour]); // dry run
            // check the bridge
            if (hop[neighbour] > distance[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else
        {
            // there is back edge present
            hop[node] = min(hop[node], distance[neighbour]); // dry run
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // initallizing the variable
    int timer = 0;
    vector<int> distance(n); // discovery time
    vector<int> hop(n);      // hoping to next node
    int parent = -1;
    unordered_map<int, bool> vis;
    // dfs
    vector<vector<int>> result;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, distance, hop, timer, adjList, vis, result);
        }
    }
    return result;
}
void dfs(int node, int parent, vector<int> &distance, vector<int> &hop, int &timer, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<vector<int>> &result)
{
    visited[node] = true;
    distance[node] = hop[node] = timer++;
    for (auto neighbour : adjList[node])
    {
        if (neighbour == parent)
            continue;
        if (!visited[neighbour])
        {
            dfs(neighbour, node, distance, hop, timer, adjList, visited, result);
            // while returning or backTracking
            hop[node] = min(hop[node], hop[neighbour]); // dry run
            // check the bridge
            if (hop[neighbour] > distance[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else
        {
            // there is back edge present
            hop[node] = min(hop[node], distance[neighbour]); // dry run
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // initallizing the variable
    int timer = 0;
    vector<int> distance(n); // discovery time
    vector<int> hop(n);      // hoping to next node
    int parent = -1;
    unordered_map<int, bool> vis;
    // dfs
    vector<vector<int>> result;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, distance, hop, timer, adjList, vis, result);
        }
    }
    return result;
}
int main()
{
}