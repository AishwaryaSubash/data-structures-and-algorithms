#include <bits/stdc++.h>
#include <cmath>
#include <gmp.h>
using namespace std;

int gcd(int e, int f)
{
    if (f != 0)
        return gcd(f, e % f);
    else
        return e;
}

int table(int fi, int e)
{
    int r1 = fi, r2 = e;
    int t1 = 0, t2 = 1;
    int q = r1 / r2;
    int t = t1 - q * t2;
    int r = r1 % r2;
    while (r != 0)
    {
        r1 = r2;
        r2 = r;
        q = r1 / r2;
        r = r1 % r2;
        t1 = t2;
        t2 = t;
        t = t1 - q * t2;
    }
    r1 = r2;
    r2 = r;
    t1 = t2;
    t2 = t;
    return t1;
}

int main()
{

    vector<int> primes;
    for (int i = 2; i < 35000; i++)
    {
        int flag = 0;
        for (int j = 2; j < (i / 2) + 1; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            primes.push_back(i);
    }

    int range = primes.size();
    // int p = primes.at(rand() % range);
    // int q = primes.at(rand() % range);

    int p = 7, q = 13;

    int n, f;
    int e;
    cin >> p >> q;
    cout << p << " " << q << endl;
    cout << "e ";
    cin >> e;

    n = p * q;
    f = (p - 1) * (q - 1);

    int g = gcd(e, f);

    int d = table(f, e);
    cout << "n " << n << endl;
    cout << "d " << d << endl;

    mpz_t pow;

    long long int m, c = pow(m, e);
    cout << "m ";
    cin >> m;
    c = c % n;
    cout << "c " << c << endl;

    // int a = 8, b = 3;
    // cout << pow(a, b);
}