#include <bits/stdc++.h>
using namespace std;

//81/89 passed
int compare(string s)
{
    int c = 0;
    char a = s.front();
    for (int i = 0; i < s.length(); i++)
    {
        if (a == '0')
        {
            if (i % 2 == 0 && s[i] != '0')
            {
                c++;
                // cout << "even 0";
            }
            if (i % 2 == 1 && s[i] != '1')
            {
                c++;
                // cout << "odd 1";
            }
        }
        else
        {
            if (i % 2 == 0 && s[i] != '1')
            {
                c++;
                // cout << "even 1";
            }
            if (i % 2 == 1 && s[i] != '0')
            {
                c++;
                // cout << "odd 0";
            }
        }
    }
    return c;
}

int main()
{
    string s = "10010100";
    int m = compare(s);
    reverse(s.begin(), s.end());
    int n = compare(s);
    cout << (m > n) ? n : m;
}