#include <bits/stdc++.h>
using namespace std;
/*
Examples:

Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20
*/
void interLeaveQueue(queue<int> &q)
{
    queue<int> newQ;
    int mid = q.size() / 2;
    for (int i = 0; i < mid; i++)
    {
        int front = q.front();
        newQ.push(front);
        q.pop();
    }
    while (!newQ.empty())
    {
        int f1 = newQ.front();
        q.push(f1);
        newQ.pop();
        int f2 = q.front();
        q.push(f2);
        q.pop();
    }
}