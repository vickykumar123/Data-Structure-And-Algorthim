/*
this second method that uses T.C of O(n)
*/
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
public:
    // Function to return the diameter of a Binary Tree.
    pair<int, int> diameterFast(Node *root)
    {
        if (root == NULL)
        {
            pair<int, int> temp = make_pair(0, 0);
            return temp;
        }
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        int d1 = left.first;
        int d2 = right.first;
        int height = left.second + right.second + 1; // +1 for adding root node

        pair<int, int> ans;
        // ans.first is max of left and right
        ans.first = max(d1, max(d2, height));
        // ans.second is height max;
        ans.second = max(left.second, right.second) + 1; // +1 for adding root node
        return ans;
    }
    int diameter(Node *root)
    {
        return diameterFast(root).first;
    }
};
int main()
{
}