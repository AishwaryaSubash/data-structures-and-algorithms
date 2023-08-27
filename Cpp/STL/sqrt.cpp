#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 2, r;
    if (x == 1)
        return 1;
    for (int i = 1; i <= x / 2; i++)
    {
        if (i * i == x)
        {
            cout << i;
            break;
        }
        else if (i * i > x)
        {
            cout << i - 1;
            break;
        }
    }
}