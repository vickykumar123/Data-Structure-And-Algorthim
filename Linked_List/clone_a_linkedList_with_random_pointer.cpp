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
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
Node *copyList(Node *head)
{
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    unordered_map<Node *, Node *> oldToNewNode;
    Node *orginialNode = head;
    Node *cloneNode = cloneHead;
    while (orginialNode != NULL && cloneNode != NULL)
    {
        oldToNewNode[orginialNode] = cloneNode;
        orginialNode = orginialNode->next;
        cloneNode = cloneNode->next;
    }
    orginialNode = head;
    cloneNode = cloneHead;
    while (orginialNode != NULL)
    {
        cloneNode->random = oldToNewNode[orginialNode->random];
        orginialNode = orginialNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}

/*
another method;

Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        int i=0;
        Node* ptr = head;
        while (ptr) {
            m[ptr] =new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
*/