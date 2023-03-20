/*
Method 2 -> Recursion
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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    if (list1->data <= list2->data)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}
int main()
{
}