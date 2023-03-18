#include <iostream>
using namespace std;

// int main()
// {
//     int arr[4] = {10, 20, 30, 40};
//     int sum = 0;
//     for (int i = 0; i < 4; i++)
//     {
//         sum += arr[i];
//     }
//     cout << "sum is " << sum;
// }
int getSum(int arr[], int size)
{
    if (size == 0)
        return 0;
    if (size == 1)
        return arr[0];
    int remaining = getSum(arr + 1, size - 1);
    return arr[0] + remaining;
}
int main()
{
    int arr[4] = {10, 20, 30, 40};
    int size = 4;
    cout << "sum is " << getSum(arr, size);
}