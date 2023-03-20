#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
class Solution
{
public:
    pair<bool, int> isSumTreeFast(Node *root)
    {
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }
        pair<int, int> left = isSumTreeFast(root->left);
        pair<int, int> right = isSumTreeFast(root->right);
        bool leftSumTree = left.first;
        bool rightSumTree = right.first;
        bool sum = root->data == left.second + right.second;

        pair<bool, int> ans;
        if (leftSumTree && rightSumTree && sum)
        {
            ans.first = true;
            ans.second = 2 * root->data;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node *root)
    {
        return isSumTreeFast(root).first;
    }
};
int main()
{
}