#include <bits/stdc++.h>
using namespace std;
int main()
{
    //     int nums[4] = {1, 2, 5, 9};
    //     int mid = 4 / 2;
    //     int result = 0;
    //     for (int i = 0; i < 4; i++)
    //     {
    //         int v = 1.0 * nums[i];
    //         int val = ceil((1.0 * nums[i]) / mid);
    //         result += ceil((1.0 * nums[i]) / mid);
    //     }
    //     cout << result;
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(3);
    vector<int> t(nums);
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << " ";
    }
}
