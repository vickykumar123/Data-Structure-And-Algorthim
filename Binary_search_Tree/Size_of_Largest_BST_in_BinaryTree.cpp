#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class info
{
public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};
info solve(Node *root, int &ans)
{
    if (root == NULL)
        return {INT_MAX, INT_MIN, true, 0};
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);
    if (left.isBST && right.isBST && (left.maxi < root->data && right.mini > root->data))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }
    if (currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }
    return currNode;
}
int largestBST(Node *root)
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}
int main()
{
}