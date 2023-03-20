#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node *solve(Node *root, int targetNodeVal, int &k)
{
    if (root == NULL)
        return NULL;
    if (root->data == targetNodeVal)
        return root;

    Node *leftAns = solve(root->left, targetNodeVal, k);
    Node *rightAns = solve(root->right, targetNodeVal, k);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX; // k will have max value because when k-- is done it does not become zero...
            return root;
        }
        return leftAns;
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX; // k will have max value because when k-- is done it does not become zero...
            return root;
        }
        return rightAns;
    }
}
Node *findKthAncestor(Node *root, int targetNodeVal, int k)
{
    Node *ans = solve(root, targetNodeVal, k);
    if (root == NULL || ans->data == targetNodeVal)
        return NULL;
    return ans;
}