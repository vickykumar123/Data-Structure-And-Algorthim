/*
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
*/
#include <bits/stdc++.h>
using namespace std;
class ListNode
{

public:
    int data;
    ListNode *next; // next element address
    // Constructor
    ListNode(int data) // creating simple node and putting data in it
    {
        this->data = data;
        this->next = NULL;
    }
};
// reverse linked_List
ListNode *reverse(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *curr = head;
    ListNode *next = NULL;
    ListNode *prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// Insert At tail
void insertAtTail(ListNode *&head, ListNode *&tail, int data)
{
    ListNode *temp = new ListNode(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
// add to element
ListNode *add(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    ListNode *ansHead = NULL;
    ListNode *ansTail = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        int sum = carry + l1->data + l2->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        int sum = carry + l1->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        int sum = carry + l2->data;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
        l2 = l2->next;
    }
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }
    return ansHead;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode *ans = add(l1, l2);
    ans = reverse(ans);
    return ans;
}
int main()
{
}