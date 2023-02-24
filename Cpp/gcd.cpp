#include <bits/stdc++.h>
using namespace std;

int gcd(int p, int q)
{
    if (q == 0)
    {
        return p;
    }
    else
    {
        return gcd(q, p % q);
    }
}

int main()
{

    cout << gcd(1, 2);

    // vector<int> v = {3, 8, 5, 6, 2};
    // sort(v.begin(), v.end());

    // int s = v.at(0), l = v.at(v.size() - 1);
    // cout << s << " " << l << endl;
    // int flag = 0;
    // for (int i = s; i <= l; i++)
    // {
    //     if (s % i == 0 && l % i == 0)
    //     {
    //         flag = i;
    //     }
    // }
    // cout << flag;

    return 1;
}
