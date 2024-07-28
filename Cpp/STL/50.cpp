#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    if (n % 2 == 1)
        return myPow(x, n - 1) * x;
    return myPow(x, n / 2) * myPow(x, n / 2);
}

int main()
{
    double x = 2;
    int n = 2;

    cout << myPow(x, n);
}