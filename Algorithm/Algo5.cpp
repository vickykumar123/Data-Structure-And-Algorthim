// Merge Sort
#include <iostream>
using namespace std;

int merge(int a[], int b[], int m, int n)
{
    int i = 0, j = 0, k = 0;
    int c[k];
    while (i <= m && j <= n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    cout << c[k];
    return 0;
}

int main()
{
    int a[4] = {2, 8, 15, 18};
    int b[4] = {5, 9, 12, 17};
    cout << merge(a, b, 4, 4);
    return 0;
}