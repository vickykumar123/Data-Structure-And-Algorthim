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
Node *minVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *deleteBST(Node *root, int val)
{
    if (root == NULL)
        return root;
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        // if its a left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // if its a right child
        if (root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->right != NULL && root->left != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteBST(root->right, val);
        return root;
    }
}
int main()
{
}