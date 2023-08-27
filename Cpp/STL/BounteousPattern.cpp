#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int m = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << m;
            if (j < i)
                cout << "*";
        }
        m++;
        cout << endl;
    }

    m = n;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i + j >= n - 1)
                cout << m;
            if (i + j >= n)
                cout << "*";
        }
        m--;
        cout << endl;
    }
}

// 1
// op
// 1
// 1

// 2
// op
// 1
// 2*2
// 2*2
// 1