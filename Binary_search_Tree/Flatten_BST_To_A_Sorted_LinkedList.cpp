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
void inorder(Node *root, vector &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
Node *flatten(Node *root)
{
    vector node;
    inorder(root, node);
    Node *newNode = new Node(node[0]);
    Node *curr = newNode;
    for (int i = 1; i < node.size(); i++)
    {
        Node *temp = new Node(node[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    return newNode;
}
int main()
{
}