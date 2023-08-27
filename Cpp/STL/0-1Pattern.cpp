#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << 1;
            if (j < i)
                cout << 0;
        }
        cout << endl;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (i + j >= n - 2)
                cout << 1;
            if (i + j > n - 2)
                cout << 0;
        }
        cout << endl;
    }
}