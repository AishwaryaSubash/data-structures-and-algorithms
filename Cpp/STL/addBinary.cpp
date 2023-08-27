#include <bits/stdc++.h>
using namespace std;

string ans = "";
char c = '0';

void sum(char x, char y, char c)
{
    if (c == '0')
    {
        if (x == 0 && y == 0)
        {
            ans += "0";
            c = '0';
            cout << 1;
        }
        else if (x == 1 && y == 1)
        {
            ans += "0";
            c = '1';
            cout << 2;
        }
        else
        {
            ans += "1";
            c = '0';
            cout << 3;
        }
    }
    else if (c == '1')
    {
        if (x == 0 && y == 0)
        {
            ans += "1";
            c = '0';
            cout << 4;
        }
        else if (x == 1 && y == 1)
        {
            ans += "1";
            c = '1';
            cout << 5;
        }
        else
        {
            ans += "0";
            c = '1';
            cout << 6;
        }
    }
}

int main()
{
    string a = "11", b = "1";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len;
    if (a.length() > b.length())
    {
        len = a.length();
        while (b.length() < a.length())
            b.push_back('0');
    }
    else
    {
        len = b.length();
        while (a.length() < b.length())
            a.push_back('0');
    }
    cout << endl;
    for (int i = 0; i < len; i++)
    {
        sum(a[i], b[i], c);
    }
    if (c == '1')
        ans += to_string(c);
    reverse(ans.begin(), ans.end());
    cout << endl
         << ans;
}