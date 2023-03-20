/*
Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void solve(Node *root, int sum, int &maxSum, int len, int &maxLen)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}
int sumOfLongRootToLeafPath(Node *root)
{
    int len = 0;
    int sum = 0;

    int maxLen = 0;
    int maxSum = 0;

    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}