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

vector<int> getTopView(TreeNode<int> *root)
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
        if (nodes.find(hD) == nodes.end()) // if is not present then it will push it
        {
            nodes[hD] = front->val;
        }
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