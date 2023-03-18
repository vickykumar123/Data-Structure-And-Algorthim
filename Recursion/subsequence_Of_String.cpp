/*
Sample Input 1:
1
abc

Sample Output 1:
a ab abc ac b bc c

Explanation Of Sample Input 1:
All possible subsequences of abc are :
“a” , “b” , “c” , “ab” , “bc” , “ac”, “abc”
*/

#include <bits/stdc++.h>
using namespace std;
void solve(vector<string> str, string output, int index, vector<string> ans)
{
    if (index >= str.length())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }
    solve(str, output, index + 1, ans);
    char ele = str[index];
    output.push_back(ele);
    solve(str, output, index + 1, ans);
}
vector<string> subsquence(vector<string> str)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}
int main()
{
}