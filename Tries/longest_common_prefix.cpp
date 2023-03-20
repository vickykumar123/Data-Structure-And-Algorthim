#include <bits/stdc++.h>
using namespace std;
/*
Sample Input 1:
2
4
coding codezen codingninja coder
3
night ninja nil

Sample Output 1:
cod
ni
Explanation Of Sample Input 1:
For the first test case,
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”.

For the second test case,
The longest common prefix among all the given strings is “ni” as it is present as a prefix in all strings. Hence, the answer is “ni”.
*/
// without trie, but it works great
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    for (int i = 0; i < arr[0].size(); i++)
    {
        char ch = arr[0][i]; // first string of character by character comparsion
        bool match = true;
        for (int j = 1; j < n; j++)
        {
            // not matching
            if (arr[j].size() < 1 || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}
