#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{
    vector<string> arr;
    string t = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            arr.push_back(t);
            t.clear();
        }
        else
        {
            t += s[i];
        }
    }
    arr.push_back(t);
    set<char> p(pattern.begin(), pattern.end());
    set<string> strarr(arr.begin(), arr.end());

    if (p.size() != strarr.size())
        return false;
    if (pattern.size() != arr.size())
        return false;

    map<char, string> m;
    for (int i = 0; i < pattern.size(); i++)
    {
        if (m.find(pattern[i]) == m.end())
            m[pattern[i]] = arr[i];
        else if (m[pattern[i]] == arr[i])
            continue;
        else
            return false;
    }

    return true;
}

int main()
{
    string pattern = "abba", s = "dog cat cat dog";
    cout << wordPattern(pattern, s);
}