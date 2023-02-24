#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 512;

    if (x == 1 || x % 2 == 0)
    {
        for (int i = 2; i < x; i = i * 2)
        {
            if (x % i == 0)
            {
                cout << true;
                break;
            }
        }
    }
    else
    {
        cout << false;
    }
}