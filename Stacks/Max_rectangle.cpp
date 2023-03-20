#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(int *heights, int n)
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
vector<int> prevSmallerElement(int *heights, int n)
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
int largestRectangleArea(int *heights, int n)
{

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
int maxArea(int M[][4], int n, int m)
{

    int area = largestRectangleArea(M[0], m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }
        int newArea = largestRectangleArea(M[i], m);
        area = max(area, newArea);
    }
    return area;
}
int main()
{
}