#include <bits/stdc++.h>
using namespace std;

bool palin(string s)
{
    string t = s;
    reverse(s.begin(), s.end());
    if (t == s)
    {
        return true;
    }
    return false;
}

int main()
{
    string s = "abca";
    if (palin(s))
    {
        cout << true;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            string u = s;
            u.erase(u.begin() + i);
            if (palin(u))
            {
                cout << true;
                break;
            }
        }
    }
    return 0;
}