#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i] > a[i + 1] && i % 2 == 0) || (a[i] < a[i + 1] && i % 2 != 0))
        {
            int b = a[i];
            a[i] = a[i + 1];
            a[i + 1] = b;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}