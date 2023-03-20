#include <iostream>
#include <cmath>
using namespace std;
int powe(int num, int sq)
{
    int i, power = 1;
    if (sq == 0)
        return 1;
    for (i = 1; i <= sq; i++)
    {
        power = power * num;
    }
    return power;
}
// int main()
// {
//     int n = 5;
//     int ans = 0;
//     int i = 0;
//     // int c;
//     while (n != 0)
//     {
//         int bits = n & 1;
//         int power = powe(10, i);

//         int c = (bits * power);
//         ans = c + ans;
//         n = n >> 1;
//         i++;
//     }
//     cout << ans;
// }
int main()
{
    int n = 101;
    int ans = 0;
    int i = 0;
    // int c;
    while (n != 0)
    {
        int digit = n % 10;
        if (digit == 1)
        {
            ans = ans + powe(2, i);
        }
        n = n / 10;
        i++;
    }
    cout << ans;
}