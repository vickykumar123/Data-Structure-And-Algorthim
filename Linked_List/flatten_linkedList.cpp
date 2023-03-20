/*
Flatten A Linked List
Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22   35
|           |     |
8          50    40
|                 |
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every
node in a single level.
(Note: | represents the bottom pointer.)
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};
Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    if (left->data <= right->data)
    {
        left->bottom = merge(left->bottom, right);
        return left;
    }
    else
    {
        right->bottom = merge(left, right->bottom);
        return right;
    }
}
Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *ans = flattenLinkedList(head->next);
    return merge(head, ans);
}
int main()
{
}