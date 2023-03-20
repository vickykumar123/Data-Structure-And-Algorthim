#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &stack, int ele)
{
    if (stack.empty())
    {
        stack.push(ele);
        return;
    }
    int num = stack.top();
    stack.pop();
    insertAtBottom(stack, ele);
    stack.push(num);
}
void reverseStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, num);
}
int main()
{
}