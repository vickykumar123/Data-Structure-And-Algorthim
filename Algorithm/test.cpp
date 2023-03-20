#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int mask = 111;
    int ans = ~n;
    n = n >> 1;
    cout << n << endl;
    n = n >> 1;
    cout << n << endl;
    cout << ans;
}