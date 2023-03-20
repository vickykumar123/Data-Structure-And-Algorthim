// This solution takes T.C of o(n^2) follow diameter of BinaryTree 2 program
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    int height(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1; // +1 for adding root node
        return ans;
    }

public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lefts = diameter(root->left);
        int rights = diameter(root->right);
        int add = height(root->left) + height(root->right) + 1; // +1 for adding root node
        int ans = max(lefts, max(rights, add));
        return ans;
    }
};
int main()
{
}