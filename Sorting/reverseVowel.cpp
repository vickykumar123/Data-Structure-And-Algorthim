#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
string reverseVowel(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        while (i < s.length() && !isVowel(s[i]))
        {
            i++;
        }
        while (j >= 0 && !isVowel(s[j]))
        {
            j--;
        }
        if (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    return s;
}
int main()
{
    string s = "aeiou";
    cout << reverseVowel(s);
    return 0;
}