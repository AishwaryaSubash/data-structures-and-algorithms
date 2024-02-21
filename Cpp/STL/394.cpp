#include <bits/stdc++.h>
using namespace std;

string decodeString(string s)
{
    stack<char> stk;
    string t = "";
    int count;
    int i = 0;
    while (i < s.length())
    {
        if (isdigit(s[i]))
        {
            count = count * 10 + (s[i++] - '0');
        }
        if (s[i] == '[')
        {
            i++;
            while (s[i] != ']')
            {
                stk.push(s[i++]);
            }
            if (s[i] == ']')
            {
                i++;
                string a = "";
                while (!stk.empty())
                {
                    a += stk.top();
                    stk.pop();
                }
                reverse(a.begin(), a.end());
                while (count != 0)
                {
                    t += a;
                    count--;
                }
            }
        }
    }
    return t;
}

int main()
{
    string s = "2[abc]3[cd]ef";
    cout << decodeString(s);
}