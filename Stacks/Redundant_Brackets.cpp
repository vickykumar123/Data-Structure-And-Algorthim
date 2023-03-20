#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '*' || ch == '/' || ch == '-')
        {
            st.push(s[i]);
        }
        else
        {
            if (ch == ')')
            {

                bool isRedundant = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '*' || top == '/' || top == '-')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if (isRedundant == true)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}
int main()
{
    string str = "((a+b))";
    int ans = findRedundantBrackets(str);
}