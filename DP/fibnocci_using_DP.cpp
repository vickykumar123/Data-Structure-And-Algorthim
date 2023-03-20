#include <bits/stdc++.h>
using namespace std;

// using TOP-Down Approach T.C = o(n) s.c = o(n)+o(n)
int fib(int n, vector<int> &dp)
{
    if (n == 1 || n == 0)
        return n;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}
int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    cout << fib(n, dp);
    return 0;
}

// Bottom- Down Aprroach T.C = o(n) s.c = o(n)
int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}

// Space Optimization T.C = o(n) s.c = o(1)
int main()
{
    int n;
    cin >> n;

    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    cout << prev1;
    return 0;
}