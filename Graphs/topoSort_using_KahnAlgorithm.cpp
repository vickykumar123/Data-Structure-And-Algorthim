#include <bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Create adjenecy list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }
    // make inDegree of the node
    vector<int> inDegree(v);
    for (auto i : adjList)
        for (auto j : i.second)
        {
            inDegree[j]++;
        }
    // push the 0 indregee into the queue
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    // bfs
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto neighbour : adjList[front])
        {
            inDegree[neighbour]--;
            if (inDegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return ans;
}
int main()
{
}