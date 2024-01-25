#include <bits/stdc++.h>
using namespace std;

map<int, int> m;

int tribonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (n == 3)
        return 2;
    if (m.find(n) != m.end())
    {
        return m[n];
    }
    m[n] = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
    return m[n];
}

int main()
{
    int n = 35;
    cout << tribonacci(n);
}