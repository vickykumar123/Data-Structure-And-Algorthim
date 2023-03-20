/*
Input: s = "abccbaacz"
Output: "c"
Explanation:
The letter 'a' appears on the indexes 0, 5 and 6.
The letter 'b' appears on the indexes 1 and 4.
The letter 'c' appears on the indexes 2, 3 and 7.
The letter 'z' appears on the index 8.
The letter 'c' is the first letter to appear twice, because out of all the letters the index of its second occurrence is the smallest.
*/
#include <bits/stdc++.h>
using namespace std;
char repeatedCharacter(string s)
{
    unordered_map<char, int> count;
    for (auto i : s)
    {
        if (count[i] == 1)
            return i;
        else if (count[i] == 0)
            count[i]++;
    }
    return 0;
}

int main()
{
}