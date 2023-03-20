#include <bits/stdc++.h>
using namespace std;
/*
Input: root = [1,2,3,4,5,6]
Output: 6
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
    void traversal(TreeNode *root, int &count)
    {
        if (root == NULL)
        {
            return;
        }
        traversal(root->left, count);
        count++;
        traversal(root->right, count);
    }

public:
    int countNodes(TreeNode *root)
    {
        int cnt = 0;
        traversal(root, cnt);
        return cnt;
    }
};