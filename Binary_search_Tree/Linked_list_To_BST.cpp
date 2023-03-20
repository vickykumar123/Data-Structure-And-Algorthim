#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

Node *sortedListToBST(ListNode *head)
{
    if (!head)
        return NULL;

    if (!head->next)
    {
        Node *root = new Node(head->val);
        return root;
    }
    // find mid
    ListNode *slow = head, *fast = head, *prev = NULL;
    while (fast && fast->next)
    {
        prev = slow; // it is required because to save previous number
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *head2 = slow->next;
    prev->next = NULL;                        // do dry run u will get to know
    Node *root = new Node(slow->val); // it is required

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(head2);

    return root;
}

int main()
{
}