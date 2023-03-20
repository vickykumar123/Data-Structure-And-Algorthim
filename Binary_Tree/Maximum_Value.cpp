/*
Input:
        4
       / \
      9   2
     / \   \
    3   5   7
Output:
4 9 7
Explanation:
At 0 level, values of nodes are {4}
                 Maximum value is 4
At 1 level, values of nodes are {9,2}
                 Maximum value is 9
At 2 level, values of nodes are {3,5,7}
                 Maximum value is 7
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};
vector<int> maximumValue(Node *node)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        int maxi = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            maxi = max(maxi, front->data);
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }

        ans.push_back(maxi);
    }
    return ans;
}
int main()
{
}