#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "00110011";
    vector<int> v;
    int count = 1;

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            v.push_back(count);
            count = 1;
        }
    }
    v.push_back(count);
    int ans = 0;
    for (int i = 1; i < v.size(); i++)
    {
        ans += min(v[i - 1], v[i]);
    }
    cout << ans;
}