#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &heights, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int ele = heights[i];
        while (s.top() != -1 && heights[s.top()] >= ele)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> &heights, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int ele = heights[i];
        while (s.top() != -1 && heights[s.top()] >= ele)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int len = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int breath = next[i] - prev[i] - 1;
        int newArea = len * breath;
        area = max(area, newArea);
    }
    return area;
}

int main()
{
}