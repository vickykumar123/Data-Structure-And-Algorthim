#include <bits/stdc++.h>
using namespace std;
// T.C= o(N^2)
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }
    // creating key, parent, mst(minimum spanning tree) using vector
    vector<int> minWeight(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        minWeight[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    minWeight[1] = 0;
    parent[1] = -1;
    for (int i = 1; i < n; i++)
    {

        int mini = INT_MAX;
        int currentNode;
        for (int nextNode = 1; nextNode <= n; nextNode++)
        {
            if (mst[nextNode] == false && minWeight[nextNode] < mini)
            {
                currentNode = nextNode;
                mini = minWeight[nextNode];
            }
        }
        mst[currentNode] = true;
        // finding neighbour
        for (auto it : adjList[currentNode])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < minWeight[v])
            {
                parent[v] = currentNode;
                minWeight[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    { // 2 because 0 is not traversed and 1 parent is -1
        result.push_back({{parent[i], i}, minWeight[i]});
    }
    return result;
}
int main()
{
}