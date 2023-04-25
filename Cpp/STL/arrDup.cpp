#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    string s = "{3,1,3,3,2}";
    vector<string> v;
    string t = "";
    s.erase(s.begin(), s.begin() + 1);
    s.erase(s.end() - 1, s.end());
    for (char c : s)
    {
        if (c != ',')
        {
            t += c;
        }
        else
        {
            v.push_back(t);
            t.clear();
        }
    }
    if (!t.empty())
        v.push_back(t);
    unordered_map<string, int> m;
    for (string d : v)
    {
        m[d] += 1;
    }
    for (pair<string, int> k : m)
    {
        if (k.second > n / 2)
        {
            cout << k.first;
            return 0;
        }
    }
    cout << -1;
    return 0;
}