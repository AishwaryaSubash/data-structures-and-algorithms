#include <bits/stdc++.h>
using namespace std;

int seq(int n)
{
    if (n == 1)
        return 1;
    return n * n + seq((n - 1));
}

int main()
{
    int n = 6;
    cout << seq(n);
}