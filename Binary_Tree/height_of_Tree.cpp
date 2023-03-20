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
// Same as levelOrderTraversal....
class Solution
{
public:
    // Function to find the height of a binary tree.
    void height(struct Node *root, int &count)
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                count++;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
    }

    int height(struct Node *node)
    {
        int cnt;
        height(node, cnt);
        return cnt;
    }
};
/*
or other using Method using Recursion....

class Solution{
    public:
    int height(struct Node* node){
        if(node == NULL){
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        int ans = max(left,right)+1; // +1 for adding root node
        return ans;
    }
};
*/
int main()
{
}