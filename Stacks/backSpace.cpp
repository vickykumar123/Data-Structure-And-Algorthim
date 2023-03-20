/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.



Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
*/
#include <bits/stdc++.h>
using namespace std;
bool backspaceCompare(string s, string t)
{
    string s1;
    string s2;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '#')
        {
            if (!s1.empty())
                s1.pop_back();
        }
        else
        {
            s1.push_back(s[i]);
        }
    }
    for (int j = 0; j < t.length(); j++)
    {
        if (t[j] == '#')
        {
            if (!s2.empty())
                s2.pop_back();
        }
        else
        {
            s2.push_back(t[j]);
        }
    }
    int i = 0, j = 0;
    while (i < s1.size() || j < s2.size())
    {
        if (s1[i] != s2[j])
        {
            return false;
        }
        i++;
        j++;
    }
    return true;
}
int main()
{

    int ans = backspaceCompare("isfcow#", "isfco#w#");
    if (ans)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}