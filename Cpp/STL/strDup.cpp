#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "\"zvvo\"";
    s.erase(s.begin(), s.begin() + 1);
    s.erase(s.end() - 1, s.end());
    string t = "";
    for (char i : s)
    {
        if (find(t.begin(), t.end(), i) == t.end())
        {
            t += i;
        }
    }
    cout << "\"" << t << "\"";
}