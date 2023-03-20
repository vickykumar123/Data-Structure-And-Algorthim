/*
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/
#include <bits/stdc++.h>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adjList[u].push_back(v);
    }
    // inDegree
    vector<int> inDegree(numCourses);
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            inDegree[j]++;
        }
    }
    // push inDegree of 0 into queue
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
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
    // check true or false
    if (ans.size() == numCourses)
        return true;
    else
        return false;
}