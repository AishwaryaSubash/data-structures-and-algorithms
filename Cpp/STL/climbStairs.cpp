#include <bits/stdc++.h>
using namespace std;

//Fib series
int fib(int n)
{

    int a = 0, b = 1;
    int c;
    for (int i = 0; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;

    // if (n == 0)
    // {
    //     return 1;
    // }
    // else if (n == 1)
    // {
    //     return 1;
    // }
    // else if (n == 2)
    // {
    //     return 2;
    // }
    // else
    // {
    //     return fib(n - 1) + fib(n - 2);
    // }
}

int main()
{
    int n = 6;
    // cin >> n;
    cout << fib(n);
}
