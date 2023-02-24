#include <bits/stdc++.h>
using namespace std;

long long int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int zero(int n)
{
    int m = fact(n);
    cout << m << endl;
    int count = 0;
    while (m > 0)
    {
        m = m / 10;
        count++;
    }
    m = n;
    int zcount = 0;
    for (int i = 0; i < count; i++)
    {
        if (m % 10 == 0)
        {
            zcount++;
        }
        else
        {
            break;
        }
        m = m / 10;
    }
    return zcount;
}

int main()
{
    int num;
    cin >> num;
    cout << zero(num);
}
