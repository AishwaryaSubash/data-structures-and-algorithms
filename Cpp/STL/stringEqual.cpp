#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    // cout << s << " " << t;
    int flag = 0;
    if (s.length() == t.length())
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == t[i])
            {
                flag = 1;
                continue;
            }
            else if (s[i] == '*' || s[i] == '?' || t[i] == '*' || t[i] == '?')
            {
                flag = 1;
                continue;
            }
            else
            {
                cout << "Not Equal";
                flag = 0;
                break;
            }
        }
    }
    else
    {
        cout << "Not Equal";
    }
    if (flag == 1)
    {
        cout << "Equal";
    }
}