/* Input: head = [1,2,2,1]
Output: true */
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
bool checkPalindrome(vector<int> &arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        if (arr[s] != arr[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}
bool isPalindrome(ListNode *head)
{
    vector<int> arr;
    ListNode *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return checkPalindrome(arr);
}