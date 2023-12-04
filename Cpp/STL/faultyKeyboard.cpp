#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "string";
    string t = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'i')
        {
            reverse(t.begin(), t.end());
        }
        else
            t += s[i];
    }
    cout << t;
}