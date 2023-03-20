/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
int countNode(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 1 + countNode(root->left) + countNode(root->right);
    return count;
}
bool isCBT(TreeNode *root, int i, int nodeCount)
{
    if (root == NULL)
    {
        return true;
    }
    if (i >= nodeCount)
    {
        return false;
    }
    else
    {
        bool left = isCBT(root->left, 2 * i + 1, nodeCount);
        bool right = isCBT(root->right, 2 * i + 2, nodeCount);
        return left && right;
    }
}
bool isCompleteTree(TreeNode *root)
{
    int index = 0;
    int totalCount = countNode(root);
    if (isCBT(root, index, totalCount))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
}