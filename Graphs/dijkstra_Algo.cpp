#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];
        // as it is undirected graph
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }
    // make a dist with INT_MAX
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;
    // creating a set with nodeDistance, node...
    // set put minimum value at the top...
    set<pair<int, int>> st;
    st.insert(make_pair(0, source));
    while (!st.empty())
    {
        auto top = *(st.begin());
        st.erase(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        for (auto i : adjList[topNode])
        {
            if (nodeDistance + i.second < dist[i.first])
            {
                // find the record that have to be removed
                auto record = st.find(make_pair(dist[i.first], i.first));
                if (record != st.end())
                {
                    st.erase(record);
                }
                // update the dist
                dist[i.first] = nodeDistance + i.second;
                // push the update into set
                st.insert(make_pair(dist[i.first], i.first));
            }
        }
    }
    return dist;
}

int main()
{
}