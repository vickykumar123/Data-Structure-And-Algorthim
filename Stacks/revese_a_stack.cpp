#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "vicky";
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }
    string ans = "";
    int top = s.size();
    while (!s.empty())
    {
        char s1 = s.top();
        ans.push_back(s1);
        s.pop();
    }
    cout << "Reverse the string " << ans;
}