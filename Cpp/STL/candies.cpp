#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}
int comb(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
int main()
{
    vector<int> ans;
    int n = 5;
    int m = 3;
    for (int i = 0; i < comb(n, m); i++)
    {
        int l = 0;
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = j; k <= n; k++)
            {
                cout << j << " " << k << endl;
                l++;
            }
        }
        l = 0;
        cout << endl;
    }
}