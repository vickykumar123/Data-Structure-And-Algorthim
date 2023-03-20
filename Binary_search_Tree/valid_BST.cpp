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

bool isValid(Node *root, long min, long max)
{
    if (root == NULL)
        return true;
    if (root->data >= min && root->data <= max)
    {
        bool left = isValid(root->left, min, root->data);
        bool right = isValid(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}
bool validateBST(Node *root)
{
    return isValid(root, LONG_MIN, LONG_MAX);
}
int main()
{
}