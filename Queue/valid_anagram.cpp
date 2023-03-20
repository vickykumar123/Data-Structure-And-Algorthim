#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t)
{
    int arr1[26] = {0};
    int arr2[26] = {0};
    if (s.size() != t.size())
    {
        return false;
    }
    for (int i = 0; i < s.size(); i++)
    {
        int ch = s[i] - 'a';
        arr1[ch]++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        int ch = t[i] - 'a';
        arr2[ch]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

/*
------another method using stack-------
bool isAnagram(string s, string t) {
        stack<int> s1;
        stack<int> t1;
        if(s.size()!=t.size()){
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i =0;i<s.size();i++){
            s1.push(s[i]);
        }
        for(int i =0;i<t.size();i++){
            t1.push(t[i]);
        }
        while(!s1.empty()){
            if(s1.top()!=t1.top()){
                return false;
            }
            s1.pop();
            t1.pop();
        }
    return true;
    }
*/
int main()
{
}