#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next; // next element address
    Node *random;
    // Constructor
    Node(int data) // creating simple node and putting data in it
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};
Node *deleteMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}