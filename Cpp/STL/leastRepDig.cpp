#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> &a,
         pair<char, int> &b)
{
    return a.second < b.second;
}

void leastRepeatedDigit(long int n)
{
    string s = to_string(n);
    map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    vector<pair<char, int>> v;
    map<char, int>::iterator it = m.begin();
    while (it != m.end())
    {
        v.push_back(make_pair(it->first, it->second));
        ++it;
    }
    sort(v.begin(), v.end(), cmp);
    for (pair<char, int> p : v)
    {
        cout << p.first << " " << p.second << endl;
    }
}

int main()
{
    long int n = 11232;
    leastRepeatedDigit(n);
}