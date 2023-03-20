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
int countNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 1 + countNode(root->left) + countNode(root->right);
    return count;
}
bool isCBT(Node *root, int i, int NodeCount)
{
    if (root == NULL)
    {
        return true;
    }
    if (i >= NodeCount)
    {
        return false;
    }
    else
    {
        bool left = isCBT(root->left, 2 * i + 1, NodeCount);
        bool right = isCBT(root->right, 2 * i + 2, NodeCount);
        return left && right;
    }
}
bool isMaxHeap(Node *root)
{
    // leaf NOde
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if (root->right == NULL)
    {
        return root->data > root->left->data;
    }
    else
    {
        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);
        int leftData = root->left->data;
        int rightData = root->right->data;
        if (left && right && (root->data > leftData && root->data > rightData))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool isHeap(Node *tree)
{
    int index = 0;
    int totalNode = countNode(tree);
    if (isCBT(tree, index, totalNode) && isMaxHeap(tree))
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