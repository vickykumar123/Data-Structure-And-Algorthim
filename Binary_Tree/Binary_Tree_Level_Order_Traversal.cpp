#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == NULL)
    {
        return result;
    }
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            TreeNode *frontNode = q.front();
            q.pop();
            ans[i] = frontNode->val;

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
        result.push_back(ans);
    }
    return result;
}

/*
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root == NULL){
        return result;
    }
    queue<TreeNode*> q;
    q.push(root);


    while(!q.empty()){
        int size = q.size();
        vector<int> ans;

        for(int i =0;i<size;i++){
            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right)
                q.push(frontNode->right);
            ans.push_back(frontNode->val);
        }
        result.push_back(ans);
        }
        return result;
    }
*/