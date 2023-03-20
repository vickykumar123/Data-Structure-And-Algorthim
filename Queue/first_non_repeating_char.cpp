/*
Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'
*/
#include <bits/stdc++.h>
using namespace std;
string FirstNonRepeating(string A)
{
    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";
    for (int i = 0; i < A.size(); i++)
    {
        char ch = A[i];
        count[ch]++;
        q.push(A[i]);
        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}
int main()
{
}