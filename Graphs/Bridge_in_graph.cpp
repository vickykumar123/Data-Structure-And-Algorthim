#include <bits/stdc++.h>
using namespace std;
// ***** important ******
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
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // initallizing the variable
    int timer = 0;
    vector<int> distance(v); // discovery time
    vector<int> hop(v);      // hoping to next node
    int parent = -1;
    unordered_map<int, bool> vis;
    // dfs
    vector<vector<int>> result;
    for (int i = 0; i < v; i++)
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