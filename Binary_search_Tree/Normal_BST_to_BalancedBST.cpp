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
void inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
Node *balanced(vector<int> ans, int s, int e)
{
    if (s > e)
        return NULL;
    int mid = (s + e) / 2;
    Node *root = new Node(ans[mid]);
    root->left = balanced(ans, s, mid - 1);
    root->right = balanced(ans, mid + 1, e);
    return root;
}
Node *balancedBst(Node *root)
{
    vector<int> ans;
    inorder(root, ans);
    return balanced(ans, 0, ans.size() - 1);
}
int main()
{
}