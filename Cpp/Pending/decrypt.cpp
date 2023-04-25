#include <bits/stdc++.h>
using namespace std;

int main()
{
    // a=97 i=105 j=106 z=122
    // a=1 i=9    j=10#  z=26#
    map<string, char> m = {{"1", 'a'}, {"10#", 'j'}};
    string s = "10#11#12";
    int start = 96;
    string ans3;
    string ans2;
    for (int i = 0; i < s.length(); i++)
    {
        if (i < s.length() - 1)
        {
            if (s[i + 2] == '#')
            {
                ans3 = s.substr(i, 3);
                ans3.erase(ans3.back(), 1);
                cout << ans3 << " ";
            }
            if (i + 2 == s.length())
            {
                ans2 = s.substr(i, 2);
                cout << ans2 << " ";
            }
        }

        // if (i < s.length() - 2 && (s[i + 2] == '#' || s.length() == i + 1))
        // {
        //     string v = s.substr(i, 2);
        //     cout << v << endl;
        //     ans += to_string(start + stoi(v));
        //     i += 2;
        //     cout << ans << endl;
        // }
        // else
        // {
        // }
    }
    // cout << ans << " ";
}