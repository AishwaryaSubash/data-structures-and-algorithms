#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcd";
    string ans = "";
    int k;
    cin >> k;
    for (int j = 0; j < k; j++)
    {
        for (int i = 1; i < s.length(); i++)
        {
            ans += s.at(i);
        }
        ans += s.front();
        s = ans;
        ans.clear();
    }
    cout << s;
}