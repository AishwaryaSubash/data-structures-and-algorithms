#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    long n = 4;
    string bin = "";
    long long int ans = 0;
    while (n > 0)
    {
        bin += to_string(n % 2);
        n = n / 2;
    }
    bin.reverse(bin.begin(), bin.end());
    for (int i = 0; bin.length() < 32; i++)
    {
        bin.insert(bin.begin(), '0');
    }
    cout << bin << endl;

    for (int i = 0; i < 32; i++)
    {
        if (bin[i] == '0')
            bin[i] = '1';
        else
            bin[i] = '0';
    }
    cout << bin;
    // int m;
    // int q = 1;
    // for (int i = 31; i > 0; i--)
    // {
    //     m = atoi(bin[i]);
    //     ans = pow(m, q);
    //     q *= 10;
    // }
    // cout << ans;
}