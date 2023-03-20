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
void inorder(Node *&root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
vector<int> merge(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans.push_back(a[i]);
            i++;
        }
        else
        {
            ans.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size())
    {
        ans.push_back(a[i]);
        i++;
    }
    while (j < b.size())
    {
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}
Node *ToBST(vector<int> &a, int s, int e)
{
    if (s > e)
        return NULL;
    int mid = (s + e) / 2;
    Node *root = new Node(a[mid]);
    root->left = ToBST(a, s, mid - 1);
    root->right = ToBST(a, mid + 1, e);
    return root;
}
Node *mergeBST(Node *root1, Node *root2)
{
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);
    vector<int> mergeArray = merge(bst1, bst2);
    int i = 0, j = mergeArray.size() - 1;
    return ToBST(mergeArray, i, j);
}
int main()
{
}