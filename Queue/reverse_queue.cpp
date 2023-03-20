#include <bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q)
{
    int n = q.size();
    stack<int> s;
    while (!q.empty())
    {
        int qfront = q.front();
        s.push(qfront);
        q.pop();
    }
    queue<int> ans;
    while (!s.empty())
    {
        int top = s.top();
        ans.push(top);
        s.pop();
    }
    return ans;
}

/*
----------- Or another method ----------
void reverse(queue < int > & q) {
    stack<int> s;
    while(!q.empty()){
        int front = q.front();
        s.push(front);
        q.pop();
    }
    while(!s.empty()){
        int top = s.top();
        q.push(top);
        s.pop();
    }
}
*/
int main()
{
}