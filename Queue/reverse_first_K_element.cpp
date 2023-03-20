/*
Input:
5 3
1 2 3 4 5

Output:
3 2 1 4 5

Explanation:
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.
*/
#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> s;
    queue<int> q1;
    while (s.size() < k)
    {
        int front = q.front();
        s.push(front);
        q.pop();
    }
    while (!s.empty())
    {
        int top = s.top();
        q1.push(top);
        s.pop();
    }
    while (!q.empty())
    {
        int front = q.front();
        q1.push(front);
        q.pop();
    }
    return q1;
}
int main()
{
}