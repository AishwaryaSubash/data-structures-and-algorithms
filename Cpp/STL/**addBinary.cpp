#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a = "11", b = "1";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ans = "";
    int c = 0;

    int len = (a.length() > b.length()) ? 1 : 0;
    if (len)
    {
        while (a.length() > b.length())
            b += "0000";
        b = b.substr(0, a.length());
    }
    else
    {
        while (b.length() > a.length())
            a += "0000";
        a = a.substr(0, b.length());
    }
    cout << a << " " << b << endl;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[i])
        {
            ans += to_string(int(c));
            if (a[i] == '1')
                c = 1;
            else
                c = 0;
        }
        else
        {
            if (c == 0)
                ans += "1";
            else
                ans += "0";
        }
        cout << ans << endl;
    }
    cout << ans << endl;
}