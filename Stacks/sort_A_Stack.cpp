#include <bits/stdc++.h>
using namespace std;
void sortInsert(stack<int> &stack, int ele)
{
    if (stack.empty() || (!stack.empty() && stack.top() < ele))
    {
        stack.push(ele);
        return;
    }
    int num = stack.top();
    stack.pop();
    sortInsert(stack, ele);
    stack.push(num);
}
void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortInsert(stack, num);
}
int main()
{
}