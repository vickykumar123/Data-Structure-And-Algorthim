// this method is not useful for because it is O(N^2) using balanced_tree2

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
        int ans = max(left, right) + 1;
        return ans;
    }

public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool heights = abs(height(root->left) - height(root->right)) <= 1;

        if (left && right && heights)
        {
            return 1;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
}