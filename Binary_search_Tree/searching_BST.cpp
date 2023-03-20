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
bool searchInBST(Node *root, int x)
{
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return true;
        }
        if (temp->data > x)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}
/*
//but it takes longer complexity in the case of O(N)
bool searchInBST(Node *root, int x){
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    if(root->data > x){
        searchBST(root->left,x);
    }else{
        searchBST(root->right,x);
    }
}
*/
int main()
{
}