#include <bits/stdc++.h>
using namespace std;
bool checkPalidrome(string s, int i, int j)
{
    if (i > j)
        return true;
    if (s[i] != s[j])
        return false;
    else
        return checkPalidrome(s, i + 1, j - 1);
}
int main()
{
    string str = "abba";
    int ans = checkPalidrome(str, 0, str.length() - 1);
    if (ans)
        cout << "It's a Palidrome ";
    else
        cout << "It's not Palidrome ";
}
