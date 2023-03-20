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

void insertAtHead(Node *&head, int data) // this inserts in reverse order like 30,20,10
{
    // Creates new Node
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp = tail->next;
}
void positionToInsert(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
void deleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Creating new node
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->node << endl;

    // head is pointed to node
    Node *head = node1;
    Node *tail = node1;
    // print(head);
    insertAtHead(head, 12);
    positionToInsert(tail, head, 1, 123);
    insertAtTail(tail, 101);
    print(head);
    deleteNode(head, 2);
    print(head);
}