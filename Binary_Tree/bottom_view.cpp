#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getBottomView(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> nodes;
    queue<pair<TreeNode<int> *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        TreeNode<int> *front = temp.first;
        int hD = temp.second;

        nodes[hD] = front->val; // it will override the node..

        if (front->left)
            q.push(make_pair(front->left, hD - 1));
        if (front->right)
            q.push(make_pair(front->right, hD + 1));
    }
    for (auto i : nodes)
    {
        ans.push_back(i.second);
    }
    return ans;
}