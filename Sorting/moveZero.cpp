/*
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int nonZero = 0; // as first element should be non-zero.
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[nonZero]);
            nonZero++;
        }
    }
}
int main()
{
}