#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void traversal(BinaryTreeNode<int> *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    traversal(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    traversal(root->right, count);
}
int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    int cnt = 0;
    traversal(root, cnt);
    return cnt;
}
int main()
{
}