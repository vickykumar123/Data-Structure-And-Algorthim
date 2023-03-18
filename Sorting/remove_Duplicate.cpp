#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "xyyxxzaa";
    string s1 = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s1.size() > 0 && s[i] == s1.back())
        {
            s1.pop_back();
        }
        else
        {
            s1.push_back(s[i]);
        }
    }
    cout << s1;
}