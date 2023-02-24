#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    map<char, int> maps;
    map<char, int> mapt;
    if (s.length() == t.length())
    {
        for (int i = 0; i < s.length(); i++)
        {
            // if (count(s.begin(), s.end(), s[i]) != count(t.begin(), t.end(), s[i])) {
            if (maps.find(s[i]) != maps.end())
            {
                maps[s[i]]++;
            }
            else
            {
                maps.insert(pair<char, int>(s[i], 1));
            }
            if (mapt.find(t[i]) != mapt.end())
            {
                mapt[t[i]]++;
            }
            else
            {

                mapt.insert(pair<char, int>(t[i], 1));
            }
        }
        if (maps == mapt)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

    return 0;
}