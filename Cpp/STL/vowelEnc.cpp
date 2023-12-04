#include <bits/stdc++.h>
using namespace std;

bool isPrime(int m)
{
    if (m == 2 || m == 3 || m == 5 || m == 7)
        return true;
    return false;
}

int main()
{
    int n = 123421;
    vector<char> v = {'a', 'e', 'i', 'o', 'u'};
    int l = 0;
    int c = 0;
    map<char, char> m;
    string s = to_string(n);
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        string j = "";
        j += s[i];
        int k = stoi(j);
        if (isPrime(k))
        {
            if (m.find(k) != m.end())
            {
                m[k] = v.at(l++);
            }
            ans += m[k];
        }
        else
        {
            if (m.find(k) != m.end())
                m[k] = v.at(0) + (c++);
            ans += m[k];
        }
    }
    for (pair<char, char> p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << ans;
}