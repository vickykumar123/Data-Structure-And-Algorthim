#include <bits/stdc++.h>
using namespace std;
int sqrt(int x)
{
    int start = 1, end = x, ans = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int square = mid * mid;
        if (square == x)
        {
            return mid;
        }
        else if (square > x)
            end = mid - 1;
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int x = 36;
    cout << "Square root of 36 is " << sqrt(x);
}