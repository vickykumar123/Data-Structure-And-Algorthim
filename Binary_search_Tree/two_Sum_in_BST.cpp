/*
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
// I am using inorder because to store BST value in sorted order
void inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
bool twoSumInBST(Node *root, int target)
{
    vector<int> ans;
    inorder(root, ans);
    int i = 0, j = ans.size() - 1; // using two pointer we compare two sum
    while (i < j)
    {
        int sum = ans[i] + ans[j];
        if (sum == target)
        {
            return true;
        }
        if (sum > target)
            j--;
        if (sum < target)
            i++;
    }
    return false;
}
int main()
{
}