#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    string t;
    getline(cin, t);
    string n = "";
    n += s.at(s.length() - 1);
    int m = stoi(n);
    vector<int> v;
    n.clear();
    for (int i = 0; i < t.length(); i++)
    {
        if (isdigit(t[i]))
            n += t.at(i);
        if (t[i] == ',' || t[i] == '}')
        {
            v.push_back(stoi(n));
            n.clear();
            continue;
        }
    }
    // for (int i : v)
    // {
    //     cout << i;
    // }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (i != v.size() - 1 && v.at(i) + 1 != v.at(i + 1))
        {
            cout << v.at(i) + 1;
        }
    }
}