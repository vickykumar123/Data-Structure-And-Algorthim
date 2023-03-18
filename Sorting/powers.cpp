/*Not sorting problem*/
#include <bits/stdc++.h>
using namespace std;
int power(int nums, int sqrt)
{
    int i = 1, power = 1;
    for (; i <= sqrt; i++)
    {
        power *= nums;
    }
    return power;
}
int main()
{
    cout << power(2, 2);
}