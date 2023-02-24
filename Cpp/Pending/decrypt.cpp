#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "10#11#12";
    int start = 96;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (i < s.length() - 2 && s[i + 2] == '#')
        {
            string v = s.substr(i, 2);
            ans += to_string(start + stoi(v));
            i += 2;
        }
        else
        {
        }
    }
    cout<<ans;
}