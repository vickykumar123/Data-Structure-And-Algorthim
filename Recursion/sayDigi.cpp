#include <iostream>
using namespace std;
void sayDigi(string arr[], int n)
{
    if (n == 0)
        return;
    int digit = n % 10;
    n = n / 10;
    sayDigi(arr, n);
    cout << arr[digit] << " ";
}
int main()
{
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n = 412;
    sayDigi(arr, n);
}