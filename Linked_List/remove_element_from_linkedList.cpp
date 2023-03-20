/*
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    int data;
    Node *next; // next element address
    // Constructor
    Node(int data) // creating simple node and putting data in it
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *removeElements(Node *head, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (head->data == val)
        head = head->next;
    return head;
}
int main()
{
}