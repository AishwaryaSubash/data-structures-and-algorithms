#include <bits/stdc++.h>
using namespace std;

int fibonacciModified(int t1, int t2, int n)
{
    int t3 = 0;
    while (n - 2 > 0)
    {
        t3 = t1 + (t2 * t2);
        t1 = t2;
        t2 = t3;
        n--;
        cout << t1 << " " << t2 << " " << t3 << endl;
    }
    return t3;
}

int main()
{
    int t1 = 0, t2 = 1, n = -1;
    if (n <= 0)
        cout << "Error";
    else if (n == 1)
        cout << t1 << endl;
    else if (n == 2)
        cout << t2 << endl;
    else
        cout << fibonacciModified(t1, t2, n);
}