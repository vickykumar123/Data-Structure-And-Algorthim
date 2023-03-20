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
void findMin(Node *root, int &mini)
{
    if (root == NULL)
    {
        return;
    }
    mini = min(mini, root->data);
    findMin(root->left, mini);
    findMin(root->right, mini);
}
int minValue(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int mini = INT_MAX;
    findMin(root, mini);
    return mini;
}
int main()
{
}