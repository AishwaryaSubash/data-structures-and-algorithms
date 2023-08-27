#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "eeeeDDDDD111110000";
    map<char, int> m;
    string ans = "";
    vector<char> v;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]] += 1;
        if (m[s[i]] == 1)
        {
            v.push_back(s[i]);
        }
    }
    reverse(s.begin(), s.end());

    for (int i = 0; i < v.size(); i++)
    {

        ans += v[i];
        ans += to_string(m[v[i]]);
    }

    cout << ans;
}

// op: "e4D51504"