#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "I speak Goat Latin";
    vector<string> v;
    string t = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            v.push_back(t);
            t.clear();
            i++;
        }
        // i++;
        t += s[i];
    }
    v.push_back(t);

    string st = "ma";
    for (int i = 0; i < v.size(); i++)
    {
        int flag = 0;
        string u = v.at(i);
        if (u.at(0) == 'a' || u.at(0) == 'e' || u.at(0) == 'i' || u.at(0) == 'o' || u.at(0) == 'u' || u.at(0) == 'A' || u.at(0) == 'E' || u.at(0) == 'I' || u.at(0) == 'O' || u.at(0) == 'U')
        {
            flag = 1;
        }
        if (flag == 0)
        {
            char ch = u.at(0);
            u.erase(u.begin());
            u += ch;
        }
        st += "a";
        u += st;

        v.at(i) = u;
    }
    string ans = "";
    for (string u : v)
    {
        ans += u;
        ans += " ";
    }
    ans.erase(ans.end());
    cout << ans;
}