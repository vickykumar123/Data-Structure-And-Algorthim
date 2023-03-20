/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1
*/
#include <bits/stdc++.h>
using namespace std;
int firstUniqChar(string s)
{
    unordered_map<char, int> count;
    int ans = -1;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        count[ch]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (count[s[i]] == 1)
        {
            return i;
        }
    }
    return ans;
}
int main()
{
}