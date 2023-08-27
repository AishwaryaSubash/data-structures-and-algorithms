#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "aaaaayyhhhh";
    string ans = "";
    map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
        if (m[s[i]] >= 3)
        {
            continue;
        }
        else
        {
            ans += s[i];
        }
    }
    cout << ans;
}