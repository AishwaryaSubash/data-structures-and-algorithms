#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "loveleetcode";
    map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (m[s[i]] == 1)
            return i;
    }
    return -1;
}