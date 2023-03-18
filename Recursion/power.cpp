#include <bits/stdc++.h>
using namespace std;
int power(int nums, int sq)
{
    if (sq == 0)
        return 1;
    if (sq == 1)
        return nums;
    int ans = power(nums, sq / 2);
    if (sq % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return nums * ans * ans;
    }
}
int main()
{
    int nums = 2, sq = 10;
    cout << power(nums, sq);
}