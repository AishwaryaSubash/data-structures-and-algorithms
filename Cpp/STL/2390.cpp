#include <bits/stdc++.h>
using namespace std;

string removeStars(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '*')
        {
            stk.push(s[i]);
        }
        else
        {
            if (i != 0)
            {
                stk.pop();
            }
        }
    }
    string t = "";
    while (!stk.empty())
    {
        t += stk.top();
        stk.pop();
    }
    reverse(t.begin(), t.end());
    return t;
}

int main()
{
    string s = "leet**cod*e";
    cout << removeStars(s);
}