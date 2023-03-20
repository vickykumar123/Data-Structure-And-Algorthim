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
Node *removeDuplicate(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    unordered_map<int, bool> visited;
    Node *temp = head;
    Node *prev = head;
    while (temp != NULL)
    {
        if (visited[temp->data] == true)
        {
            prev->next = temp->next;
        }
        else
        {
            prev = temp;
            visited[temp->data] = true;
        }
        temp = temp->next;
    }
    return head;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp = tail->next;
}
void insertAtHead(Node *&head, int data) // this inserts in reverse order like 30,20,10
{
    // Creates new Node
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void positionToInsert(Node *&tail, Node *&head, int position, int d)
{
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
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
    Node *node1 = new Node(4);
    Node *head = node1;
    Node *tail = node1;

    positionToInsert(tail, head, 2, 5);
    positionToInsert(tail, head, 3, 4);
    positionToInsert(tail, head, 4, 2);
    positionToInsert(tail, head, 5, 2);
    removeDuplicate(head);
    print(head);
}