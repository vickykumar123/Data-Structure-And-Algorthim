// another important traversal that takes o(1) space complexity
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void MorrisTraversal(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            // process current node and move to the right
            cout << curr->val << " ";
            curr = curr->right;
        }
        else
        {
            // find the predecessor of the current node
            TreeNode *pre = curr->left;
            while (pre->right != nullptr && pre->right != curr)
            {
                pre = pre->right;
            }
            if (pre->right == nullptr)
            {
                // establish the link between the predecessor and the current node
                pre->right = curr;
                // move to the left child
                curr = curr->left;
            }
            else
            {
                // remove the link between the predecessor and the current node
                pre->right = nullptr;
                // process current node and move to the right
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}
int main()
{
}