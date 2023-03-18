#include <bits/stdc++.h>
using namespace std;
// string reverseStr(string s, int k)
// {
//     for (int i = 0; i < s.length(); i = i + k)
//     {
//         swap(s[i], s[i + 1]);
//     }
//     return s;
// }
// int main()
// {
//     string s = "abcdef";
//     cout << reverseStr(s, 2);
// }

int main()
{
    int n = 5;
    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j < n)
        {
            cout << "*"
                 << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}