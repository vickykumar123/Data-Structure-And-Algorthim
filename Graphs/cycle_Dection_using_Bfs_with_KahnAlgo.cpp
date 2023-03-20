#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
    }
    // inDegree
    vector<int> inDegree(n);
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            inDegree[j]++;
        }
    }
    // pushing 0 inDegree into queue
    queue<int> q;
    for (int i = 1; i < n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    // storing count
    int count = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        count++;
        for (auto neighbour : adjList[front])
        {
            inDegree[neighbour]--;
            if (inDegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    // check the count
    // if count == n , that means cycle is not present or else cycle is present
    if (count == n)
        return false;
    else
        return true;
}
int main()
{
}