#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *hasCycle(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return temp;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return head;
}
Node *removeLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *startingLoop = hasCycle(head);
    if (startingLoop == NULL)
    {
        return head;
    }
    Node *slow = startingLoop;
    while (slow->next != startingLoop)
    {
        slow = slow->next;
    }
    slow->next = NULL;
    return head;
}