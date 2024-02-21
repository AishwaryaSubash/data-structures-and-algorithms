#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int m, v, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> v;
        sum += m * v;
    }
    cout << sum;
}