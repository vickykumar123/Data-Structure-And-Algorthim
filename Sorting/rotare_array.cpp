/* Not sorting problem */
/*
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> rotate(vector<int> arr, int k)
{ // k =number of rotation
    vector<int> temp(arr.size());
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int rotateArray = (i + k) % n;
        temp[rotateArray] = arr[i];
    }
    arr = temp;
    return arr;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    vector<int> arr = rotate(nums, 3);
    for (auto i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}