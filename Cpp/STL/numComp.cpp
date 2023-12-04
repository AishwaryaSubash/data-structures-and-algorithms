#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 8;
    vector<int> v;
    while (num != 0)
    {
        v.push_back(num % 2);
        num /= 2;
    }

    long int ans = 0;
    int s = 1;
    for (int i : v)
    {
        // cout << i;
        if (i == 0)
            i = 1;
        else
            i = 0;
        num = num + i * s;
        s *= 2;
    }
    cout << num;

    // string ans = "";
    // for (int i : v)
    // {
    //     if (i == 0)
    //         i = 1;
    //     else
    //         i = 0;
    //     ans += to_string(i);
    // }
    // cout << ans;
}