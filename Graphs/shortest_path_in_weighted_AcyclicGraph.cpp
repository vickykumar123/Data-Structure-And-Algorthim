#include <bits/stdc++.h>
using namespace std;
/*
Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i, 0<=i

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.



Example:

Input:
n = 6, m= 7
edge=[[0,1,2],[0,4,1],[4,5,4]
,[4,2,2],[1,2,3],[2,3,6],[5,3,1]]

Output:
0 2 3 6 1 5
*/
void dfs(int src, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<pair<int, int>>> &adjList)
{
    visited[src] = true;
    for (auto neighbour : adjList[src])
    {
        if (!visited[neighbour.first])
        {
            dfs(neighbour.first, visited, s, adjList);
        }
    }
    s.push(src);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        pair<int, int> p = make_pair(v, weight);
        adjList[u].push_back(p);
    }
    // topological order using dfs
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
            dfs(i, visited, s, adjList);
    }
    // source is starting from 0
    int src = 0;
    vector<int> dist(N);
    for (int i = 0; i < N; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (dist[top] != INT_MAX)
        {

            for (auto neighbour : adjList[top])
            {
                int shortestWeight = dist[top] + neighbour.second;
                int prevWeight = dist[neighbour.first]; // we need to update in dist
                if (shortestWeight < prevWeight)
                    dist[neighbour.first] = shortestWeight;
            }
        }
        else
        {
            // if it is impossible to reach any vertex, then return -1
            dist[top] = -1;
        }
    }
    return dist;
}